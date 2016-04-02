//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Mar 21 22:05:40 2016 by ROOT version 6.02/05
// from TTree PreSelection/PreSelection
// found on file: root://cmsxrootd.fnal.gov//store/user/awhitbe1/SMS-T5Wg_RA2bNtuples/Spring15Fastv2.SMS-T5Wg_mGl-800to1000_mNLSP-0to950_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_91_RA2AnalysisTree.root
//////////////////////////////////////////////////////////

#ifndef RA2bNtuple_h
#define RA2bNtuple_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <iostream>
#include <vector>
#include "TLorentzVector.h"

using namespace std;

class RA2bNtuple {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   vector<TString> branchMask;

   // Declaration of leaf types
   UInt_t          RunNum;
   UInt_t          LumiBlockNum;
   ULong64_t       EvtNum;
   Int_t           BTags;
   Int_t           BTagsclean;
   Int_t           BTagsJECdown;
   Int_t           BTagsJECup;
   Double_t        CaloMETPhi;
   Double_t        CaloMETPt;
   Double_t        CrossSection;
   Double_t        DeltaPhi1;
   Double_t        DeltaPhi1clean;
   Double_t        DeltaPhi1JECdown;
   Double_t        DeltaPhi1JECup;
   Double_t        DeltaPhi2;
   Double_t        DeltaPhi2clean;
   Double_t        DeltaPhi2JECdown;
   Double_t        DeltaPhi2JECup;
   Double_t        DeltaPhi3;
   Double_t        DeltaPhi3clean;
   Double_t        DeltaPhi3JECdown;
   Double_t        DeltaPhi3JECup;
   Double_t        DeltaPhi4;
   Double_t        DeltaPhi4clean;
   Double_t        DeltaPhi4JECdown;
   Double_t        DeltaPhi4JECup;
   vector<int>     *ElectronCharge;
   vector<TLorentzVector> *Electrons;
   vector<double>  *GenDeltaPhi;
   vector<int>     *GenElec_GenElecFromTau;
   vector<double>  *GenElec_MT2Activity;
   vector<double>  *GenElec_RecoTrkAct;
   vector<double>  *GenElec_RecoTrkd3;
   vector<double>  *GenElec_RecoTrkIso;
   vector<TLorentzVector> *GenEls;
   Double_t        genHT;
   vector<TLorentzVector> *GenJets;
   vector<double>  *GenJets_invisibleEnergy;
   Double_t        GenMETPhi;
   Double_t        GenMETPt;
   Double_t        GenMHT;
   Double_t        GenMHT_Phi;
   vector<double>  *GenMinDeltaPhiEta24;
   vector<double>  *GenMinDeltaPhiEta5;
   vector<int>     *GenMinDeltaPhiIndexEta24;
   vector<int>     *GenMinDeltaPhiIndexEta5;
   vector<int>     *GenMu_GenMuFromTau;
   vector<double>  *GenMu_MT2Activity;
   vector<double>  *GenMu_RecoTrkAct;
   vector<double>  *GenMu_RecoTrkd3;
   vector<double>  *GenMu_RecoTrkIso;
   vector<TLorentzVector> *GenMus;
   vector<TLorentzVector> *GenParticles;
   vector<int>     *GenParticles_ParentId;
   vector<int>     *GenParticles_ParentIdx;
   vector<int>     *GenParticles_PdgId;
   vector<int>     *GenParticles_Status;
   vector<int>     *GenTau_GenTauHad;
   vector<double>  *GenTau_MT2Activity;
   vector<double>  *GenTauLeadRecoTrkAct;
   vector<double>  *GenTauLeadRecoTrkd3;
   vector<double>  *GenTauLeadRecoTrkIso;
   vector<TLorentzVector> *GenTauLeadTrk;
   vector<TLorentzVector> *GenTauNu;
   vector<TLorentzVector> *GenTaus;
   Double_t        HT;
   Double_t        HTclean;
   Double_t        HTJECdown;
   Double_t        HTJECup;
   vector<bool>    *HTJetsMask;
   vector<bool>    *HTJetsMaskclean;
   vector<bool>    *HTJetsMaskJECdown;
   vector<bool>    *HTJetsMaskJECup;
   Int_t           isoElectronTracks;
   Int_t           isoElectronTracksclean;
   vector<TLorentzVector> *IsolatedElectronTracksVeto;
   vector<TLorentzVector> *IsolatedMuonTracksVeto;
   vector<TLorentzVector> *IsolatedPionTracksVeto;
   Int_t           isoMuonTracks;
   Int_t           isoMuonTracksclean;
   Int_t           isoPionTracks;
   Int_t           isoPionTracksclean;
   Bool_t          JetID;
   Bool_t          JetIDclean;
   Bool_t          JetIDJECdown;
   Bool_t          JetIDJECup;
   vector<TLorentzVector> *Jets;
   vector<double>  *Jets_bDiscriminatorCSV;
   vector<double>  *Jets_bDiscriminatorMVA;
   vector<double>  *Jets_chargedEmEnergyFraction;
   vector<double>  *Jets_chargedHadronEnergyFraction;
   vector<int>     *Jets_chargedHadronMultiplicity;
   vector<int>     *Jets_chargedMultiplicity;
   vector<int>     *Jets_electronMultiplicity;
   vector<int>     *Jets_hadronFlavor;
   vector<bool>    *Jets_ID;
   vector<double>  *Jets_jecFactor;
   vector<double>  *Jets_jecUnc;
   vector<double>  *Jets_jetArea;
   vector<double>  *Jets_muonEnergyFraction;
   vector<int>     *Jets_muonMultiplicity;
   vector<double>  *Jets_neutralEmEnergyFraction;
   vector<double>  *Jets_neutralHadronEnergyFraction;
   vector<int>     *Jets_neutralHadronMultiplicity;
   vector<int>     *Jets_neutralMultiplicity;
   vector<int>     *Jets_partonFlavor;
   vector<double>  *Jets_photonEnergyFraction;
   vector<int>     *Jets_photonMultiplicity;
   vector<double>  *Jets_qgLikelihood;
   vector<TLorentzVector> *JetsAK8;
   vector<double>  *JetsAK8_bDiscriminatorSubjet1CSV;
   vector<double>  *JetsAK8_bDiscriminatorSubjet2CSV;
   vector<double>  *JetsAK8_NsubjettinessTau1;
   vector<double>  *JetsAK8_NsubjettinessTau2;
   vector<double>  *JetsAK8_NsubjettinessTau3;
   vector<double>  *JetsAK8_prunedMass;
   vector<TLorentzVector> *Jetsclean;
   vector<double>  *Jetsclean_bDiscriminatorCSV;
   vector<int>     *Jetsclean_hadronFlavor;
   vector<bool>    *Jetsclean_ID;
   vector<int>     *Jetsclean_partonFlavor;
   vector<TLorentzVector> *JetsJECdown;
   vector<double>  *JetsJECdown_bDiscriminatorCSV;
   vector<int>     *JetsJECdown_hadronFlavor;
   vector<bool>    *JetsJECdown_ID;
   vector<int>     *JetsJECdown_partonFlavor;
   vector<TLorentzVector> *JetsJECup;
   vector<double>  *JetsJECup_bDiscriminatorCSV;
   vector<int>     *JetsJECup_hadronFlavor;
   vector<bool>    *JetsJECup_ID;
   vector<int>     *JetsJECup_partonFlavor;
   Int_t           Leptons;
   Double_t        METPhi;
   Double_t        METPhiclean;
   vector<double>  *METPhiDown;
   vector<double>  *METPhiUp;
   Double_t        METPt;
   Double_t        METPtclean;
   vector<double>  *METPtDown;
   vector<double>  *METPtUp;
   Double_t        MHT;
   Double_t        MHT_Phi;
   Double_t        MHT_Phiclean;
   Double_t        MHT_PhiJECdown;
   Double_t        MHT_PhiJECup;
   Double_t        MHTclean;
   Double_t        MHTJECdown;
   Double_t        MHTJECup;
   vector<bool>    *MHTJetsMask;
   vector<bool>    *MHTJetsMaskclean;
   vector<bool>    *MHTJetsMaskJECdown;
   vector<bool>    *MHTJetsMaskJECup;
   vector<string>  *minDeltaPhiNames;
   Double_t        MT2;
   vector<int>     *MuonCharge;
   vector<TLorentzVector> *Muons;
   Int_t           nAllVertices;
   vector<TLorentzVector> *NeutrinoLorentzVector;
   vector<int>     *NeutrinoMotherPdg;
   vector<int>     *NeutrinoPdg;
   Int_t           NJets;
   Int_t           NJetsclean;
   Int_t           NJetsJECdown;
   Int_t           NJetsJECup;
   Int_t           nTAPElectronTracks;
   Int_t           nTAPMuonTracks;
   Int_t           nTAPPionTracks;
   Double_t        NumEvents;
   Int_t           NumPhotons;
   Int_t           NumInteractions;
   Int_t           NVtx;
   vector<int>     *PDFids;
   vector<double>  *PDFweights;
   vector<double>  *photon_genMatched;
   vector<double>  *photon_hadTowOverEM;
   vector<double>  *photon_hasPixelSeed;
   vector<double>  *photon_isEB;
   vector<bool>    *photon_nonPrompt;
   vector<double>  *photon_passElectronVeto;
   vector<double>  *photon_pfChargedIso;
   vector<double>  *photon_pfChargedIsoRhoCorr;
   vector<double>  *photon_pfGammaIso;
   vector<double>  *photon_pfGammaIsoRhoCorr;
   vector<double>  *photon_pfNeutralIso;
   vector<double>  *photon_pfNeutralIsoRhoCorr;
   vector<double>  *photon_sigmaIetaIeta;
   vector<TLorentzVector> *Photons;
   vector<TLorentzVector> *bestPhoton;
   vector<int> *bestPhotonIndex;
   Double_t        puSysDown;
   Double_t        puSysUp;
   Double_t        puWeight;
   vector<double>  *RJetDeltaPhi;
   vector<double>  *RJetMinDeltaPhiEta24;
   vector<double>  *RJetMinDeltaPhiEta5;
   vector<int>     *RJetMinDeltaPhiIndexEta24;
   vector<int>     *RJetMinDeltaPhiIndexEta5;
   vector<double>  *ScaleWeights;
   vector<TLorentzVector> *selectedIDElectrons;
   vector<bool>    *selectedIDElectrons_mediumID;
   vector<double>  *selectedIDElectrons_MiniIso;
   vector<double>  *selectedIDElectrons_MT2Activity;
   vector<double>  *selectedIDElectrons_MTW;
   vector<bool>    *selectedIDIsoElectrons_mediumID;
   vector<double>  *selectedIDIsoElectrons_MT2Activity;
   vector<double>  *selectedIDIsoElectrons_MTW;
   vector<double>  *selectedIDIsoElectrons_PTW;
   vector<double>  *selectedIDIsoMuons_MT2Activity;
   vector<double>  *selectedIDIsoMuons_MTW;
   vector<double>  *selectedIDIsoMuons_PTW;
   vector<TLorentzVector> *selectedIDMuons;
   vector<double>  *selectedIDMuons_MiniIso;
   vector<double>  *selectedIDMuons_MT2Activity;
   vector<double>  *selectedIDMuons_MTW;
   vector<TLorentzVector> *slimJet;
   vector<double>  *slimJet_jecFactor;
   vector<double>  *slimJet_jecUnc;
   vector<bool>    *slimJet_slimJetID;
   vector<TLorentzVector> *slimJetJECdown;
   vector<bool>    *slimJetJECdown_slimJetID;
   vector<TLorentzVector> *slimJetJECup;
   vector<bool>    *slimJetJECup_slimJetID;
   Double_t        SusyLSPMass;
   Double_t        SusyMotherMass;
   Int_t           TagLeptonHighPT;
   vector<TLorentzVector> *TAPElectronTracks;
   vector<double>  *TAPElectronTracks_activity;
   vector<int>     *TAPElectronTracks_chg;
   vector<double>  *TAPElectronTracks_mT;
   vector<double>  *TAPElectronTracks_trkiso;
   vector<TLorentzVector> *TAPMuonTracks;
   vector<double>  *TAPMuonTracks_activity;
   vector<int>     *TAPMuonTracks_chg;
   vector<double>  *TAPMuonTracks_mT;
   vector<double>  *TAPMuonTracks_trkiso;
   vector<TLorentzVector> *TAPPionTracks;
   vector<double>  *TAPPionTracks_activity;
   vector<int>     *TAPPionTracks_chg;
   vector<double>  *TAPPionTracks_mT;
   vector<double>  *TAPPionTracks_trkiso;
   vector<TLorentzVector> *TauDecayCands;
   vector<int>     *TauDecayCands_momInd;
   vector<int>     *TauDecayCands_pdgID;
   vector<string>  *TriggerNames;
   vector<int>     *TriggerPass;
   vector<int>     *TriggerPrescales;
   Double_t        TrueNumInteractions;
   Double_t        Weight;
   vector<TLorentzVector> *ZCandidates;

