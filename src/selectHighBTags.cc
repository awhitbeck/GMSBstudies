#ifndef SELECTHIGHBTAGS
#define SELECTHIGHBTAGS

#include "processor.h"

#include "TH1F.h"
#include "TLorentzVector.h"

#include <iostream>

using namespace std;

template <class TreeType> class selectHighBTags : public processor<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;

  selectHighBTags()
    : processor<TreeType>("selectHighBTags")
  {
    ntuple = 0; 
  };
  selectHighBTags( TreeType *ntuple_ )
    : processor<TreeType>("selectHighBTags")
  {
    ntuple = ntuple_;
    histo = new TH1F("selectHighBTagsYields","selectHighBTagsYields",1,0.5,1.5);

    ntuple->fChain->SetBranchStatus("BTags",1);

  };

  bool process( ) override {

    // I am assuming that this has already been done!!!
    //ntuple->patchJetID();

    /*
    std::cout << "Leptons: " << ntuple->Leptons << endl;
    std::cout << "NumPhotons: " << ntuple->NumPhotons << endl;
    std::cout << "NJets: " << ntuple->NJets << endl;    
    std::cout << "HT: " << ntuple->HT << endl;
    std::cout << "MHT: " << ntuple->MHT << endl;
    std::cout << "DeltaPhi1: " << ntuple->DeltaPhi1 << endl;
    std::cout << "DeltaPhi2: " << ntuple->DeltaPhi2 << endl;    
    std::cout << "DeltaPhi3: " << ntuple->DeltaPhi3 << endl;
    std::cout << "DeltaPhi4: " << ntuple->DeltaPhi4 << endl;
    */

    histo->Fill(0);
    if( ntuple->BTags>=2 ) histo->Fill(1);
    else return false;

    return true;

  };

  void postProcess( ) override{
    histo->Write();
  };

};

#endif
