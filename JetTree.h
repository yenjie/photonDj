//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Feb 20 21:12:09 2023 by ROOT version 6.22/00
// from TTree JetTree/JetToyHI tree
// found on file: PbPb-pyquen-PhotonJet-1.root
//////////////////////////////////////////////////////////

#ifndef JetTree_h
#define JetTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class JetTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<double>  *SignalJet03Pt;
   vector<double>  *SignalJet03Eta;
   vector<double>  *SignalJet03Phi;
   vector<double>  *SignalJet03M;
   vector<double>  *SignalJet03Area;
   vector<double>  *SignalJet03WTAAxisPt;
   vector<double>  *SignalJet03WTAAxisEta;
   vector<double>  *SignalJet03WTAAxisPhi;
   vector<double>  *SignalJet03WTAAxisM;
   vector<double>  *SignalJet03WTAAxisArea;
   vector<double>  *SignalJet03JewelPt;
   vector<double>  *SignalJet03JewelEta;
   vector<double>  *SignalJet03JewelPhi;
   vector<double>  *SignalJet03JewelM;
   vector<double>  *SignalJet03JewelArea;
   vector<double>  *SignalJet03particlePt;
   vector<double>  *SignalJet03particleEta;
   vector<double>  *SignalJet03particlePhi;
   vector<double>  *SignalJet03particleM;
   vector<double>  *SignalJet03particleArea;
   vector<double>  *LeadingPhotonPt;
   vector<double>  *LeadingPhotonEta;
   vector<double>  *LeadingPhotonPhi;
   vector<double>  *LeadingPhotonM;
   vector<double>  *LeadingPhotonArea;
   vector<double>  *PhotonIso;
   vector<double>  *ParticlesRealPt;
   vector<double>  *ParticlesRealEta;
   vector<double>  *ParticlesRealPhi;
   vector<double>  *ParticlesRealM;
   vector<double>  *ParticlesRealArea;
   vector<int>     *pdg_id;
   vector<double>  *DummyPt;
   vector<double>  *DummyEta;
   vector<double>  *DummyPhi;
   vector<double>  *DummyM;
   vector<double>  *DummyArea;
   vector<double>  *EventWeight;

   // List of branches
   TBranch        *b_SignalJet03Pt;   //!
   TBranch        *b_SignalJet03Eta;   //!
   TBranch        *b_SignalJet03Phi;   //!
   TBranch        *b_SignalJet03M;   //!
   TBranch        *b_SignalJet03Area;   //!
   TBranch        *b_SignalJet03WTAAxisPt;   //!
   TBranch        *b_SignalJet03WTAAxisEta;   //!
   TBranch        *b_SignalJet03WTAAxisPhi;   //!
   TBranch        *b_SignalJet03WTAAxisM;   //!
   TBranch        *b_SignalJet03WTAAxisArea;   //!
   TBranch        *b_SignalJet03JewelPt;   //!
   TBranch        *b_SignalJet03JewelEta;   //!
   TBranch        *b_SignalJet03JewelPhi;   //!
   TBranch        *b_SignalJet03JewelM;   //!
   TBranch        *b_SignalJet03JewelArea;   //!
   TBranch        *b_SignalJet03particlePt;   //!
   TBranch        *b_SignalJet03particleEta;   //!
   TBranch        *b_SignalJet03particlePhi;   //!
   TBranch        *b_SignalJet03particleM;   //!
   TBranch        *b_SignalJet03particleArea;   //!
   TBranch        *b_LeadingPhotonPt;   //!
   TBranch        *b_LeadingPhotonEta;   //!
   TBranch        *b_LeadingPhotonPhi;   //!
   TBranch        *b_LeadingPhotonM;   //!
   TBranch        *b_LeadingPhotonArea;   //!
   TBranch        *b_PhotonIso;   //!
   TBranch        *b_ParticlesRealPt;   //!
   TBranch        *b_ParticlesRealEta;   //!
   TBranch        *b_ParticlesRealPhi;   //!
   TBranch        *b_ParticlesRealM;   //!
   TBranch        *b_ParticlesRealArea;   //!
   TBranch        *b_pdg_id;   //!
   TBranch        *b_DummyPt;   //!
   TBranch        *b_DummyEta;   //!
   TBranch        *b_DummyPhi;   //!
   TBranch        *b_DummyM;   //!
   TBranch        *b_DummyArea;   //!
   TBranch        *b_EventWeight;   //!

   JetTree(TTree *tree=0);
   virtual ~JetTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef JetTree_cxx
JetTree::JetTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("PbPb-pyquen-PhotonJet-1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("PbPb-pyquen-PhotonJet-1.root");
      }
      f->GetObject("JetTree",tree);

   }
   Init(tree);
}

