#!/bin/bash

timestamp=$(date +%s)
echo $timestamp
for i in {1..50}; do
    rnd=$((1 + RANDOM % 5000))
    echo $rnd
    sed -n "$rnd"p ../thermal_raw_20210507_full
    /20210507_1605_3078.txt >> eval_"$timestamp".txt    
    sed -n "$rnd"p ../thermal_raw_20210507_full/20210507_1605_C088.txt >> ../thermal_raw_20210507_full/eval_"$timestamp".txt    
done
