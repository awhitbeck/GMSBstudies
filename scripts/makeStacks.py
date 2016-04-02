from ROOT import *
import stackPlots 
gROOT.SetBatch(True)

vars = ["HT","MHT","NJets","BTags","DeltaPhi1","DeltaPhi2","DeltaPhi3","DeltaPhi4","photonTruth"]
regions = ["SR","ldpCR","lepCR",
          "SR_highBTags","ldpCR_highBTags","lepCR_highBTags",
          "SR_higgs","ldpCR_higgs","lepCR_higgs"
          ]

inputFile = TFile("fullAnalysis_all.root","READ")

for var in vars :
    for reg in regions : 
        stackPlots.plot(var+"_"+reg,inputFile)
    
