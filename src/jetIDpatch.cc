#ifndef JETIDPATCH
#define JETIDPATCH

#include  "TLorentzVector.h"
#include "producer.h"
#include <map>
#include <cassert>

template <class TreeType> class jetIDpatch : public producer<TreeType> {

public : 
	
  TreeType *ntuple ; 
  TTree* newTree ;
  
  jetIDpatch(){
    ntuple = 0;
  };
  jetIDpatch(TreeType* ntuple_){
    ntuple = ntuple_;
    newTree = ntuple->fChain->CloneTree(0);
  };
  
  bool process() override {
    ntuple->HT = 0. ;
    ntuple->NJets = 0 ;
    ntuple->JetID = true ; 
    TLorentzVector mht(0.,0.,0.,0.);

    std::vector<TLorentzVector> jets = *(ntuple->slimJet);
    for( unsigned int i = 0 ; i < jets.size() ; i++ ){
      if( jets[i].Pt()>30. ){
	if( fabs(jets[i].Eta())<2.4 ){
	  ntuple->HT+=jets[i].Pt();
	  ntuple->NJets++;
	}
	if( fabs(jets[i].Eta())<5.0){
	  mht += TLorentzVector(jets[i].Px(),jets[i].Py(),0.,0.) ;
	}
      }
      if( ntuple->slimJet_slimJetID == 0 && jets[i].DeltaR((*ntuple->bestPhoton)[0])>0.4 )
	ntuple->JetID = false ; 
    }
    
    ntuple->MHT = mht.Pt();
    newTree->Fill();
    
    return true;

  };
  
  void postProcess() override{
    newTree->Write();
  }
  
};

#endif
