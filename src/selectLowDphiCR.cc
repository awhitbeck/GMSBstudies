#ifndef SELECTLOWDPHICR
#define SELECTLOWDPHICR

#include "processor.h"
#include "TH1F.h"
#include <iostream>

using namespace std;

template <class TreeType> class selectLowDphiCR : public processor<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;
  TString label;

  selectLowDphiCR()
    : processor<TreeType>("selectLowDphiCR")
  {
    ntuple = 0; 
  };
  selectLowDphiCR( TreeType *ntuple_ ,
		   TString label_ )
    : processor<TreeType>("selectLowDphiCR")
  {
    ntuple = ntuple_;
    label = label_;
    histo = new TH1F("lowDphiCRYields_"+label,"lowDphiCRYields_"+label,6,0.5,6.5);
  };

  bool process( ) override {
    // I am assuming that this has already been done!!
    //ntuple->patchJetID();

    histo->Fill(0);
    if( ntuple->Leptons == 0 ) histo->Fill(1);
    else return false;
    if( ntuple->NumPhotons >= 1 ) histo->Fill(2);
    else return false;
    if( ntuple->NJets>=4 ) histo->Fill(3);
    else return false;
    if( ntuple->HT>500. ) histo->Fill(4);
    else return false;
    if( ntuple->MHT>0. ) histo->Fill(5); 
    else return false;
    if( ntuple->DeltaPhi1<0.5 || ntuple->DeltaPhi2<0.5 || ntuple->DeltaPhi3<0.3 || ntuple->DeltaPhi4<0.3 ) histo->Fill(6);
    else return false;

    return true;

  };

  void postProcess( ) override{
    histo->Write();
  };

};

#endif