   // List of branches
   TBranch        *b_RunNum;   //!
   TBranch        *b_LumiBlockNum;   //!
   TBranch        *b_EvtNum;   //!
   TBranch        *b_BTags;   //!
   TBranch        *b_BTagsclean;   //!
   TBranch        *b_BTagsJECdown;   //!
   TBranch        *b_BTagsJECup;   //!
   TBranch        *b_CaloMETPhi;   //!
   TBranch        *b_CaloMETPt;   //!
   TBranch        *b_CrossSection;   //!
   TBranch        *b_DeltaPhi1;   //!
   TBranch        *b_DeltaPhi1clean;   //!
   TBranch        *b_DeltaPhi1JECdown;   //!
   TBranch        *b_DeltaPhi1JECup;   //!
   TBranch        *b_DeltaPhi2;   //!
   TBranch        *b_DeltaPhi2clean;   //!
   TBranch        *b_DeltaPhi2JECdown;   //!
   TBranch        *b_DeltaPhi2JECup;   //!
   TBranch        *b_DeltaPhi3;   //!
   TBranch        *b_DeltaPhi3clean;   //!
   TBranch        *b_DeltaPhi3JECdown;   //!
   TBranch        *b_DeltaPhi3JECup;   //!
   TBranch        *b_DeltaPhi4;   //!
   TBranch        *b_DeltaPhi4clean;   //!
   TBranch        *b_DeltaPhi4JECdown;   //!
   TBranch        *b_DeltaPhi4JECup;   //!
   TBranch        *b_ElectronCharge;   //!
   TBranch        *b_Electrons;   //!
   TBranch        *b_GenDeltaPhi;   //!
   TBranch        *b_GenElec_GenElecFromTau;   //!
   TBranch        *b_GenElec_MT2Activity;   //!
   TBranch        *b_GenElec_RecoTrkAct;   //!
   TBranch        *b_GenElec_RecoTrkd3;   //!
   TBranch        *b_GenElec_RecoTrkIso;   //!
   TBranch        *b_GenEls;   //!
   TBranch        *b_genHT;   //!
   TBranch        *b_GenJets;   //!
   TBranch        *b_GenJets_invisibleEnergy;   //!
   TBranch        *b_GenMETPhi;   //!
   TBranch        *b_GenMETPt;   //!
   TBranch        *b_GenMHT;   //!
   TBranch        *b_GenMHT_Phi;   //!
   TBranch        *b_GenMinDeltaPhiEta24;   //!
   TBranch        *b_GenMinDeltaPhiEta5;   //!
   TBranch        *b_GenMinDeltaPhiIndexEta24;   //!
   TBranch        *b_GenMinDeltaPhiIndexEta5;   //!
   TBranch        *b_GenMu_GenMuFromTau;   //!
   TBranch        *b_GenMu_MT2Activity;   //!
   TBranch        *b_GenMu_RecoTrkAct;   //!
   TBranch        *b_GenMu_RecoTrkd3;   //!
   TBranch        *b_GenMu_RecoTrkIso;   //!
   TBranch        *b_GenMus;   //!
   TBranch        *b_GenParticles;   //!
   TBranch        *b_GenParticles_ParentId;   //!
   TBranch        *b_GenParticles_ParentIdx;   //!
   TBranch        *b_GenParticles_PdgId;   //!
   TBranch        *b_GenParticles_Status;   //!
   TBranch        *b_GenTau_GenTauHad;   //!
   TBranch        *b_GenTau_MT2Activity;   //!
   TBranch        *b_GenTauLeadRecoTrkAct;   //!
   TBranch        *b_GenTauLeadRecoTrkd3;   //!
   TBranch        *b_GenTauLeadRecoTrkIso;   //!
   TBranch        *b_GenTauLeadTrk;   //!
   TBranch        *b_GenTauNu;   //!
   TBranch        *b_GenTaus;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_HTclean;   //!
   TBranch        *b_HTJECdown;   //!
   TBranch        *b_HTJECup;   //!
   TBranch        *b_HTJetsMask;   //!
   TBranch        *b_HTJetsMaskclean;   //!
   TBranch        *b_HTJetsMaskJECdown;   //!
   TBranch        *b_HTJetsMaskJECup;   //!
   TBranch        *b_isoElectronTracks;   //!
   TBranch        *b_isoElectronTracksclean;   //!
   TBranch        *b_IsolatedElectronTracksVeto;   //!
   TBranch        *b_IsolatedMuonTracksVeto;   //!
   TBranch        *b_IsolatedPionTracksVeto;   //!
   TBranch        *b_isoMuonTracks;   //!
   TBranch        *b_isoMuonTracksclean;   //!
   TBranch        *b_isoPionTracks;   //!
   TBranch        *b_isoPionTracksclean;   //!
   TBranch        *b_JetID;   //!
   TBranch        *b_JetIDclean;   //!
   TBranch        *b_JetIDJECdown;   //!
   TBranch        *b_JetIDJECup;   //!
   TBranch        *b_Jets;   //!
   TBranch        *b_Jets_bDiscriminatorCSV;   //!
   TBranch        *b_Jets_bDiscriminatorMVA;   //!
   TBranch        *b_Jets_chargedEmEnergyFraction;   //!
   TBranch        *b_Jets_chargedHadronEnergyFraction;   //!
   TBranch        *b_Jets_chargedHadronMultiplicity;   //!
   TBranch        *b_Jets_chargedMultiplicity;   //!
   TBranch        *b_Jets_electronMultiplicity;   //!
   TBranch        *b_Jets_hadronFlavor;   //!
   TBranch        *b_Jets_ID;   //!
   TBranch        *b_Jets_jecFactor;   //!
   TBranch        *b_Jets_jecUnc;   //!
   TBranch        *b_Jets_jetArea;   //!
   TBranch        *b_Jets_muonEnergyFraction;   //!
   TBranch        *b_Jets_muonMultiplicity;   //!
   TBranch        *b_Jets_neutralEmEnergyFraction;   //!
   TBranch        *b_Jets_neutralHadronEnergyFraction;   //!
   TBranch        *b_Jets_neutralHadronMultiplicity;   //!
   TBranch        *b_Jets_neutralMultiplicity;   //!
   TBranch        *b_Jets_partonFlavor;   //!
   TBranch        *b_Jets_photonEnergyFraction;   //!
   TBranch        *b_Jets_photonMultiplicity;   //!
   TBranch        *b_Jets_qgLikelihood;   //!
   TBranch        *b_JetsAK8;   //!
   TBranch        *b_JetsAK8_bDiscriminatorSubjet1CSV;   //!
   TBranch        *b_JetsAK8_bDiscriminatorSubjet2CSV;   //!
   TBranch        *b_JetsAK8_NsubjettinessTau1;   //!
   TBranch        *b_JetsAK8_NsubjettinessTau2;   //!
   TBranch        *b_JetsAK8_NsubjettinessTau3;   //!
   TBranch        *b_JetsAK8_prunedMass;   //!
   TBranch        *b_Jetsclean;   //!
   TBranch        *b_Jetsclean_bDiscriminatorCSV;   //!
   TBranch        *b_Jetsclean_hadronFlavor;   //!
   TBranch        *b_Jetsclean_ID;   //!
   TBranch        *b_Jetsclean_partonFlavor;   //!
   TBranch        *b_JetsJECdown;   //!
   TBranch        *b_JetsJECdown_bDiscriminatorCSV;   //!
   TBranch        *b_JetsJECdown_hadronFlavor;   //!
   TBranch        *b_JetsJECdown_ID;   //!
   TBranch        *b_JetsJECdown_partonFlavor;   //!
   TBranch        *b_JetsJECup;   //!
   TBranch        *b_JetsJECup_bDiscriminatorCSV;   //!
   TBranch        *b_JetsJECup_hadronFlavor;   //!
   TBranch        *b_JetsJECup_ID;   //!
   TBranch        *b_JetsJECup_partonFlavor;   //!
   TBranch        *b_Leptons;   //!
   TBranch        *b_METPhi;   //!
   TBranch        *b_METPhiclean;   //!
   TBranch        *b_METPhiDown;   //!
   TBranch        *b_METPhiUp;   //!
   TBranch        *b_METPt;   //!
   TBranch        *b_METPtclean;   //!
   TBranch        *b_METPtDown;   //!
   TBranch        *b_METPtUp;   //!
   TBranch        *b_MHT;   //!
   TBranch        *b_MHT_Phi;   //!
   TBranch        *b_MHT_Phiclean;   //!
   TBranch        *b_MHT_PhiJECdown;   //!
   TBranch        *b_MHT_PhiJECup;   //!
   TBranch        *b_MHTclean;   //!
   TBranch        *b_MHTJECdown;   //!
   TBranch        *b_MHTJECup;   //!
   TBranch        *b_MHTJetsMask;   //!
   TBranch        *b_MHTJetsMaskclean;   //!
   TBranch        *b_MHTJetsMaskJECdown;   //!
   TBranch        *b_MHTJetsMaskJECup;   //!
   TBranch        *b_minDeltaPhiNames;   //!
   TBranch        *b_MT2;   //!
   TBranch        *b_MuonCharge;   //!
   TBranch        *b_Muons;   //!
   TBranch        *b_nAllVertices;   //!
   TBranch        *b_NeutrinoLorentzVector;   //!
   TBranch        *b_NeutrinoMotherPdg;   //!
   TBranch        *b_NeutrinoPdg;   //!
   TBranch        *b_NJets;   //!
   TBranch        *b_NJetsclean;   //!
   TBranch        *b_NJetsJECdown;   //!
   TBranch        *b_NJetsJECup;   //!
   TBranch        *b_nTAPElectronTracks;   //!
   TBranch        *b_nTAPMuonTracks;   //!
   TBranch        *b_nTAPPionTracks;   //!
   TBranch        *b_NumEvents;   //!
   TBranch        *b_NumInteractions;   //!
   TBranch        *b_NVtx;   //!
   TBranch        *b_PDFids;   //!
   TBranch        *b_PDFweights;   //!
   TBranch        *b_photon_genMatched;   //!
   TBranch        *b_photon_hadTowOverEM;   //!
   TBranch        *b_photon_hasPixelSeed;   //!
   TBranch        *b_photon_isEB;   //!
   TBranch        *b_photon_nonPrompt;   //!
   TBranch        *b_photon_passElectronVeto;   //!
   TBranch        *b_photon_pfChargedIso;   //!
   TBranch        *b_photon_pfChargedIsoRhoCorr;   //!
   TBranch        *b_photon_pfGammaIso;   //!
   TBranch        *b_photon_pfGammaIsoRhoCorr;   //!
   TBranch        *b_photon_pfNeutralIso;   //!
   TBranch        *b_photon_pfNeutralIsoRhoCorr;   //!
   TBranch        *b_photon_sigmaIetaIeta;   //!
   TBranch        *b_Photons;   //!
   TBranch        *b_puSysDown;   //!
   TBranch        *b_puSysUp;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_RJetDeltaPhi;   //!
   TBranch        *b_RJetMinDeltaPhiEta24;   //!
   TBranch        *b_RJetMinDeltaPhiEta5;   //!
   TBranch        *b_RJetMinDeltaPhiIndexEta24;   //!
   TBranch        *b_RJetMinDeltaPhiIndexEta5;   //!
   TBranch        *b_ScaleWeights;   //!
   TBranch        *b_selectedIDElectrons;   //!
   TBranch        *b_selectedIDElectrons_mediumID;   //!
   TBranch        *b_selectedIDElectrons_MiniIso;   //!
   TBranch        *b_selectedIDElectrons_MT2Activity;   //!
   TBranch        *b_selectedIDElectrons_MTW;   //!
   TBranch        *b_selectedIDIsoElectrons_mediumID;   //!
   TBranch        *b_selectedIDIsoElectrons_MT2Activity;   //!
   TBranch        *b_selectedIDIsoElectrons_MTW;   //!
   TBranch        *b_selectedIDIsoElectrons_PTW;   //!
   TBranch        *b_selectedIDIsoMuons_MT2Activity;   //!
   TBranch        *b_selectedIDIsoMuons_MTW;   //!
   TBranch        *b_selectedIDIsoMuons_PTW;   //!
   TBranch        *b_selectedIDMuons;   //!
   TBranch        *b_selectedIDMuons_MiniIso;   //!
   TBranch        *b_selectedIDMuons_MT2Activity;   //!
   TBranch        *b_selectedIDMuons_MTW;   //!
   TBranch        *b_slimJet;   //!
   TBranch        *b_slimJet_jecFactor;   //!
   TBranch        *b_slimJet_jecUnc;   //!
   TBranch        *b_slimJet_slimJetID;   //!
   TBranch        *b_slimJetJECdown;   //!
   TBranch        *b_slimJetJECdown_slimJetID;   //!
   TBranch        *b_slimJetJECup;   //!
   TBranch        *b_slimJetJECup_slimJetID;   //!
   TBranch        *b_SusyLSPMass;   //!
   TBranch        *b_SusyMotherMass;   //!
   TBranch        *b_TagLeptonHighPT;   //!
   TBranch        *b_TAPElectronTracks;   //!
   TBranch        *b_TAPElectronTracks_activity;   //!
   TBranch        *b_TAPElectronTracks_chg;   //!
   TBranch        *b_TAPElectronTracks_mT;   //!
   TBranch        *b_TAPElectronTracks_trkiso;   //!
   TBranch        *b_TAPMuonTracks;   //!
   TBranch        *b_TAPMuonTracks_activity;   //!
   TBranch        *b_TAPMuonTracks_chg;   //!
   TBranch        *b_TAPMuonTracks_mT;   //!
   TBranch        *b_TAPMuonTracks_trkiso;   //!
   TBranch        *b_TAPPionTracks;   //!
   TBranch        *b_TAPPionTracks_activity;   //!
   TBranch        *b_TAPPionTracks_chg;   //!
   TBranch        *b_TAPPionTracks_mT;   //!
   TBranch        *b_TAPPionTracks_trkiso;   //!
   TBranch        *b_TauDecayCands;   //!
   TBranch        *b_TauDecayCands_momInd;   //!
   TBranch        *b_TauDecayCands_pdgID;   //!
   TBranch        *b_TriggerNames;   //!
   TBranch        *b_TriggerPass;   //!
   TBranch        *b_TriggerPrescales;   //!
   TBranch        *b_TrueNumInteractions;   //!
   TBranch        *b_Weight;   //!
   TBranch        *b_ZCandidates;   //!

