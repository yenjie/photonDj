#include "JetTree.C"
#include <cmath>
#include <iostream>

class Data {
public:
  Double_t photonPt, photonEta, photonPhi, jetPt, jetEta, jetPhi, dphi, dj, weight;
};


void setBranch(TTree *outputTree, Data *data)
{
  outputTree->Branch("photonPt", &data->photonPt, "photonPt/D");
  outputTree->Branch("photonEta", &data->photonEta, "photonEta/D");
  outputTree->Branch("photonPhi", &data->photonPhi, "photonPhi/D");
  outputTree->Branch("jetPt", &data->jetPt, "jetPt/D");
  outputTree->Branch("jetEta", &data->jetEta, "jetEta/D");
  outputTree->Branch("jetPhi", &data->jetPhi, "jetPhi/D");
  outputTree->Branch("dphi", &data->dphi, "dphi/D");
  outputTree->Branch("dj", &data->dj, "dj/D");
  outputTree->Branch("weight", &data->weight, "weight/D");
}


class DataSD {
public:
  Double_t photonPt, photonEta, photonPhi, jetPt, jetEta, jetPhi, dphi, dj, weight, zg, rg;
};


void setBranchSD(TTree *outputTree, DataSD *data)
{
  outputTree->Branch("photonPt", &data->photonPt, "photonPt/D");
  outputTree->Branch("photonEta", &data->photonEta, "photonEta/D");
  outputTree->Branch("photonPhi", &data->photonPhi, "photonPhi/D");
  outputTree->Branch("jetPt", &data->jetPt, "jetPt/D");
  outputTree->Branch("jetEta", &data->jetEta, "jetEta/D");
  outputTree->Branch("jetPhi", &data->jetPhi, "jetPhi/D");
  outputTree->Branch("dphi", &data->dphi, "dphi/D");
  outputTree->Branch("dj", &data->dj, "dj/D");
  outputTree->Branch("zg", &data->zg, "zg/D");
  outputTree->Branch("rg", &data->rg, "rg/D");
  outputTree->Branch("weight", &data->weight, "weight/D");
}

double calcPhi(double phi)
{
   phi = fmod(phi + M_PI, 2*M_PI);
   if (phi < 0) {
       phi += 2*M_PI;
   }
   phi -= M_PI;
   return phi;
}

