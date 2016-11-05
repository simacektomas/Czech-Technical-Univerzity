#!/bin/bash
for file in ./*.gnuplot
do
	gnuplot "$file"
done
