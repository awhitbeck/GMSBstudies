#ifndef WEIGHTPRODUCERNEW
#define WEIGHTPRODUCERNEW

#include "producer.h"
#include <map>
#include <cassert>

template <class TreeType> class weightProducerNew : public producer<TreeType> {

public : 
	
	TreeType *ntuple ; 
	TTree* newTree ;
	std::map<double,double> gluinoXsec;
	
	weightProducerNew(){
    	ntuple = 0;
	};
	weightProducerNew(TreeType* ntuple_){
	  ntuple = ntuple_;
	  newTree = ntuple->fChain->CloneTree(0);
	  
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
		
	};

	bool process() override {
	  ntuple->Weight = 3.1415;
	  newTree->Fill();
	};

	void postProcess() override{
	  newTree->Write();
	}

};

#endif
