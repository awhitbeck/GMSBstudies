#!/bin/sh

workingDir=$PWD

source /cvmfs/cms.cern.ch/cmsset_default.sh
scram p CMSSW CMSSW_7_4_2
cd CMSSW_7_4_2/src

eval `scramv1 runtime -sh`

pwd

git clone https://github.com/awhitbeck/AnalysisTools.git
git clone https://github.com/awhitbeck/GMSBstudies.git

g++ `root-config --cflags --glibs` -I./AnalysisTools/src/ -I./GMSBstudies/src/ GMSBstudies/src/signalRegionSkim.cc -o GMSBstudies/src/signalRegionSkim.exe
ls
echo "RUNNING ANALYSIS"

cd GMSBstudies/src/
./signalRegionSkim.exe $1
ls
echo "COPYING OUTPUT"
xrdcp signalRegionSkim_${1}.root root://cmseos.fnal.gov//store/user/awhitbe1/GMSBstudies/skims/signalRegionSkim_${1}.root
