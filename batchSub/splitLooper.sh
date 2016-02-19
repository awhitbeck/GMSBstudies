#!/bin/sh

sample=""

for i in $(grep $sample ../src/inputFiles.txt)
do 
    tag=`echo $i | awk -F "/" '{print $NF}'`
    index=`echo $tag | awk -F "_" '{print $((NF-1)) }'`
    echo $tag
    echo "${sample}_${index}"
    python spawnJobs.py -s $tag -n "${sample}_${index}"
done