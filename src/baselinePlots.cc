#include "RA2bNtuple.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
#include "fillHisto.cc"
#include "skim.cc"
#include "weightProducer.cc"
#include "producer.h"
#include "jetIDpatch.cc"

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
  TChain* t = buildChain("skimInput.txt",sample,"PreSelection");

  RA2bNtuple *ntuple = new RA2bNtuple(t);
  weightProducer<RA2bNtuple> *wp = new weightProducer<RA2bNtuple>(ntuple,"Weight",10.);
  jetIDpatch<RA2bNtuple> *patch = new jetIDpatch<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> *HThisto = new fillHisto<RA2bNtuple>(ntuple,20,500,1500,sample+"_HT","HT",wp);
  fillHisto<RA2bNtuple> *MHThisto = new fillHisto<RA2bNtuple>(ntuple,20,0,1000,sample+"_MHT","MHT",wp);
  fillHisto<RA2bNtuple> *NJetshisto = new fillHisto<RA2bNtuple>(ntuple,7,3.5,10.5,sample+"_NJets","NJets",wp);
  fillHisto<RA2bNtuple> *BTagshisto = new fillHisto<RA2bNtuple>(ntuple,5,-0.5,4.5,sample+"_BTags","BTags",wp);

  analyzer<RA2bNtuple> a(ntuple);

  a.addProcessor( patch );
  a.addProcessor( wp );
  a.addProcessor( HThisto );
  a.addProcessor( MHThisto );
  a.addProcessor( NJetshisto );
  a.addProcessor( BTagshisto );

  cout << "loop" << endl;
  a.looper();

  cout << "save tree" << endl;
  TFile* outFile = new TFile("baselinePlots_"+sample+".root","UPDATE");


  HThisto->histo->Write();
  MHThisto->histo->Write();
  NJetshisto->histo->Write();
  BTagshisto->histo->Write();

  outFile->Close();

  delete ntuple;
  delete wp; 
  delete patch;
  delete HThisto;
  delete MHThisto;
  delete NJetshisto;
  delete BTagshisto;

}
