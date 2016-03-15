executable=$1

if [ $# != 1 ] : 
    then 
    echo "not enough args given"
    exit
fi

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
WJetsToLNu_HT-400To600
WJetsToLNu_HT-600To800
WJetsToLNu_HT-800To1200
WJetsToLNu_HT-1200To2500
WJetsToLNu_HT-2500ToInf
TTJets_TuneCUETP8M1"""
samples="""SMS-T5Wg_mGl-1550_mNLSP-0to1500"""
#TTJets_HT-600to800
#TTJets_HT-800to1200
#TTJets_HT-1200to2500
#TTJets_HT-2500toInf
#TTJets_SingleLeptFromT_
#TTJets_SingleLeptFromTbar
#TTWJetsToLNu
#TTWJetsToQQ
#TTZToLLNuNu
#TTZToQQ
#WH_HToBB_WToLNu
#WWTo1L1Nu2Q
#WWTo2L2Nu
#WWZ
#WZTo1L1Nu2Q
#WZTo1L3Nu
#ZH_HToBB_ZToNuNu
#ZZTo2L2Q
#ZZTo2Q2Nu
#ZZZ
#ttHJetTobb

for sample in $samples ; do
    echo $i
    echo "#### DAG FILE FOR ${executable}_${sample}" > ${executable}_${sample}.dag
    for i in $(grep $sample ../src/inputFiles.txt) ; do 
	tag=`echo $i | awk -F "/" '{print $NF}' | awk -F ".root" '{print $1}'`
	index=`echo $tag | awk -F "_" '{print $((NF-1)) }'`
	echo $tag
	echo "${sample}_${index}"
	python spawnJobs.py -s $tag -n "${sample}_${index}" -e $executable
	echo "JOB ${sample}_${index} ${executable}_${sample}_${index}.jdl" >> ${executable}_${sample}.dag
    done
done