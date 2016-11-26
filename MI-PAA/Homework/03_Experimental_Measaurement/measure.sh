#!/bin/bash

# Exact algorithm
for ALG in PD 
do
	for FILE in data/weight/*
	do
		PARAM="`echo $FILE | sed 's/[^0-9]//g'`"
		RESULT="`./knapsack.vol2 $ALG $FILE`"
		echo "$PARAM $RESULT"
	done
#	echo "PRICE"
#	for FILE in data/price/*
#	do
#		RESULT="`./knapsack.vol2 $ALG $FILE`"
#		echo "$RESULT $FILE"
#	done 
#	echo "RATIO"
#	for FILE in data/ratio/* 
#	do
#		RESULT="`./knapsack.vol2 $ALG $FILE`"
#		echo "$RESULT $FILE"
#	done 
#	echo "GRANULARITY"
#	for FILE in data/granul/*
#	do 
#		RESULT="`./knapsack.vol2 $ALG $FILE`"
#		echo "$RESULT $FILE"
#	done
#	echo ""
done