   RA2bNtuple(TTree *tree=0);
   virtual ~RA2bNtuple();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   void patchJetID();
   void setStatus( bool status );

};

#endif

#ifdef RA2bNtuple_cxx
RA2bNtuple::RA2bNtuple(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmsxrootd.fnal.gov//store/user/awhitbe1/SMS-T5Wg_RA2bNtuples/Spring15Fastv2.SMS-T5Wg_mGl-800to1000_mNLSP-0to950_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_91_RA2AnalysisTree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://cmsxrootd.fnal.gov//store/user/awhitbe1/SMS-T5Wg_RA2bNtuples/Spring15Fastv2.SMS-T5Wg_mGl-800to1000_mNLSP-0to950_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_91_RA2AnalysisTree.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("root://cmsxrootd.fnal.gov//store/user/awhitbe1/SMS-T5Wg_RA2bNtuples/Spring15Fastv2.SMS-T5Wg_mGl-800to1000_mNLSP-0to950_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_91_RA2AnalysisTree.root:/TreeMaker2");
      dir->GetObject("PreSelection",tree);

   }
   Init(tree);
}

RA2bNtuple::~RA2bNtuple()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t RA2bNtuple::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t RA2bNtuple::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void RA2bNtuple::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   ElectronCharge = 0;
   Electrons = 0;
   GenDeltaPhi = 0;
   GenElec_GenElecFromTau = 0;
   GenElec_MT2Activity = 0;
   GenElec_RecoTrkAct = 0;
   GenElec_RecoTrkd3 = 0;
   GenElec_RecoTrkIso = 0;
   GenEls = 0;
   GenJets = 0;
   GenJets_invisibleEnergy = 0;
   GenMinDeltaPhiEta24 = 0;
   GenMinDeltaPhiEta5 = 0;
   GenMinDeltaPhiIndexEta24 = 0;
   GenMinDeltaPhiIndexEta5 = 0;
   GenMu_GenMuFromTau = 0;
   GenMu_MT2Activity = 0;
   GenMu_RecoTrkAct = 0;
   GenMu_RecoTrkd3 = 0;
   GenMu_RecoTrkIso = 0;
   GenMus = 0;
   GenParticles = 0;
   GenParticles_ParentId = 0;
   GenParticles_ParentIdx = 0;
   GenParticles_PdgId = 0;
   GenParticles_Status = 0;
   GenTau_GenTauHad = 0;
   GenTau_MT2Activity = 0;
   GenTauLeadRecoTrkAct = 0;
   GenTauLeadRecoTrkd3 = 0;
   GenTauLeadRecoTrkIso = 0;
   GenTauLeadTrk = 0;
   GenTauNu = 0;
   GenTaus = 0;
   HTJetsMask = 0;
   HTJetsMaskclean = 0;
   HTJetsMaskJECdown = 0;
   HTJetsMaskJECup = 0;
   IsolatedElectronTracksVeto = 0;
   IsolatedMuonTracksVeto = 0;
   IsolatedPionTracksVeto = 0;
   Jets = 0;
   Jets_bDiscriminatorCSV = 0;
   Jets_bDiscriminatorMVA = 0;
   Jets_chargedEmEnergyFraction = 0;
   Jets_chargedHadronEnergyFraction = 0;
   Jets_chargedHadronMultiplicity = 0;
   Jets_chargedMultiplicity = 0;
   Jets_electronMultiplicity = 0;
   Jets_hadronFlavor = 0;
   Jets_ID = 0;
   Jets_jecFactor = 0;
   Jets_jecUnc = 0;
   Jets_jetArea = 0;
   Jets_muonEnergyFraction = 0;
   Jets_muonMultiplicity = 0;
   Jets_neutralEmEnergyFraction = 0;
   Jets_neutralHadronEnergyFraction = 0;
   Jets_neutralHadronMultiplicity = 0;
   Jets_neutralMultiplicity = 0;
   Jets_partonFlavor = 0;
   Jets_photonEnergyFraction = 0;
   Jets_photonMultiplicity = 0;
   Jets_qgLikelihood = 0;
   JetsAK8 = 0;
   JetsAK8_bDiscriminatorSubjet1CSV = 0;
   JetsAK8_bDiscriminatorSubjet2CSV = 0;
   JetsAK8_NsubjettinessTau1 = 0;
   JetsAK8_NsubjettinessTau2 = 0;
   JetsAK8_NsubjettinessTau3 = 0;
   JetsAK8_prunedMass = 0;
   Jetsclean = 0;
   Jetsclean_bDiscriminatorCSV = 0;
   Jetsclean_hadronFlavor = 0;
   Jetsclean_ID = 0;
   Jetsclean_partonFlavor = 0;
   JetsJECdown = 0;
   JetsJECdown_bDiscriminatorCSV = 0;
   JetsJECdown_hadronFlavor = 0;
   JetsJECdown_ID = 0;
   JetsJECdown_partonFlavor = 0;
   JetsJECup = 0;
   JetsJECup_bDiscriminatorCSV = 0;
   JetsJECup_hadronFlavor = 0;
   JetsJECup_ID = 0;
   JetsJECup_partonFlavor = 0;
   METPhiDown = 0;
   METPhiUp = 0;
   METPtDown = 0;
   METPtUp = 0;
   MHTJetsMask = 0;
   MHTJetsMaskclean = 0;
   MHTJetsMaskJECdown = 0;
   MHTJetsMaskJECup = 0;
   minDeltaPhiNames = 0;
   MuonCharge = 0;
   Muons = 0;
   NeutrinoLorentzVector = 0;
   NeutrinoMotherPdg = 0;
   NeutrinoPdg = 0;
   PDFids = 0;
   PDFweights = 0;
   photon_genMatched = 0;
   photon_hadTowOverEM = 0;
   photon_hasPixelSeed = 0;
   photon_isEB = 0;
   photon_nonPrompt = 0;
   photon_passElectronVeto = 0;
   photon_pfChargedIso = 0;
   photon_pfChargedIsoRhoCorr = 0;
   photon_pfGammaIso = 0;
   photon_pfGammaIsoRhoCorr = 0;
   photon_pfNeutralIso = 0;
   photon_pfNeutralIsoRhoCorr = 0;
   photon_sigmaIetaIeta = 0;
   Photons = 0;
   bestPhoton = 0;
   bestPhotonIndex = 0;
   RJetDeltaPhi = 0;
   RJetMinDeltaPhiEta24 = 0;
   RJetMinDeltaPhiEta5 = 0;
   RJetMinDeltaPhiIndexEta24 = 0;
   RJetMinDeltaPhiIndexEta5 = 0;
   ScaleWeights = 0;
   selectedIDElectrons = 0;
   selectedIDElectrons_mediumID = 0;
   selectedIDElectrons_MiniIso = 0;
   selectedIDElectrons_MT2Activity = 0;
   selectedIDElectrons_MTW = 0;
   selectedIDIsoElectrons_mediumID = 0;
   selectedIDIsoElectrons_MT2Activity = 0;
   selectedIDIsoElectrons_MTW = 0;
   selectedIDIsoElectrons_PTW = 0;
   selectedIDIsoMuons_MT2Activity = 0;
   selectedIDIsoMuons_MTW = 0;
   selectedIDIsoMuons_PTW = 0;
   selectedIDMuons = 0;
   selectedIDMuons_MiniIso = 0;
   selectedIDMuons_MT2Activity = 0;
   selectedIDMuons_MTW = 0;
   slimJet = 0;
   slimJet_jecFactor = 0;
   slimJet_jecUnc = 0;
   slimJet_slimJetID = 0;
   slimJetJECdown = 0;
   slimJetJECdown_slimJetID = 0;
   slimJetJECup = 0;
   slimJetJECup_slimJetID = 0;
   TAPElectronTracks = 0;
   TAPElectronTracks_activity = 0;
   TAPElectronTracks_chg = 0;
   TAPElectronTracks_mT = 0;
   TAPElectronTracks_trkiso = 0;
   TAPMuonTracks = 0;
   TAPMuonTracks_activity = 0;
   TAPMuonTracks_chg = 0;
   TAPMuonTracks_mT = 0;
   TAPMuonTracks_trkiso = 0;
   TAPPionTracks = 0;
   TAPPionTracks_activity = 0;
   TAPPionTracks_chg = 0;
   TAPPionTracks_mT = 0;
   TAPPionTracks_trkiso = 0;
   TauDecayCands = 0;
   TauDecayCands_momInd = 0;
   TauDecayCands_pdgID = 0;
   TriggerNames = 0;
   TriggerPass = 0;
   TriggerPrescales = 0;
   ZCandidates = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
   fChain->SetBranchAddress("LumiBlockNum", &LumiBlockNum, &b_LumiBlockNum);
   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("BTags", &BTags, &b_BTags);
   fChain->SetBranchAddress("BTagsclean", &BTagsclean, &b_BTagsclean);
   fChain->SetBranchAddress("BTagsJECdown", &BTagsJECdown, &b_BTagsJECdown);
   fChain->SetBranchAddress("BTagsJECup", &BTagsJECup, &b_BTagsJECup);
   fChain->SetBranchAddress("CaloMETPhi", &CaloMETPhi, &b_CaloMETPhi);
   fChain->SetBranchAddress("CaloMETPt", &CaloMETPt, &b_CaloMETPt);
   fChain->SetBranchAddress("CrossSection", &CrossSection, &b_CrossSection);
   fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
   fChain->SetBranchAddress("DeltaPhi1clean", &DeltaPhi1clean, &b_DeltaPhi1clean);
   fChain->SetBranchAddress("DeltaPhi1JECdown", &DeltaPhi1JECdown, &b_DeltaPhi1JECdown);
   fChain->SetBranchAddress("DeltaPhi1JECup", &DeltaPhi1JECup, &b_DeltaPhi1JECup);
   fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
   fChain->SetBranchAddress("DeltaPhi2clean", &DeltaPhi2clean, &b_DeltaPhi2clean);
   fChain->SetBranchAddress("DeltaPhi2JECdown", &DeltaPhi2JECdown, &b_DeltaPhi2JECdown);
   fChain->SetBranchAddress("DeltaPhi2JECup", &DeltaPhi2JECup, &b_DeltaPhi2JECup);
   fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
   fChain->SetBranchAddress("DeltaPhi3clean", &DeltaPhi3clean, &b_DeltaPhi3clean);
   fChain->SetBranchAddress("DeltaPhi3JECdown", &DeltaPhi3JECdown, &b_DeltaPhi3JECdown);
   fChain->SetBranchAddress("DeltaPhi3JECup", &DeltaPhi3JECup, &b_DeltaPhi3JECup);
   fChain->SetBranchAddress("DeltaPhi4", &DeltaPhi4, &b_DeltaPhi4);
   fChain->SetBranchAddress("DeltaPhi4clean", &DeltaPhi4clean, &b_DeltaPhi4clean);
   fChain->SetBranchAddress("DeltaPhi4JECdown", &DeltaPhi4JECdown, &b_DeltaPhi4JECdown);
   fChain->SetBranchAddress("DeltaPhi4JECup", &DeltaPhi4JECup, &b_DeltaPhi4JECup);
   fChain->SetBranchAddress("ElectronCharge", &ElectronCharge, &b_ElectronCharge);
   fChain->SetBranchAddress("Electrons", &Electrons, &b_Electrons);
   fChain->SetBranchAddress("GenDeltaPhi", &GenDeltaPhi, &b_GenDeltaPhi);
   fChain->SetBranchAddress("GenElec_GenElecFromTau", &GenElec_GenElecFromTau, &b_GenElec_GenElecFromTau);
   fChain->SetBranchAddress("GenElec_MT2Activity", &GenElec_MT2Activity, &b_GenElec_MT2Activity);
   fChain->SetBranchAddress("GenElec_RecoTrkAct", &GenElec_RecoTrkAct, &b_GenElec_RecoTrkAct);
   fChain->SetBranchAddress("GenElec_RecoTrkd3", &GenElec_RecoTrkd3, &b_GenElec_RecoTrkd3);
   fChain->SetBranchAddress("GenElec_RecoTrkIso", &GenElec_RecoTrkIso, &b_GenElec_RecoTrkIso);
   fChain->SetBranchAddress("GenEls", &GenEls, &b_GenEls);
   fChain->SetBranchAddress("genHT", &genHT, &b_genHT);
   fChain->SetBranchAddress("GenJets", &GenJets, &b_GenJets);
   fChain->SetBranchAddress("GenJets_invisibleEnergy", &GenJets_invisibleEnergy, &b_GenJets_invisibleEnergy);
   fChain->SetBranchAddress("GenMETPhi", &GenMETPhi, &b_GenMETPhi);
   fChain->SetBranchAddress("GenMETPt", &GenMETPt, &b_GenMETPt);
   fChain->SetBranchAddress("GenMHT", &GenMHT, &b_GenMHT);
   fChain->SetBranchAddress("GenMHT_Phi", &GenMHT_Phi, &b_GenMHT_Phi);
   fChain->SetBranchAddress("GenMinDeltaPhiEta24", &GenMinDeltaPhiEta24, &b_GenMinDeltaPhiEta24);
   fChain->SetBranchAddress("GenMinDeltaPhiEta5", &GenMinDeltaPhiEta5, &b_GenMinDeltaPhiEta5);
   fChain->SetBranchAddress("GenMinDeltaPhiIndexEta24", &GenMinDeltaPhiIndexEta24, &b_GenMinDeltaPhiIndexEta24);
   fChain->SetBranchAddress("GenMinDeltaPhiIndexEta5", &GenMinDeltaPhiIndexEta5, &b_GenMinDeltaPhiIndexEta5);
   fChain->SetBranchAddress("GenMu_GenMuFromTau", &GenMu_GenMuFromTau, &b_GenMu_GenMuFromTau);
   fChain->SetBranchAddress("GenMu_MT2Activity", &GenMu_MT2Activity, &b_GenMu_MT2Activity);
   fChain->SetBranchAddress("GenMu_RecoTrkAct", &GenMu_RecoTrkAct, &b_GenMu_RecoTrkAct);
   fChain->SetBranchAddress("GenMu_RecoTrkd3", &GenMu_RecoTrkd3, &b_GenMu_RecoTrkd3);
   fChain->SetBranchAddress("GenMu_RecoTrkIso", &GenMu_RecoTrkIso, &b_GenMu_RecoTrkIso);
   fChain->SetBranchAddress("GenMus", &GenMus, &b_GenMus);
   fChain->SetBranchAddress("GenParticles", &GenParticles, &b_GenParticles);
   fChain->SetBranchAddress("GenParticles_ParentId", &GenParticles_ParentId, &b_GenParticles_ParentId);
   fChain->SetBranchAddress("GenParticles_ParentIdx", &GenParticles_ParentIdx, &b_GenParticles_ParentIdx);
   fChain->SetBranchAddress("GenParticles_PdgId", &GenParticles_PdgId, &b_GenParticles_PdgId);
   fChain->SetBranchAddress("GenParticles_Status", &GenParticles_Status, &b_GenParticles_Status);
   fChain->SetBranchAddress("GenTau_GenTauHad", &GenTau_GenTauHad, &b_GenTau_GenTauHad);
   fChain->SetBranchAddress("GenTau_MT2Activity", &GenTau_MT2Activity, &b_GenTau_MT2Activity);
   fChain->SetBranchAddress("GenTauLeadRecoTrkAct", &GenTauLeadRecoTrkAct, &b_GenTauLeadRecoTrkAct);
   fChain->SetBranchAddress("GenTauLeadRecoTrkd3", &GenTauLeadRecoTrkd3, &b_GenTauLeadRecoTrkd3);
   fChain->SetBranchAddress("GenTauLeadRecoTrkIso", &GenTauLeadRecoTrkIso, &b_GenTauLeadRecoTrkIso);
   fChain->SetBranchAddress("GenTauLeadTrk", &GenTauLeadTrk, &b_GenTauLeadTrk);
   fChain->SetBranchAddress("GenTauNu", &GenTauNu, &b_GenTauNu);
   fChain->SetBranchAddress("GenTaus", &GenTaus, &b_GenTaus);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("HTclean", &HTclean, &b_HTclean);
   fChain->SetBranchAddress("HTJECdown", &HTJECdown, &b_HTJECdown);
   fChain->SetBranchAddress("HTJECup", &HTJECup, &b_HTJECup);
   fChain->SetBranchAddress("HTJetsMask", &HTJetsMask, &b_HTJetsMask);
   fChain->SetBranchAddress("HTJetsMaskclean", &HTJetsMaskclean, &b_HTJetsMaskclean);
   fChain->SetBranchAddress("HTJetsMaskJECdown", &HTJetsMaskJECdown, &b_HTJetsMaskJECdown);
   fChain->SetBranchAddress("HTJetsMaskJECup", &HTJetsMaskJECup, &b_HTJetsMaskJECup);
   fChain->SetBranchAddress("isoElectronTracks", &isoElectronTracks, &b_isoElectronTracks);
   fChain->SetBranchAddress("isoElectronTracksclean", &isoElectronTracksclean, &b_isoElectronTracksclean);
   fChain->SetBranchAddress("IsolatedElectronTracksVeto", &IsolatedElectronTracksVeto, &b_IsolatedElectronTracksVeto);
   fChain->SetBranchAddress("IsolatedMuonTracksVeto", &IsolatedMuonTracksVeto, &b_IsolatedMuonTracksVeto);
   fChain->SetBranchAddress("IsolatedPionTracksVeto", &IsolatedPionTracksVeto, &b_IsolatedPionTracksVeto);
   fChain->SetBranchAddress("isoMuonTracks", &isoMuonTracks, &b_isoMuonTracks);
   fChain->SetBranchAddress("isoMuonTracksclean", &isoMuonTracksclean, &b_isoMuonTracksclean);
   fChain->SetBranchAddress("isoPionTracks", &isoPionTracks, &b_isoPionTracks);
   fChain->SetBranchAddress("isoPionTracksclean", &isoPionTracksclean, &b_isoPionTracksclean);
   fChain->SetBranchAddress("JetID", &JetID, &b_JetID);
   fChain->SetBranchAddress("JetIDclean", &JetIDclean, &b_JetIDclean);
   fChain->SetBranchAddress("JetIDJECdown", &JetIDJECdown, &b_JetIDJECdown);
   fChain->SetBranchAddress("JetIDJECup", &JetIDJECup, &b_JetIDJECup);
   fChain->SetBranchAddress("Jets", &Jets, &b_Jets);
   fChain->SetBranchAddress("Jets_bDiscriminatorCSV", &Jets_bDiscriminatorCSV, &b_Jets_bDiscriminatorCSV);
   fChain->SetBranchAddress("Jets_bDiscriminatorMVA", &Jets_bDiscriminatorMVA, &b_Jets_bDiscriminatorMVA);
   fChain->SetBranchAddress("Jets_chargedEmEnergyFraction", &Jets_chargedEmEnergyFraction, &b_Jets_chargedEmEnergyFraction);
   fChain->SetBranchAddress("Jets_chargedHadronEnergyFraction", &Jets_chargedHadronEnergyFraction, &b_Jets_chargedHadronEnergyFraction);
   fChain->SetBranchAddress("Jets_chargedHadronMultiplicity", &Jets_chargedHadronMultiplicity, &b_Jets_chargedHadronMultiplicity);
   fChain->SetBranchAddress("Jets_chargedMultiplicity", &Jets_chargedMultiplicity, &b_Jets_chargedMultiplicity);
   fChain->SetBranchAddress("Jets_electronMultiplicity", &Jets_electronMultiplicity, &b_Jets_electronMultiplicity);
   fChain->SetBranchAddress("Jets_hadronFlavor", &Jets_hadronFlavor, &b_Jets_hadronFlavor);
   fChain->SetBranchAddress("Jets_ID", &Jets_ID, &b_Jets_ID);
   fChain->SetBranchAddress("Jets_jecFactor", &Jets_jecFactor, &b_Jets_jecFactor);
   fChain->SetBranchAddress("Jets_jecUnc", &Jets_jecUnc, &b_Jets_jecUnc);
   fChain->SetBranchAddress("Jets_jetArea", &Jets_jetArea, &b_Jets_jetArea);
   fChain->SetBranchAddress("Jets_muonEnergyFraction", &Jets_muonEnergyFraction, &b_Jets_muonEnergyFraction);
   fChain->SetBranchAddress("Jets_muonMultiplicity", &Jets_muonMultiplicity, &b_Jets_muonMultiplicity);
   fChain->SetBranchAddress("Jets_neutralEmEnergyFraction", &Jets_neutralEmEnergyFraction, &b_Jets_neutralEmEnergyFraction);
   fChain->SetBranchAddress("Jets_neutralHadronEnergyFraction", &Jets_neutralHadronEnergyFraction, &b_Jets_neutralHadronEnergyFraction);
   fChain->SetBranchAddress("Jets_neutralHadronMultiplicity", &Jets_neutralHadronMultiplicity, &b_Jets_neutralHadronMultiplicity);
   fChain->SetBranchAddress("Jets_neutralMultiplicity", &Jets_neutralMultiplicity, &b_Jets_neutralMultiplicity);
   fChain->SetBranchAddress("Jets_partonFlavor", &Jets_partonFlavor, &b_Jets_partonFlavor);
   fChain->SetBranchAddress("Jets_photonEnergyFraction", &Jets_photonEnergyFraction, &b_Jets_photonEnergyFraction);
   fChain->SetBranchAddress("Jets_photonMultiplicity", &Jets_photonMultiplicity, &b_Jets_photonMultiplicity);
   fChain->SetBranchAddress("Jets_qgLikelihood", &Jets_qgLikelihood, &b_Jets_qgLikelihood);
   fChain->SetBranchAddress("JetsAK8", &JetsAK8, &b_JetsAK8);
   fChain->SetBranchAddress("JetsAK8_bDiscriminatorSubjet1CSV", &JetsAK8_bDiscriminatorSubjet1CSV, &b_JetsAK8_bDiscriminatorSubjet1CSV);
   fChain->SetBranchAddress("JetsAK8_bDiscriminatorSubjet2CSV", &JetsAK8_bDiscriminatorSubjet2CSV, &b_JetsAK8_bDiscriminatorSubjet2CSV);
   fChain->SetBranchAddress("JetsAK8_NsubjettinessTau1", &JetsAK8_NsubjettinessTau1, &b_JetsAK8_NsubjettinessTau1);
   fChain->SetBranchAddress("JetsAK8_NsubjettinessTau2", &JetsAK8_NsubjettinessTau2, &b_JetsAK8_NsubjettinessTau2);
   fChain->SetBranchAddress("JetsAK8_NsubjettinessTau3", &JetsAK8_NsubjettinessTau3, &b_JetsAK8_NsubjettinessTau3);
   fChain->SetBranchAddress("JetsAK8_prunedMass", &JetsAK8_prunedMass, &b_JetsAK8_prunedMass);
   fChain->SetBranchAddress("Jetsclean", &Jetsclean, &b_Jetsclean);
   fChain->SetBranchAddress("Jetsclean_bDiscriminatorCSV", &Jetsclean_bDiscriminatorCSV, &b_Jetsclean_bDiscriminatorCSV);
   fChain->SetBranchAddress("Jetsclean_hadronFlavor", &Jetsclean_hadronFlavor, &b_Jetsclean_hadronFlavor);
   fChain->SetBranchAddress("Jetsclean_ID", &Jetsclean_ID, &b_Jetsclean_ID);
   fChain->SetBranchAddress("Jetsclean_partonFlavor", &Jetsclean_partonFlavor, &b_Jetsclean_partonFlavor);
   fChain->SetBranchAddress("JetsJECdown", &JetsJECdown, &b_JetsJECdown);
   fChain->SetBranchAddress("JetsJECdown_bDiscriminatorCSV", &JetsJECdown_bDiscriminatorCSV, &b_JetsJECdown_bDiscriminatorCSV);
   fChain->SetBranchAddress("JetsJECdown_hadronFlavor", &JetsJECdown_hadronFlavor, &b_JetsJECdown_hadronFlavor);
   fChain->SetBranchAddress("JetsJECdown_ID", &JetsJECdown_ID, &b_JetsJECdown_ID);
   fChain->SetBranchAddress("JetsJECdown_partonFlavor", &JetsJECdown_partonFlavor, &b_JetsJECdown_partonFlavor);
   fChain->SetBranchAddress("JetsJECup", &JetsJECup, &b_JetsJECup);
   fChain->SetBranchAddress("JetsJECup_bDiscriminatorCSV", &JetsJECup_bDiscriminatorCSV, &b_JetsJECup_bDiscriminatorCSV);
   fChain->SetBranchAddress("JetsJECup_hadronFlavor", &JetsJECup_hadronFlavor, &b_JetsJECup_hadronFlavor);
   fChain->SetBranchAddress("JetsJECup_ID", &JetsJECup_ID, &b_JetsJECup_ID);
   fChain->SetBranchAddress("JetsJECup_partonFlavor", &JetsJECup_partonFlavor, &b_JetsJECup_partonFlavor);
   fChain->SetBranchAddress("Leptons", &Leptons, &b_Leptons);
   fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
   fChain->SetBranchAddress("METPhiclean", &METPhiclean, &b_METPhiclean);
   fChain->SetBranchAddress("METPhiDown", &METPhiDown, &b_METPhiDown);
   fChain->SetBranchAddress("METPhiUp", &METPhiUp, &b_METPhiUp);
   fChain->SetBranchAddress("METPt", &METPt, &b_METPt);
   fChain->SetBranchAddress("METPtclean", &METPtclean, &b_METPtclean);
   fChain->SetBranchAddress("METPtDown", &METPtDown, &b_METPtDown);
   fChain->SetBranchAddress("METPtUp", &METPtUp, &b_METPtUp);
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("MHT_Phi", &MHT_Phi, &b_MHT_Phi);
   fChain->SetBranchAddress("MHT_Phiclean", &MHT_Phiclean, &b_MHT_Phiclean);
   fChain->SetBranchAddress("MHT_PhiJECdown", &MHT_PhiJECdown, &b_MHT_PhiJECdown);
   fChain->SetBranchAddress("MHT_PhiJECup", &MHT_PhiJECup, &b_MHT_PhiJECup);
   fChain->SetBranchAddress("MHTclean", &MHTclean, &b_MHTclean);
   fChain->SetBranchAddress("MHTJECdown", &MHTJECdown, &b_MHTJECdown);
   fChain->SetBranchAddress("MHTJECup", &MHTJECup, &b_MHTJECup);
   fChain->SetBranchAddress("MHTJetsMask", &MHTJetsMask, &b_MHTJetsMask);
   fChain->SetBranchAddress("MHTJetsMaskclean", &MHTJetsMaskclean, &b_MHTJetsMaskclean);
   fChain->SetBranchAddress("MHTJetsMaskJECdown", &MHTJetsMaskJECdown, &b_MHTJetsMaskJECdown);
   fChain->SetBranchAddress("MHTJetsMaskJECup", &MHTJetsMaskJECup, &b_MHTJetsMaskJECup);
   fChain->SetBranchAddress("minDeltaPhiNames", &minDeltaPhiNames, &b_minDeltaPhiNames);
   fChain->SetBranchAddress("MT2", &MT2, &b_MT2);
   fChain->SetBranchAddress("MuonCharge", &MuonCharge, &b_MuonCharge);
   fChain->SetBranchAddress("Muons", &Muons, &b_Muons);
   fChain->SetBranchAddress("nAllVertices", &nAllVertices, &b_nAllVertices);
   fChain->SetBranchAddress("NeutrinoLorentzVector", &NeutrinoLorentzVector, &b_NeutrinoLorentzVector);
   fChain->SetBranchAddress("NeutrinoMotherPdg", &NeutrinoMotherPdg, &b_NeutrinoMotherPdg);
   fChain->SetBranchAddress("NeutrinoPdg", &NeutrinoPdg, &b_NeutrinoPdg);
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("NJetsclean", &NJetsclean, &b_NJetsclean);
   fChain->SetBranchAddress("NJetsJECdown", &NJetsJECdown, &b_NJetsJECdown);
   fChain->SetBranchAddress("NJetsJECup", &NJetsJECup, &b_NJetsJECup);
   fChain->SetBranchAddress("nTAPElectronTracks", &nTAPElectronTracks, &b_nTAPElectronTracks);
   fChain->SetBranchAddress("nTAPMuonTracks", &nTAPMuonTracks, &b_nTAPMuonTracks);
   fChain->SetBranchAddress("nTAPPionTracks", &nTAPPionTracks, &b_nTAPPionTracks);
   fChain->SetBranchAddress("NumEvents", &NumEvents, &b_NumEvents);
   fChain->SetBranchAddress("NumInteractions", &NumInteractions, &b_NumInteractions);
   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("PDFids", &PDFids, &b_PDFids);
   fChain->SetBranchAddress("PDFweights", &PDFweights, &b_PDFweights);
   fChain->SetBranchAddress("photon_genMatched", &photon_genMatched, &b_photon_genMatched);
   fChain->SetBranchAddress("photon_hadTowOverEM", &photon_hadTowOverEM, &b_photon_hadTowOverEM);
   fChain->SetBranchAddress("photon_hasPixelSeed", &photon_hasPixelSeed, &b_photon_hasPixelSeed);
   fChain->SetBranchAddress("photon_isEB", &photon_isEB, &b_photon_isEB);
   fChain->SetBranchAddress("photon_nonPrompt", &photon_nonPrompt, &b_photon_nonPrompt);
   fChain->SetBranchAddress("photon_passElectronVeto", &photon_passElectronVeto, &b_photon_passElectronVeto);
   fChain->SetBranchAddress("photon_pfChargedIso", &photon_pfChargedIso, &b_photon_pfChargedIso);
   fChain->SetBranchAddress("photon_pfChargedIsoRhoCorr", &photon_pfChargedIsoRhoCorr, &b_photon_pfChargedIsoRhoCorr);
   fChain->SetBranchAddress("photon_pfGammaIso", &photon_pfGammaIso, &b_photon_pfGammaIso);
   fChain->SetBranchAddress("photon_pfGammaIsoRhoCorr", &photon_pfGammaIsoRhoCorr, &b_photon_pfGammaIsoRhoCorr);
   fChain->SetBranchAddress("photon_pfNeutralIso", &photon_pfNeutralIso, &b_photon_pfNeutralIso);
   fChain->SetBranchAddress("photon_pfNeutralIsoRhoCorr", &photon_pfNeutralIsoRhoCorr, &b_photon_pfNeutralIsoRhoCorr);
   fChain->SetBranchAddress("photon_sigmaIetaIeta", &photon_sigmaIetaIeta, &b_photon_sigmaIetaIeta);
   fChain->SetBranchAddress("Photons", &Photons, &b_Photons);
   fChain->SetBranchAddress("puSysDown", &puSysDown, &b_puSysDown);
   fChain->SetBranchAddress("puSysUp", &puSysUp, &b_puSysUp);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("RJetDeltaPhi", &RJetDeltaPhi, &b_RJetDeltaPhi);
   fChain->SetBranchAddress("RJetMinDeltaPhiEta24", &RJetMinDeltaPhiEta24, &b_RJetMinDeltaPhiEta24);
   fChain->SetBranchAddress("RJetMinDeltaPhiEta5", &RJetMinDeltaPhiEta5, &b_RJetMinDeltaPhiEta5);
   fChain->SetBranchAddress("RJetMinDeltaPhiIndexEta24", &RJetMinDeltaPhiIndexEta24, &b_RJetMinDeltaPhiIndexEta24);
   fChain->SetBranchAddress("RJetMinDeltaPhiIndexEta5", &RJetMinDeltaPhiIndexEta5, &b_RJetMinDeltaPhiIndexEta5);
   fChain->SetBranchAddress("ScaleWeights", &ScaleWeights, &b_ScaleWeights);
   fChain->SetBranchAddress("selectedIDElectrons", &selectedIDElectrons, &b_selectedIDElectrons);
   fChain->SetBranchAddress("selectedIDElectrons_mediumID", &selectedIDElectrons_mediumID, &b_selectedIDElectrons_mediumID);
   fChain->SetBranchAddress("selectedIDElectrons_MiniIso", &selectedIDElectrons_MiniIso, &b_selectedIDElectrons_MiniIso);
   fChain->SetBranchAddress("selectedIDElectrons_MT2Activity", &selectedIDElectrons_MT2Activity, &b_selectedIDElectrons_MT2Activity);
   fChain->SetBranchAddress("selectedIDElectrons_MTW", &selectedIDElectrons_MTW, &b_selectedIDElectrons_MTW);
   fChain->SetBranchAddress("selectedIDIsoElectrons_mediumID", &selectedIDIsoElectrons_mediumID, &b_selectedIDIsoElectrons_mediumID);
   fChain->SetBranchAddress("selectedIDIsoElectrons_MT2Activity", &selectedIDIsoElectrons_MT2Activity, &b_selectedIDIsoElectrons_MT2Activity);
   fChain->SetBranchAddress("selectedIDIsoElectrons_MTW", &selectedIDIsoElectrons_MTW, &b_selectedIDIsoElectrons_MTW);
   fChain->SetBranchAddress("selectedIDIsoElectrons_PTW", &selectedIDIsoElectrons_PTW, &b_selectedIDIsoElectrons_PTW);
   fChain->SetBranchAddress("selectedIDIsoMuons_MT2Activity", &selectedIDIsoMuons_MT2Activity, &b_selectedIDIsoMuons_MT2Activity);
   fChain->SetBranchAddress("selectedIDIsoMuons_MTW", &selectedIDIsoMuons_MTW, &b_selectedIDIsoMuons_MTW);
   fChain->SetBranchAddress("selectedIDIsoMuons_PTW", &selectedIDIsoMuons_PTW, &b_selectedIDIsoMuons_PTW);
   fChain->SetBranchAddress("selectedIDMuons", &selectedIDMuons, &b_selectedIDMuons);
   fChain->SetBranchAddress("selectedIDMuons_MiniIso", &selectedIDMuons_MiniIso, &b_selectedIDMuons_MiniIso);
   fChain->SetBranchAddress("selectedIDMuons_MT2Activity", &selectedIDMuons_MT2Activity, &b_selectedIDMuons_MT2Activity);
   fChain->SetBranchAddress("selectedIDMuons_MTW", &selectedIDMuons_MTW, &b_selectedIDMuons_MTW);
   fChain->SetBranchAddress("slimJet", &slimJet, &b_slimJet);
   fChain->SetBranchAddress("slimJet_jecFactor", &slimJet_jecFactor, &b_slimJet_jecFactor);
   fChain->SetBranchAddress("slimJet_jecUnc", &slimJet_jecUnc, &b_slimJet_jecUnc);
   fChain->SetBranchAddress("slimJet_slimJetID", &slimJet_slimJetID, &b_slimJet_slimJetID);
   fChain->SetBranchAddress("slimJetJECdown", &slimJetJECdown, &b_slimJetJECdown);
   fChain->SetBranchAddress("slimJetJECdown_slimJetID", &slimJetJECdown_slimJetID, &b_slimJetJECdown_slimJetID);
   fChain->SetBranchAddress("slimJetJECup", &slimJetJECup, &b_slimJetJECup);
   fChain->SetBranchAddress("slimJetJECup_slimJetID", &slimJetJECup_slimJetID, &b_slimJetJECup_slimJetID);
   fChain->SetBranchAddress("SusyLSPMass", &SusyLSPMass, &b_SusyLSPMass);
   fChain->SetBranchAddress("SusyMotherMass", &SusyMotherMass, &b_SusyMotherMass);
   fChain->SetBranchAddress("TagLeptonHighPT", &TagLeptonHighPT, &b_TagLeptonHighPT);
   fChain->SetBranchAddress("TAPElectronTracks", &TAPElectronTracks, &b_TAPElectronTracks);
   fChain->SetBranchAddress("TAPElectronTracks_activity", &TAPElectronTracks_activity, &b_TAPElectronTracks_activity);
   fChain->SetBranchAddress("TAPElectronTracks_chg", &TAPElectronTracks_chg, &b_TAPElectronTracks_chg);
   fChain->SetBranchAddress("TAPElectronTracks_mT", &TAPElectronTracks_mT, &b_TAPElectronTracks_mT);
   fChain->SetBranchAddress("TAPElectronTracks_trkiso", &TAPElectronTracks_trkiso, &b_TAPElectronTracks_trkiso);
   fChain->SetBranchAddress("TAPMuonTracks", &TAPMuonTracks, &b_TAPMuonTracks);
   fChain->SetBranchAddress("TAPMuonTracks_activity", &TAPMuonTracks_activity, &b_TAPMuonTracks_activity);
   fChain->SetBranchAddress("TAPMuonTracks_chg", &TAPMuonTracks_chg, &b_TAPMuonTracks_chg);
   fChain->SetBranchAddress("TAPMuonTracks_mT", &TAPMuonTracks_mT, &b_TAPMuonTracks_mT);
   fChain->SetBranchAddress("TAPMuonTracks_trkiso", &TAPMuonTracks_trkiso, &b_TAPMuonTracks_trkiso);
   fChain->SetBranchAddress("TAPPionTracks", &TAPPionTracks, &b_TAPPionTracks);
   fChain->SetBranchAddress("TAPPionTracks_activity", &TAPPionTracks_activity, &b_TAPPionTracks_activity);
   fChain->SetBranchAddress("TAPPionTracks_chg", &TAPPionTracks_chg, &b_TAPPionTracks_chg);
   fChain->SetBranchAddress("TAPPionTracks_mT", &TAPPionTracks_mT, &b_TAPPionTracks_mT);
   fChain->SetBranchAddress("TAPPionTracks_trkiso", &TAPPionTracks_trkiso, &b_TAPPionTracks_trkiso);
   fChain->SetBranchAddress("TauDecayCands", &TauDecayCands, &b_TauDecayCands);
   fChain->SetBranchAddress("TauDecayCands_momInd", &TauDecayCands_momInd, &b_TauDecayCands_momInd);
   fChain->SetBranchAddress("TauDecayCands_pdgID", &TauDecayCands_pdgID, &b_TauDecayCands_pdgID);
   fChain->SetBranchAddress("TriggerNames", &TriggerNames, &b_TriggerNames);
   fChain->SetBranchAddress("TriggerPass", &TriggerPass, &b_TriggerPass);
   fChain->SetBranchAddress("TriggerPrescales", &TriggerPrescales, &b_TriggerPrescales);
   fChain->SetBranchAddress("TrueNumInteractions", &TrueNumInteractions, &b_TrueNumInteractions);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   fChain->SetBranchAddress("ZCandidates", &ZCandidates, &b_ZCandidates);
   Notify();
}

