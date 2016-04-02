#ifndef FILLLEPTONTRUTH
#define FILLLEPTONTRUTH

#include "filler.h"
#include <iostream>
#include <string>
#include <cassert>

#include "TLeaf.h"
#include "TString.h"
#include "TLorentzVector.h"

using namespace std;

template <class TreeType> class fillLeptonTruth : public filler<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;
  TString weightbranch;

  fillLeptonTruth()
    : filler<TreeType>("fillLeptonTruth"){
    ntuple = 0;
    histo = new TH1F("test","test",20,0.,TMath::Pi());
  };
  
  fillLeptonTruth( TreeType* ntuple_ , 
		   TString histotag ,
		   TString weightbranch_ )
	     : filler<TreeType>("fillLeptonTruth")
	     {

	       ntuple = ntuple_;
	       weightbranch = weightbranch_;

	       histo = new TH1F("leptonTruth_"+histotag,"leptonTruth_"+histotag,2,-0.5,1.5);
	       ntuple->fChain->SetBranchStatus("Muons",1);	       
	       ntuple->fChain->SetBranchStatus("Electrons",1);
	       ntuple->fChain->SetBranchStatus("GenMus",1);
	       ntuple->fChain->SetBranchStatus("GenEls",1);
	       ntuple->fChain->SetBranchStatus(weightbranch,1);
	       
	     };

  bool process( ) override {

    // assume that this has been done previously
    // ntuple->patchJetID();

    vector<TLorentzVector> muons = *ntuple->Muons;
    vector<TLorentzVector> electrons = *ntuple->Electrons;
    vector<TLorentzVector> genElectrons = *ntuple->GenEls;
    vector<TLorentzVector> genMuons = *ntuple->GenMus;
    
    for( unsigned int i = 0 ; i < muons.size() ; i++ ){
      bool matched = false;
      for( unsigned int j = 0 ; j < genMuons.size() ; j++ ){
	if( muons[i].DeltaR(genMuons[j]) < 0.1 ){
	  matched = true;
	  break;
	}
      }
      if( matched ) 
	histo->Fill(1.,ntuple->fChain->GetLeaf(weightbranch)->GetValue());
      else
	histo->Fill(0.,ntuple->fChain->GetLeaf(weightbranch)->GetValue());
    }

    for( unsigned int i = 0 ; i < electrons.size() ; i++ ){
      bool matched = false;
      for( unsigned int j = 0 ; j < genElectrons.size() ; j++ ){
	if( electrons[i].DeltaR(genElectrons[j]) < 0.1 ){
	  matched = true;
	  break;
	}
      }
      if( matched ) 
	histo->Fill(1.,ntuple->fChain->GetLeaf(weightbranch)->GetValue());
      else
	histo->Fill(0.,ntuple->fChain->GetLeaf(weightbranch)->GetValue());
    }



    return true;
  };

};

#endif
