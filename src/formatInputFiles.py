samples= {"GJets_HT-400To600":"GJets",
          "GJets_HT-600ToInf":"GJets",
          "QCD_HT300to500":"QCD",
          "QCD_HT500to700":"QCD",
          "QCD_HT700to1000":"QCD",
          "QCD_HT1000to1500":"QCD",
          "QCD_HT1500to2000":"QCD",
          "QCD_HT2000toInf":"QCD",
          "DYJetsToLL_M-50_HT-400to600":"DYJets",
          "DYJetsToLL_M-50_HT-600toInf":"DYJets",
          "ZJetsToNuNu_HT-400To600":"ZJetsToNuNu",
          "ZJetsToNuNu_HT-600ToInf":"ZJetsToNuNu",
          "WJetsToLNu_HT-400To600":"WJetsToLNu",
          "WJetsToLNu_HT-600To800":"WJetsToLNu",
          "WJetsToLNu_HT-800To1200":"WJetsToLNu",
          "WJetsToLNu_HT-1200To2500":"WJetsToLNu",
          "WJetsToLNu_HT-2500ToInf":"WJetsToLNu",
          "TTJets_TuneCUETP8M1":"TTJets",
          "SMS-T5Wg_mGl-1550_mNLSP-0to1500":"SMS-T5Wg_mGl-1550_mNLSP-0to1500",
          #"TTJets_HT-600to800",
          #"TTJets_HT-800to1200",
          #"TTJets_HT-1200to2500",
          #"TTJets_HT-2500toInf",
          #"TTJets_SingleLeptFromT_TuneCUETP8M1",
          #"TTJets_SingleLeptFromTbar_TuneCUETP8M1",
          #"TTWJetsToLNu",
          #"TTWJetsToQQ",
          #"TTZToLLNuNu",
          #"TTZToQQ",
          #"WH_HToBB_WToLNu",
          #"WWTo1L1Nu2Q",
          #"WWTo2L2Nu",
          #"WWZ",
          #"WZTo1L1Nu2Q",
          #"WZTo1L3Nu",
          #"ZH_HToBB_ZToNuNu",
          #"ZZTo2L2Q",
          #"ZZTo2Q2Nu",
          #"ZZZ",
          #"ttHJetTobb"
          }

files=open("skims.txt","r")
outFile=open("newSkims.txt","w")

for f in files:
    f=f[:-1]
    for sample in samples : 
        if f.find(sample) != -1 : 
            outFile.write("/store/user/lpcsusyhad/SusyRA2Analysis2015/Run2ProductionV6/"+f+" "+samples[sample]+"\n")
            break


outFile.close()
