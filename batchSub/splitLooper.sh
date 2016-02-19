#!/bin/sh

sample="SMS-T5Wg_mGl-1550_mNLSP-0to1500"

for i in $(grep $sample ../src/T5WgFiles.txt)
do 
    tag=`echo $i | awk -F "/" '{print $NF}'`
    index=`echo $tag | awk -F "_" '{print $((NF-1)) }'`
    echo $tag
    echo "${sample}_${index}"
    python spawnJobs.py -s $tag -n "${sample}_${index}"
done