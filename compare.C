#include <TFile.h>
#include <TH1D.h>
#include <TCanvas.h>

void compare()
{
   TCanvas *c = new TCanvas("c","",600,600);
   
   TFile *inf = new TFile("output.root");
   
   TH1D *hJewelPP=(TH1D*)inf->Get("hJewelPP");
   TH1D *hJewelPbPb=(TH1D*)inf->Get("hJewelPbPb");
   TH1D *hPyquenPP=(TH1D*)inf->Get("hPyquenPP");
   TH1D *hPyquenPbPb=(TH1D*)inf->Get("hPyquenPbPb");


   hJewelPbPb->SetLineColor(2);
   hPyquenPbPb->SetLineColor(kOrange+2);
   hJewelPP->SetLineColor(1);
   hPyquenPP->SetLineColor(kGray+2);
   
   hJewelPbPb->SetMarkerColor(2);
   hPyquenPbPb->SetMarkerColor(kOrange+2);
   hJewelPP->SetMarkerColor(1);
   hPyquenPP->SetMarkerColor(kGray+2);

   TLegend *leg = new TLegend(0.5,0.7,0.9,0.9);
   
   
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
   leg->AddEntry(hJewelPP, "Jewel pp","pl");
   leg->AddEntry(hJewelPbPb, "Jewel PbPb 0-10%","pl");
   leg->AddEntry(hPyquenPP, "Pyquen pp","pl");
   leg->AddEntry(hPyquenPbPb, "Pyquen PbPb 0-10%","pl");
   
   hJewelPP->SetXTitle("#deltaj");
   hJewelPP->SetYTitle("1/N^{#gamma j} dN/d#delta j");
   hJewelPP->SetAxisRange(-2,27,"Y");
   hJewelPP->GetXaxis()->CenterTitle();
   hJewelPP->GetYaxis()->CenterTitle();
   TLine *l = new TLine(0,0,0.3,0);
   l->SetLineStyle(2);
   
   TH1D *h = (TH1D*)hJewelPP->Clone("h");
   h->Clear();
   h->Draw();
   hJewelPP->Draw("same");
   hJewelPbPb->Draw("same");
   hPyquenPP->Draw("same");
   hPyquenPbPb->Draw("same");
   leg->Draw();
   l->Draw("same");
 
}
