#!/bin/sh

source /cvmfs/cms.cern.ch/cmsset_default.sh
scram p CMSSW CMSSW_7_4_2
cd CMSSW_7_4_2/src

eval `scramv1 runtime -sh`

pwd

echo "this is a crazy fucking thing!"

git clone https://github.com/awhitbeck/AnalysisTools.git

cd AnalysisTools
g++ `root-config --cflags --glibs` genericPlotter.cc -o genericPlotter.exe
ls
echo "RUNNING ANALYSIS"
./genericPlotter.exe $1
ls
echo "COPYING OUTPUT"
xrdcp genericPlotter_${1}.root root://cmseos.fnal.gov//store/user/awhitbe1/DissectingJetsPlusMET/analysis/genericPlotter_${1}.root
