#include "TString.h"
#include "TChain.h"
#include "TFile.h"
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

TChain* buildChain(TString inputFileList, TString substr, TString treeName){

  string line;
  ifstream inputFile(inputFileList);

  TChain* t = new TChain(treeName);

  char temp[200];

  if( inputFile.is_open() ){

    while( getline( inputFile , line ) ){

      if( line.find(substr.Data()) == string::npos ) continue;

      sprintf( temp , "root://cmsxrootd.fnal.gov//%s", line.c_str() );
      t->Add( temp );

    }// end while loop over lines in file

  }// end is_open() if statement

  return t ;

}

