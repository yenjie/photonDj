#include "JetTree.C"
#include <cmath>
double calcPhi(double phi)
{
   phi = fmod(phi + M_PI, 2*M_PI);
   if (phi < 0) {
       phi += 2*M_PI;
   }
   phi -= M_PI;
   return phi;
}

void fillDjHist(JetTree *j, TH1D* h)
{
   double sumEntry=0;
   h->Sumw2();
   for (int i=0;i<j->fChain->GetEntries();i++) {
      j->GetEntry(i);
      if ((*j->LeadingPhotonPt)[0]<40) continue;
      for (int k=0;k<j->SignalJet03JewelPt->size();k++) {
         if ((*j->SignalJet03JewelPt)[k]>30) {
	    double dPhi_jgamma = fabs(calcPhi((*j->SignalJet03JewelPhi)[k]-(*j->LeadingPhotonPhi)[0]));
	    if (dPhi_jgamma<3.14159*7./8.) continue;
	    double dPhi = calcPhi((*j->SignalJet03JewelPhi)[k]-(*j->SignalJet03WTAAxisPhi)[k]);
	    double dEta = (*j->SignalJet03JewelEta)[k]-(*j->SignalJet03WTAAxisEta)[k];
	    double dj = sqrt(dPhi*dPhi+dEta*dEta);
	    h->Fill(dj,(*j->EventWeight)[0]);
	    sumEntry+=(*j->EventWeight)[0];
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
   
   TTree *tJewelPP    = (TTree*)infJewelPP   ->Get("JetTree");
   TTree *tJewelPbPb  = (TTree*)infJewelPbPb ->Get("JetTree");
   TTree *tPyquenPP   = (TTree*)infPyquenPP  ->Get("JetTree");
   TTree *tPyquenPbPb = (TTree*)infPyquenPbPb->Get("JetTree");
   
   const int nBin = 10;
   double myBins[nBin+1] = {0, 0.015, 0.03, 0.045, 0.06, 0.08, 0.1, 0.12, 0.15, 0.2, 0.3};
   
   TH1D *hJewelPP   = new TH1D("hJewelPP","",nBin,myBins);
   TH1D *hJewelPbPb = new TH1D("hJewelPbPb","",nBin,myBins);
   TH1D *hPyquenPP   = new TH1D("hPyquenPP","",nBin,myBins);
   TH1D *hPyquenPbPb = new TH1D("hPyquenPbPb","",nBin,myBins);
   
   JetTree *JewelPP    = new JetTree(tJewelPP);
   JetTree *JewelPbPb  = new JetTree(tJewelPbPb);
   JetTree *PyquenPP   = new JetTree(tPyquenPP);
   JetTree *PyquenPbPb = new JetTree(tPyquenPbPb);

   fillDjHist(JewelPP,hJewelPP);
   fillDjHist(JewelPbPb,hJewelPbPb);
   fillDjHist(PyquenPP,hPyquenPP);
   fillDjHist(PyquenPbPb,hPyquenPbPb);
   
   hJewelPP->Draw();
   
   
}
