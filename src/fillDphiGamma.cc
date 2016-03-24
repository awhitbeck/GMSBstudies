#ifndef FILLDPHIGAMMA
#define FILLDPHIGAMMA

#include "filler.h"
#include <iostream>
#include <string>
#include <cassert>

#include "TLeaf.h"
#include "TString.h"
#include "TLorentzVector.h"

using namespace std;

template <class TreeType> class fillDphiGamma : public filler<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;
  int NLSPmass;
  int gluinoMass;

  fillDphiGamma()
    : filler<TreeType>("fillDphiGamma"){
    ntuple = 0;
    histo = new TH1F("test","test",20,0.,TMath::Pi());
  };
  
  fillDphiGamma( TreeType* ntuple_ , 
		 TString histotag )
	     : filler<TreeType>("fillDphiGamma")
	     {

	       ntuple = ntuple_;
	       histo = new TH1F("dPhiGamma_"+histotag,"dPhiGamma_"+histotag,20,0.,TMath::Pi());

	       ntuple->fChain->SetBranchStatus("MHT_Phi",1);

	       if( ntuple->fChain->GetLeaf( "MHT_Phi" ) == NULL )
		 assert(0);	       
	     };

  bool process( ) override {

    // assume that this has been done previously
    // ntuple->patchJetID();

    vector<TLorentzVector> *photons = ntuple->bestPhoton;

    /*
    cout << "photon pt: " << photons->at(0).Pt() << endl;
    cout << "photon eta: " << photons->at(0).Eta() << endl;
    cout << "photon phi: " << photons->at(0).Phi() << endl;
    cout << "MHT_Phi: " << ntuple->MHT_Phi << endl;
    */

    double dPhiGamma = photons->at(0).Phi()-ntuple->MHT_Phi ;
    if( dPhiGamma > TMath::Pi() )
      dPhiGamma -= 2*TMath::Pi() ;
    if( dPhiGamma < -TMath::Pi() )
      dPhiGamma += 2*TMath::Pi() ;

    //cout << "dPhiGamma: " << dPhiGamma << endl;

    histo->Fill( fabs( dPhiGamma ) );

    return true;
  };

};

#endif
