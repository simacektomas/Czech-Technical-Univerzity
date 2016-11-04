#!/bin/bash
NUM=$1
diff <(cat data/sol/knap_${NUM}.sol.dat | cut -d ' ' -f 1,2,3) <(./knapsack.vol2 data/inst/knap_${NUM}.inst.dat | cut -d ' ' -f 1,2,3)

