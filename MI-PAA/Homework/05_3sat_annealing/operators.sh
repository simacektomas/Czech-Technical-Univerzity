#!/bin/bash
SUM=0
COUNT=0
for file in $1/*.cnf
do
	echo $file
	./annealing $file 2 0.001 0.9 300 > /dev/null
	SUM=$(($SUM+$?))
	COUNT=$(($COUNT+1))
done
echo "$1 $SUM $COUNT"
