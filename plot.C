#include "JetTree.C"
#include <cmath>
#include <iostream>
#include <vector>

class EventData {
public:
    std::vector<Double_t> photonPts;
    std::vector<Double_t> photonEtas;
    std::vector<Double_t> photonPhis;
    std::vector<Double_t> jetPts;
    std::vector<Double_t> jetEtas;
    std::vector<Double_t> jetPhis;
    Double_t weight;
};

void setBranches(TTree *tree, EventData &data) {
    tree->Branch("photonPt", &data.photonPts);
    tree->Branch("photonEta", &data.photonEtas);
    tree->Branch("photonPhi", &data.photonPhis);
    tree->Branch("jetPt", &data.jetPts);
    tree->Branch("jetEta", &data.jetEtas);
    tree->Branch("jetPhi", &data.jetPhis);
    tree->Branch("weight", &data.weight, "weight/D");
}

double calcPhi(double phi) {
    phi = fmod(phi + M_PI, 2 * M_PI);
    if (phi < 0) {
        phi += 2 * M_PI;
    }
    phi -= M_PI;
    return phi;
}

void processEvent(JetTree *j, TH1D* h, EventData &data, TTree *tree) {
    h->Sumw2();

    double sumEntry = 0;
    for (long long int i = 0; i < j->fChain->GetEntries(); i++) {
        if (i % 10000 == 0) std::cout << i << " " << j->fChain->GetEntries() << std::endl;
	data.photonPts.clear();
        data.photonEtas.clear();
        data.photonPhis.clear();
        data.jetPts.clear();
        data.jetEtas.clear();
        data.jetPhis.clear();
        j->GetEntry(i);
        if ((*j->LeadingPhotonPt)[0] < 40) continue;

        bool hasValidJets = false;
        std::vector<Double_t> eventJetPts;
        std::vector<Double_t> eventJetEtas;
        std::vector<Double_t> eventJetPhis;

        // Loop over jets in the event
        for (size_t k = 0; k < j->SignalJet03JewelPt->size(); k++) {
            if ((*j->SignalJet03JewelPt)[k] > 30 && fabs((*j->SignalJet03JewelEta)[k]) < 1.6) {
                double dPhi_jgamma = fabs(calcPhi((*j->SignalJet03JewelPhi)[k] - (*j->LeadingPhotonPhi)[0]));
                if (dPhi_jgamma < 3.14159 / 2.) continue;

                eventJetPts.push_back((*j->SignalJet03JewelPt)[k]);
                eventJetEtas.push_back((*j->SignalJet03JewelEta)[k]);
                eventJetPhis.push_back((*j->SignalJet03JewelPhi)[k]);
                hasValidJets = true;
            }
        }

        if (hasValidJets) {
            data.photonPts.push_back((*j->LeadingPhotonPt)[0]);
            data.photonEtas.push_back((*j->LeadingPhotonEta)[0]);
            data.photonPhis.push_back((*j->LeadingPhotonPhi)[0]);
            data.jetPts.insert(data.jetPts.end(), eventJetPts.begin(), eventJetPts.end());
            data.jetEtas.insert(data.jetEtas.end(), eventJetEtas.begin(), eventJetEtas.end());
            data.jetPhis.insert(data.jetPhis.end(), eventJetPhis.begin(), eventJetPhis.end());

            data.weight = (*j->EventWeight)[0];
            sumEntry += data.weight;
            tree->Fill();
        }
    }

    h->Scale(1. / sumEntry);
    for (int i = 0; i < h->GetNbinsX(); i++) {
        h->SetBinContent(i, h->GetBinContent(i) / h->GetBinWidth(i));
        h->SetBinError(i, h->GetBinError(i) / h->GetBinWidth(i));
    }
}



void plot() {
    TFile *infJewelPP = new TFile("inputJetTree/jewel-pp.root");
    TFile *infJewelPbPb = new TFile("inputJetTree/jewel-PbPb.root");
    TFile *infPyquenPP = new TFile("inputJetTree/pyquen-pp.root");
    TFile *infPyquenPbPb = new TFile("inputJetTree/pyquen-PbPb.root");

    TTree *tJewelPP = (TTree*)infJewelPP->Get("JetTree");
    TTree *tJewelPbPb = (TTree*)infJewelPbPb->Get("JetTree");
    TTree *tPyquenPP = (TTree*)infPyquenPP->Get("JetTree");
    TTree *tPyquenPbPb = (TTree*)infPyquenPbPb->Get("JetTree");

    TFile *outf = new TFile("output.root", "recreate");

    TTree* outputTreeJewelPP = new TTree("tJewelPP", "");
    TTree* outputTreeJewelPbPb = new TTree("tJewelPbPb", "");
    TTree* outputTreePyquenPP = new TTree("tPyquenPP", "");
    TTree* outputTreePyquenPbPb = new TTree("tPyquenPbPb", "");

    EventData dataJewelPP, dataJewelPbPb, dataPyquenPP, dataPyquenPbPb;
    setBranches(outputTreeJewelPP, dataJewelPP);
    setBranches(outputTreeJewelPbPb, dataJewelPbPb);
    setBranches(outputTreePyquenPP, dataPyquenPP);
    setBranches(outputTreePyquenPbPb, dataPyquenPbPb);

    const int nBin = 10;
    double myBins[nBin + 1] = {0, 0.015, 0.03, 0.045, 0.06, 0.08, 0.1, 0.12, 0.15, 0.2, 0.3};
    TH1D *hJewelPP = new TH1D("hJewelPP", "", nBin, myBins);
    TH1D *hJewelPbPb = new TH1D("hJewelPbPb", "", nBin, myBins);
    TH1D *hPyquenPP = new TH1D("hPyquenPP", "", nBin, myBins);
    TH1D *hPyquenPbPb = new TH1D("hPyquenPbPb", "", nBin, myBins);

    JetTree *JewelPP = new JetTree(tJewelPP);
    JetTree *JewelPbPb = new JetTree(tJewelPbPb);
    JetTree *PyquenPP = new JetTree(tPyquenPP);
    JetTree *PyquenPbPb = new JetTree(tPyquenPbPb);

    cout << "Processing JetTree Data" << endl;
    processEvent(JewelPP, hJewelPP, dataJewelPP, outputTreeJewelPP);
    processEvent(JewelPbPb, hJewelPbPb, dataJewelPbPb, outputTreeJewelPbPb);
    processEvent(PyquenPP, hPyquenPP, dataPyquenPP, outputTreePyquenPP);
    processEvent(PyquenPbPb, hPyquenPbPb, dataPyquenPbPb, outputTreePyquenPbPb);

    outf->cd();
    hJewelPP->Write();
    hJewelPbPb->Write();
    hPyquenPP->Write();
    hPyquenPbPb->Write();
    outputTreeJewelPP->Write();
    outputTreeJewelPbPb->Write();
    outputTreePyquenPP->Write();
    outputTreePyquenPbPb->Write();

    outf->Close();
    cout << "Done" << endl;
}
