#include "RA2bNtuple.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
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
  
  //TChain* t = new TChain("TreeMaker2/PreSelection");
  //t->Add("Spring15v2.ZJetsToNuNu_HT-600ToInf_13TeV-madgraph_1_RA2AnalysisTree.root");

  cout << "RA2bNtuple" << endl;
  RA2bNtuple *ntuple = new RA2bNtuple(t);
  cout << "skim" << endl;
  skim<RA2bNtuple> *skimmer = new skim<RA2bNtuple>(ntuple); 
  cout << "selectBaseline" << endl;
  selectBaseline<RA2bNtuple> *select = new selectBaseline<RA2bNtuple>(ntuple);
  cout << "analyzer" << endl;
  analyzer<RA2bNtuple> a(ntuple);
  cout << "weightProducer" << endl;
  weightProducer<RA2bNtuple> *wp = new weightProducer<RA2bNtuple>(ntuple,"Weight");
  a.addProcessor( wp );
  a.addProcessor( select );
  a.addProcessor( skimmer );
  
  cout << "loop" << endl;
  a.looper();

  cout << "save tree" << endl;
  TFile* outFile = new TFile("signalRegionSkim_"+sample+".root","UPDATE");

  skimmer->skimTree->Write();
  wp->events->Write();
  wp->xsections->Write();
  select->histo->Write("baselineYields_"+sample);
  outFile->Close();

  delete ntuple;
  delete skimmer;
  delete select;

}  

