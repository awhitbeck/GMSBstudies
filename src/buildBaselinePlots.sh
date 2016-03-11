#!/bin/sh


cd ../../
source /cvmfs/cms.cern.ch/cmsset_default.sh
eval `scramv1 runtime -sh`

#g++ `root-config --cflags --glibs` -pg -I./AnalysisTools/src/ -I./GMSBstudies/src/ GMSBstudies/src/baselinePlots.cc -o GMSBstudies/src/baselinePlots.exe
g++ `root-config --cflags --glibs` -I./AnalysisTools/src/ -I./GMSBstudies/src/ GMSBstudies/src/baselinePlots.cc -o GMSBstudies/src/baselinePlots.exe

