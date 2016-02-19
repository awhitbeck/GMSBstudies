#ifndef WEIGHTPRODUCER
#define WEIGHTPRODUCER

#include "filler.h"
#include <iostream>
#include <string>
#include <map>

#include "TString.h"

using namespace std;

template <class TreeType> class weightProducer : public processor<TreeType> {

public : 

  TString weightBranch;
  double weight;
  double lumi;
  TreeType* ntuple;
  
  weightProducer(){
    ntuple = 0;
    weightBranch = "";
    weight = -999.;
  };

  weightProducer( TreeType* ntuple_ , 
		  TString weightBranch_ ,
		  double lumi_ = 10.){

    ntuple = ntuple_;
    weightBranch = weightBranch_;
    weight = -999.;
    lumi = lumi_;

  };

  bool process( ) override {
    weight = ntuple->fChain->GetLeaf( weightBranch.Data() )->GetValue();
    return true;
  };

};

#endif
