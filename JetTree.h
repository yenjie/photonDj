//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Mar 16 10:52:45 2023 by ROOT version 6.24/06
// from TTree JetTree/JetToyHI tree
// found on file: jewel-pp.root
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
   vector<double>  *SignalJet02Pt;
   vector<double>  *SignalJet02Eta;
   vector<double>  *SignalJet02Phi;
   vector<double>  *SignalJet02M;
   vector<double>  *SignalJet02Area;
   vector<double>  *SignalJet02WTAAxisPt;
   vector<double>  *SignalJet02WTAAxisEta;
   vector<double>  *SignalJet02WTAAxisPhi;
   vector<double>  *SignalJet02WTAAxisM;
   vector<double>  *SignalJet02WTAAxisArea;
   vector<double>  *SignalJet02JewelPt;
   vector<double>  *SignalJet02JewelEta;
   vector<double>  *SignalJet02JewelPhi;
   vector<double>  *SignalJet02JewelM;
   vector<double>  *SignalJet02JewelArea;
   vector<double>  *SignalJet02ParticlePt;
   vector<double>  *SignalJet02ParticleEta;
   vector<double>  *SignalJet02ParticlePhi;
   vector<double>  *SignalJet02ParticleM;
   vector<double>  *SignalJet02ParticleArea;
   vector<double>  *SignalJet02SDPt;
   vector<double>  *SignalJet02SDEta;
   vector<double>  *SignalJet02SDPhi;
   vector<double>  *SignalJet02SDM;
   vector<double>  *SignalJet02SDArea;
   vector<double>  *SignalJet02SDSubjet1Pt;
   vector<double>  *SignalJet02SDSubjet1Eta;
   vector<double>  *SignalJet02SDSubjet1Phi;
   vector<double>  *SignalJet02SDSubjet1M;
   vector<double>  *SignalJet02SDSubjet1Area;
   vector<double>  *SignalJet02SDSubjet2Pt;
   vector<double>  *SignalJet02SDSubjet2Eta;
   vector<double>  *SignalJet02SDSubjet2Phi;
   vector<double>  *SignalJet02SDSubjet2M;
   vector<double>  *SignalJet02SDSubjet2Area;
   vector<double>  *SignalJet02SDDR12;
   vector<double>  *SignalJet02SDZG;
   vector<int>     *SignalJet02SDNBranch;
   vector<double>  *SignalJet02SDJewelPt;
   vector<double>  *SignalJet02SDJewelEta;
   vector<double>  *SignalJet02SDJewelPhi;
   vector<double>  *SignalJet02SDJewelM;
   vector<double>  *SignalJet02SDJewelArea;
   vector<double>  *SignalJet02SDJewelSubjet1Pt;
   vector<double>  *SignalJet02SDJewelSubjet1Eta;
   vector<double>  *SignalJet02SDJewelSubjet1Phi;
   vector<double>  *SignalJet02SDJewelSubjet1M;
   vector<double>  *SignalJet02SDJewelSubjet1Area;
   vector<double>  *SignalJet02SDJewelSubjet2Pt;
   vector<double>  *SignalJet02SDJewelSubjet2Eta;
   vector<double>  *SignalJet02SDJewelSubjet2Phi;
   vector<double>  *SignalJet02SDJewelSubjet2M;
   vector<double>  *SignalJet02SDJewelSubjet2Area;
   vector<double>  *SignalJet02SDJewelDR12;
   vector<double>  *SignalJet02SDJewelZG;
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
   vector<double>  *SignalJet03ParticlePt;
   vector<double>  *SignalJet03ParticleEta;
   vector<double>  *SignalJet03ParticlePhi;
   vector<double>  *SignalJet03ParticleM;
   vector<double>  *SignalJet03ParticleArea;
   vector<double>  *SignalJet03SDPt;
   vector<double>  *SignalJet03SDEta;
   vector<double>  *SignalJet03SDPhi;
   vector<double>  *SignalJet03SDM;
   vector<double>  *SignalJet03SDArea;
   vector<double>  *SignalJet03SDSubjet1Pt;
   vector<double>  *SignalJet03SDSubjet1Eta;
   vector<double>  *SignalJet03SDSubjet1Phi;
   vector<double>  *SignalJet03SDSubjet1M;
   vector<double>  *SignalJet03SDSubjet1Area;
   vector<double>  *SignalJet03SDSubjet2Pt;
   vector<double>  *SignalJet03SDSubjet2Eta;
   vector<double>  *SignalJet03SDSubjet2Phi;
   vector<double>  *SignalJet03SDSubjet2M;
   vector<double>  *SignalJet03SDSubjet2Area;
   vector<double>  *SignalJet03SDDR12;
   vector<double>  *SignalJet03SDZG;
   vector<int>     *SignalJet03SDNBranch;
   vector<double>  *SignalJet03SDJewelPt;
   vector<double>  *SignalJet03SDJewelEta;
   vector<double>  *SignalJet03SDJewelPhi;
   vector<double>  *SignalJet03SDJewelM;
   vector<double>  *SignalJet03SDJewelArea;
   vector<double>  *SignalJet03SDJewelSubjet1Pt;
   vector<double>  *SignalJet03SDJewelSubjet1Eta;
   vector<double>  *SignalJet03SDJewelSubjet1Phi;
   vector<double>  *SignalJet03SDJewelSubjet1M;
   vector<double>  *SignalJet03SDJewelSubjet1Area;
   vector<double>  *SignalJet03SDJewelSubjet2Pt;
   vector<double>  *SignalJet03SDJewelSubjet2Eta;
   vector<double>  *SignalJet03SDJewelSubjet2Phi;
   vector<double>  *SignalJet03SDJewelSubjet2M;
   vector<double>  *SignalJet03SDJewelSubjet2Area;
   vector<double>  *SignalJet03SDJewelDR12;
   vector<double>  *SignalJet03SDJewelZG;
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
   TBranch        *b_SignalJet02Pt;   //!
   TBranch        *b_SignalJet02Eta;   //!
   TBranch        *b_SignalJet02Phi;   //!
   TBranch        *b_SignalJet02M;   //!
   TBranch        *b_SignalJet02Area;   //!
   TBranch        *b_SignalJet02WTAAxisPt;   //!
   TBranch        *b_SignalJet02WTAAxisEta;   //!
   TBranch        *b_SignalJet02WTAAxisPhi;   //!
   TBranch        *b_SignalJet02WTAAxisM;   //!
   TBranch        *b_SignalJet02WTAAxisArea;   //!
   TBranch        *b_SignalJet02JewelPt;   //!
   TBranch        *b_SignalJet02JewelEta;   //!
   TBranch        *b_SignalJet02JewelPhi;   //!
   TBranch        *b_SignalJet02JewelM;   //!
   TBranch        *b_SignalJet02JewelArea;   //!
   TBranch        *b_SignalJet02ParticlePt;   //!
   TBranch        *b_SignalJet02ParticleEta;   //!
   TBranch        *b_SignalJet02ParticlePhi;   //!
   TBranch        *b_SignalJet02ParticleM;   //!
   TBranch        *b_SignalJet02ParticleArea;   //!
   TBranch        *b_SignalJet02SDPt;   //!
   TBranch        *b_SignalJet02SDEta;   //!
   TBranch        *b_SignalJet02SDPhi;   //!
   TBranch        *b_SignalJet02SDM;   //!
   TBranch        *b_SignalJet02SDArea;   //!
   TBranch        *b_SignalJet02SDSubjet1Pt;   //!
   TBranch        *b_SignalJet02SDSubjet1Eta;   //!
   TBranch        *b_SignalJet02SDSubjet1Phi;   //!
   TBranch        *b_SignalJet02SDSubjet1M;   //!
   TBranch        *b_SignalJet02SDSubjet1Area;   //!
   TBranch        *b_SignalJet02SDSubjet2Pt;   //!
   TBranch        *b_SignalJet02SDSubjet2Eta;   //!
   TBranch        *b_SignalJet02SDSubjet2Phi;   //!
   TBranch        *b_SignalJet02SDSubjet2M;   //!
   TBranch        *b_SignalJet02SDSubjet2Area;   //!
   TBranch        *b_SignalJet02SDDR12;   //!
   TBranch        *b_SignalJet02SDZG;   //!
   TBranch        *b_SignalJet02SDNBranch;   //!
   TBranch        *b_SignalJet02SDJewelPt;   //!
   TBranch        *b_SignalJet02SDJewelEta;   //!
   TBranch        *b_SignalJet02SDJewelPhi;   //!
   TBranch        *b_SignalJet02SDJewelM;   //!
   TBranch        *b_SignalJet02SDJewelArea;   //!
   TBranch        *b_SignalJet02SDJewelSubjet1Pt;   //!
   TBranch        *b_SignalJet02SDJewelSubjet1Eta;   //!
   TBranch        *b_SignalJet02SDJewelSubjet1Phi;   //!
   TBranch        *b_SignalJet02SDJewelSubjet1M;   //!
   TBranch        *b_SignalJet02SDJewelSubjet1Area;   //!
   TBranch        *b_SignalJet02SDJewelSubjet2Pt;   //!
   TBranch        *b_SignalJet02SDJewelSubjet2Eta;   //!
   TBranch        *b_SignalJet02SDJewelSubjet2Phi;   //!
   TBranch        *b_SignalJet02SDJewelSubjet2M;   //!
   TBranch        *b_SignalJet02SDJewelSubjet2Area;   //!
   TBranch        *b_SignalJet02SDJewelDR12;   //!
   TBranch        *b_SignalJet02SDJewelZG;   //!
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
   TBranch        *b_SignalJet03ParticlePt;   //!
   TBranch        *b_SignalJet03ParticleEta;   //!
   TBranch        *b_SignalJet03ParticlePhi;   //!
   TBranch        *b_SignalJet03ParticleM;   //!
   TBranch        *b_SignalJet03ParticleArea;   //!
   TBranch        *b_SignalJet03SDPt;   //!
   TBranch        *b_SignalJet03SDEta;   //!
   TBranch        *b_SignalJet03SDPhi;   //!
   TBranch        *b_SignalJet03SDM;   //!
   TBranch        *b_SignalJet03SDArea;   //!
   TBranch        *b_SignalJet03SDSubjet1Pt;   //!
   TBranch        *b_SignalJet03SDSubjet1Eta;   //!
   TBranch        *b_SignalJet03SDSubjet1Phi;   //!
   TBranch        *b_SignalJet03SDSubjet1M;   //!
   TBranch        *b_SignalJet03SDSubjet1Area;   //!
   TBranch        *b_SignalJet03SDSubjet2Pt;   //!
   TBranch        *b_SignalJet03SDSubjet2Eta;   //!
   TBranch        *b_SignalJet03SDSubjet2Phi;   //!
   TBranch        *b_SignalJet03SDSubjet2M;   //!
   TBranch        *b_SignalJet03SDSubjet2Area;   //!
   TBranch        *b_SignalJet03SDDR12;   //!
   TBranch        *b_SignalJet03SDZG;   //!
   TBranch        *b_SignalJet03SDNBranch;   //!
   TBranch        *b_SignalJet03SDJewelPt;   //!
   TBranch        *b_SignalJet03SDJewelEta;   //!
   TBranch        *b_SignalJet03SDJewelPhi;   //!
   TBranch        *b_SignalJet03SDJewelM;   //!
   TBranch        *b_SignalJet03SDJewelArea;   //!
   TBranch        *b_SignalJet03SDJewelSubjet1Pt;   //!
   TBranch        *b_SignalJet03SDJewelSubjet1Eta;   //!
   TBranch        *b_SignalJet03SDJewelSubjet1Phi;   //!
   TBranch        *b_SignalJet03SDJewelSubjet1M;   //!
   TBranch        *b_SignalJet03SDJewelSubjet1Area;   //!
   TBranch        *b_SignalJet03SDJewelSubjet2Pt;   //!
   TBranch        *b_SignalJet03SDJewelSubjet2Eta;   //!
   TBranch        *b_SignalJet03SDJewelSubjet2Phi;   //!
   TBranch        *b_SignalJet03SDJewelSubjet2M;   //!
   TBranch        *b_SignalJet03SDJewelSubjet2Area;   //!
   TBranch        *b_SignalJet03SDJewelDR12;   //!
   TBranch        *b_SignalJet03SDJewelZG;   //!
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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("jewel-pp.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("jewel-pp.root");
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
   SignalJet02Pt = 0;
   SignalJet02Eta = 0;
   SignalJet02Phi = 0;
   SignalJet02M = 0;
   SignalJet02Area = 0;
   SignalJet02WTAAxisPt = 0;
   SignalJet02WTAAxisEta = 0;
   SignalJet02WTAAxisPhi = 0;
   SignalJet02WTAAxisM = 0;
   SignalJet02WTAAxisArea = 0;
   SignalJet02JewelPt = 0;
   SignalJet02JewelEta = 0;
   SignalJet02JewelPhi = 0;
   SignalJet02JewelM = 0;
   SignalJet02JewelArea = 0;
   SignalJet02ParticlePt = 0;
   SignalJet02ParticleEta = 0;
   SignalJet02ParticlePhi = 0;
   SignalJet02ParticleM = 0;
   SignalJet02ParticleArea = 0;
   SignalJet02SDPt = 0;
   SignalJet02SDEta = 0;
   SignalJet02SDPhi = 0;
   SignalJet02SDM = 0;
   SignalJet02SDArea = 0;
   SignalJet02SDSubjet1Pt = 0;
   SignalJet02SDSubjet1Eta = 0;
   SignalJet02SDSubjet1Phi = 0;
   SignalJet02SDSubjet1M = 0;
   SignalJet02SDSubjet1Area = 0;
   SignalJet02SDSubjet2Pt = 0;
   SignalJet02SDSubjet2Eta = 0;
   SignalJet02SDSubjet2Phi = 0;
   SignalJet02SDSubjet2M = 0;
   SignalJet02SDSubjet2Area = 0;
   SignalJet02SDDR12 = 0;
   SignalJet02SDZG = 0;
   SignalJet02SDNBranch = 0;
   SignalJet02SDJewelPt = 0;
   SignalJet02SDJewelEta = 0;
   SignalJet02SDJewelPhi = 0;
   SignalJet02SDJewelM = 0;
   SignalJet02SDJewelArea = 0;
   SignalJet02SDJewelSubjet1Pt = 0;
   SignalJet02SDJewelSubjet1Eta = 0;
   SignalJet02SDJewelSubjet1Phi = 0;
   SignalJet02SDJewelSubjet1M = 0;
   SignalJet02SDJewelSubjet1Area = 0;
   SignalJet02SDJewelSubjet2Pt = 0;
   SignalJet02SDJewelSubjet2Eta = 0;
   SignalJet02SDJewelSubjet2Phi = 0;
   SignalJet02SDJewelSubjet2M = 0;
   SignalJet02SDJewelSubjet2Area = 0;
   SignalJet02SDJewelDR12 = 0;
   SignalJet02SDJewelZG = 0;
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
   SignalJet03ParticlePt = 0;
   SignalJet03ParticleEta = 0;
   SignalJet03ParticlePhi = 0;
   SignalJet03ParticleM = 0;
   SignalJet03ParticleArea = 0;
   SignalJet03SDPt = 0;
   SignalJet03SDEta = 0;
   SignalJet03SDPhi = 0;
   SignalJet03SDM = 0;
   SignalJet03SDArea = 0;
   SignalJet03SDSubjet1Pt = 0;
   SignalJet03SDSubjet1Eta = 0;
   SignalJet03SDSubjet1Phi = 0;
   SignalJet03SDSubjet1M = 0;
   SignalJet03SDSubjet1Area = 0;
   SignalJet03SDSubjet2Pt = 0;
   SignalJet03SDSubjet2Eta = 0;
   SignalJet03SDSubjet2Phi = 0;
   SignalJet03SDSubjet2M = 0;
   SignalJet03SDSubjet2Area = 0;
   SignalJet03SDDR12 = 0;
   SignalJet03SDZG = 0;
   SignalJet03SDNBranch = 0;
   SignalJet03SDJewelPt = 0;
   SignalJet03SDJewelEta = 0;
   SignalJet03SDJewelPhi = 0;
   SignalJet03SDJewelM = 0;
   SignalJet03SDJewelArea = 0;
   SignalJet03SDJewelSubjet1Pt = 0;
   SignalJet03SDJewelSubjet1Eta = 0;
   SignalJet03SDJewelSubjet1Phi = 0;
   SignalJet03SDJewelSubjet1M = 0;
   SignalJet03SDJewelSubjet1Area = 0;
   SignalJet03SDJewelSubjet2Pt = 0;
   SignalJet03SDJewelSubjet2Eta = 0;
   SignalJet03SDJewelSubjet2Phi = 0;
   SignalJet03SDJewelSubjet2M = 0;
   SignalJet03SDJewelSubjet2Area = 0;
   SignalJet03SDJewelDR12 = 0;
   SignalJet03SDJewelZG = 0;
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

   fChain->SetBranchAddress("SignalJet02Pt", &SignalJet02Pt, &b_SignalJet02Pt);
   fChain->SetBranchAddress("SignalJet02Eta", &SignalJet02Eta, &b_SignalJet02Eta);
   fChain->SetBranchAddress("SignalJet02Phi", &SignalJet02Phi, &b_SignalJet02Phi);
   fChain->SetBranchAddress("SignalJet02M", &SignalJet02M, &b_SignalJet02M);
   fChain->SetBranchAddress("SignalJet02Area", &SignalJet02Area, &b_SignalJet02Area);
   fChain->SetBranchAddress("SignalJet02WTAAxisPt", &SignalJet02WTAAxisPt, &b_SignalJet02WTAAxisPt);
   fChain->SetBranchAddress("SignalJet02WTAAxisEta", &SignalJet02WTAAxisEta, &b_SignalJet02WTAAxisEta);
   fChain->SetBranchAddress("SignalJet02WTAAxisPhi", &SignalJet02WTAAxisPhi, &b_SignalJet02WTAAxisPhi);
   fChain->SetBranchAddress("SignalJet02WTAAxisM", &SignalJet02WTAAxisM, &b_SignalJet02WTAAxisM);
   fChain->SetBranchAddress("SignalJet02WTAAxisArea", &SignalJet02WTAAxisArea, &b_SignalJet02WTAAxisArea);
   fChain->SetBranchAddress("SignalJet02JewelPt", &SignalJet02JewelPt, &b_SignalJet02JewelPt);
   fChain->SetBranchAddress("SignalJet02JewelEta", &SignalJet02JewelEta, &b_SignalJet02JewelEta);
   fChain->SetBranchAddress("SignalJet02JewelPhi", &SignalJet02JewelPhi, &b_SignalJet02JewelPhi);
   fChain->SetBranchAddress("SignalJet02JewelM", &SignalJet02JewelM, &b_SignalJet02JewelM);
   fChain->SetBranchAddress("SignalJet02JewelArea", &SignalJet02JewelArea, &b_SignalJet02JewelArea);
   fChain->SetBranchAddress("SignalJet02ParticlePt", &SignalJet02ParticlePt, &b_SignalJet02ParticlePt);
   fChain->SetBranchAddress("SignalJet02ParticleEta", &SignalJet02ParticleEta, &b_SignalJet02ParticleEta);
   fChain->SetBranchAddress("SignalJet02ParticlePhi", &SignalJet02ParticlePhi, &b_SignalJet02ParticlePhi);
   fChain->SetBranchAddress("SignalJet02ParticleM", &SignalJet02ParticleM, &b_SignalJet02ParticleM);
   fChain->SetBranchAddress("SignalJet02ParticleArea", &SignalJet02ParticleArea, &b_SignalJet02ParticleArea);
   fChain->SetBranchAddress("SignalJet02SDPt", &SignalJet02SDPt, &b_SignalJet02SDPt);
   fChain->SetBranchAddress("SignalJet02SDEta", &SignalJet02SDEta, &b_SignalJet02SDEta);
   fChain->SetBranchAddress("SignalJet02SDPhi", &SignalJet02SDPhi, &b_SignalJet02SDPhi);
   fChain->SetBranchAddress("SignalJet02SDM", &SignalJet02SDM, &b_SignalJet02SDM);
   fChain->SetBranchAddress("SignalJet02SDArea", &SignalJet02SDArea, &b_SignalJet02SDArea);
   fChain->SetBranchAddress("SignalJet02SDSubjet1Pt", &SignalJet02SDSubjet1Pt, &b_SignalJet02SDSubjet1Pt);
   fChain->SetBranchAddress("SignalJet02SDSubjet1Eta", &SignalJet02SDSubjet1Eta, &b_SignalJet02SDSubjet1Eta);
   fChain->SetBranchAddress("SignalJet02SDSubjet1Phi", &SignalJet02SDSubjet1Phi, &b_SignalJet02SDSubjet1Phi);
   fChain->SetBranchAddress("SignalJet02SDSubjet1M", &SignalJet02SDSubjet1M, &b_SignalJet02SDSubjet1M);
   fChain->SetBranchAddress("SignalJet02SDSubjet1Area", &SignalJet02SDSubjet1Area, &b_SignalJet02SDSubjet1Area);
   fChain->SetBranchAddress("SignalJet02SDSubjet2Pt", &SignalJet02SDSubjet2Pt, &b_SignalJet02SDSubjet2Pt);
   fChain->SetBranchAddress("SignalJet02SDSubjet2Eta", &SignalJet02SDSubjet2Eta, &b_SignalJet02SDSubjet2Eta);
   fChain->SetBranchAddress("SignalJet02SDSubjet2Phi", &SignalJet02SDSubjet2Phi, &b_SignalJet02SDSubjet2Phi);
   fChain->SetBranchAddress("SignalJet02SDSubjet2M", &SignalJet02SDSubjet2M, &b_SignalJet02SDSubjet2M);
   fChain->SetBranchAddress("SignalJet02SDSubjet2Area", &SignalJet02SDSubjet2Area, &b_SignalJet02SDSubjet2Area);
   fChain->SetBranchAddress("SignalJet02SDDR12", &SignalJet02SDDR12, &b_SignalJet02SDDR12);
   fChain->SetBranchAddress("SignalJet02SDZG", &SignalJet02SDZG, &b_SignalJet02SDZG);
   fChain->SetBranchAddress("SignalJet02SDNBranch", &SignalJet02SDNBranch, &b_SignalJet02SDNBranch);
   fChain->SetBranchAddress("SignalJet02SDJewelPt", &SignalJet02SDJewelPt, &b_SignalJet02SDJewelPt);
   fChain->SetBranchAddress("SignalJet02SDJewelEta", &SignalJet02SDJewelEta, &b_SignalJet02SDJewelEta);
   fChain->SetBranchAddress("SignalJet02SDJewelPhi", &SignalJet02SDJewelPhi, &b_SignalJet02SDJewelPhi);
   fChain->SetBranchAddress("SignalJet02SDJewelM", &SignalJet02SDJewelM, &b_SignalJet02SDJewelM);
   fChain->SetBranchAddress("SignalJet02SDJewelArea", &SignalJet02SDJewelArea, &b_SignalJet02SDJewelArea);
   fChain->SetBranchAddress("SignalJet02SDJewelSubjet1Pt", &SignalJet02SDJewelSubjet1Pt, &b_SignalJet02SDJewelSubjet1Pt);
   fChain->SetBranchAddress("SignalJet02SDJewelSubjet1Eta", &SignalJet02SDJewelSubjet1Eta, &b_SignalJet02SDJewelSubjet1Eta);
   fChain->SetBranchAddress("SignalJet02SDJewelSubjet1Phi", &SignalJet02SDJewelSubjet1Phi, &b_SignalJet02SDJewelSubjet1Phi);
   fChain->SetBranchAddress("SignalJet02SDJewelSubjet1M", &SignalJet02SDJewelSubjet1M, &b_SignalJet02SDJewelSubjet1M);
   fChain->SetBranchAddress("SignalJet02SDJewelSubjet1Area", &SignalJet02SDJewelSubjet1Area, &b_SignalJet02SDJewelSubjet1Area);
   fChain->SetBranchAddress("SignalJet02SDJewelSubjet2Pt", &SignalJet02SDJewelSubjet2Pt, &b_SignalJet02SDJewelSubjet2Pt);
   fChain->SetBranchAddress("SignalJet02SDJewelSubjet2Eta", &SignalJet02SDJewelSubjet2Eta, &b_SignalJet02SDJewelSubjet2Eta);
   fChain->SetBranchAddress("SignalJet02SDJewelSubjet2Phi", &SignalJet02SDJewelSubjet2Phi, &b_SignalJet02SDJewelSubjet2Phi);
   fChain->SetBranchAddress("SignalJet02SDJewelSubjet2M", &SignalJet02SDJewelSubjet2M, &b_SignalJet02SDJewelSubjet2M);
   fChain->SetBranchAddress("SignalJet02SDJewelSubjet2Area", &SignalJet02SDJewelSubjet2Area, &b_SignalJet02SDJewelSubjet2Area);
   fChain->SetBranchAddress("SignalJet02SDJewelDR12", &SignalJet02SDJewelDR12, &b_SignalJet02SDJewelDR12);
   fChain->SetBranchAddress("SignalJet02SDJewelZG", &SignalJet02SDJewelZG, &b_SignalJet02SDJewelZG);
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
   fChain->SetBranchAddress("SignalJet03ParticlePt", &SignalJet03ParticlePt, &b_SignalJet03ParticlePt);
   fChain->SetBranchAddress("SignalJet03ParticleEta", &SignalJet03ParticleEta, &b_SignalJet03ParticleEta);
   fChain->SetBranchAddress("SignalJet03ParticlePhi", &SignalJet03ParticlePhi, &b_SignalJet03ParticlePhi);
   fChain->SetBranchAddress("SignalJet03ParticleM", &SignalJet03ParticleM, &b_SignalJet03ParticleM);
   fChain->SetBranchAddress("SignalJet03ParticleArea", &SignalJet03ParticleArea, &b_SignalJet03ParticleArea);
   fChain->SetBranchAddress("SignalJet03SDPt", &SignalJet03SDPt, &b_SignalJet03SDPt);
   fChain->SetBranchAddress("SignalJet03SDEta", &SignalJet03SDEta, &b_SignalJet03SDEta);
   fChain->SetBranchAddress("SignalJet03SDPhi", &SignalJet03SDPhi, &b_SignalJet03SDPhi);
   fChain->SetBranchAddress("SignalJet03SDM", &SignalJet03SDM, &b_SignalJet03SDM);
   fChain->SetBranchAddress("SignalJet03SDArea", &SignalJet03SDArea, &b_SignalJet03SDArea);
   fChain->SetBranchAddress("SignalJet03SDSubjet1Pt", &SignalJet03SDSubjet1Pt, &b_SignalJet03SDSubjet1Pt);
   fChain->SetBranchAddress("SignalJet03SDSubjet1Eta", &SignalJet03SDSubjet1Eta, &b_SignalJet03SDSubjet1Eta);
   fChain->SetBranchAddress("SignalJet03SDSubjet1Phi", &SignalJet03SDSubjet1Phi, &b_SignalJet03SDSubjet1Phi);
   fChain->SetBranchAddress("SignalJet03SDSubjet1M", &SignalJet03SDSubjet1M, &b_SignalJet03SDSubjet1M);
   fChain->SetBranchAddress("SignalJet03SDSubjet1Area", &SignalJet03SDSubjet1Area, &b_SignalJet03SDSubjet1Area);
   fChain->SetBranchAddress("SignalJet03SDSubjet2Pt", &SignalJet03SDSubjet2Pt, &b_SignalJet03SDSubjet2Pt);
   fChain->SetBranchAddress("SignalJet03SDSubjet2Eta", &SignalJet03SDSubjet2Eta, &b_SignalJet03SDSubjet2Eta);
   fChain->SetBranchAddress("SignalJet03SDSubjet2Phi", &SignalJet03SDSubjet2Phi, &b_SignalJet03SDSubjet2Phi);
   fChain->SetBranchAddress("SignalJet03SDSubjet2M", &SignalJet03SDSubjet2M, &b_SignalJet03SDSubjet2M);
   fChain->SetBranchAddress("SignalJet03SDSubjet2Area", &SignalJet03SDSubjet2Area, &b_SignalJet03SDSubjet2Area);
   fChain->SetBranchAddress("SignalJet03SDDR12", &SignalJet03SDDR12, &b_SignalJet03SDDR12);
   fChain->SetBranchAddress("SignalJet03SDZG", &SignalJet03SDZG, &b_SignalJet03SDZG);
   fChain->SetBranchAddress("SignalJet03SDNBranch", &SignalJet03SDNBranch, &b_SignalJet03SDNBranch);
   fChain->SetBranchAddress("SignalJet03SDJewelPt", &SignalJet03SDJewelPt, &b_SignalJet03SDJewelPt);
   fChain->SetBranchAddress("SignalJet03SDJewelEta", &SignalJet03SDJewelEta, &b_SignalJet03SDJewelEta);
   fChain->SetBranchAddress("SignalJet03SDJewelPhi", &SignalJet03SDJewelPhi, &b_SignalJet03SDJewelPhi);
   fChain->SetBranchAddress("SignalJet03SDJewelM", &SignalJet03SDJewelM, &b_SignalJet03SDJewelM);
   fChain->SetBranchAddress("SignalJet03SDJewelArea", &SignalJet03SDJewelArea, &b_SignalJet03SDJewelArea);
   fChain->SetBranchAddress("SignalJet03SDJewelSubjet1Pt", &SignalJet03SDJewelSubjet1Pt, &b_SignalJet03SDJewelSubjet1Pt);
   fChain->SetBranchAddress("SignalJet03SDJewelSubjet1Eta", &SignalJet03SDJewelSubjet1Eta, &b_SignalJet03SDJewelSubjet1Eta);
   fChain->SetBranchAddress("SignalJet03SDJewelSubjet1Phi", &SignalJet03SDJewelSubjet1Phi, &b_SignalJet03SDJewelSubjet1Phi);
   fChain->SetBranchAddress("SignalJet03SDJewelSubjet1M", &SignalJet03SDJewelSubjet1M, &b_SignalJet03SDJewelSubjet1M);
   fChain->SetBranchAddress("SignalJet03SDJewelSubjet1Area", &SignalJet03SDJewelSubjet1Area, &b_SignalJet03SDJewelSubjet1Area);
   fChain->SetBranchAddress("SignalJet03SDJewelSubjet2Pt", &SignalJet03SDJewelSubjet2Pt, &b_SignalJet03SDJewelSubjet2Pt);
   fChain->SetBranchAddress("SignalJet03SDJewelSubjet2Eta", &SignalJet03SDJewelSubjet2Eta, &b_SignalJet03SDJewelSubjet2Eta);
   fChain->SetBranchAddress("SignalJet03SDJewelSubjet2Phi", &SignalJet03SDJewelSubjet2Phi, &b_SignalJet03SDJewelSubjet2Phi);
   fChain->SetBranchAddress("SignalJet03SDJewelSubjet2M", &SignalJet03SDJewelSubjet2M, &b_SignalJet03SDJewelSubjet2M);
   fChain->SetBranchAddress("SignalJet03SDJewelSubjet2Area", &SignalJet03SDJewelSubjet2Area, &b_SignalJet03SDJewelSubjet2Area);
   fChain->SetBranchAddress("SignalJet03SDJewelDR12", &SignalJet03SDJewelDR12, &b_SignalJet03SDJewelDR12);
   fChain->SetBranchAddress("SignalJet03SDJewelZG", &SignalJet03SDJewelZG, &b_SignalJet03SDJewelZG);
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
