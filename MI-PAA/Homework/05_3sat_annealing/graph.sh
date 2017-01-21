#!/bin/bash


FILE="./solution/graphs/ratio.dat"
gnuplot << EOF
set terminal png
set output 'ratio.png'
set title "Zavislost konstanty cenove funkce"
set xlabel "Hodnota konstanty K"
set ylabel "Pomer nesplnenych/splnenych klauzuli"
set y2label "Soucet vah vysledku"
set y2tics
set xtics (0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.95,1) rotate by 90 right
set mxtics 1
set ytics nomirror
set key top right
set xrange [-0.1:1.1]
set style fill solid border -1
plot "$FILE" using 1:3 title "soucet vah" axes x1y2 lt rgb "#20B2AA" with boxes,\
     "$FILE" using 1:2 title "pomer klauzuli" lt rgb "#4B0082" with boxes
EOF

FILE="./solution/graphs/simple_operator.dat"
FILE2="./solution/graphs/komplex_operator.dat"
gnuplot << EOF
set terminal png
set output 'operators.png'
set title "Zavislost operatoru na hledani splnitelne konfigurace"
set xlabel "Velikost instance"
set ylabel "Pomer splnenych instanci v datasetu"
set yrange [0:1.1]
set xtics nomirror
set style data histograms
set style fill solid border -1
set key top right
plot "$FILE" using 5:xtic(1) title "jednoduchy operator" lt rgb "#20B2AA",\
	'' using 6 title "komplexni opetator" lt rgb "#4B0082"
EOF

FILE="./output.txt"
gnuplot << EOF
set terminal png
set output 'annealing.png'
set title "Titul"
set xlabel "iterace"
set ylabel "cena"
set key bottom right
plot "$FILE" using 1:2 title "dataset" lt rgb "#4B0082", \
     "$FILE" using 1:3 title "temperature" axes x1y2 lt rgb "#20B2AA"
EOF
