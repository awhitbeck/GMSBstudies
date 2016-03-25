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

  TString sampleTag = rmap.begin()->first;

  TChain* t = buildChain(rmap.begin()->second,"TreeMaker2/PreSelection");
  
  RA2bNtuple *ntuple = new RA2bNtuple(t);
  
  selectPrompt<RA2bNtuple> prompt(ntuple,false); // selecton prompt photons
  if( sampleTag == "QCD" )
    prompt.negate = true ; // selects non-prompt photons

  // setup selectors and fillers for the signal region
  selectBaseline<RA2bNtuple> *selectBase = new selectBaseline<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> SR_HThisto(ntuple,40,500,4000,"SR_"+sampleTag,"HT","Weight");
  fillHisto<RA2bNtuple> SR_MHThisto(ntuple,40,0,1000,"SR_"+sampleTag,"MHT","Weight");
  fillHisto<RA2bNtuple> SR_NJetshisto(ntuple,12,3.5,15.5,"SR_"+sampleTag,"NJets","Weight");
  fillHisto<RA2bNtuple> SR_BTagshisto(ntuple,7,-0.5,6.5,"SR_"+sampleTag,"BTags","Weight");
  fillHisto<RA2bNtuple> SR_DeltaPhi1histo(ntuple,50,0.,3.0,"SR_"+sampleTag,"DeltaPhi1","Weight");
  fillHisto<RA2bNtuple> SR_DeltaPhi2histo(ntuple,50,0.,3.0,"SR_"+sampleTag,"DeltaPhi2","Weight");
  fillHisto<RA2bNtuple> SR_DeltaPhi3histo(ntuple,50,0.,3.0,"SR_"+sampleTag,"DeltaPhi3","Weight");
  fillHisto<RA2bNtuple> SR_DeltaPhi4histo(ntuple,50,0.,3.0,"SR_"+sampleTag,"DeltaPhi4","Weight");
  fillPhotonTruth<RA2bNtuple> SR_photonTruth(ntuple,"SR_"+sampleTag);
  analyzer<RA2bNtuple> SR(ntuple,0);
  SR.addProcessor(selectBase);
  // make sure that for QCD or GJets samples, either non-prompt or
  // prompt photons, respectively are used
  if( sampleTag == "QCD" || sampleTag == "GJets" )
    SR.addProcessor(&prompt);
  SR.addProcessor(&SR_HThisto);
  SR.addProcessor(&SR_MHThisto);
  SR.addProcessor(&SR_NJetshisto);
  SR.addProcessor(&SR_BTagshisto);
  SR.addProcessor(&SR_DeltaPhi1histo);
  SR.addProcessor(&SR_DeltaPhi2histo);
  SR.addProcessor(&SR_DeltaPhi3histo);
  SR.addProcessor(&SR_DeltaPhi4histo);
  SR.addProcessor(&SR_photonTruth);

  // setup selectors and fillers for the low deltaPhi control region
  selectLowDphiCR<RA2bNtuple> *selectLdP = new selectLowDphiCR<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> ldpCR_HThisto = fillHisto<RA2bNtuple>(SR_HThisto,"HT_ldpHT_"+sampleTag) ; 
  fillHisto<RA2bNtuple> ldpCR_MHThisto = fillHisto<RA2bNtuple>(SR_MHThisto,"MHT_ldpHT_"+sampleTag)   ; 
  fillHisto<RA2bNtuple> ldpCR_NJetshisto = fillHisto<RA2bNtuple>(SR_NJetshisto,"NJets_ldpHT_"+sampleTag) ;
  fillHisto<RA2bNtuple> ldpCR_BTagshisto = fillHisto<RA2bNtuple>(SR_BTagshisto,"BTags_ldpCR_"+sampleTag) ; 
  fillHisto<RA2bNtuple> ldpCR_DeltaPhi1histo = fillHisto<RA2bNtuple>(SR_DeltaPhi1histo,"DeltaPhi1_ldpCR_"+sampleTag);
  fillHisto<RA2bNtuple> ldpCR_DeltaPhi2histo = fillHisto<RA2bNtuple>(SR_DeltaPhi2histo,"DeltaPhi2_ldpCR_"+sampleTag);
  fillHisto<RA2bNtuple> ldpCR_DeltaPhi3histo = fillHisto<RA2bNtuple>(SR_DeltaPhi3histo,"DeltaPhi3_ldpCR_"+sampleTag);
  fillHisto<RA2bNtuple> ldpCR_DeltaPhi4histo = fillHisto<RA2bNtuple>(SR_DeltaPhi4histo,"DeltaPhi4_ldpCR_"+sampleTag);
  fillDphiGamma<RA2bNtuple> ldpCR_dPhiGamma(ntuple,"ldpCR_"+sampleTag);
  fillPhotonTruth<RA2bNtuple> ldpCR_photonTruth(ntuple,"ldpCR_"+sampleTag);
  analyzer<RA2bNtuple> ldpCR(ntuple,1);
  ldpCR.addProcessor(selectLdP);
  // make sure that for QCD or GJets samples, either non-prompt or
  // prompt photons, respectively are used
  if( sampleTag == "QCD" || sampleTag == "GJets" )
    ldpCR.addProcessor(&prompt);
  ldpCR.addProcessor(&ldpCR_HThisto);
  ldpCR.addProcessor(&ldpCR_MHThisto);
  ldpCR.addProcessor(&ldpCR_NJetshisto);
  ldpCR.addProcessor(&ldpCR_BTagshisto);
  ldpCR.addProcessor(&ldpCR_DeltaPhi1histo);
  ldpCR.addProcessor(&ldpCR_DeltaPhi2histo);
  ldpCR.addProcessor(&ldpCR_DeltaPhi3histo);
  ldpCR.addProcessor(&ldpCR_DeltaPhi4histo);
  ldpCR.addProcessor(&ldpCR_dPhiGamma);
  ldpCR.addProcessor(&ldpCR_photonTruth);

  // setup selectors and fillers for the single lepton control region
  selectLeptonCR<RA2bNtuple> *select1L = new selectLeptonCR<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> lepCR_HThisto = fillHisto<RA2bNtuple>(SR_HThisto,"HT_lepCR_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCR_MHThisto = fillHisto<RA2bNtuple>(SR_MHThisto,"MHT_lepCR_"+sampleTag) ; 
  fillHisto<RA2bNtuple> lepCR_NJetshisto = fillHisto<RA2bNtuple>(SR_NJetshisto,"NJets_lepCR_"+sampleTag) ; 
  fillHisto<RA2bNtuple> lepCR_BTagshisto = fillHisto<RA2bNtuple>(SR_BTagshisto,"BTags_lepCR_"+sampleTag) ; 
  fillHisto<RA2bNtuple> lepCR_DeltaPhi1histo = fillHisto<RA2bNtuple>(SR_DeltaPhi1histo,"DeltaPhi1_lepCR_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCR_DeltaPhi2histo = fillHisto<RA2bNtuple>(SR_DeltaPhi2histo,"DeltaPhi2_lepCR_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCR_DeltaPhi3histo = fillHisto<RA2bNtuple>(SR_DeltaPhi3histo,"DeltaPhi3_lepCR_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCR_DeltaPhi4histo = fillHisto<RA2bNtuple>(SR_DeltaPhi4histo,"DeltaPhi4_lepCR_"+sampleTag) ;
  fillPhotonTruth<RA2bNtuple> lepCR_photonTruth(ntuple,"lepCR_"+sampleTag);
  fillLeptonTruth<RA2bNtuple> lepCR_leptonTruth(ntuple,"lepCR_"+sampleTag);
  analyzer<RA2bNtuple> lepCR(ntuple,1);
  lepCR.addProcessor(select1L);
  // make sure that for QCD or GJets samples, either non-prompt or
  // prompt photons, respectively are used
  if( sampleTag == "QCD" || sampleTag == "GJets" )
    lepCR.addProcessor(&prompt);
  lepCR.addProcessor(&lepCR_HThisto);
  lepCR.addProcessor(&lepCR_MHThisto);
  lepCR.addProcessor(&lepCR_NJetshisto);
  lepCR.addProcessor(&lepCR_BTagshisto);
  lepCR.addProcessor(&lepCR_DeltaPhi1histo);
  lepCR.addProcessor(&lepCR_DeltaPhi2histo);
  lepCR.addProcessor(&lepCR_DeltaPhi3histo);
  lepCR.addProcessor(&lepCR_DeltaPhi4histo);
  lepCR.addProcessor(&lepCR_photonTruth);
  lepCR.addProcessor(&lepCR_leptonTruth);

  // setup selectors and fillers for the high btag single lepton control region
  selectLeptonCR<RA2bNtuple> *select1L2Btag = new selectLeptonCR<RA2bNtuple>(ntuple);
  selectHighBtags<RA2bNtuple> *select = new selectLeptonCR<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> lepCR2Btag_HThisto = fillHisto<RA2bNtuple>(SR_HThisto,"HT_lepCR2Btag_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCR2Btag_MHThisto = fillHisto<RA2bNtuple>(SR_MHThisto,"MHT_lepCR2Btag_"+sampleTag) ; 
  fillHisto<RA2bNtuple> lepCR2Btag_NJetshisto = fillHisto<RA2bNtuple>(SR_NJetshisto,"NJets_lepCR2Btag_"+sampleTag) ; 
  fillHisto<RA2bNtuple> lepCR2Btag_BTagshisto = fillHisto<RA2bNtuple>(SR_BTagshisto,"BTags_lepCR2Btag_"+sampleTag) ; 
  fillHisto<RA2bNtuple> lepCR2Btag_DeltaPhi1histo = fillHisto<RA2bNtuple>(SR_DeltaPhi1histo,"DeltaPhi1_lepCR2Btag_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCR2Btag_DeltaPhi2histo = fillHisto<RA2bNtuple>(SR_DeltaPhi2histo,"DeltaPhi2_lepCR2Btag_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCR2Btag_DeltaPhi3histo = fillHisto<RA2bNtuple>(SR_DeltaPhi3histo,"DeltaPhi3_lepCR2Btag_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCR2Btag_DeltaPhi4histo = fillHisto<RA2bNtuple>(SR_DeltaPhi4histo,"DeltaPhi4_lepCR2Btag_"+sampleTag) ;
  fillPhotonTruth<RA2bNtuple> lepCR2Btag_photonTruth(ntuple,"lepCR2Btag_"+sampleTag);
  fillLeptonTruth<RA2bNtuple> lepCR2Btag_leptonTruth(ntuple,"lepCR2Btag_"+sampleTag);
  analyzer<RA2bNtuple> lepCR2Btag(ntuple,1);
  lepCR2Btag.addProcessor(select1L2Btag);
  // make sure that for QCD or GJets samples, either non-prompt or
  // prompt photons, respectively are used
  if( sampleTag == "QCD" || sampleTag == "GJets" )
    lepCR2Btag.addProcessor(&prompt);
  lepCR2Btag.addProcessor(&lepCR2Btag_HThisto);
  lepCR2Btag.addProcessor(&lepCR2Btag_MHThisto);
  lepCR2Btag.addProcessor(&lepCR2Btag_NJetshisto);
  lepCR2Btag.addProcessor(&lepCR2Btag_BTagshisto);
  lepCR2Btag.addProcessor(&lepCR2Btag_DeltaPhi1histo);
  lepCR2Btag.addProcessor(&lepCR2Btag_DeltaPhi2histo);
  lepCR2Btag.addProcessor(&lepCR2Btag_DeltaPhi3histo);
  lepCR2Btag.addProcessor(&lepCR2Btag_DeltaPhi4histo);
  lepCR2Btag.addProcessor(&lepCR2Btag_photonTruth);
  lepCR2Btag.addProcessor(&lepCR2Btag_leptonTruth);

  // setup selectors and fillers for the high MHT single lepton control region
  selectLeptonCR<RA2bNtuple> *select1LMHT200 = new selectLeptonCR<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> lepCRMHT200_HThisto = fillHisto<RA2bNtuple>(SR_HThisto,"HT_lepCRMHT200_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCRMHT200_MHThisto = fillHisto<RA2bNtuple>(SR_MHThisto,"MHT_lepCRMHT200_"+sampleTag) ; 
  fillHisto<RA2bNtuple> lepCRMHT200_NJetshisto = fillHisto<RA2bNtuple>(SR_NJetshisto,"NJets_lepCRMHT200_"+sampleTag) ; 
  fillHisto<RA2bNtuple> lepCRMHT200_BTagshisto = fillHisto<RA2bNtuple>(SR_BTagshisto,"BTags_lepCRMHT200_"+sampleTag) ; 
  fillHisto<RA2bNtuple> lepCRMHT200_DeltaPhi1histo = fillHisto<RA2bNtuple>(SR_DeltaPhi1histo,"DeltaPhi1_lepCRMHT200_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCRMHT200_DeltaPhi2histo = fillHisto<RA2bNtuple>(SR_DeltaPhi2histo,"DeltaPhi2_lepCRMHT200_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCRMHT200_DeltaPhi3histo = fillHisto<RA2bNtuple>(SR_DeltaPhi3histo,"DeltaPhi3_lepCRMHT200_"+sampleTag) ;
  fillHisto<RA2bNtuple> lepCRMHT200_DeltaPhi4histo = fillHisto<RA2bNtuple>(SR_DeltaPhi4histo,"DeltaPhi4_lepCRMHT200_"+sampleTag) ;
  fillPhotonTruth<RA2bNtuple> lepCRMHT200_photonTruth(ntuple,"lepCRMHT200_"+sampleTag);
  fillLeptonTruth<RA2bNtuple> lepCRMHT200_leptonTruth(ntuple,"lepCRMHT200_"+sampleTag);
  analyzer<RA2bNtuple> lepCRMHT200(ntuple,1);
  lepCRMHT200.addProcessor(select1LMHT200);
  // make sure that for QCD or GJets samples, either non-prompt or
  // prompt photons, respectively are used
  if( sampleTag == "QCD" || sampleTag == "GJets" )
    lepCRMHT200.addProcessor(&prompt);
  lepCRMHT200.addProcessor(&lepCRMHT200_HThisto);
  lepCRMHT200.addProcessor(&lepCRMHT200_MHThisto);
  lepCRMHT200.addProcessor(&lepCRMHT200_NJetshisto);
  lepCRMHT200.addProcessor(&lepCRMHT200_BTagshisto);
  lepCRMHT200.addProcessor(&lepCRMHT200_DeltaPhi1histo);
  lepCRMHT200.addProcessor(&lepCRMHT200_DeltaPhi2histo);
  lepCRMHT200.addProcessor(&lepCRMHT200_DeltaPhi3histo);
  lepCRMHT200.addProcessor(&lepCRMHT200_DeltaPhi4histo);
  lepCRMHT200.addProcessor(&lepCRMHT200_photonTruth);
  lepCRMHT200.addProcessor(&lepCRMHT200_leptonTruth);

  for( int i = 0 ; i < t->GetEntries() ; i++ ){

    t->GetEntry(i);
    if( i % 10000 == 0 ) 
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
    for( unsigned int iProc = 0 ; iProc < lepCR2Btag.processorList->size() ; iProc++){
      if( ! lepCR2Btag.processorList->at(iProc)->process() ) break;
    }
    for( unsigned int iProc = 0 ; iProc < lepCRMHT200.processorList->size() ; iProc++){
      if( ! lepCRMHT200.processorList->at(iProc)->process() ) break;
    }
  }

  cout << "save tree" << endl;

  TFile* outFile = new TFile("fullAnalysis_"+fileTag+".root","RECREATE");
  selectBase->histo->Write("baselineYields_"+sampleTag);
  selectLdP->histo->Write("lowDphiYields_"+sampleTag);
  select1L->histo->Write("singleLepYields_"+sampleTag);
  select1L2Btag->histo->Write("singleLep2BtagYields_"+sampleTag);
  select1LMHT200->histo->Write("singleLepMHT200Yields_"+sampleTag);

  SR_HThisto.histo->Write();
  SR_MHThisto.histo->Write();
  SR_NJetshisto.histo->Write();
  SR_BTagshisto.histo->Write();
  SR_photonTruth.histo->Write();
  SR_DeltaPhi1histo.histo->Write();
  SR_DeltaPhi2histo.histo->Write();
  SR_DeltaPhi3histo.histo->Write();
  SR_DeltaPhi4histo.histo->Write();
  
  ldpCR_HThisto.histo->Write();
  ldpCR_MHThisto.histo->Write();
  ldpCR_NJetshisto.histo->Write();
  ldpCR_BTagshisto.histo->Write();
  ldpCR_dPhiGamma.histo->Write();
  ldpCR_photonTruth.histo->Write();
  ldpCR_DeltaPhi1histo.histo->Write();
  ldpCR_DeltaPhi2histo.histo->Write();
  ldpCR_DeltaPhi3histo.histo->Write();
  ldpCR_DeltaPhi4histo.histo->Write();

  lepCR_HThisto.histo->Write();
  lepCR_MHThisto.histo->Write();
  lepCR_NJetshisto.histo->Write();
  lepCR_BTagshisto.histo->Write();
  lepCR_photonTruth.histo->Write();
  lepCR_leptonTruth.histo->Write();
  lepCR_DeltaPhi1histo.histo->Write();
  lepCR_DeltaPhi2histo.histo->Write();
  lepCR_DeltaPhi3histo.histo->Write();
  lepCR_DeltaPhi4histo.histo->Write();

  lepCR2Btag_HThisto.histo->Write();
  lepCR2Btag_MHThisto.histo->Write();
  lepCR2Btag_NJetshisto.histo->Write();
  lepCR2Btag_BTagshisto.histo->Write();
  lepCR2Btag_photonTruth.histo->Write();
  lepCR2Btag_leptonTruth.histo->Write();
  lepCR2Btag_DeltaPhi1histo.histo->Write();
  lepCR2Btag_DeltaPhi2histo.histo->Write();
  lepCR2Btag_DeltaPhi3histo.histo->Write();
  lepCR2Btag_DeltaPhi4histo.histo->Write();

  lepCRMHT200_HThisto.histo->Write();
  lepCRMHT200_MHThisto.histo->Write();
  lepCRMHT200_NJetshisto.histo->Write();
  lepCRMHT200_BTagshisto.histo->Write();
  lepCRMHT200_photonTruth.histo->Write();
  lepCRMHT200_leptonTruth.histo->Write();
  lepCRMHT200_DeltaPhi1histo.histo->Write();
  lepCRMHT200_DeltaPhi2histo.histo->Write();
  lepCRMHT200_DeltaPhi3histo.histo->Write();
  lepCRMHT200_DeltaPhi4histo.histo->Write();

  outFile->Close();

  delete ntuple;
  delete selectLdP;
  delete select1L;

}  

