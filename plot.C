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

double calcPhi(double phi)
{
   phi = fmod(phi + M_PI, 2*M_PI);
   if (phi < 0) {
       phi += 2*M_PI;
   }
   phi -= M_PI;
   return phi;
}

void fillDjHist(JetTree *j, TH1D* h, Data *data, TTree *t)
{
   double sumEntry=0;
   h->Sumw2();
   for (int i=0;i<j->fChain->GetEntries();i++) {
      if (i%10000==0) cout <<i <<" "<<j->fChain->GetEntries()<<endl;
      j->GetEntry(i);
      if ((*j->LeadingPhotonPt)[0]<40) continue;
      for (int k=0;k<j->SignalJet03JewelPt->size();k++) {
         if ((*j->SignalJet03JewelPt)[k]>30 && fabs((*j->SignalJet03JewelEta)[k])<1.6) {
	    double dPhi_jgamma = fabs(calcPhi((*j->SignalJet03JewelPhi)[k]-(*j->LeadingPhotonPhi)[0]));
	    if (dPhi_jgamma<3.14159/2.) continue;
	    double dPhi = calcPhi((*j->SignalJet03JewelPhi)[k]-(*j->SignalJet03WTAAxisPhi)[k]);
	    double dEta = (*j->SignalJet03JewelEta)[k]-(*j->SignalJet03WTAAxisEta)[k];
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
	    data->dphi=dPhi;
	    t->Fill();
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
   TFile *infPyquenPP   = new TFile("pyquen-pp.root");
   TFile *infPyquenPbPb = new TFile("pyquen-PbPb.root");
   TFile *infPyquenNoWidePbPb = new TFile("pyquenNoWide-PbPb.root");
   
   TTree *tJewelPP    = (TTree*)infJewelPP   ->Get("JetTree");
   TTree *tJewelPbPb  = (TTree*)infJewelPbPb ->Get("JetTree");
   TTree *tPyquenPP   = (TTree*)infPyquenPP  ->Get("JetTree");
   TTree *tPyquenPbPb = (TTree*)infPyquenPbPb->Get("JetTree");
   TTree *tPyquenNoWidePbPb = (TTree*)infPyquenNoWidePbPb->Get("JetTree");
   
   TFile *outf = new TFile("output.root","recreate");
   
   TTree* outputTreeJewelPP = new TTree("tJewelPP","");
   Data *dataJewelPP = new Data;
   setBranch(outputTreeJewelPP, dataJewelPP);
   TTree* outputTreeJewelPbPb = new TTree("tJewelPbPb","");
   Data *dataJewelPbPb = new Data;
   setBranch(outputTreeJewelPbPb, dataJewelPbPb);
   TTree* outputTreePyquenPP = new TTree("tPyquenPP","");
   Data *dataPyquenPP = new Data;
   setBranch(outputTreePyquenPP, dataPyquenPP);
   TTree* outputTreePyquenPbPb = new TTree("tPyquenPbPb","");
   Data *dataPyquenPbPb = new Data;
   setBranch(outputTreePyquenPbPb, dataPyquenPbPb);
   TTree* outputTreePyquenNoWidePbPb = new TTree("tPyquenNoWidePbPb","");
   Data *dataPyquenNoWidePbPb = new Data;
   setBranch(outputTreePyquenNoWidePbPb, dataPyquenNoWidePbPb);

   
   const int nBin = 10;
   double myBins[nBin+1] = {0, 0.015, 0.03, 0.045, 0.06, 0.08, 0.1, 0.12, 0.15, 0.2, 0.3};
   
   TH1D *hJewelPP   = new TH1D("hJewelPP","",nBin,myBins);
   TH1D *hJewelPbPb = new TH1D("hJewelPbPb","",nBin,myBins);
   TH1D *hPyquenPP   = new TH1D("hPyquenPP","",nBin,myBins);
   TH1D *hPyquenPbPb = new TH1D("hPyquenPbPb","",nBin,myBins);
   TH1D *hPyquenNoWidePbPb = new TH1D("hPyquenNoWidePbPb","",nBin,myBins);
   
   
   cout <<"JetTree"<<endl;
   JetTree *JewelPP    = new JetTree(tJewelPP);
   JetTree *JewelPbPb  = new JetTree(tJewelPbPb);
   JetTree *PyquenPP   = new JetTree(tPyquenPP);
   JetTree *PyquenPbPb = new JetTree(tPyquenPbPb);
   JetTree *PyquenNoWidePbPb = new JetTree(tPyquenNoWidePbPb);

   cout <<"Done"<<endl;
   fillDjHist(JewelPP,hJewelPP, dataJewelPP, outputTreeJewelPP);
   fillDjHist(JewelPbPb,hJewelPbPb, dataJewelPbPb, outputTreeJewelPbPb);
   fillDjHist(PyquenPP,hPyquenPP, dataPyquenPP, outputTreePyquenPP);
   fillDjHist(PyquenPbPb,hPyquenPbPb, dataPyquenPbPb, outputTreePyquenPbPb);
   fillDjHist(PyquenNoWidePbPb,hPyquenNoWidePbPb, dataPyquenNoWidePbPb, outputTreePyquenNoWidePbPb);
   
   hJewelPP->Draw();
   hJewelPP->Write();
   hJewelPbPb->Write();
   hPyquenPP->Write();
   hPyquenPbPb->Write();
   hPyquenNoWidePbPb->Write();
   outputTreeJewelPP->Write();
   outputTreeJewelPbPb->Write();
   outputTreePyquenPP->Write();
   outputTreePyquenPbPb->Write();
   outputTreePyquenNoWidePbPb->Write();
   
}
