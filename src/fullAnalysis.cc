#include "RA2bNtuple.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
#include "selectLowDphiCR.cc"
#include "selectLeptonCR.cc"
#include "selectPrompt.cc"
#include "skim.cc"
#include "weightProducer.cc"
#include "fillHisto.cc"
#include "fillDphiGamma.cc"

#include "TString.h"
#include "TChain.h"
#include "TFile.h"

#include <cstdio>
#include <string>
#include <iostream>

#include "helpers.h"

using namespace std;

/*  = = = = = = = = = = = = = = = = = =

    Things to develop:  

    - Need code that will split signals into different histograms 
      based on their masses 
    - Need histos that give the fraction of events that have a gen-level
      electron, muon, photon, di-muon, di-electron, e-mu, tau, di-tau 
    - Need to understand how often electrons are fakes
    - Need to understand how often photons are fake electrons
    
    = = = = = = = = = = = = = = = = = = */


int main(int argc, char** argv){

  // this code is setup specifically for analyzing one input file at a time.  The output histonames
  // are based on the sample key, from the fmap (see helper.h for details)
  TString fileTag = argv[1];
  fileMap fmap = parseInputs("inputFiles.txt");
  sampleMap rmap = reduceMap(fmap,fileTag);
  if( rmap.size() != 1 ){
    cout << "either no samples found or too many samples found..." << endl;
    return 1;
  }
  TChain* t = buildChain(rmap.begin()->second,"TreeMaker2/PreSelection");
  
  RA2bNtuple *ntuple = new RA2bNtuple(t);
  
  selectPrompt<RA2bNtuple> prompt(ntuple,false); // selecton prompt photons
  if( rmap.begin()->first == "QCD" )
    prompt.negate = true ; // selects non-prompt photons

  // setup selectors and fillers for the signal region
  selectBaseline<RA2bNtuple> *selectBase = new selectBaseline<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> SR_HThisto(ntuple,40,500,4000,"SR_"+rmap.begin()->first,"HT","Weight");
  fillHisto<RA2bNtuple> SR_MHThisto(ntuple,40,0,1000,"SR_"+rmap.begin()->first,"MHT","Weight");
  fillHisto<RA2bNtuple> SR_NJetshisto(ntuple,12,3.5,15.5,"SR_"+rmap.begin()->first,"NJets","Weight");
  fillHisto<RA2bNtuple> SR_BTagshisto(ntuple,7,-0.5,6.5,"SR_"+rmap.begin()->first,"BTags","Weight");
  analyzer<RA2bNtuple> SR(ntuple,0);
  SR.addProcessor(selectBase);
  // make sure that for QCD or GJets samples, either non-prompt or
  // prompt photons, respectively are used
  if( rmap.begin()->first == "QCD" || rmap.begin()->first == "GJets" )
    SR.addProcessor(&prompt);
  SR.addProcessor(&SR_HThisto);
  SR.addProcessor(&SR_MHThisto);
  SR.addProcessor(&SR_NJetshisto);
  SR.addProcessor(&SR_BTagshisto);

  // setup selectors and fillers for the low deltaPhi control region
  selectLowDphiCR<RA2bNtuple> *selectLdP = new selectLowDphiCR<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> ldpCR_HThisto = fillHisto<RA2bNtuple>(SR_HThisto,"HT_ldpHT_"+rmap.begin()->first) ; 
  fillHisto<RA2bNtuple> ldpCR_MHThisto = fillHisto<RA2bNtuple>(SR_MHThisto,"MHT_ldpHT_"+rmap.begin()->first)   ; 
  fillHisto<RA2bNtuple> ldpCR_NJetshisto = fillHisto<RA2bNtuple>(SR_NJetshisto,"NJets_ldpHT_"+rmap.begin()->first) ;
  fillHisto<RA2bNtuple> ldpCR_BTagshisto = fillHisto<RA2bNtuple>(SR_BTagshisto,"BTags_ldpCR_"+rmap.begin()->first) ; 
  fillDphiGamma<RA2bNtuple> ldpCR_dPhiGamma(ntuple,"dPhiGamma_ldpCR_"+rmap.begin()->first);
  analyzer<RA2bNtuple> ldpCR(ntuple,1);
  ldpCR.addProcessor(selectLdP);
  // make sure that for QCD or GJets samples, either non-prompt or
  // prompt photons, respectively are used
  if( rmap.begin()->first == "QCD" || rmap.begin()->first == "GJets" )
    ldpCR.addProcessor(&prompt);
  ldpCR.addProcessor(&ldpCR_HThisto);
  ldpCR.addProcessor(&ldpCR_MHThisto);
  ldpCR.addProcessor(&ldpCR_NJetshisto);
  ldpCR.addProcessor(&ldpCR_BTagshisto);
  ldpCR.addProcessor(&ldpCR_dPhiGamma);

  // setup selectors and fillers for the single lepton control region
  selectLeptonCR<RA2bNtuple> *select1L = new selectLeptonCR<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> lepCR_HThisto = fillHisto<RA2bNtuple>(SR_HThisto,"HT_lepCR_"+rmap.begin()->first) ;
  fillHisto<RA2bNtuple> lepCR_MHThisto = fillHisto<RA2bNtuple>(SR_MHThisto,"MHT_lepCR_"+rmap.begin()->first) ; 
  fillHisto<RA2bNtuple> lepCR_NJetshisto = fillHisto<RA2bNtuple>(SR_NJetshisto,"NJets_lepCR_"+rmap.begin()->first) ; 
  fillHisto<RA2bNtuple> lepCR_BTagshisto = fillHisto<RA2bNtuple>(SR_BTagshisto,"BTags_lepCR_"+rmap.begin()->first) ; 
  analyzer<RA2bNtuple> lepCR(ntuple,1);
  lepCR.addProcessor(select1L);
  // make sure that for QCD or GJets samples, either non-prompt or
  // prompt photons, respectively are used
  if( rmap.begin()->first == "QCD" || rmap.begin()->first == "GJets" )
    lepCR.addProcessor(&prompt);
  lepCR.addProcessor(&lepCR_HThisto);
  lepCR.addProcessor(&lepCR_MHThisto);
  lepCR.addProcessor(&lepCR_NJetshisto);
  lepCR.addProcessor(&lepCR_BTagshisto);

  for( int i = 0 ; i < t->GetEntries() ; i++ ){

    t->GetEntry(i);
    if( i % 1000 == 0 ) 
      cout << "event: " << i << endl;
    ntuple->patchJetID();

    for( unsigned int iProc = 0 ; iProc < SR.processorList->size() ; iProc++){
      //cout << "SR proc: " << iProc << endl; // " " << SR.processorList->at(iProc)->moduleName << endl;
      if( ! SR.processorList->at(iProc)->process() ) break;
    }
    for( unsigned int iProc = 0 ; iProc < ldpCR.processorList->size() ; iProc++){
      //cout << "ldpCR proc: " << iProc << endl; // " " << ldpCR.processorList->at(iProc)->moduleName << endl;
      if( ! ldpCR.processorList->at(iProc)->process() ) break;
    }
    for( unsigned int iProc = 0 ; iProc < lepCR.processorList->size() ; iProc++){
      //cout << "lepCR proc: " << iProc << endl; // " " << lepCR.processorList->at(iProc)->moduleName << endl;
      if( ! lepCR.processorList->at(iProc)->process() ) break;
    }
  }

  cout << "save tree" << endl;

  TFile* outFile = new TFile("fullAnalysis_"+fileTag+".root","RECREATE");
  selectBase->histo->Write("baselineYields_"+rmap.begin()->first);
  selectLdP->histo->Write("lowDphiYields_"+rmap.begin()->first);
  select1L->histo->Write("singleLepYields_"+rmap.begin()->first);
  SR_HThisto.histo->Write();
  SR_MHThisto.histo->Write();
  SR_NJetshisto.histo->Write();
  SR_BTagshisto.histo->Write();
  ldpCR_HThisto.histo->Write();
  ldpCR_MHThisto.histo->Write();
  ldpCR_NJetshisto.histo->Write();
  ldpCR_BTagshisto.histo->Write();
  ldpCR_dPhiGamma.histo->Write();
  lepCR_HThisto.histo->Write();
  lepCR_MHThisto.histo->Write();
  lepCR_NJetshisto.histo->Write();
  lepCR_BTagshisto.histo->Write();

  outFile->Close();

  delete ntuple;
  delete selectLdP;
  delete select1L;

}  

