#include "RA2bNtuple.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
#include "fillHisto.cc"
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
  TChain* t = buildChain("inputSkimFiles.txt",sample,"TreeMaker2/PreSelection");

  cout << "RA2bNtuple" << endl;
  RA2bNtuple *ntuple = new RA2bNtuple(t);
  cout << "weights" << endl;
  weightProducer<RA2bNtuple> *wp = new weightProducer<RA2bNtuple>(t,"Weight",10.);
  cout << "plot histo" << endl;
  fillHisto<RA2bNtuple> *HThisto = new fillHisto<RA2bNtuple>(t,20,500,1500,sample+"_HT","HT",wp);
  fillHisto<RA2bNtuple> *MHThisto = new fillHisto<RA2bNtuple>(t,20,0,1000,sample+"_MHT","MHT",wp);
  fillHisto<RA2bNtuple> *NJetshisto = new fillHisto<RA2bNtuple>(t,6,3.5,10.5,sample+"_NJets","NJets",wp);
  fillHisto<RA2bNtuple> *BTagshisto = new fillHisto<RA2bNtuple>(t,4,-0.5,2.5,sample+"_BTags","BTags",wp);
  cout << "analyzer" << endl;
  analyzer<RA2bNtuple> a<RA2bNtuple>(ntuple);
  a.addProcessor( wp );
  a.addProcessor( HThisto );
  a.addProcessor( MHThisto );
  a.addProcessor( NJetshisto );
  a.addProcessor( BTagshisto );

  cout << "loop" << endl;
  a.looper();

  cout << "save tree" << endl;
  TFile* outFile = new TFile("signalRegionSkim_"+sample+".root","UPDATE");

  skimmer->skimTree->Write();

  select->histo->Write("baselineYields_"+sample);
  outFile->Close();

  HThisto->histo->Write();
  MHThisto->histo->Write();
  NJetshisto->histo->Write();
  BTagshisto->histo->Write();

  delete ntuple;
  delete HThisto;
  delete MHThisto;
  delete NJetshisto;
  delete BTagshisto;

}
