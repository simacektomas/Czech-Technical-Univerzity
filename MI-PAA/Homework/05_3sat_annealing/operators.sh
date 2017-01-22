#!/bin/bash
COUNT=0
for file in $1/*.cnf
do
	echo $file
	OUTPUT="`./annealing $file 1 0.0005 0.95`" 
	echo "$COUNT $OUTPUT" >> "./solution/graphs/cs20.dat"
	COUNT=$(($COUNT+1))
done
