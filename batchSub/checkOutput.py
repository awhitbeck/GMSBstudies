import subprocess

samples=["GJets_HT-400To600",
         "GJets_HT-600ToInf",
         "QCD_HT300to500",
         "QCD_HT500to700",
         "QCD_HT700to1000",
         "QCD_HT1000to1500",
         "QCD_HT1500to2000",
         "QCD_HT2000toInf",
         "DYJetsToLL_M-50_HT-400to600",
         "DYJetsToLL_M-50_HT-600toInf",
         "ZJetsToNuNu_HT-400To600",
         "ZJetsToNuNu_HT-600ToInf",
         #"TTJets_HT-600to800",
         #"TTJets_HT-800to1200",
         #"TTJets_HT-1200to2500",
         #"TTJets_HT-2500toInf",
         #"TTJets_SingleLeptFromT_",
         #"TTJets_SingleLeptFromTbar",
         "TTJets_TuneCUETP8M1",
         "WJetsToLNu_HT-400To600",
         "WJetsToLNu_HT-600To800",
         "WJetsToLNu_HT-800To1200",
         "WJetsToLNu_HT-1200To2500",
         "WJetsToLNu_HT-2500ToInf",
         "SMS-T5Wg_mGl-1550_mNLSP-0to1500"]

for sample in samples :
    print "----------------------------------"
    print sample
    filesFound=subprocess.check_output("eos root://cmseos.fnal.gov ls -l /store/user/awhitbe1/GMSBstudies/fullAnalysis/a365727e4aa0fe10838936dd80354fe5a4e3aef8/ | grep {0} | wc -l".format(sample),shell=True)
    filesSubmitted=subprocess.check_output("ls doSkims_{0}*.jdl | wc -l".format(sample),shell=True)
    print "files found:",int(filesFound)
    print "files submitted:",int(filesSubmitted)