void RA2bNtuple::patchJetID(){
  
  HT = 0. ;
  NJets = 0 ;
  JetID = true ; 
  bestPhoton = 0 ;
  bestPhotonIndex = 0 ;
  NumPhotons = 0 ;

  for( unsigned int iPh = 0 ; iPh < Photons->size() ; iPh++ ){

    bool isBarrelPhoton=false;
    bool isEndcapPhoton=false;
    bool passIDVeryLoose=false;
    bool passIsoVeryLoose=false;
    bool passIDLoose=false;
    bool passIsoLoose=false;
    bool passAcc=false;

    /*
    cout << "iPh: " << iPh << endl;
    cout << "Pt:" << Photons->at(iPh).Pt() << endl;
    cout << "isEB: " << photon_isEB->at(iPh) << endl;
    cout << "H/E: " << photon_hadTowOverEM->at(iPh) << endl;
    cout << "photon_hadTowOverEM: " << photon_hadTowOverEM->at(iPh) << endl;
    cout << "photon_sigmaIetaIeta: " << photon_sigmaIetaIeta->at(iPh) << endl;
    cout << "NeutralIsoRhoCorr: " << photon_pfNeutralIsoRhoCorr->at(iPh) << endl;
    cout << "ChargedIsoRhoCorr: " << photon_pfChargedIsoRhoCorr->at(iPh) << endl;
    cout << "GammaIsoRhoCorr: " << photon_pfGammaIsoRhoCorr->at(iPh) << endl;
    */

    // ---------------------------------- apply id cuts
    if(photon_isEB->at(iPh)){
      if(photon_hadTowOverEM->at(iPh) < 0.028 ){
        passIDVeryLoose=true;
      }//id criterea barrel (very loose)
      if(photon_hadTowOverEM->at(iPh) < 0.028 && photon_sigmaIetaIeta->at(iPh) < 0.0107){
	passIDLoose=true;
      }//id criterea barrel (loose)
    }else if(!photon_isEB->at(iPh)){
      if(photon_hadTowOverEM->at(iPh) < 0.093 ){
        passIDVeryLoose=true;
      }//id criterea endcap (very loose)
      if(photon_hadTowOverEM->at(iPh) < 0.093 && photon_sigmaIetaIeta->at(iPh) < 0.0272){
	passIDLoose=true;
      }//id criterea endcap (loose)
    }// ---------------------------------- end id cuts
 
    // ----------------------------------- apply isolation cuts
    if(photon_isEB->at(iPh)){
      if(photon_pfNeutralIsoRhoCorr->at(iPh) <  (7.23 + TMath::Exp(0.0028*(Photons->at(iPh).Pt()+0.5408)))  && photon_pfGammaIsoRhoCorr->at(iPh) < ( 2.11 + 0.0014*(Photons->at(iPh).Pt())) ){
        passIsoVeryLoose=true;      
      }//very loose, no charged iso cut
      if(photon_pfChargedIsoRhoCorr->at(iPh) <2.67 && photon_pfNeutralIsoRhoCorr->at(iPh) <  (7.23 + TMath::Exp(0.0028*(Photons->at(iPh).Pt()+0.5408)))  && photon_pfGammaIsoRhoCorr->at(iPh) < ( 2.11 + 0.0014*(Photons->at(iPh).Pt() )) ){
        passIsoLoose=true;      
      }//loose isolation 
    }
    else if(!photon_isEB->at(iPh)){
      if(photon_pfNeutralIsoRhoCorr->at(iPh) <  (8.89 + 0.01725*(Photons->at(iPh).Pt()))  && photon_pfGammaIsoRhoCorr->at(iPh) < ( 3.09 + 0.0091*(Photons->at(iPh).Pt())) ){
        passIsoVeryLoose=true;
      }//very loose, no charged iso cut
      if(photon_pfChargedIsoRhoCorr->at(iPh) <1.79 && photon_pfNeutralIsoRhoCorr->at(iPh) <  (8.89 + 0.01725*(Photons->at(iPh).Pt()))  && photon_pfGammaIsoRhoCorr->at(iPh) < ( 3.09 + 0.0091*(Photons->at(iPh).Pt())) ){
        passIsoLoose=true;
      }//loose isolation

    }// ---------------------------------- end iso cuts

    if( passIDLoose && passIsoLoose && Photons->at(iPh).Pt() > 100.0){//pure photons
      //cout << "EGamma Loose WP photon" << endl;
      if( ! bestPhoton ){
	bestPhoton = new vector<TLorentzVector>();
	bestPhotonIndex = new vector<int>();
      }
      bestPhoton->push_back(Photons->at(iPh));
      bestPhotonIndex->push_back(iPh);
      NumPhotons++;
    }
  }

  //cout << "done with photons" << endl;
    
  vector<TLorentzVector> jets = *slimJet;
  vector<TLorentzVector> htJets;

  TLorentzVector mht(0.,0.,0.,0.);
  
  for( unsigned int i = 0 ; i < jets.size() ; i++ ){

    //cout << "jet: " << i << endl;
    //cout << "pt: " << jets[i].Pt() << endl;
    
    if( jets[i].Pt()>30. ){
      if( fabs(jets[i].Eta())<2.4 ){
	HT+=jets[i].Pt();
	NJets++;
	htJets.push_back(jets[i]);
      }
      if( fabs(jets[i].Eta())<5.0){
	mht += TLorentzVector(jets[i].Px(),jets[i].Py(),0.,0.) ;
      }
    }else{
      // this explicitly assumes that the vector is ordered!
      break;
    }
    // if a loose photon is found, recompute the jet ID
    if(bestPhoton && bestPhoton->size()>0){
      if( (*slimJet_slimJetID)[i] == 0 && jets[i].Pt()>30. && jets[i].DeltaR((*bestPhoton)[0])>0.4 )
	JetID = false ;
    } 
  }
  
  MHT = mht.Pt();
  MHT_Phi = mht.Phi();
  
  DeltaPhi1 = htJets.size()>=1 ? fabs(mht.DeltaPhi( htJets[0] )) : 10. ;
  DeltaPhi2 = htJets.size()>=2 ? fabs(mht.DeltaPhi( htJets[1] )) : 10. ;
  DeltaPhi3 = htJets.size()>=3 ? fabs(mht.DeltaPhi( htJets[2] )) : 10. ;
  DeltaPhi4 = htJets.size()>=4 ? fabs(mht.DeltaPhi( htJets[3] )) : 10. ;

}

void RA2bNtuple::setStatus( bool status ){

  if( status ){
    fChain->SetBranchStatus("*",0);
    for( unsigned int iBranch = 0 ; iBranch < branchMask.size() ; iBranch++ ){
      fChain->SetBranchStatus(branchMask[iBranch],1);
    } 
  }else
    fChain->SetBranchStatus("*",0);

}

Bool_t RA2bNtuple::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void RA2bNtuple::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t RA2bNtuple::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef RA2bNtuple_cxx
