#ifndef SELECTBIN
#define SELECTBIN

#include "processor.h"

#include "TH1F.h"
#include "TLorentzVector.h"

#include <iostream>

using namespace std;

template <class TreeType> class selectBin : public processor<TreeType> {

public : 

  TH1F* histo;
  TreeType* ntuple;
  TString binLabel;
  int minBTags,maxBTags,minNJets,maxNJets;
  int minHiggsTags,maxHiggsTags,minVTags,maxVTags;
  double minMHT,maxMHT,minHT,maxHT;

  TH1F* prunedMassHiggs;
  TH1F* prunedMassV;

  selectBin()
    : processor<TreeType>("selectBin")
  {
    ntuple = 0; 
  };
  selectBin( TreeType *ntuple_ ,
	     TString binLabel_ , 
	     int minBTags_ = 0 , int maxBTags_ = 99 , 
	     int minNJets_ = 4, int maxNJets_ = 99 , 
	     double minMHT_ = 0. ,double maxMHT_ = 999999. , 
	     double minHT_ = 0. , double maxHT_ = 999999. , 
	     int minHiggsTags_ = 0 , int maxHiggsTags_ = 99 , 
	     int minVTags_ = 0 , int maxVTags_ = 99 )
    : processor<TreeType>("selectBin_"+binLabel_)
  {
    ntuple = ntuple_;
    binLabel = binLabel_;
    minBTags = minBTags_;
    maxBTags = maxBTags_;
    minNJets = minNJets_;
    maxNJets = maxNJets_;
    minMHT = minMHT_;
    maxMHT = maxMHT_;
    minHT = minHT_;
    maxHT = maxHT_;
    minHiggsTags = minHiggsTags_;
    maxHiggsTags = maxHiggsTags_;
    minVTags = minVTags_;
    maxVTags = maxVTags_;

    histo = new TH1F("selectBin_"+binLabel_+"_Yields","selectBin_"+binLabel_+"_Yields",6,0.5,6.5);
    prunedMassHiggs = new TH1F("prunedMassHiggs_"+binLabel,"prunedMassHiggs_"+binLabel,50,0.,150.);
    prunedMassV = new TH1F("prunedMassV_"+binLabel,"prunedMassV_"+binLabel,50,0.,150.);
    
    ntuple->fChain->SetBranchStatus("BTags",1);
    ntuple->fChain->SetBranchStatus("NJets",1);
    ntuple->fChain->SetBranchStatus("MHT",1);
    ntuple->fChain->SetBranchStatus("HT",1);
    ntuple->fChain->SetBranchStatus("JetsAK8",1);
    ntuple->fChain->SetBranchStatus("JetsAK8_bDiscriminatorSubjet1CSV",1);
    ntuple->fChain->SetBranchStatus("JetsAK8_bDiscriminatorSubjet2CSV",1);
    ntuple->fChain->SetBranchStatus("JetsAK8_NsubjettinessTau1",1);
    ntuple->fChain->SetBranchStatus("JetsAK8_NsubjettinessTau2",1);
    ntuple->fChain->SetBranchStatus("JetsAK8_NsubjettinessTau3",1);
    ntuple->fChain->SetBranchStatus("JetsAK8_prunedMass",1);

  };

  bool process( ) override {

    // I am assuming that this has already been done!!!
    //ntuple->patchJetID();

    /*
    std::cout << "NJets: " << ntuple->NJets << std::endl;    
    std::cout << "HT: " << ntuple->HT << std::endl;
    std::cout << "MHT: " << ntuple->MHT << std::endl;
    std::cout << "BTags: " << ntuple->BTags << std::endl;
    */

    histo->Fill(0);
    if( ntuple->BTags>=minBTags && ntuple->BTags<=maxBTags ) histo->Fill(1);
    else return false;
    if( ntuple->NJets>=minNJets && ntuple->NJets<=maxNJets ) histo->Fill(2);
    else return false;
    if( ntuple->NJets>=minNJets && ntuple->NJets<=maxNJets ) histo->Fill(3);
    else return false;
    if( ntuple->HT>minHT && ntuple->HT<maxHT ) histo->Fill(4);
    else return false;
    if( ntuple->MHT>minMHT && ntuple->MHT<maxMHT ) histo->Fill(5);
    else return false;

    // -------------------------------------------------------
    // higgs/V tags
    // -------------------------------------------------------
    int numHiggsTags = 0 ;
    int numVTags = 0 ;
    
    vector<TLorentzVector> ak8Jets = *(ntuple->JetsAK8);
    for( unsigned int j = 0 ; j < ak8Jets.size() ; ++j ){

      /*
      std::cout << "AK8jet Pt: " << ak8Jets[j].Pt() << std::endl;
      std::cout << "AK8jet pruned mass: " << ntuple->JetsAK8_prunedMass->at(j) << std::endl;
      std::cout << "AK8jet subjet1 CSV: " << ntuple->JetsAK8_bDiscriminatorSubjet1CSV->at(j) << std::endl;
      std::cout << "AK8jet subjet2 CSV: " << ntuple->JetsAK8_bDiscriminatorSubjet2CSV->at(j) << std::endl;
      std::cout << "AK8jet tau12: " << ntuple->JetsAK8_NsubjettinessTau1->at(j)/ntuple->JetsAK8_NsubjettinessTau2->at(j) << std::endl;
      */
      
      if( (ntuple->JetsAK8_bDiscriminatorSubjet1CSV->at(j) > .89 ||
	   ntuple->JetsAK8_bDiscriminatorSubjet2CSV->at(j) > .89 ) &&
	  ntuple->JetsAK8_NsubjettinessTau2->at(j)/ntuple->JetsAK8_NsubjettinessTau1->at(j) < 0.6 ){
	prunedMassHiggs->Fill(ntuple->JetsAK8_prunedMass->at(j));
	if( ntuple->JetsAK8_prunedMass->at(j) < 130. && 
	    ntuple->JetsAK8_prunedMass->at(j) > 100. )
	  numHiggsTags++;
      }
      if( ntuple->JetsAK8_NsubjettinessTau2->at(j)/ntuple->JetsAK8_NsubjettinessTau1->at(j) < 0.6 ){
	prunedMassV->Fill(ntuple->JetsAK8_prunedMass->at(j));
	if( ntuple->JetsAK8_prunedMass->at(j) < 100. && 
	    ntuple->JetsAK8_prunedMass->at(j) > 60. )
	  numVTags++;
      }

    } 
    // -------------------------------------------------------

    if( numHiggsTags>=minHiggsTags && numHiggsTags<=maxHiggsTags ) histo->Fill(6);
    else return false;
    if( numVTags>=minVTags && numVTags<=maxVTags ) histo->Fill(7);
    else return false;

    return true;

  };

  void postProcess( ) override{
    histo->Write();
    prunedMassV->Write();
    prunedMassHiggs->Write();
  };

};

#endif
