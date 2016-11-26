#!/bin/bash
FILE="./weight/solution.dat"
gnuplot << EOF
set terminal png
set output 'bb_weight.png'
set title "Bound and branch - zavislost maximalni vahy na vypocetnim case"
set xlabel "maximalni vaha"
set ylabel "cas vypoctu [s]"
set logscale y
set key top left
plot "$FILE" using 1:4 title "dataset"
EOF

FILE="./price/solution.dat"
gnuplot << EOF 
set terminal png                                                                              
set output 'bb_price.png'                                                                           
set title "Bound and branch - zavislost maximalni ceny na vypocetnim case" 
set xlabel "maximalni cena"                                                                         
set ylabel "cas vypoctu [s]" 
set logscale y 
set key top left 
plot "$FILE" using 1:4 title "dataset" 
EOF

FILE="./ratio/solution.dat" 
gnuplot << EOF 
set terminal png 
set output 'bb_ratio.png' 
set title "B&B - zavislost pomeru kapacity batohu k sumarni vaze na case" 
set xlabel "pomer kapacity batohu k sumarni vaze" 
set xrange [0:1.1]
set ylabel "cas vypoctu [s]" 
set logscale y 
set key top right 
plot "$FILE" using 1:4 title "dataset" 
EOF

POSITIVE="./granul/positive/solution.dat"
NEUTRAL="./granul/neutral/solution.dat"
NEGATIVE="./granul/negative/solution.dat"

gnuplot << EOF
set terminal png
set output './bb_granularity.png'
set title "Bound and branch - zavislot granularity na vypocentnim case"
set xlabel "exponent granularity"
set ylabel "cas vypoctu [s]"
set logscale y
set xrange [0:3.25]
set key top left
plot "$POSITIVE" using 1:4 title "velke veci", "$NEUTRAL" using 1:4 title "male veci", "$NEGATIVE" using 1:4 title "rovnovaha" 
EOF