void fillDjHist(JetTree *j, TH1D* h, Data *data, TTree *t, DataSD *dataSD, TTree *tSD, bool JEWELRecoil = true)
{
   double sumEntry=0;
   h->Sumw2();
   for (long long int i=0;i<j->fChain->GetEntries();i++) {
      if (i%10000==0) cout <<i <<" "<<j->fChain->GetEntries()<<endl;
      j->GetEntry(i);
      if ((*j->LeadingPhotonPt)[0]<40) continue;

      // R=0.3 Photon-Jet SD analysis
      for (long unsigned int k=0;k<j->SignalJet03JewelPt->size();k++) {
         if (((*j->SignalJet03JewelPt)[k]>30 && fabs((*j->SignalJet03JewelEta)[k])<1.6&&JEWELRecoil) ||
	     ((*j->SignalJet03Pt)[k]>30 && fabs((*j->SignalJet03Eta)[k])<1.6&&!JEWELRecoil)
	    ) {
	    double dPhi_jgamma = 0;

	    if (JEWELRecoil) dPhi_jgamma=fabs(calcPhi((*j->SignalJet03JewelPhi)[k]-(*j->LeadingPhotonPhi)[0]));
	    else             dPhi_jgamma=fabs(calcPhi((*j->SignalJet03Phi)[k]-(*j->LeadingPhotonPhi)[0]));

	    if (dPhi_jgamma<3.14159/2.) continue;

	    double dPhi = 0;
	    if (JEWELRecoil) dPhi=calcPhi((*j->SignalJet03JewelPhi)[k]-(*j->SignalJet03WTAAxisPhi)[k]);
	    else             dPhi=calcPhi((*j->SignalJet03Phi)[k]-(*j->SignalJet03WTAAxisPhi)[k]);

	    double dEta = 0;
	    if (JEWELRecoil) dEta=(*j->SignalJet03JewelEta)[k]-(*j->SignalJet03WTAAxisEta)[k];
	    else             dEta=(*j->SignalJet03Eta)[k]-(*j->SignalJet03WTAAxisEta)[k];

	    double dj = sqrt(dPhi*dPhi+dEta*dEta);
	    h->Fill(dj,(*j->EventWeight)[0]);
	    sumEntry+=(*j->EventWeight)[0];
	    data->weight=(*j->EventWeight)[0];
	    data->photonPt= (*j->LeadingPhotonPt)[0];
	    data->photonEta= (*j->LeadingPhotonEta)[0];
	    data->photonPhi= (*j->LeadingPhotonPhi)[0];
	    data->jetPt= (*j->SignalJet03JewelPt)[k];
	    data->jetEta= (*j->SignalJet03JewelEta)[k];
	    data->jetPhi= (*j->SignalJet03JewelPhi)[k];
	    data->dj=dj;
	    data->dphi=dPhi_jgamma;
	    t->Fill();
	 }
      }

      for (long unsigned int k=0;k<j->SignalJet02JewelPt->size();k++) {
         if ((*j->SignalJet02JewelPt)[k]>30 && fabs((*j->SignalJet02JewelEta)[k])<1.6) {
	    double dPhi_jgamma = fabs(calcPhi((*j->SignalJet02JewelPhi)[k]-(*j->LeadingPhotonPhi)[0]));
	    if (dPhi_jgamma<3.14159/2.) continue;
	    double dPhi = calcPhi((*j->SignalJet02JewelPhi)[k]-(*j->SignalJet02WTAAxisPhi)[k]);
	    double dEta = (*j->SignalJet02JewelEta)[k]-(*j->SignalJet02WTAAxisEta)[k];
	    double dj = sqrt(dPhi*dPhi+dEta*dEta);
	    h->Fill(dj,(*j->EventWeight)[0]);
	    sumEntry+=(*j->EventWeight)[0];
	    dataSD->weight=(*j->EventWeight)[0];
	    dataSD->photonPt= (*j->LeadingPhotonPt)[0];
	    dataSD->photonEta= (*j->LeadingPhotonEta)[0];
	    dataSD->photonPhi= (*j->LeadingPhotonPhi)[0];
	    dataSD->jetPt= (*j->SignalJet02JewelPt)[k];
	    dataSD->jetEta= (*j->SignalJet02JewelEta)[k];
	    dataSD->jetPhi= (*j->SignalJet02JewelPhi)[k];
	    dataSD->dj=dj;
	    dataSD->dphi=dPhi_jgamma;
	    tSD->Fill();
	 }
      }

   }
   h->Scale(1./sumEntry);
   
   for (int i=0;i<h->GetNbinsX();i++) {
      h->SetBinContent(i,h->GetBinContent(i)/h->GetBinWidth(i));
      h->SetBinError(i,h->GetBinError(i)/h->GetBinWidth(i));
   }    
}

