//#ifndef DISSECTINGJETMET
//#define DISSECTINGJETMET
//#include "dissectingJetsMET.cc"
//#endif

#ifndef SELECTBASELINE
#define SELECTBASELINE

#include "processor.h"
#include <iostream>

using namespace std;

template <class TreeType> class selectBaseline : public processor<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;

  selectBaseline(){ ntuple = 0; };
  selectBaseline( TreeType *ntuple_ ){
    ntuple = ntuple_;
    histo = new TH1F("selectBaselineYields","selectBaselineYields",5,0.5,5.5);
  };
  
  bool process( ) override {

    histo->Fill(0);
    if( ntuple->HT>500. ) histo->Fill(1);
    else return false;
    if( ntuple->MHT>200. ) histo->Fill(2); 
    else return false;
    if( ntuple->NJets>=2 ) histo->Fill(3);
    else return false;
    if( ntuple->NLeptons <= 0 ) histo->Fill(4);
    else return false;
    if( ntuple->dPhi>0.3 ) histo->Fill(5);
    else return false;

    return true;

  };

};

#endif