JetTree::~JetTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t JetTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t JetTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void JetTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   SignalJet03Pt = 0;
   SignalJet03Eta = 0;
   SignalJet03Phi = 0;
   SignalJet03M = 0;
   SignalJet03Area = 0;
   SignalJet03WTAAxisPt = 0;
   SignalJet03WTAAxisEta = 0;
   SignalJet03WTAAxisPhi = 0;
   SignalJet03WTAAxisM = 0;
   SignalJet03WTAAxisArea = 0;
   SignalJet03JewelPt = 0;
   SignalJet03JewelEta = 0;
   SignalJet03JewelPhi = 0;
   SignalJet03JewelM = 0;
   SignalJet03JewelArea = 0;
   SignalJet03particlePt = 0;
   SignalJet03particleEta = 0;
   SignalJet03particlePhi = 0;
   SignalJet03particleM = 0;
   SignalJet03particleArea = 0;
   LeadingPhotonPt = 0;
   LeadingPhotonEta = 0;
   LeadingPhotonPhi = 0;
   LeadingPhotonM = 0;
   LeadingPhotonArea = 0;
   PhotonIso = 0;
   ParticlesRealPt = 0;
   ParticlesRealEta = 0;
   ParticlesRealPhi = 0;
   ParticlesRealM = 0;
   ParticlesRealArea = 0;
   pdg_id = 0;
   DummyPt = 0;
   DummyEta = 0;
   DummyPhi = 0;
   DummyM = 0;
   DummyArea = 0;
   EventWeight = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("SignalJet03Pt", &SignalJet03Pt, &b_SignalJet03Pt);
   fChain->SetBranchAddress("SignalJet03Eta", &SignalJet03Eta, &b_SignalJet03Eta);
   fChain->SetBranchAddress("SignalJet03Phi", &SignalJet03Phi, &b_SignalJet03Phi);
   fChain->SetBranchAddress("SignalJet03M", &SignalJet03M, &b_SignalJet03M);
   fChain->SetBranchAddress("SignalJet03Area", &SignalJet03Area, &b_SignalJet03Area);
   fChain->SetBranchAddress("SignalJet03WTAAxisPt", &SignalJet03WTAAxisPt, &b_SignalJet03WTAAxisPt);
   fChain->SetBranchAddress("SignalJet03WTAAxisEta", &SignalJet03WTAAxisEta, &b_SignalJet03WTAAxisEta);
   fChain->SetBranchAddress("SignalJet03WTAAxisPhi", &SignalJet03WTAAxisPhi, &b_SignalJet03WTAAxisPhi);
   fChain->SetBranchAddress("SignalJet03WTAAxisM", &SignalJet03WTAAxisM, &b_SignalJet03WTAAxisM);
   fChain->SetBranchAddress("SignalJet03WTAAxisArea", &SignalJet03WTAAxisArea, &b_SignalJet03WTAAxisArea);
   fChain->SetBranchAddress("SignalJet03JewelPt", &SignalJet03JewelPt, &b_SignalJet03JewelPt);
   fChain->SetBranchAddress("SignalJet03JewelEta", &SignalJet03JewelEta, &b_SignalJet03JewelEta);
   fChain->SetBranchAddress("SignalJet03JewelPhi", &SignalJet03JewelPhi, &b_SignalJet03JewelPhi);
   fChain->SetBranchAddress("SignalJet03JewelM", &SignalJet03JewelM, &b_SignalJet03JewelM);
   fChain->SetBranchAddress("SignalJet03JewelArea", &SignalJet03JewelArea, &b_SignalJet03JewelArea);
   fChain->SetBranchAddress("SignalJet03particlePt", &SignalJet03particlePt, &b_SignalJet03particlePt);
   fChain->SetBranchAddress("SignalJet03particleEta", &SignalJet03particleEta, &b_SignalJet03particleEta);
   fChain->SetBranchAddress("SignalJet03particlePhi", &SignalJet03particlePhi, &b_SignalJet03particlePhi);
   fChain->SetBranchAddress("SignalJet03particleM", &SignalJet03particleM, &b_SignalJet03particleM);
   fChain->SetBranchAddress("SignalJet03particleArea", &SignalJet03particleArea, &b_SignalJet03particleArea);
   fChain->SetBranchAddress("LeadingPhotonPt", &LeadingPhotonPt, &b_LeadingPhotonPt);
   fChain->SetBranchAddress("LeadingPhotonEta", &LeadingPhotonEta, &b_LeadingPhotonEta);
   fChain->SetBranchAddress("LeadingPhotonPhi", &LeadingPhotonPhi, &b_LeadingPhotonPhi);
   fChain->SetBranchAddress("LeadingPhotonM", &LeadingPhotonM, &b_LeadingPhotonM);
   fChain->SetBranchAddress("LeadingPhotonArea", &LeadingPhotonArea, &b_LeadingPhotonArea);
   fChain->SetBranchAddress("PhotonIso", &PhotonIso, &b_PhotonIso);
   fChain->SetBranchAddress("ParticlesRealPt", &ParticlesRealPt, &b_ParticlesRealPt);
   fChain->SetBranchAddress("ParticlesRealEta", &ParticlesRealEta, &b_ParticlesRealEta);
   fChain->SetBranchAddress("ParticlesRealPhi", &ParticlesRealPhi, &b_ParticlesRealPhi);
   fChain->SetBranchAddress("ParticlesRealM", &ParticlesRealM, &b_ParticlesRealM);
   fChain->SetBranchAddress("ParticlesRealArea", &ParticlesRealArea, &b_ParticlesRealArea);
   fChain->SetBranchAddress("pdg_id", &pdg_id, &b_pdg_id);
   fChain->SetBranchAddress("DummyPt", &DummyPt, &b_DummyPt);
   fChain->SetBranchAddress("DummyEta", &DummyEta, &b_DummyEta);
   fChain->SetBranchAddress("DummyPhi", &DummyPhi, &b_DummyPhi);
   fChain->SetBranchAddress("DummyM", &DummyM, &b_DummyM);
   fChain->SetBranchAddress("DummyArea", &DummyArea, &b_DummyArea);
   fChain->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
   Notify();
}

Bool_t JetTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void JetTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t JetTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef JetTree_cxx
