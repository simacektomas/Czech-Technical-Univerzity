#!/bin/bash

FILE="./gnuplot.dat"
gnuplot << EOF
set terminal png
set output 'annealing.png'
set title "$1"
set xlabel "iterace"
set ylabel "cena"
set key bottom right
plot "$FILE" using :1 title "dataset"
EOF

FILE="./low.dat"
FILE1="./med.dat"
FILE2="./high.dat"

gnuplot << EOF
set terminal png
set output 'init.png'
set xlabel "iterace"
set title "$1"
set ylabel "cena"
set yrange [0:5000]
set key bottom righ
plot "$FILE" using :1 title "low",\
     "$FILE1" using :1 title "med",\
     "$FILE2" using :1 title "high"
EOF