void plot()
{
   TFile *infJewelPP    = new TFile("jewel-pp.root");
   TFile *infJewelPbPb  = new TFile("jewel-PbPb.root");
   TFile *infJewelPbPbNoRecoil  = new TFile("jewel-PbPb.root");
   TFile *infPyquenPP   = new TFile("pyquen-pp.root");
   TFile *infPyquenPbPb = new TFile("pyquen-PbPb.root");
   TFile *infPyquenNoWidePbPb = new TFile("pyquenNoWide-PbPb.root");
   
   TTree *tJewelPP    = (TTree*)infJewelPP   ->Get("JetTree");
   TTree *tJewelPbPb  = (TTree*)infJewelPbPb ->Get("JetTree");
   TTree *tJewelPbPbNoRecoil  = (TTree*)infJewelPbPbNoRecoil ->Get("JetTree");
   TTree *tPyquenPP   = (TTree*)infPyquenPP  ->Get("JetTree");
   TTree *tPyquenPbPb = (TTree*)infPyquenPbPb->Get("JetTree");
   TTree *tPyquenNoWidePbPb = (TTree*)infPyquenNoWidePbPb->Get("JetTree");
   
   TFile *outf = new TFile("output.root","recreate");
   
   TTree* outputTreeJewelPP = new TTree("tJewelPP","");
   TTree* outputTreeSDJewelPP = new TTree("tSDJewelPP","");
   Data *dataJewelPP = new Data;
   DataSD *dataSDJewelPP = new DataSD;
   setBranch(outputTreeJewelPP, dataJewelPP);
   setBranchSD(outputTreeSDJewelPP, dataSDJewelPP);
   
   TTree* outputTreeJewelPbPb = new TTree("tJewelPbPb","");
   TTree* outputTreeSDJewelPbPb = new TTree("tSDJewelPbPb","");
   Data *dataJewelPbPb = new Data;
   DataSD *dataSDJewelPbPb = new DataSD;
   setBranch(outputTreeJewelPbPb, dataJewelPbPb);
   setBranchSD(outputTreeSDJewelPbPb, dataSDJewelPbPb);
      
   TTree* outputTreeJewelPbPbNoRecoil = new TTree("tJewelPbPbNoRecoil","");
   TTree* outputTreeSDJewelPbPbNoRecoil = new TTree("tSDJewelPbPbNoRecoil","");
   Data *dataJewelPbPbNoRecoil = new Data;
   DataSD *dataSDJewelPbPbNoRecoil = new DataSD;
   setBranch(outputTreeJewelPbPbNoRecoil, dataJewelPbPbNoRecoil);
   setBranchSD(outputTreeSDJewelPbPbNoRecoil, dataSDJewelPbPbNoRecoil);
      
   TTree* outputTreePyquenPP = new TTree("tPyquenPP","");
   TTree* outputTreeSDPyquenPP = new TTree("tSDPyquenPP","");
   Data *dataPyquenPP = new Data;
   DataSD *dataSDPyquenPP = new DataSD;
   setBranch(outputTreePyquenPP, dataPyquenPP);
   setBranchSD(outputTreeSDPyquenPP, dataSDPyquenPP);
   
   TTree* outputTreePyquenPbPb = new TTree("tPyquenPbPb","");
   TTree* outputTreeSDPyquenPbPb = new TTree("tSDPyquenPbPb","");
   Data *dataPyquenPbPb = new Data;
   DataSD *dataSDPyquenPbPb = new DataSD;
   setBranch(outputTreePyquenPbPb, dataPyquenPbPb);
   setBranchSD(outputTreeSDPyquenPbPb, dataSDPyquenPbPb);

   TTree* outputTreePyquenNoWidePbPb = new TTree("tPyquenNoWidePbPb","");
   TTree* outputTreeSDPyquenNoWidePbPb = new TTree("tSDPyquenNoWidePbPb","");
   Data *dataPyquenNoWidePbPb = new Data;
   DataSD *dataSDPyquenNoWidePbPb = new DataSD;
   setBranch(outputTreePyquenNoWidePbPb, dataPyquenNoWidePbPb);
   setBranchSD(outputTreeSDPyquenNoWidePbPb, dataSDPyquenNoWidePbPb);

   
   
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
   fillDjHist(JewelPP,hJewelPP, dataJewelPP, outputTreeJewelPP, dataSDJewelPP, outputTreeSDJewelPP);
   fillDjHist(JewelPbPb,hJewelPbPb, dataJewelPbPb, outputTreeJewelPbPb, dataSDJewelPbPb, outputTreeSDJewelPbPb);
   fillDjHist(JewelPbPbNoRecoil,hJewelPbPbNoRecoil, dataJewelPbPbNoRecoil, outputTreeJewelPbPbNoRecoil, dataSDJewelPbPbNoRecoil, outputTreeSDJewelPbPbNoRecoil,0);
   fillDjHist(PyquenPP,hPyquenPP, dataPyquenPP, outputTreePyquenPP, dataSDPyquenPP, outputTreeSDPyquenPP);
   fillDjHist(PyquenPbPb,hPyquenPbPb, dataPyquenPbPb, outputTreePyquenPbPb, dataSDPyquenPbPb, outputTreeSDPyquenPbPb);
   fillDjHist(PyquenNoWidePbPb,hPyquenNoWidePbPb, dataPyquenNoWidePbPb, outputTreePyquenNoWidePbPb, dataSDPyquenNoWidePbPb, outputTreeSDPyquenNoWidePbPb);
   
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
   outputTreeSDJewelPP->Write();
   outputTreeSDJewelPbPb->Write();
   outputTreeSDPyquenPP->Write();
   outputTreeSDPyquenPbPb->Write();
   outputTreeSDPyquenNoWidePbPb->Write();
   
}
