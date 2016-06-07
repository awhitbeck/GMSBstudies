# Code for studying some GMSB scenarios

## Setup

cmsrel CMSSW_7_4_2
cd CMSSW_7_4_2/src/
git clone https://github.com/awhitbeck/RA2bUtils
git clone https://github.com/awhitbeck/AnalysisTools
git clone https://github.com/awhitbeck/GMSBstudies

## Running skims

First, compile the code:

<pre>
g++ `root-config --cflags --glibs` -IAnalysisTools/src/ -IRA2bUtils/src/ -IGMSBstudies/src/ $CMSSW_BASE/src/GMSBstudies/src/signalRegionSkim.cc -o $CMSSW_BASE/src/GMSBstudies/src/signalRegionSkim.exe
</pre>

Running the code... you can choose either an individual file from the list of inputFiles.txt or a subset, e.g. QCD_HT1000to1500:

<pre>
 ./signalRegionSkim.exe QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_103
</pre>

