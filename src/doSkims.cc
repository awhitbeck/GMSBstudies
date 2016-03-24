#include "RA2bNtuple.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
#include "selectLowDphiCR.cc"
#include "selectLeptonCR.cc"
#include "skim.cc"
#include "weightProducer.cc"

#include "TString.h"
#include "TChain.h"
#include "TFile.h"

#include <cstdio>
#include <string>
#include <iostream>

#include "helpers.h"

using namespace std;

int main(int argc, char** argv){

  TString sample = argv[1];
  TChain* t = buildChain("inputFiles.txt",sample,"TreeMaker2/PreSelection");
  
  RA2bNtuple *ntuple = new RA2bNtuple(t);
  skim<RA2bNtuple> *skimBase = new skim<RA2bNtuple>(ntuple); 
  skim<RA2bNtuple> *skimLdP = new skim<RA2bNtuple>(ntuple); 
  skim<RA2bNtuple> *skim1L = new skim<RA2bNtuple>(ntuple); 
  selectBaseline<RA2bNtuple> *selectBase = new selectBaseline<RA2bNtuple>(ntuple);
  selectLowDphiCR<RA2bNtuple> *selectLdP = new selectLowDphiCR<RA2bNtuple>(ntuple);
  selectLeptonCR<RA2bNtuple> *select1L = new selectLeptonCR<RA2bNtuple>(ntuple);

  analyzer<RA2bNtuple> a(ntuple);
  weightProducer<RA2bNtuple> *wp = new weightProducer<RA2bNtuple>(ntuple,"Weight");

  for( int i = 0 ; i < t->GetEntries() ; i++ ){

    t->GetEntry(i);

    ntuple->patchJetID(); 

    if( selectBase->process() )
      skimBase->process();
    if( selectLdP->process() )
      skimLdP->process();
    if( select1L->process() )
      skim1L->process();

  }

  cout << "save tree" << endl;
  //wp->events->Write();
  //wp->xsections->Write();
  TFile* baselineFile = new TFile("signalRegionSkim_"+sample+".root","UPDATE");
  selectBase->histo->Write("baselineYields_"+sample);
  skimBase->skimTree->Write();
  baselineFile->Close();

  TFile* ldpFile = new TFile("lowDphiSkim_"+sample+".root","UPDATE");
  selectLdP->histo->Write("lowDphiYields_"+sample);
  skimLdP->skimTree->Write();
  ldpFile->Close();

  TFile* lepFile = new TFile("singleLepSkim_"+sample+".root","UPDATE");
  select1L->histo->Write("singleLepYields_"+sample);
  skim1L->skimTree->Write();
  lepFile->Close();

  delete ntuple;
  delete skimBase;
  delete selectBase;
  delete skimLdP;
  delete selectLdP;
  delete skim1L;
  delete select1L;

}  

