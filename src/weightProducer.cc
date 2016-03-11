#ifndef WEIGHTPRODUCER
#define WEIGHTPRODUCER

#include "processor.h"
#include <iostream>
#include <string>
#include <map>
#include <cassert>

#include "TLeaf.h"
#include "TString.h"

using namespace std;

template <class TreeType> class weightProducer : public processor<TreeType> {

public : 

  TString weightBranch;
  double weight;
  double lumi;
  TreeType* ntuple;
  std::map<double,double> gluinoXsec;
  TH2F* events = new TH2F("events","events",161,797.5,1602.5,320,-2.5,1602.5);
  TH2F* xsections = new TH2F("xsections","xsections",161,797.5,1602.5,320,-2.5,1602.5);

  weightProducer():processor<TreeType>("weightProducer"){
    ntuple = 0;
    weightBranch = "";
    weight = -999.;
    
  };

  weightProducer( TreeType* ntuple_ , 
		  TString weightBranch_ ,
		  double lumi_ = 10.):processor<TreeType>("weightProducer"){

    ntuple = ntuple_;
    weightBranch = weightBranch_;
    weight = -999.;
    lumi = lumi_;
    
    // information for computing weights:
    // w = gluinoXsec*Y/eventsSim [weight for 1 pb]
    gluinoXsec[1495] = 0.0146102;
    gluinoXsec[1500] = 0.0141903;
    gluinoXsec[1505] = 0.01377;	   
    gluinoXsec[1510] = 0.0133923;  
    gluinoXsec[1515] = 0.0130286;  
    gluinoXsec[1520] = 0.012649;   
    gluinoXsec[1525] = 0.0123374;  
    gluinoXsec[1530] = 0.0119628;  
    gluinoXsec[1535] = 0.0116378;  
    gluinoXsec[1540] = 0.0113183;  
    gluinoXsec[1545] = 0.0110039;  
    gluinoXsec[1550] = 0.0107027;  
    gluinoXsec[1555] = 0.0103967;  
    gluinoXsec[1560] = 0.0101149;  
    gluinoXsec[1565] = 0.00984079; 
    gluinoXsec[1570] = 0.00956216; 
    gluinoXsec[1575] = 0.00930893; 
    gluinoXsec[1580] = 0.00905112; 
    gluinoXsec[1585] = 0.00880102; 
    gluinoXsec[1590] = 0.00856388; 
    gluinoXsec[1595] = 0.00832287; 
    gluinoXsec[1600] = 0.00810078; 

    ntuple->fChain->SetBranchStatus(weightBranch.Data(),1);
    if( ntuple->fChain->GetLeaf(weightBranch.Data()) == NULL )
      std::cout << "weightProducer couldn't find branch: " << weightBranch << std::endl;

  };

  bool process( ) override {

    int SusyLSPMass;
    int SusyMotherMass;
    
    try{
      if( ntuple->fChain->GetLeaf("SusyMotherMass") == NULL )
	throw "SusyMotherMass";
      if( ntuple->fChain->GetLeaf("SusyLSPMass") == NULL )
	throw "SusyLSPMass";
      if( ntuple->fChain->GetLeaf( weightBranch.Data() ) == NULL )
	throw weightBranch.Data();
  
      SusyLSPMass = ntuple->fChain->GetLeaf("SusyLSPMass")->GetValue();
      SusyMotherMass = ntuple->fChain->GetLeaf("SusyMotherMass")->GetValue();

      if( SusyLSPMass == 0 && SusyMotherMass == 0 )  
	weight = ntuple->fChain->GetLeaf( weightBranch.Data() )->GetValue()*lumi;
      else{ 	
	if( gluinoXsec.find( ntuple->fChain->GetLeaf("SusyMotherMass")->GetValue() ) == gluinoXsec.end() ){
	  throw SusyMotherMass;
	  weight = 1.;
	}
      }
    }catch( char* branch ){
      std::cout << "Branch not found: " << branch << std::endl;
      assert(0);
    }catch( int mass ){
      std::cout << "Cross section of SusyMotherMass="<< mass << " not found." << std::endl;
      std::cout << "    Setting cross section to 1/pb." << std::endl;
    }

    events->Fill(SusyMotherMass,SusyLSPMass);
    xsections->SetBinContent(xsections->FindBin(SusyMotherMass,SusyLSPMass),gluinoXsec[SusyMotherMass]);
    
    return true;

  };

};

#endif
