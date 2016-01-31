//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Dec 22 16:21:45 2015 by ROOT version 6.02/05
// from TTree analysisTree/
// found on file: ttbar_600_1200_76_slim.root
//////////////////////////////////////////////////////////

#ifndef dissectingJetsMET_h
#define dissectingJetsMET_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>

using namespace std;

// Header file for the classes stored in the TTree if any.

class dissectingJetsMET {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        HT;
   Double_t        MHT;
   Double_t        MET;
   Double_t        METphi;
   Double_t        dPhi;
   Int_t           NJets;
   Int_t           NLeptons;
   Double_t        sumJetMass;
   Double_t        leadJetPt;
   Double_t        mEff;
   Double_t        dEta;
   Double_t        alphaT;
   Double_t        mT2;
   Double_t        mRazor;
   Double_t        dRazor;

   // List of branches
   TBranch        *b_HT;   //!
   TBranch        *b_MHT;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_METphi;   //!
   TBranch        *b_dPhi;   //!
   TBranch        *b_NJets;   //!
   TBranch        *b_NLeptons;   //!
   TBranch        *b_sumJetMass;   //!
   TBranch        *b_leadJetPt;   //!
   TBranch        *b_mEff;   //!
   TBranch        *b_dEta;   //!
   TBranch        *b_alphaT;   //!
   TBranch        *b_mT2;   //!
   TBranch        *b_mRazor;   //!
   TBranch        *b_dRazor;   //!

   dissectingJetsMET(TTree *tree=0);
   virtual ~dissectingJetsMET();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop( bool (*processor)() );
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef dissectingJetsMET_cxx
dissectingJetsMET::dissectingJetsMET(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   Init(tree);
}

dissectingJetsMET::~dissectingJetsMET()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t dissectingJetsMET::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t dissectingJetsMET::LoadTree(Long64_t entry)
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

void dissectingJetsMET::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   //fChain->SetMakeClass(1);

   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("METphi", &METphi, &b_METphi);
   fChain->SetBranchAddress("dPhi", &dPhi, &b_dPhi);
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("NLeptons", &NLeptons, &b_NLeptons);
   fChain->SetBranchAddress("sumJetMass", &sumJetMass, &b_sumJetMass);
   fChain->SetBranchAddress("leadJetPt", &leadJetPt, &b_leadJetPt);
   fChain->SetBranchAddress("mEff", &mEff, &b_mEff);
   fChain->SetBranchAddress("dEta", &dEta, &b_dEta);
   fChain->SetBranchAddress("alphaT", &alphaT, &b_alphaT);
   fChain->SetBranchAddress("mT2", &mT2, &b_mT2);
   fChain->SetBranchAddress("mRazor", &mRazor, &b_mRazor);
   fChain->SetBranchAddress("dRazor", &dRazor, &b_dRazor);
   Notify();
}

Bool_t dissectingJetsMET::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void dissectingJetsMET::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}

Int_t dissectingJetsMET::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef dissectingJetsMET_cxx
