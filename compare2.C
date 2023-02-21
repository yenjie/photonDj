#include <TFile.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLine.h>
#include <TTree.h>
#include <TCut.h>

void normalize(TH1D *h)
{
   for (int i=0;i<h->GetNbinsX();i++) {
      h->SetBinContent(i,h->GetBinContent(i)/h->GetBinWidth(i));
      h->SetBinError(i,h->GetBinError(i)/h->GetBinWidth(i));
   }   
}


void compare2(TCut cut="1",bool jewel=1, bool pyquen=1)
{
   TCanvas *c = new TCanvas("c","",600,600);
   
   TFile *inf = new TFile("output.root");
   
   const int nBin = 10;
   double myBins[nBin+1] = {0, 0.015, 0.03, 0.045, 0.06, 0.08, 0.1, 0.12, 0.15, 0.2, 0.3};
   
   TH1D *hJewelPP   = new TH1D("hJewelPP","",nBin,myBins);
   TH1D *hJewelPbPb = new TH1D("hJewelPbPb","",nBin,myBins);
   TH1D *hPyquenPP   = new TH1D("hPyquenPP","",nBin,myBins);
   TH1D *hPyquenPbPb = new TH1D("hPyquenPbPb","",nBin,myBins);

   hJewelPP->Sumw2();
   hJewelPbPb->Sumw2();
   hPyquenPP->Sumw2();
   hPyquenPbPb->Sumw2();
   
   TTree *tJewelPP=(TTree*)inf->Get("tJewelPP");
   TTree *tJewelPbPb=(TTree*)inf->Get("tJewelPbPb");
   TTree *tPyquenPP=(TTree*)inf->Get("tPyquenPP");
   TTree *tPyquenPbPb=(TTree*)inf->Get("tPyquenPbPb");


   tJewelPP->Draw("dj>>hJewelPP","data.weight"*cut);
   tJewelPbPb->Draw("dj>>hJewelPbPb","data.weight"*cut);
   tPyquenPP->Draw("dj>>hPyquenPP","data.weight"*cut);
   tPyquenPbPb->Draw("dj>>hPyquenPbPb","data.weight"*cut);

    hJewelPP->Scale(1./hJewelPP->Integral(0,100));
   hJewelPbPb->Scale(1./hJewelPbPb->Integral(0,100));
   hPyquenPP->Scale(1./hPyquenPP->Integral(0,100));
   hPyquenPbPb->Scale(1./hPyquenPbPb->Integral(0,100));
   normalize(hJewelPP);
   normalize(hJewelPbPb);
   normalize(hPyquenPP);
   normalize(hPyquenPbPb);
   

   hJewelPbPb->SetLineColor(2);
   hPyquenPbPb->SetLineColor(kOrange+2);
   hJewelPP->SetLineColor(1);
   hPyquenPP->SetLineColor(kGray+2);
   
   hJewelPbPb->SetMarkerColor(2);
   hPyquenPbPb->SetMarkerColor(2);
   hJewelPP->SetMarkerColor(1);
   hPyquenPP->SetMarkerColor(1);
   
   hPyquenPP->SetMarkerStyle(24);
   hPyquenPbPb->SetMarkerStyle(24);

   TLegend *leg = new TLegend(0.5,0.7,0.9,0.9);
   
   
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
   leg->AddEntry(hJewelPP,"Photon p_{T}> 60 GeV","");
   if (jewel) leg->AddEntry(hJewelPP, "Jewel pp","pl");
   if (jewel) leg->AddEntry(hJewelPbPb, "Jewel PbPb 0-10%","pl");
   if (pyquen) leg->AddEntry(hPyquenPP, "Pyquen pp","pl");
   if (pyquen) leg->AddEntry(hPyquenPbPb, "Pyquen Wide PbPb 0-10%","pl");
   
   hJewelPP->SetXTitle("#deltaj");
   hJewelPP->SetYTitle("1/N^{#gamma j} dN/d#delta j");
   hJewelPP->SetAxisRange(-2,27,"Y");
   hJewelPP->GetXaxis()->CenterTitle();
   hJewelPP->GetYaxis()->CenterTitle();
   TLine *l = new TLine(0,0,0.3,0);
   l->SetLineStyle(2);
   
   TH1D *h = (TH1D*)hJewelPP->Clone("h");
   h->Reset();
   h->Draw();
   if (jewel) hJewelPP->Draw("same");
   if (jewel) hJewelPbPb->Draw("same");
   if (pyquen) hPyquenPP->Draw("same");
   if (pyquen) hPyquenPbPb->Draw("same");
   leg->Draw();
   l->Draw("same");
 
}
