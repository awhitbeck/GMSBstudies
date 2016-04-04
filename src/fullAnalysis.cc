#include "RA2bNtuple.cc"
#include "analyzer.cc"
#include "lowDphiCR.cc"
#include "leptonCR.cc"
#include "signalRegion.cc"
#include "selectBaseline.cc"
#include "selectLowDphiCR.cc"
#include "selectLeptonCR.cc"
#include "selectPrompt.cc"
#include "selectHighMHT.cc"
#include "selectHighBTags.cc"
#include "selectBin.cc"
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

/*  = = = = = = = = = = = = = = = = = =

    Things to develop:  

    - Need code that will split signals into different histograms 
      based on their masses 
    - Need histos that give the fraction of events that have a gen-level
      electron, muon, photon, di-muon, di-electron, e-mu, tau, di-tau 
    - Need to understand how often electrons are fakes
    - Need to understand how often photons are fake electrons
    
    = = = = = = = = = = = = = = = = = = */

typedef selectBin<RA2bNtuple> binCut;

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

  // >=2 btags
  binCut SRhighBTags(ntuple,"SR_highBTags");
  SRhighBTags.minBTags=2; SRhighBTags.maxBTags=2;
  signalRegion SR_highBTags(ntuple,sampleTag,"SR_highBTags");
  SR_highBTags.addProcessor(&SRhighBTags,1);

  binCut ldpCRhighBTagsCut(ntuple,"ldpCR_highBTags");
  ldpCRhighBTagsCut.minBTags=2; ldpCRhighBTagsCut.maxBTags=2;
  lowDphiCR ldpCR_highBTags(ntuple,sampleTag,"ldpCR_highBTags");
  ldpCR_highBTags.addProcessor(&ldpCRhighBTagsCut,1);

  binCut lepCRhighBTags(ntuple,"lepCR_highBTags");
  lepCRhighBTags.minBTags=2; lepCRhighBTags.maxBTags=2;
  leptonCR  lepCR_highBTags(ntuple,sampleTag,"lepCR_highBTags");
  lepCR_highBTags.addProcessor(&lepCRhighBTags,1);

  // higgs tag
  binCut SRhiggsCut(ntuple,"SR_higgs");
  SRhiggsCut.minHiggsTags=1; SRhiggsCut.maxHiggsTags=1;
  signalRegion SR_higgs(ntuple,sampleTag,"SR_higgs");
  SR_higgs.addProcessor(&SRhiggsCut,1);

  binCut ldpCRhiggsCut(ntuple,"ldpCR_higgs");
  ldpCRhiggsCut.minHiggsTags=1; ldpCRhiggsCut.maxHiggsTags=1;
  lowDphiCR ldpCR_higgs(ntuple,sampleTag,"ldpCR_higgs");
  ldpCR_higgs.addProcessor(&ldpCRhiggsCut,1);

  binCut lepCRhiggsCut(ntuple,"lepCR_higgs");
  lepCRhiggsCut.minHiggsTags=1; lepCRhiggsCut.maxHiggsTags=1;
  leptonCR  lepCR_higgs(ntuple,sampleTag,"lepCR_higgs");
  lepCR_higgs.addProcessor(&lepCRhiggsCut,1);

  // 2higgs tag
  binCut SR2higgsCut(ntuple,"SR_2higgs");
  SR2higgsCut.minHiggsTags=2; SR2higgsCut.maxHiggsTags=2;
  signalRegion SR_2higgs(ntuple,sampleTag,"SR_2higgs");
  SR_2higgs.addProcessor(&SR2higgsCut,1);

  binCut ldpCR2higgsCut(ntuple,"ldpCR_2higgs");
  ldpCR2higgsCut.minHiggsTags=2; ldpCR2higgsCut.maxHiggsTags=2;
  lowDphiCR ldpCR_2higgs(ntuple,sampleTag,"ldpCR_2higgs");
  ldpCR_2higgs.addProcessor(&ldpCR2higgsCut,1);

  binCut lepCR2higgsCut(ntuple,"lepCR_2higgs");
  lepCR2higgsCut.minHiggsTags=2; lepCR2higgsCut.maxHiggsTags=2;
  leptonCR  lepCR_2higgs(ntuple,sampleTag,"lepCR_2higgs");
  lepCR_2higgs.addProcessor(&lepCR2higgsCut,1);

  // W/Z tag
  binCut SRVtagCut(ntuple,"SR_Vtag");
  SRVtagCut.minVTags=1; SRVtagCut.maxVTags=1;
  signalRegion SR_Vtag(ntuple,sampleTag,"SR_Vtag");
  SR_Vtag.addProcessor(&SRVtagCut,1);

  binCut ldpCRVtagCut(ntuple,"ldpCR_Vtag");
  ldpCRVtagCut.minVTags=1; ldpCRVtagCut.maxVTags=1;
  lowDphiCR ldpCR_Vtag(ntuple,sampleTag,"ldpCR_Vtag");
  ldpCR_Vtag.addProcessor(&ldpCRVtagCut,1);

  binCut lepCRVtagCut(ntuple,"lepCR_Vtag");
  lepCRVtagCut.minVTags=1; lepCRVtagCut.maxVTags=1;
  leptonCR  lepCR_Vtag(ntuple,sampleTag,"lepCR_Vtag");
  lepCR_Vtag.addProcessor(&lepCRVtagCut,1);
  
  signalRegion SR(ntuple,sampleTag);
  lowDphiCR ldpCR(ntuple,sampleTag);
  leptonCR  lepCR(ntuple,sampleTag);

  for( int i = 0 ; i < t->GetEntries() ; i++ ){

    t->GetEntry(i);
    if( i % 10000 == 0 ) 
      cout << "event: " << i << endl;
    ntuple->patchJetID();

    SR.analyze();
    ldpCR.analyze();
    lepCR.analyze();
    SR_highBTags.analyze();
    ldpCR_highBTags.analyze();
    lepCR_highBTags.analyze();
    SR_higgs.analyze();
    ldpCR_higgs.analyze();
    lepCR_higgs.analyze();
    SR_2higgs.analyze();
    ldpCR_2higgs.analyze();
    lepCR_2higgs.analyze();
    SR_Vtag.analyze();
    ldpCR_Vtag.analyze();
    lepCR_Vtag.analyze();

  }

  cout << "save tree" << endl;

  TFile* outFile = new TFile("fullAnalysis_"+fileTag+".root","RECREATE");
  
  SR.postProcess();
  ldpCR.postProcess();
  lepCR.postProcess();
  SR_highBTags.postProcess();
  ldpCR_highBTags.postProcess();
  lepCR_highBTags.postProcess();
  SR_higgs.postProcess();
  SRhiggsCut.postProcess();
  ldpCR_higgs.postProcess();
  lepCR_higgs.postProcess();
  SR_2higgs.postProcess();
  ldpCR_2higgs.postProcess();
  lepCR_2higgs.postProcess();
  SR_Vtag.postProcess();
  SRVtagCut.postProcess();
  ldpCR_Vtag.postProcess();
  lepCR_Vtag.postProcess();
  
  outFile->Close();
  
  delete ntuple;

}  

