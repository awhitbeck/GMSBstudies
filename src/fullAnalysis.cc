#include "RA2bNtuple.cc"
#include "analyzer.cc"
#include "selectBaseline.cc"
#include "selectLowDphiCR.cc"
#include "selectLeptonCR.cc"
#include "skim.cc"
#include "weightProducer.cc"
#include "fillHisto.cc"

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

  selectBaseline<RA2bNtuple> *selectBase = new selectBaseline<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> *SR_HThisto    = new fillHisto<RA2bNtuple>(ntuple,40,500,4000,sample+"_SR_HT","HT","Weight");
  fillHisto<RA2bNtuple> *SR_MHThisto   = new fillHisto<RA2bNtuple>(ntuple,40,0,2000,sample+"_SR_MHT","MHT","Weight");
  fillHisto<RA2bNtuple> *SR_NJetshisto = new fillHisto<RA2bNtuple>(ntuple,12,3.5,15.5,sample+"_SR_NJets","NJets","Weight");
  fillHisto<RA2bNtuple> *SR_BTagshisto = new fillHisto<RA2bNtuple>(ntuple,20,500,1500,sample+"_SR_BTags","BTags","Weight");
  analyzer<RA2bNtuple> SR(ntuple,5);
  SR.addProcessor(selectBase);
  SR.addProcessor(SR_HThisto);
  SR.addProcessor(SR_MHThisto);
  SR.addProcessor(SR_NJetshisto);
  SR.addProcessor(SR_BTagshisto);

  cout << "done with SR" << endl;

  selectLowDphiCR<RA2bNtuple> *selectLdP = new selectLowDphiCR<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> *ldpCR_HThisto = new fillHisto<RA2bNtuple>(*SR_HThisto) ; 
  ldpCR_HThisto->histo->SetNameTitle(sample + "_ldpCR_HT",sample + "_ldpCR_HT");		
  fillHisto<RA2bNtuple> *ldpCR_MHThisto = new fillHisto<RA2bNtuple>(*SR_MHThisto)   ; 
  ldpCR_MHThisto->histo->SetNameTitle(sample + "_ldpCR_MHT",sample + "_ldpCR_MHT");
  fillHisto<RA2bNtuple> *ldpCR_NJetshisto = new fillHisto<RA2bNtuple>(*SR_NJetshisto) ;
  ldpCR_NJetshisto->histo->SetNameTitle(sample + "_ldpCR_NJets",sample + "_ldpCR_NJets");
  fillHisto<RA2bNtuple> *ldpCR_BTagshisto = new fillHisto<RA2bNtuple>(*SR_BTagshisto) ; 
  ldpCR_BTagshisto->histo->SetNameTitle(sample + "_ldpCR_BTags",sample + "_ldpCR_BTags");
  analyzer<RA2bNtuple> ldpCR(ntuple,5);
  ldpCR.addProcessor(selectBase);
  ldpCR.addProcessor(ldpCR_HThisto);
  ldpCR.addProcessor(ldpCR_MHThisto);
  ldpCR.addProcessor(ldpCR_NJetshisto);
  ldpCR.addProcessor(ldpCR_BTagshisto);

  cout << "done with ldpCR" << endl;

  selectLeptonCR<RA2bNtuple> *select1L = new selectLeptonCR<RA2bNtuple>(ntuple);
  fillHisto<RA2bNtuple> *lepCR_HThisto = new fillHisto<RA2bNtuple>(*SR_HThisto) ;
  lepCR_HThisto->histo->SetNameTitle(sample + "_lepCR_HT",sample + "_lepCR_HT");		
  fillHisto<RA2bNtuple> *lepCR_MHThisto = new fillHisto<RA2bNtuple>(*SR_MHThisto) ; 
  lepCR_MHThisto->histo->SetNameTitle(sample + "_lepCR_MHT",sample + "_lepCR_MHT");		
  fillHisto<RA2bNtuple> *lepCR_NJetshisto = new fillHisto<RA2bNtuple>(*SR_NJetshisto) ; 
  lepCR_NJetshisto->histo->SetNameTitle(sample + "_lepCR_NJets",sample + "_lepCR_NJets");
  fillHisto<RA2bNtuple> *lepCR_BTagshisto = new fillHisto<RA2bNtuple>(*SR_BTagshisto) ; 
  lepCR_BTagshisto->histo->SetNameTitle(sample + "_lepCR_BTags",sample + "_lepCR_BTags");
  analyzer<RA2bNtuple> lepCR(ntuple,5);
  lepCR.addProcessor(selectBase);
  lepCR.addProcessor(lepCR_HThisto);
  lepCR.addProcessor(lepCR_MHThisto);
  lepCR.addProcessor(lepCR_NJetshisto);
  lepCR.addProcessor(lepCR_BTagshisto);

  cout << "done with lepCR" << endl;

  for( int i = 0 ; i < t->GetEntries() ; i++ ){

    t->GetEntry(i);
    //cout << "event: " << i << endl;
    for( unsigned int iProc = 0 ; iProc < SR.processorList->size() ; iProc++){
      //cout << "SR proc: " << iProc << endl;
      if( ! SR.processorList->at(iProc) ) break;
    }
    for( unsigned int iProc = 0 ; iProc < ldpCR.processorList->size() ; iProc++){
      //cout << "ldpCR proc: " << iProc << endl;
      if( ! ldpCR.processorList->at(iProc) ) break;
    }
    for( unsigned int iProc = 0 ; iProc < lepCR.processorList->size() ; iProc++){
      //cout << "lepCR proc: " << iProc << endl;
      if( ! lepCR.processorList->at(iProc) ) break;
    }
  }

  cout << "save tree" << endl;

  TFile* outFile = new TFile("fullAnalysis_"+sample+".root","UPDATE");
  selectBase->histo->Write("baselineYields_"+sample);
  selectLdP->histo->Write("lowDphiYields_"+sample);
  select1L->histo->Write("singleLepYields_"+sample);
  SR_HThisto->histo->Write();      
  SR_MHThisto->histo->Write();  	  
  SR_NJetshisto->histo->Write();	  
  SR_BTagshisto->histo->Write();	  
  ldpCR_HThisto->histo->Write();   
  ldpCR_MHThisto->histo->Write();  
  ldpCR_NJetshisto->histo->Write();
  ldpCR_BTagshisto->histo->Write();
  lepCR_HThisto->histo->Write();	  
  lepCR_MHThisto->histo->Write();  
  lepCR_NJetshisto->histo->Write();
  lepCR_BTagshisto->histo->Write();

  outFile->Close();

  delete ntuple;
  delete selectLdP;
  delete select1L;
  delete SR_HThisto;      
  delete SR_MHThisto;  	  
  delete SR_NJetshisto;	  
  delete SR_BTagshisto;	  
  delete ldpCR_HThisto;   
  delete ldpCR_MHThisto;  
  delete ldpCR_NJetshisto;
  delete ldpCR_BTagshisto;
  delete lepCR_HThisto;	  
  delete lepCR_MHThisto;  
  delete lepCR_NJetshisto;
  delete lepCR_BTagshisto;

}  

