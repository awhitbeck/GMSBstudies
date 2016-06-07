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
  
  RA2bNtuple *ntuple = new RA2bNtuple(t);

  selectBaseline<RA2bNtuple> *select = new selectBaseline<RA2bNtuple>(ntuple,"");

  TTree* outputTree = ntuple->fChain->CloneTree(0);

  for( int i = 0 ; i < t->GetEntries() ; i++ ){
    t->GetEntry(i);
    if( select->process() )
      outputTree->Fill();
  }

  cout << "save tree" << endl;
  TFile* outFile = new TFile("signalRegionSkim_"+sample+".root","UPDATE");
  outputTree->Write();
  outFile->Close();

  delete ntuple;
  delete select;

}  

