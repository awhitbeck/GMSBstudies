#!/bin/sh

sample=$1 
executable=$2

if [ $# != 2 ] ; 
    then
    echo "not enough args given"
    exit
fi

echo "#### DAG FILE FOR ${executable}_${sample}" > ${executable}_${sample}.dag
for i in $(grep $sample ../src/inputFiles.txt)
do 
    tag=`echo $i | awk -F "/" '{print $NF}' | awk -F ".root" '{print $1}'`
    index=`echo $tag | awk -F "_" '{print $((NF-1)) }'`
    echo $tag
    echo "${sample}_${index}"
    python spawnJobs.py -s $tag -n "${sample}_${index}" -e $executable
    echo "JOB ${sample}_${index} ${executable}_${sample}_${index}.jdl" >> ${executable}_${sample}.dag
done