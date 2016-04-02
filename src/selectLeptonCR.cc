#ifndef SELECTLEPTONCR
#define SELECTLEPTONCR

#include "processor.h"
#include "TH1F.h"
#include <iostream>

using namespace std;

template <class TreeType> class selectLeptonCR : public processor<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;
  TString label;

  selectLeptonCR()
    : processor<TreeType>("selectLeptonCR")
  {
    ntuple = 0; 
  };
  selectLeptonCR( TreeType *ntuple_ ,
		  TString label_ )
    : processor<TreeType>("selectLeptonCR")
  {
    ntuple = ntuple_;
    label = label_;
    histo = new TH1F("leptonCRYields_"+label,"leptonCRYields_"+label,9,0.5,9.5);
  };

  bool process( ) override {

    // I am assuming that this was done already!!!
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
    if( ntuple->Leptons == 1 ) histo->Fill(1);
    else return false;
    if( ntuple->NumPhotons >= 1 ) histo->Fill(2);
    else return false;
    if( ntuple->NJets>=4 ) histo->Fill(3);
    else return false;
    if( ntuple->HT>500. ) histo->Fill(4);
    else return false;
    if( ntuple->MHT>0. ) histo->Fill(5); 
    else return false;
    if( ntuple->DeltaPhi1>0.5 ) histo->Fill(6);
    else return false;
    if( ntuple->DeltaPhi2>0.5 ) histo->Fill(7);
    else return false;
    if( ntuple->DeltaPhi3>0.3 ) histo->Fill(8);
    else return false;
    if( ntuple->DeltaPhi4>0.3 ) histo->Fill(9);
    else return false;

    return true;

  };

  void postProcess( ) override {
    histo->Write();
  };

};

#endif
