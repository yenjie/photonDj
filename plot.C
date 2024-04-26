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
    std::vector<Double_t> jetDjs;
    Double_t weight;
};

void setBranch(TTree *tree, EventData &data) {
    tree->Branch("photonPt", &data.photonPts);
    tree->Branch("photonEta", &data.photonEtas);
    tree->Branch("photonPhi", &data.photonPhis);
    tree->Branch("jetPt", &data.jetPts);
    tree->Branch("jetEta", &data.jetEtas);
    tree->Branch("jetPhi", &data.jetPhis);
    tree->Branch("jetDj", &data.jetDjs);
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

void processEvent(JetTree *j, TH1D* h, EventData &data, TTree *tree, bool JEWELRecoil = true) {
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
	data.jetDjs.clear();
        j->GetEntry(i);
        if ((*j->LeadingPhotonPt)[0] < 40) continue;
        data.photonPts.push_back((*j->LeadingPhotonPt)[0]);
        data.photonEtas.push_back((*j->LeadingPhotonEta)[0]);
        data.photonPhis.push_back((*j->LeadingPhotonPhi)[0]);

        data.weight = (*j->EventWeight)[0];

        bool hasValidJets = false;

        // Loop over jets in the event
        for (size_t k = 0; k < j->SignalJet03JewelPt->size(); k++) {
            if ((*j->SignalJet03JewelPt)[k] > 30 && fabs((*j->SignalJet03JewelEta)[k]) < 1.6) {
	    double dPhi_jgamma = 0;
                if (JEWELRecoil) dPhi_jgamma=fabs(calcPhi((*j->SignalJet03JewelPhi)[k]-(*j->LeadingPhotonPhi)[0]));
	        else             dPhi_jgamma=fabs(calcPhi((*j->SignalJet03Phi)[k]-(*j->LeadingPhotonPhi)[0]));
                if (dPhi_jgamma < 3.14159 / 2.) continue;
                
		double dPhi=0, dEta=0;
                if (JEWELRecoil) {
  		   data.jetPts.push_back((*j->SignalJet03JewelPt)[k]);
                   data.jetEtas.push_back((*j->SignalJet03JewelEta)[k]);
                   data.jetPhis.push_back((*j->SignalJet03JewelPhi)[k]);
                   dPhi = calcPhi((*j->SignalJet03JewelPhi)[k]-(*j->SignalJet03WTAAxisPhi)[k]);	    
	           dEta = (*j->SignalJet03JewelEta)[k]-(*j->SignalJet03WTAAxisEta)[k];
	        } else {
  		   data.jetPts.push_back((*j->SignalJet03Pt)[k]);
                   data.jetEtas.push_back((*j->SignalJet03Eta)[k]);
                   data.jetPhis.push_back((*j->SignalJet03Phi)[k]);
                   dPhi = calcPhi((*j->SignalJet03Phi)[k]-(*j->SignalJet03WTAAxisPhi)[k]);	    
	           dEta = (*j->SignalJet03Eta)[k]-(*j->SignalJet03WTAAxisEta)[k];
		}
		double dj = sqrt(dPhi*dPhi+dEta*dEta);
                sumEntry += data.weight;
		h->Fill(dj, data.weight);
		data.jetDjs.push_back(dj);
            }
        }

        tree->Fill();
    }

    h->Scale(1. / sumEntry);
    for (int i = 0; i < h->GetNbinsX(); i++) {
        h->SetBinContent(i, h->GetBinContent(i) / h->GetBinWidth(i));
        h->SetBinError(i, h->GetBinError(i) / h->GetBinWidth(i));
    }
}


