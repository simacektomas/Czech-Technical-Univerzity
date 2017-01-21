#!/bin/bash
COUNT=$1
MAX_WEIGHT=$2
WEIGHTS="w "

for file in ./*.cnf
do
	echo $file
	CONTENT="`cat $file | head -n -3`"
	for((i=0; i<$COUNT; i++))
	do
		WEIGHTS+="$(( ($RANDOM % $MAX_WEIGHT)+1 )) "
	done
	echo "$CONTENT" > $file
	echo "$WEIGHTS" >> $file
	echo "%" >> $file
	echo "0" >> $file
	echo "" >> $file
	WEIGHTS="w "
done
