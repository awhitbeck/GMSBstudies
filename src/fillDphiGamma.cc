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

  TH1F* fillDphiGammaMHT,*fillDphiGammMET,*fillDphi_minJetGamma;
  TH2F* fillDphi_minJetGamma_GammaMHT,*fillDphi_minJetGamma_GammaMET;
  TreeType* ntuple;
  TString weightbranch;

  fillDphiGamma()
    : filler<TreeType>("fillDphiGamma"){
    ntuple = 0;
    fillDphiGammaMHT = 0; 
    fillDphiGammaMET = 0; 
    fillDphi_minJetGamma = 0;
    fillDphi_minJetGamma_GammaMHT = 0;
    fillDphi_minJetGamma_GammaMET = 0;

  };
  
  fillDphiGamma( TreeType* ntuple_ , 
		 TString histotag ,
		 TString weightbranch_ )
	     : filler<TreeType>("fillDphiGamma")
	     {

	       ntuple = ntuple_;
	       weightbranch = weightbranch_;
	       fillDphiGammaMHT = new TH1F("dPhiGammaMHT_"+histotag,"dPhiGammaMHT_"+histotag,20,0.,TMath::Pi());
	       fillDphiGammaMET = new TH1F("dPhiGammaMET_"+histotag,"dPhiGammaMET_"+histotag,20,0.,TMath::Pi());
	       fillDphi_minJetGamma = new TH1F("dPhiGamma_minJetGamma_"+histotag,"dPhiGamma_minJetGamma_"+histotag,20,0.,TMath::Pi());
	       fillDphi_minJetGamma_GammaMHT = new TH2F("dPhiGamma_minJetGamma_GammaMHT_"+histotag,"dPhiGamma_minJetGamma_GammaMHT_"+histotag,20,0.,TMath::Pi(),20,0.,TMath::Pi());
	       fillDphi_minJetGamma_GammaMET = new TH2F("dPhiGamma_minJetGamma_GammaMET_"+histotag,"dPhiGamma_minJetGamma_GammaMET_"+histotag,20,0.,TMath::Pi(),20,0.,TMath::Pi());

	       ntuple->fChain->SetBranchStatus("MHT_Phi",1);
	       if( ntuple->fChain->GetLeaf( "MHT_Phi" ) == NULL )
		 assert(0);	       
	       ntuple->fChain->SetBranchStatus("METPhi",1);
	       if( ntuple->fChain->GetLeaf( "METPhi" ) == NULL )
		 assert(0);	       
	       ntuple->fChain->SetBranchStatus("Jets",1);
	       if( ntuple->fChain->GetLeaf( "Jets" ) == NULL )
		 assert(0);	       
	       ntuple->fChain->SetBranchStatus(weightbranch,1);
	       if( ntuple->fChain->GetLeaf( weightbranch ) == NULL )
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

    double dPhiGammaMHT = photons->at(0).Phi()-ntuple->MHT_Phi ;
    if( dPhiGammaMHT > TMath::Pi() )
      dPhiGammaMHT -= 2*TMath::Pi() ;
    if( dPhiGammaMHT < -TMath::Pi() )
      dPhiGammaMHT += 2*TMath::Pi() ;
    double dPhiGammaMET = photons->at(0).Phi()-ntuple->METPhi ;
    if( dPhiGammaMET > TMath::Pi() )
      dPhiGammaMET -= 2*TMath::Pi() ;
    if( dPhiGammaMET < -TMath::Pi() )
      dPhiGammaMET += 2*TMath::Pi() ;
    
    histo->Fill( fabs( dPhiGamma ) );
    
    

    return true;
  };

};

#endif