void plot() {
   TFile *infJewelPP    = new TFile("inputJetTree/jewel-pp.root");
   TFile *infJewelPbPb  = new TFile("inputJetTree/jewel-PbPb.root");
   TFile *infJewelPbPbNoRecoil  = new TFile("inputJetTree/jewel-PbPb.root");
   TFile *infPyquenPP   = new TFile("inputJetTree/pyquen-pp.root");
   TFile *infPyquenPbPb = new TFile("inputJetTree/pyquen-PbPb.root");
   TFile *infPyquenNoWidePbPb = new TFile("inputJetTree/pyquenNoWide-PbPb.root");
   
   TTree *tJewelPP    = (TTree*)infJewelPP   ->Get("JetTree");
   TTree *tJewelPbPb  = (TTree*)infJewelPbPb ->Get("JetTree");
   TTree *tJewelPbPbNoRecoil  = (TTree*)infJewelPbPbNoRecoil ->Get("JetTree");
   TTree *tPyquenPP   = (TTree*)infPyquenPP  ->Get("JetTree");
   TTree *tPyquenPbPb = (TTree*)infPyquenPbPb->Get("JetTree");
   TTree *tPyquenNoWidePbPb = (TTree*)infPyquenNoWidePbPb->Get("JetTree");
   
   TFile *outf = new TFile("output.root","recreate");
   
   TTree* outputTreeJewelPP = new TTree("tJewelPP","");
   EventData dataJewelPP;
   setBranch(outputTreeJewelPP, dataJewelPP);
   
   TTree* outputTreeJewelPbPb = new TTree("tJewelPbPb","");
   EventData dataJewelPbPb;
   setBranch(outputTreeJewelPbPb, dataJewelPbPb);
      
   TTree* outputTreeJewelPbPbNoRecoil = new TTree("tJewelPbPbNoRecoil","");
   EventData dataJewelPbPbNoRecoil;
   setBranch(outputTreeJewelPbPbNoRecoil, dataJewelPbPbNoRecoil);
      
   TTree* outputTreePyquenPP = new TTree("tPyquenPP","");
   EventData dataPyquenPP;
   setBranch(outputTreePyquenPP, dataPyquenPP);
   
   TTree* outputTreePyquenPbPb = new TTree("tPyquenPbPb","");
   EventData dataPyquenPbPb;
   setBranch(outputTreePyquenPbPb, dataPyquenPbPb);

   TTree* outputTreePyquenNoWidePbPb = new TTree("tPyquenNoWidePbPb","");
   EventData dataPyquenNoWidePbPb;
   setBranch(outputTreePyquenNoWidePbPb, dataPyquenNoWidePbPb);

   
   
   const int nBin = 10;
   double myBins[nBin+1] = {0, 0.015, 0.03, 0.045, 0.06, 0.08, 0.1, 0.12, 0.15, 0.2, 0.3};
   
   TH1D *hJewelPP   = new TH1D("hJewelPP","",nBin,myBins);
   TH1D *hJewelPbPb = new TH1D("hJewelPbPb","",nBin,myBins);
   TH1D *hJewelPbPbNoRecoil = new TH1D("hJewelPbPbNoRecoil","",nBin,myBins);
   TH1D *hPyquenPP   = new TH1D("hPyquenPP","",nBin,myBins);
   TH1D *hPyquenPbPb = new TH1D("hPyquenPbPb","",nBin,myBins);
   TH1D *hPyquenNoWidePbPb = new TH1D("hPyquenNoWidePbPb","",nBin,myBins);
   
   
   cout <<"JetTree"<<endl;
   JetTree *JewelPP    = new JetTree(tJewelPP);
   JetTree *JewelPbPb  = new JetTree(tJewelPbPb);
   JetTree *JewelPbPbNoRecoil  = new JetTree(tJewelPbPbNoRecoil);
   JetTree *PyquenPP   = new JetTree(tPyquenPP);
   JetTree *PyquenPbPb = new JetTree(tPyquenPbPb);
   JetTree *PyquenNoWidePbPb = new JetTree(tPyquenNoWidePbPb);

   cout <<"Done"<<endl;
   processEvent(JewelPP,hJewelPP, dataJewelPP, outputTreeJewelPP, 1);
   processEvent(JewelPbPb,hJewelPbPb, dataJewelPbPb, outputTreeJewelPbPb, 1);
   processEvent(JewelPbPbNoRecoil,hJewelPbPbNoRecoil, dataJewelPbPbNoRecoil, outputTreeJewelPbPbNoRecoil,0);
   processEvent(PyquenPP,hPyquenPP, dataPyquenPP, outputTreePyquenPP, 1);
   processEvent(PyquenPbPb,hPyquenPbPb, dataPyquenPbPb, outputTreePyquenPbPb, 1);
   processEvent(PyquenNoWidePbPb,hPyquenNoWidePbPb, dataPyquenNoWidePbPb, outputTreePyquenNoWidePbPb, 1);
   
   hJewelPP->Draw();
   hJewelPP->Write();
   hJewelPbPb->Write();
   hJewelPbPbNoRecoil->Write();
   hPyquenPP->Write();
   hPyquenPbPb->Write();
   hPyquenNoWidePbPb->Write();
   outputTreeJewelPP->Write();
   outputTreeJewelPbPb->Write();
   outputTreeJewelPbPbNoRecoil->Write();
   outputTreePyquenPP->Write();
   outputTreePyquenPbPb->Write();
   outputTreePyquenNoWidePbPb->Write();
}
