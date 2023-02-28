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


// Compare photon Dj distribution

void compareResult(string title="",TCut cut="1",bool jewel=1, bool pyquen=1, bool ratio = 0)
{
   TCanvas *c = new TCanvas("c","",600,600);
   
   TFile *inf = new TFile("output-v4.root");
   // v3: with pyquen NoWide
   // baseline photon pT cut = 40, baseline jet pt cut = 30   
   const int nBin = 10;
   double myBins[nBin+1] = {0, 0.015, 0.03, 0.045, 0.06, 0.08, 0.1, 0.12, 0.15, 0.2, 0.3};
   
   TH1D *hJewelPP   = new TH1D("hJewelPP","",nBin,myBins);
   TH1D *hJewelPbPb = new TH1D("hJewelPbPb","",nBin,myBins);
   TH1D *hPyquenPP   = new TH1D("hPyquenPP","",nBin,myBins);
   TH1D *hPyquenPbPb = new TH1D("hPyquenPbPb","",nBin,myBins);
   TH1D *hPyquenNoWidePbPb = new TH1D("hPyquenNoWidePbPb","",nBin,myBins);

   hJewelPP->Sumw2();
   hJewelPbPb->Sumw2();
   hPyquenPP->Sumw2();
   hPyquenPbPb->Sumw2();
   hPyquenNoWidePbPb->Sumw2();
   
   TTree *tJewelPP=(TTree*)inf->Get("tJewelPP");
   TTree *tJewelPbPb=(TTree*)inf->Get("tJewelPbPb");
   TTree *tPyquenPP=(TTree*)inf->Get("tPyquenPP");
   TTree *tPyquenPbPb=(TTree*)inf->Get("tPyquenPbPb");
   TTree *tPyquenNoWidePbPb=(TTree*)inf->Get("tPyquenNoWidePbPb");


   tJewelPP->Draw("dj>>hJewelPP","weight"*cut);
   tJewelPbPb->Draw("dj>>hJewelPbPb","weight"*cut);
   tPyquenPP->Draw("dj>>hPyquenPP","weight"*cut);
   tPyquenPbPb->Draw("dj>>hPyquenPbPb","weight"*cut);
   tPyquenNoWidePbPb->Draw("dj>>hPyquenNoWidePbPb","weight"*cut);

   hJewelPP->Scale(1./hJewelPP->Integral(0,100));
   hJewelPbPb->Scale(1./hJewelPbPb->Integral(0,100));
   hPyquenPP->Scale(1./hPyquenPP->Integral(0,100));
   hPyquenPbPb->Scale(1./hPyquenPbPb->Integral(0,100));
   hPyquenNoWidePbPb->Scale(1./hPyquenNoWidePbPb->Integral(0,100));
   normalize(hJewelPP);
   normalize(hJewelPbPb);
   normalize(hPyquenPP);
   normalize(hPyquenPbPb);
   normalize(hPyquenNoWidePbPb);
   

   hJewelPbPb->SetLineColor(2);
   hPyquenPbPb->SetLineColor(2);
   hPyquenNoWidePbPb->SetLineColor(6);
   hJewelPP->SetLineColor(1);
   hPyquenPP->SetLineColor(kGray+2);
   
   hJewelPbPb->SetMarkerColor(2);
   hPyquenPbPb->SetMarkerColor(2);
   hPyquenNoWidePbPb->SetMarkerColor(6);
   hJewelPP->SetMarkerColor(1);
   hPyquenPP->SetMarkerColor(1);
   
   hPyquenPP->SetMarkerStyle(24);
   hPyquenPbPb->SetMarkerStyle(24);
   hPyquenNoWidePbPb->SetMarkerStyle(25);

   TLegend *leg = new TLegend(0.5,0.7,0.9,0.9);
   
   
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
   leg->AddEntry(hJewelPP,title.c_str(),"");
   if (ratio) {
      leg = new TLegend(0.2,0.7,0.9,0.9);
      leg->SetBorderSize(0);
      leg->SetFillStyle(0);
      leg->AddEntry(hJewelPP,title.c_str(),"");
      if (jewel) leg->AddEntry(hJewelPbPb, "Jewel PbPb 0-10% / Jewel pp","pl");
      if (pyquen) leg->AddEntry(hPyquenPbPb, "Pyquen Wide PbPb 0-10% / Pyquen pp","pl");
      if (pyquen) leg->AddEntry(hPyquenNoWidePbPb, "Pyquen PbPb 0-10% / Pyquen pp","pl");
   } else {
      if (jewel) leg->AddEntry(hJewelPP, "Jewel pp","pl");
      if (jewel) leg->AddEntry(hJewelPbPb, "Jewel PbPb 0-10%","pl");
      if (pyquen) leg->AddEntry(hPyquenPP, "Pyquen pp","pl");
      if (pyquen) leg->AddEntry(hPyquenNoWidePbPb, "Pyquen PbPb 0-10%","pl");
      if (pyquen) leg->AddEntry(hPyquenPbPb, "Pyquen Wide PbPb 0-10%","pl");
   }
   hJewelPP->SetXTitle("#deltaj");
   TLine *l = new TLine(0,0,0.3,0);
   if (ratio) {
      l = new TLine(0,1,0.3,1);
      hJewelPP->SetAxisRange(0.5,3,"Y");
      hJewelPP->SetYTitle("Ratio");
   } else {
      hJewelPP->SetAxisRange(-2,27,"Y");
      hJewelPP->SetYTitle("1/N^{#gamma j} dN/d#delta j");
   }   
   hJewelPP->GetXaxis()->CenterTitle();
   hJewelPP->GetYaxis()->CenterTitle();
   l->SetLineStyle(2);
   
   TH1D *h = (TH1D*)hJewelPP->Clone("h");
   h->Reset();
   h->Draw();

   if (ratio) {
     if (jewel) hJewelPbPb->Divide(hJewelPP);
     if (jewel) hJewelPbPb->Draw("same");
     if (pyquen) hPyquenPbPb->Divide(hPyquenPP);
     if (pyquen) hPyquenPbPb->Draw("same");
     if (pyquen) hPyquenNoWidePbPb->Divide(hPyquenPP);
     if (pyquen) hPyquenNoWidePbPb->Draw("same");
   } else {
      if (jewel) hJewelPP->Draw("same");
      if (jewel) hJewelPbPb->Draw("same");
      if (pyquen) hPyquenPP->Draw("same");
      if (pyquen) hPyquenPbPb->Draw("same");
      if (pyquen) hPyquenNoWidePbPb->Draw("same");
   }   
   leg->Draw();
   l->Draw("same");
 
}
