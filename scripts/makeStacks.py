from ROOT import *
import stackPlots 

vars = ["HT_SR",
        "MHT_SR",
        "NJets_SR",
        "BTags_SR",
        "HT_ldpHT",
        "MHT_ldpHT",
        "NJets_ldpHT",
        "BTags_ldpCR",
        "dPhiGamma_dPhiGamma_ldpCR",
        "HT_lepCR",
        "MHT_lepCR",
        "NJets_lepCR",
        "BTags_lepCR"]

inputFile = TFile("fullAnalysis_all.root","READ")

for var in vars :

    stackPlots.plot(var,inputFile)
    
