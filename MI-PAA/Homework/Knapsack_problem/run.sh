#!/bin/bash

for file in inst/*
do 
	echo "$file"
	./knapsack "$file"
done
