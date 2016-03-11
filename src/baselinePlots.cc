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
  RA2bNtuple *ntuple_old = new RA2bNtuple(t);
  cout << "patch ctor" << endl;
  jetIDpatch<RA2bNtuple> *patch = new jetIDpatch<RA2bNtuple>(ntuple_old);  
  RA2bNtuple *ntuple = new RA2bNtuple(patch->newTree);

  // all producers should be given the same input tree and should 
  // put all new information into the same output tree.  This is 
  // just begging for a class to manage all of the producers, but 
  // I am not entirely sure about all fo the details, yet.

  // need to make an RA2bNtuple object out of the result of the 
  // producer which will be passed to all of the fillers. 

  cout << "wp & fillers ctors" << endl;
  // need a way to calculate weights differently for signal and background... I think
  weightProducer<RA2bNtuple> *wp = new weightProducer<RA2bNtuple>(ntuple,"Weight",10000.);
  fillHisto<RA2bNtuple> *HThisto = new fillHisto<RA2bNtuple>(ntuple,20,500,1500,sample+"_HT","HT",wp);
  fillHisto<RA2bNtuple> *MHThisto = new fillHisto<RA2bNtuple>(ntuple,20,0,1000,sample+"_MHT","MHT",wp);
  //fillHisto<RA2bNtuple> *MHToldhisto = new fillHisto<RA2bNtuple>(ntuple_old,20,0,1000,sample+"_MHTold","MHTold",wp);
  fillHisto<RA2bNtuple> *NJetshisto = new fillHisto<RA2bNtuple>(ntuple,7,3.5,10.5,sample+"_NJets","NJets",wp);
  fillHisto<RA2bNtuple> *BTagshisto = new fillHisto<RA2bNtuple>(ntuple,5,-0.5,4.5,sample+"_BTags","BTags",wp);

  analyzer<RA2bNtuple> a(ntuple);
  a.setReportEvery(10000);

  a.addProcessor( HThisto );
  a.addProcessor( MHThisto );
  //a.addProcessor( MHToldhisto );
  a.addProcessor( NJetshisto );
  a.addProcessor( BTagshisto );

  ntuple_old->setStatus(true);
  ntuple->setStatus(true);

  cout << "loop" << endl;
  //a.looper();

  // loop over events in old tree
  int numEvents = ntuple_old->fChain->GetEntries();

  for( int iEvt = 0 ; iEvt < numEvents ; iEvt++ ){

    // get entry in old tree, compute new vars, 
    // fill new vars into new tree and get entry 
    // for new tree

    ntuple_old->fChain->GetEntry(iEvt);
    patch->process();
    ntuple->fChain->GetEntry(iEvt);
    if( iEvt % a.reportEvery == 0 ) cout << "Event " << iEvt << "/" << numEvents << endl;
    
    // loop over all processors                
    for( unsigned int iProc = 0 ; iProc < a.processorList.size() ; iProc++ ){
      //cout << a.processorList->at(iProc)->getModuleName() << endl;      
      if( ! a.processorList[iProc]->process() ){
	//cout << "false" << endl;   
	break;
      }
    }// end loop over processors 

    /*
    wp->process();
    HThisto->process();
    MHThisto->process();
    NJetshisto->process();
    BTagshisto->process();
    */
  }// end loop over events     

  cout << "save tree" << endl;
  TFile* outFile = new TFile("baselinePlots_"+sample+".root","UPDATE");

  HThisto->histo->Write();
  MHThisto->histo->Write();
  //MHToldhisto->histo->Write();
  NJetshisto->histo->Write();
  BTagshisto->histo->Write();

  outFile->Close();

  delete ntuple_old;
  delete ntuple;
  delete wp; 
  delete patch;
  delete HThisto;
  delete MHThisto;
  delete NJetshisto;
  delete BTagshisto;

}
