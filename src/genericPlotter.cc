#include "dissectingJetsMET.cc"
#include "selectBaseline.cc"
#include "fillHisto.cc"
#include "analyzer.cc"
#include "weightProducer.cc"

#include "TString.h"
#include "TChain.h"
#include "TFile.h"

#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "helpers.h"

using namespace std;

int main(int argc, char** argv){

  TString sample = argv[1];
  TChain* t = buildChain("slimFiles.txt",sample,"analysisTree");
  
  dissectingJetsMET *ntuple = new dissectingJetsMET(t);
  weightProducer<dissectingJetsMET> *weightProd = new weightProducer<dissectingJetsMET>(ntuple,sample);
  selectBaseline<dissectingJetsMET> *select = new selectBaseline<dissectingJetsMET>(ntuple);
  
  analyzer<dissectingJetsMET> a(ntuple);
  a.addProcessor( select );

  fillHisto<dissectingJetsMET> *fillHT = new fillHisto<dissectingJetsMET>(ntuple,200,500,2500,sample,"HT",weightProd);   a.addProcessor( fillHT );
  fillHisto<dissectingJetsMET> *fillMHT = new fillHisto<dissectingJetsMET>(ntuple,200,200,1000,sample,"MHT",weightProd); a.addProcessor( fillMHT );
  fillHisto<dissectingJetsMET> *fillMET = new fillHisto<dissectingJetsMET>(ntuple,200,200,1000,sample,"MET",weightProd); a.addProcessor( fillMET );
  fillHisto<dissectingJetsMET> *fillmT2 = new fillHisto<dissectingJetsMET>(ntuple,200,200,2500,sample,"mT2",weightProd); a.addProcessor( fillmT2 );
  fillHisto<dissectingJetsMET> *fillalphaT = new fillHisto<dissectingJetsMET>(ntuple,200,0,2,sample,"alphaT",weightProd); a.addProcessor( fillalphaT );
  fillHisto<dissectingJetsMET> *fillmRazor = new fillHisto<dissectingJetsMET>(ntuple,200,200,4000,sample,"mRazor",weightProd); a.addProcessor( fillmRazor );
  fillHisto<dissectingJetsMET> *filldRazor = new fillHisto<dissectingJetsMET>(ntuple,200,0,1,sample,"dRazor",weightProd); a.addProcessor( filldRazor );
  fillHisto<dissectingJetsMET> *fillmEff = new fillHisto<dissectingJetsMET>(ntuple,200,400,4000,sample,"mEff",weightProd); a.addProcessor( fillmEff );
  fillHisto<dissectingJetsMET> *fillNJets = new fillHisto<dissectingJetsMET>(ntuple,11,-0.5,10.5,sample,"NJets",weightProd); a.addProcessor( fillNJets );
  fillHisto<dissectingJetsMET> *fillNLeptons = new fillHisto<dissectingJetsMET>(ntuple,4,-0.5,3.5,sample,"NLeptons",weightProd); a.addProcessor( fillNLeptons );
  fillHisto<dissectingJetsMET> *filldPhi = new fillHisto<dissectingJetsMET>(ntuple,20,0.,3.1415,sample,"dPhi",weightProd); a.addProcessor( filldPhi );
  fillHisto<dissectingJetsMET> *filldEta = new fillHisto<dissectingJetsMET>(ntuple,20,0.,5.,sample,"dEta",weightProd); a.addProcessor( filldEta );
  fillHisto<dissectingJetsMET> *fillsumJetMass = new fillHisto<dissectingJetsMET>(ntuple,200,100.,1000.,sample,"sumJetMass",weightProd); a.addProcessor( fillsumJetMass );
  fillHisto<dissectingJetsMET> *fillleadJetPt = new fillHisto<dissectingJetsMET>(ntuple,200,30,500,sample,"leadJetPt",weightProd); a.addProcessor( fillleadJetPt );

  a.looper();

  TFile* outFile = new TFile("genericPlotter_"+sample+".root","UPDATE");
  /*
  for( unsigned int iProc = 0 ; iProc < a.processorList.size() ; iProc++ ){
    if( filler<dissectingJetsMET>* myFiller = dynamic_cast<filler<dissectingJetsMET>* >( a.processorList[iProc] ) ){
      myFiller->histo->Write();
    }
  }
  */

  fillHT->histo->Write();
  fillMHT->histo->Write();
  fillMET->histo->Write();
  fillmT2->histo->Write();
  fillalphaT->histo->Write();
  fillmRazor->histo->Write();
  filldRazor->histo->Write();
  fillmEff->histo->Write();
  fillNJets->histo->Write();
  fillNLeptons->histo->Write();
  filldPhi->histo->Write();
  filldEta->histo->Write();
  fillsumJetMass->histo->Write();
  fillleadJetPt->histo->Write();

  select->histo->Write("baselineYields_"+sample);
  outFile->Close();

}  

