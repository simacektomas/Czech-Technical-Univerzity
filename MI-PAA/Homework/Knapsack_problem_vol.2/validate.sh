#!/bin/bash
for i in 4 10 15 20 22 25 27 30 32 35 37 40
do 
	./knapsack.vol2 PD data/inst/knap_i${i}.inst.dat > tmp.dat; cat tmp.dat | cut -d ' ' -f 1,2,3 > tmp2.dat ; cat data/sol/knap_${i}.sol.dat | cut -d ' ' -f 1,2,3 > tmp.dat ; diff tmp.dat tmp2.dat 

done
