#include "RA2bNtuple.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
#include "selectLowDphiCR.cc"
#include "selectLeptonCR.cc"
#include "selectPrompt.cc"
#include "skim.cc"
#include "weightProducer.cc"
#include "fillHisto.cc"
#include "fillPhotonTruth.cc"
#include "fillLeptonTruth.cc"

#include "TString.h"
#include "TChain.h"
#include "TFile.h"

#include <cstdio>
#include <string>
#include <iostream>

#include "helpers.h"

using namespace std; 

/* 

   analyzer for plotting distributions in the full phase space of the
   signal region ...

 */

typedef fillHisto<RA2bNtuple> histo;
typedef fillPhotonTruth<RA2bNtuple> histPhoTruth;

class leptonCR : public analyzer<RA2bNtuple> {

public :

  RA2bNtuple* ntuple;
  selectLeptonCR<RA2bNtuple> *select1L;
  selectPrompt<RA2bNtuple> *prompt;
  histo *HThisto;
  histo *MHThisto;
  histo *NJetshisto;
  histo *BTagshisto; 
  histo *DeltaPhi1histo;
  histo *DeltaPhi2histo;
  histo *DeltaPhi3histo;
  histo *DeltaPhi4histo;
  histPhoTruth *photonTruth;
  fillLeptonTruth<RA2bNtuple> *leptonTruth;
  TString sampleTag,regionTag;

  leptonCR( RA2bNtuple* ntuple_ , TString sampleTag_ , TString regionTag_ = "lepCR" , 
	   vector<processor<RA2bNtuple>* > *addSelectors = 0 )
    : analyzer<RA2bNtuple>(ntuple_,10){
    ntuple = ntuple_ ; 
    sampleTag = sampleTag_;
    regionTag = regionTag_;

    prompt = new selectPrompt<RA2bNtuple>(ntuple,false); // selecton prompt photons
    if( sampleTag == "QCD" )
      prompt->negate = true ; // selects non-prompt photons
    
    select1L = new selectLeptonCR<RA2bNtuple>(ntuple,regionTag);

    HThisto = new histo(ntuple,40,500,4000,regionTag+"_"+sampleTag,"HT","Weight") ; 
    MHThisto = new histo(ntuple,40,000,1000,regionTag+"_"+sampleTag,"MHT","Weight")   ; 
    NJetshisto = new histo(ntuple,12,3.5,15.5,regionTag+"_"+sampleTag,"NJets","Weight") ;
    BTagshisto = new histo(ntuple,7,-0.5,6.5,regionTag+"_"+sampleTag,"BTags","Weight") ; 
    DeltaPhi1histo = new histo(ntuple,40,0.,3.2,regionTag+"_"+sampleTag,"DeltaPhi1","Weight");
    DeltaPhi2histo = new histo(ntuple,40,0.,3.2,regionTag+"_"+sampleTag,"DeltaPhi2","Weight");
    DeltaPhi3histo = new histo(ntuple,40,0.,3.2,regionTag+"_"+sampleTag,"DeltaPhi3","Weight");
    DeltaPhi4histo = new histo(ntuple,40,0.,3.2,regionTag+"_"+sampleTag,"DeltaPhi4","Weight");
    photonTruth = new histPhoTruth(ntuple,regionTag+"_"+sampleTag,"Weight");
    leptonTruth = new fillLeptonTruth<RA2bNtuple>(ntuple,regionTag+"_"+sampleTag,"Weight");

    addProcessor(select1L);
    // make sure that for QCD or GJets samples, either non-prompt or
    // prompt photons, respectively are used
    if( sampleTag == "QCD" || sampleTag == "GJets" )
      addProcessor(prompt);

    if( addSelectors && addSelectors->size()>0){
      for( unsigned int s=0 ; s < addSelectors->size() ; s++ ){
	addProcessor(addSelectors->at(s));
      }
    }
    addProcessor(HThisto);
    addProcessor(MHThisto);
    addProcessor(NJetshisto);
    addProcessor(BTagshisto);
    addProcessor(DeltaPhi1histo);
    addProcessor(DeltaPhi2histo);
    addProcessor(DeltaPhi3histo);
    addProcessor(DeltaPhi4histo);
    addProcessor(photonTruth);
    addProcessor(leptonTruth);
  };

  ~leptonCR(){

    delete select1L;
    delete HThisto;
    delete MHThisto;
    delete NJetshisto;
    delete BTagshisto; 
    delete DeltaPhi1histo;
    delete DeltaPhi2histo;
    delete DeltaPhi3histo;
    delete DeltaPhi4histo;
    delete photonTruth;
    delete leptonTruth;
  };

  /* can this be moved into the base class with the option to 
     override the base class's implementation??? */
  void analyze(){
    
    for( unsigned int iProc = 0 ; iProc < processorList->size() ; iProc++){
      //cout << "ldpCR proc: " << iProc << endl; // " " << processorList->at(iProc)->moduleName << endl;
      if( ! processorList->at(iProc)->process() ) break;
    }

  };

  void postProcess(){

    select1L->histo->Write("leptonCRYields_"+sampleTag);

    HThisto->histo->Write();
    MHThisto->histo->Write();
    NJetshisto->histo->Write();
    BTagshisto->histo->Write();
    DeltaPhi1histo->histo->Write();
    DeltaPhi2histo->histo->Write();
    DeltaPhi3histo->histo->Write();
    DeltaPhi4histo->histo->Write();
    photonTruth->histo->Write();
    leptonTruth->histo->Write();
  };

};
