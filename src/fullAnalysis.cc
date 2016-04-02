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
  SR_highBTags.addProcessor(&SRhighBTags);

  binCut ldpCRhighBTagsCut(ntuple,"ldpCR_highBTags");
  ldpCRhighBTagsCut.minBTags=2; ldpCRhighBTagsCut.maxBTags=2;
  lowDphiCR ldpCR_highBTags(ntuple,sampleTag,"ldpCR_highBTags");
  ldpCR_highBTags.addProcessor(&ldpCRhighBTagsCut);

  binCut lepCRhighBTags(ntuple,"lepCR_highBTags");
  lepCRhighBTags.minBTags=2; lepCRhighBTags.maxBTags=2;
  leptonCR  lepCR_highBTags(ntuple,sampleTag,"lepCR_highBTags");
  lepCR_highBTags.addProcessor(&lepCRhighBTags);

  // higgs tag
  binCut SRhiggsCut(ntuple,"SR_higgs");
  SRhiggsCut.minHiggsTags=2; SRhiggsCut.maxHiggsTags=2;
  signalRegion SR_higgs(ntuple,sampleTag,"SR_higgs");
  SR_higgs.addProcessor(&SRhiggsCut);

  binCut ldpCRhiggsCut(ntuple,"ldpCR_higgs");
  ldpCRhiggsCut.minHiggsTags=2; ldpCRhiggsCut.maxHiggsTags=2;
  lowDphiCR ldpCR_higgs(ntuple,sampleTag,"ldpCR_higgs");
  ldpCR_higgs.addProcessor(&ldpCRhiggsCut);

  binCut lepCRhiggsCut(ntuple,"lepCR_higgs");
  lepCRhiggsCut.minHiggsTags=2; lepCRhiggsCut.maxHiggsTags=2;
  leptonCR  lepCR_higgs(ntuple,sampleTag,"lepCR_higgs");
  lepCR_higgs.addProcessor(&lepCRhiggsCut);
  

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
  ldpCR_higgs.postProcess();
  lepCR_higgs.postProcess();
  
  outFile->Close();
  
  delete ntuple;

}  

