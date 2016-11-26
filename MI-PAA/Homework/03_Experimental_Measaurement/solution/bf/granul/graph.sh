#!/bin/bash
POSITIVE="./positive/solution.dat"
NEUTRAL="./neutral/solution.dat"
NEGATIVE="./negative/solution.dat"

gnuplot << EOF
set terminal png
set output '../bf_granularity.png'
set title "Brute force - zavislot granularity na vypocentnim case"
set xlabel "exponent granularity"
set ylabel "cas vypoctu [s]"
set logscale y
set xrange [0:3.25]
set key top left
plot "$POSITIVE" using 1:4 title "velke veci", "$NEUTRAL" using 1:4 title "male veci", "$NEGATIVE" using 1:4 title "rovnovaha" 
EOF
