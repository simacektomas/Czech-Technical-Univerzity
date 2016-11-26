#!/bin/bash
FILE="./weight/solution.dat"
gnuplot << EOF
set terminal png
set output 'pw_weight.png'
set title "Heuristika cena/vaha - zavislost maximalni vahy na case"
set xlabel "maximalni vaha"
set ylabel "cas vypoctu [s]"
set logscale y
set key top left
plot "$FILE" using 1:4 title "dataset"
EOF

FILE="./price/solution.dat"
gnuplot << EOF 
set terminal png                                                                                     
set output 'pw_price.png'                                                                            
set title "Heuristika cena/vaha - zavislost maximalni ceny na case" 
set xlabel "maximalni cena"                                                                          
set ylabel "cas vypoctu [s]" 
set logscale y 
set key top left 
plot "$FILE" using 1:4 title "dataset" 
EOF

FILE="./ratio/solution.dat" 
gnuplot << EOF 
set terminal png 
set output 'pw_ratio.png' 
set title "HE c/v - zavislost pomeru kapacity batohu k sumarni vaze na case" 
set xlabel "pomer kapacity batohu k sumarni vaze" 
set ylabel "cas vypoctu [s]" 
set logscale y 
set key top left 
plot "$FILE" using 1:4 title "dataset" 
EOF

POSITIVE="./granul/positive/solution.dat"
NEUTRAL="./granul/neutral/solution.dat"
NEGATIVE="./granul/negative/solution.dat"

gnuplot << EOF
set terminal png
set output './pw_granularity.png'
set title "Heuristika pomer cena/vaha - zavislost granularity na case"
set xlabel "exponent granularity"
set ylabel "cas vypoctu [s]"
set logscale y
set xrange [0:3.25]
set key top left
plot "$POSITIVE" using 1:4 title "velke veci", "$NEUTRAL" using 1:4 title "male veci", "$NEGATIVE" using 1:4 title "rovnovaha" 
EOF
#rerr
FILE="./weight/solution.dat"
gnuplot << EOF
set terminal png
set output 'pw_weight_err.png'
set title "Heuristika pomer cena/vaha - zavislost maximalni vahy na chybe"
set xlabel "maximalni vaha"
set ylabel "relativni chyba"
set logscale y
set key bottom left
plot "$FILE" using 1:5 title "dataset"
EOF

FILE="./price/solution.dat"
gnuplot << EOF 
set terminal png                                                                                     
set output 'pw_price_err.png'                                                                            
set title "Heuristika pomer cena/vaha- zavislost maximalni ceny na chybe" 
set xlabel "maximalni cena"                                                                          
set ylabel "relativni chyba" 
set logscale y 
set key top left 
plot "$FILE" using 1:5 title "dataset" 
EOF

FILE="./ratio/solution.dat"
gnuplot << EOF 
set terminal png 
set output 'pw_ratio_err.png' 
set title "HE c/v - zavislost pomeru kapacity batohu k sumarni vaze na chybe" 
set xlabel "pomer kapacity batohu k sumarni vaze" 
set ylabel "relativni chyba" 
set logscale y 
set key top left 
plot "$FILE" using 1:5 title "dataset" 
EOF

POSITIVE="./granul/positive/solution.dat"
NEUTRAL="./granul/neutral/solution.dat"
NEGATIVE="./granul/negative/solution.dat"

gnuplot << EOF
set terminal png
set output './pw_granularity_err.png'
set title "Heuristika pomer cena/vaha - zavislost granularity na chybe"
set xlabel "exponent granularity"
set ylabel "relativni chyba"
set logscale y
set xrange [0:3.25]
set key top left
plot "$POSITIVE" using 1:5 title "velke veci", "$NEUTRAL" using 1:5 title "male veci", "$NEGATIVE" using 1:5 title "rovnovaha" 
EOF

