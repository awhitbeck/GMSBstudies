from ROOT import *
import stackPlots 
gROOT.SetBatch(True)

prunedMassV_SR_Vtag

vars = ["HT","MHT","NJets","BTags","DeltaPhi1","DeltaPhi2","DeltaPhi3","DeltaPhi4","photonTruth","prunedMassV","prunedMassHiggs"]
regions = ["SR",#"ldpCR","lepCR",
          "SR_highBTags",#"ldpCR_highBTags","lepCR_highBTags",
          "SR_higgs",#"ldpCR_higgs","lepCR_higgs",
          "SR_2higgs",#"ldpCR_2higgs","lepCR_2higgs",
          "SR_Vtag",#"ldpCR_Vtag","lepCR_Vtag"
          ]

inputFile = TFile("fullAnalysis_all.root","READ")

for var in vars :
    for reg in regions : 
        stackPlots.plot(var+"_"+reg,inputFile)
    
