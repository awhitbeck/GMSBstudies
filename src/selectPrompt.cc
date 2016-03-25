#ifndef SELECTPROMPT
#define SELECTPROMPT

#include "processor.h"
#include "TH1F.h"
#include <iostream>
#include <cassert>

using namespace std;

template <class TreeType> class selectPrompt : public processor<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;
  bool negate;

  selectPrompt()
    : processor<TreeType>("selectPrompt")
  {
    ntuple = 0; 
  };
  selectPrompt( TreeType *ntuple_ , bool negate_ = false )
    : processor<TreeType>("selectPrompt")
  {
    ntuple = ntuple_;
    negate = negate_;
    histo = new TH1F("lowDphiCRYields","lowDphiCRYields",1,0.5,1.5);

    ntuple->fChain->SetBranchStatus("Photons",1);
    ntuple->fChain->SetBranchStatus("photon_nonPrompt",1);
    if( ntuple->fChain->GetLeaf("Photons") == NULL ||
	ntuple->fChain->GetLeaf("photon_nonPrompt") == NULL ){ 
      assert(0);
    }

  };

  bool process( ) override {

    // I am assuming that this was done already!!!
    //ntuple->patchJetID();

    histo->Fill(0);
    
    vector<TLorentzVector> photons, bestPhoton;
    photons = *(ntuple->Photons);
    bestPhoton = *(ntuple->bestPhoton);
    //cout << "best photon" << endl;
    //cout << "eta: " << bestPhoton[0].Eta() << " phi: " << bestPhoton[0].Phi() << endl;
    int bestPhotonIndex = -1;
    for( unsigned int iPh = 0 ; iPh<photons.size() ; iPh++ ){
      //cout << "Photon " << iPh << endl;
      //cout << "eta: " << photons[iPh].Eta() << " phi: " << photons[iPh].Phi() << endl;
      //cout << "deltaR: " << photons[iPh].DeltaR(bestPhoton[0]) << endl;
      if( photons[iPh].DeltaR(bestPhoton[0]) < 0.05 ){
	histo->Fill(1);
	bestPhotonIndex = iPh ;
	break;
      }
    }

    if( bestPhotonIndex == -1 ){
      cout << "problem with selectPrompt::process -- no match found" << endl;
      return false;
    }

    histo->Fill(0);

    if( ntuple->photon_nonPrompt->at(bestPhotonIndex) ){
      return false^negate;
    }else{
      histo->Fill(1);
      return true^negate;
    }

  };

  void postProcess( ) override {
    histo->Write();
  }
};

#endif
