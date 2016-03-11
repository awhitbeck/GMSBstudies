#ifndef SKIM
#define SKIM

template <class TreeType> class skim : public processor<TreeType> {

public : 

  TreeType *ntuple ; 
  TTree* skimTree;
  
  skim()
    : processor<TreeType>("skim")
  { 
    ntuple=0; skimTree=0 ;
  };
  skim( TreeType* ntuple_ )
    : processor<TreeType>("skim")
  {
    ntuple = ntuple_ ;
    skimTree = ntuple->fChain->CloneTree(0);
  };

  // purely virtual method to be implement by children
  virtual bool process( ) override{

    skimTree->Fill();
    return true;
    
  };

};

#endif
