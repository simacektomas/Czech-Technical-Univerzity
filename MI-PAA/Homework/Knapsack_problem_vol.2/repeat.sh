#!/bin/bash

if [ ! -d "$2" ]; then
	echo "$1 is not a directory"
	exit 1
fi

for file in $2/*
do
	./knapsack.vol2 $1 "$file" $3
done
