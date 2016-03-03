#!/bin/sh

executable=$1
inputFileTag=$2
outputFileTag=$3

workingDir=$PWD

source /cvmfs/cms.cern.ch/cmsset_default.sh
scram p CMSSW CMSSW_7_4_2
cd CMSSW_7_4_2/src

eval `scramv1 runtime -sh`

pwd

git clone https://github.com/awhitbeck/AnalysisTools.git
git clone https://github.com/awhitbeck/GMSBstudies.git

cd GMSBstudies/batchSub
commitHash=`git rev-parse HEAD`
cd -

g++ `root-config --cflags --glibs` -I./AnalysisTools/src/ -I./GMSBstudies/src/ GMSBstudies/src/$executable.cc -o GMSBstudies/src/$executable.exe
ls
echo "RUNNING ANALYSIS"

cd GMSBstudies/src/
./$executable.exe $inputFileTag
ls
echo "COPYING OUTPUT"

mkdir awhitbe1/GMSBstudies/skims/${executable}/${commitHash}
xrdcp ${executable}_${inputFileTag}.root root://cmseos.fnal.gov//store/user/awhitbe1/GMSBstudies/skims/${executable}/${commitHash}/signalRegionSkim_${outputFileTag}.root
