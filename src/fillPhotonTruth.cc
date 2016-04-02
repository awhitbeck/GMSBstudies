#ifndef FILLPHOTONTRUTH
#define FILLPHOTONTRUTH

#include "filler.h"
#include <iostream>
#include <string>
#include <cassert>

#include "TLeaf.h"
#include "TString.h"
#include "TLorentzVector.h"

using namespace std;

template <class TreeType> class fillPhotonTruth : public filler<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;
  TString weightbranch;

  fillPhotonTruth()
    : filler<TreeType>("fillPhotonTruth"){
    ntuple = 0;
    histo = new TH1F("test","test",20,0.,TMath::Pi());
  };
  
  fillPhotonTruth( TreeType* ntuple_ , 
		   TString histotag ,
		   TString weightbranch_ )
	     : filler<TreeType>("fillPhotonTruth")
	     {

	       ntuple = ntuple_;
	       weightbranch = weightbranch_;
	       histo = new TH1F("photonTruth_"+histotag,"photonTruth_"+histotag,2,-0.5,1.5);
	       ntuple->fChain->SetBranchStatus("photon_genMatched",1);
	       ntuple->fChain->SetBranchStatus(weightbranch,1);
	       
	     };

  bool process( ) override {

    // assume that this has been done previously
    // ntuple->patchJetID();
    histo->Fill( ntuple->photon_genMatched->at(ntuple->bestPhotonIndex->at(0) ) , ntuple->fChain->GetLeaf(weightbranch)->GetValue() );

    return true;
  };

};

#endif
