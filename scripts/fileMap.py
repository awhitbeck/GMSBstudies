import os

inputFile = open("../src/inputFiles.txt")

sampleMap = {}
for line in inputFile:
    line = line[:-1]

    parsedLine = line.split()
    #print parsedLine
    if len(parsedLine) != 2 : continue
    if not parsedLine[1] in sampleMap : 
        sampleMap[parsedLine[1]] = ["root://cmsxrootd.fnal.gov//"+parsedLine[0]]
    else :
        sampleMap[parsedLine[1]].append("root://cmsxrootd.fnal.gov//"+parsedLine[0])


fileList = " ".join(sampleMap["GJets"])
print "hadd fullAnalysis_QCD.root {0}".format(fileList)
os.system("hadd fullAnalysis_QCD.root {0}".format(fileList))
