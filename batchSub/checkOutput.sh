#!/bin/bash

eval `scramv1 runtime -sh`
source /etc/profile.d/eos_aliases.sh

samples="""GJets_HT-400To600
GJets_HT-600ToInf
QCD_HT300to500
QCD_HT500to700
QCD_HT700to1000
QCD_HT1000to1500
QCD_HT1500to2000
QCD_HT2000toInf
DYJetsToLL_M-50_HT-400to600
DYJetsToLL_M-50_HT-600toInf
ZJetsToNuNu_HT-400To600
ZJetsToNuNu_HT-600ToInf
TTJets_HT-600to800
TTJets_HT-800to1200
TTJets_HT-1200to2500
TTJets_HT-2500toInf
TTJets_SingleLeptFromT_
TTJets_SingleLeptFromTbar
TTJets_TuneCUETP8M1
WJetsToLNu_HT-400To600
WJetsToLNu_HT-600To800
WJetsToLNu_HT-800To1200
WJetsToLNu_HT-1200To2500
WJetsToLNu_HT-2500ToInf
SMS-T5Wg_mGl-1550_mNLSP-0to1500"""

for sample in $samples 
do
    echo "----------------------------------"
    echo $sample
    filesFound=`eos root://cmseos.fnal.gov ls -l /store/user/awhitbe1/GMSBstudies/doSkims/cb09234348a6624fa940f363e325a75b169d52aa/ | grep $sample | wc -l`
    filesSubmitted=`ls doSkims_$sample*.jdl | wc -l`
    echo "files found: "$filesFound
    echo "files submitted: "$filesSubmitted
done