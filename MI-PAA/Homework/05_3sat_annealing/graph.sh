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

FILE="./solution/graphs/equilibrium.dat"
gnuplot << EOF
set terminal png
set output 'equilibrium.png'
set title "Delka equilibria a pocet splnenych instanci a cas - uf150/645"
set xlabel "Koeficient equilibria a velikosti instance"
set ylabel "# splnenych instanci ze 100"
set y2label "Cas behu [s]"
set y2tics
set ytics nomirror
set xrange [0.5:5.5]
set yrange [60:90]
set y2range [0.5:5.5]
set key top left
plot "$FILE" using 1:2 title "splnene instance" lt rgb "#20B2AA" with linespoint,\
     "$FILE" using 1:4 title "doba behu" axes x1y2 lt rgb "#4B0082" with linespoint
EOF

FILE="./solution/graphs/uf150.dat"
gnuplot << EOF
set terminal png
set output 'uf150.png'
set title "Reseni instanci uf150/645"
set xlabel "instance"
set ylabel "soucet vah"
set key top left
set style fill solid border -1
set xrange [-5:105]
plot "$FILE" using 1:2 title "maximalni soucet" lt rgb "#20B2AA" with boxes,\
     "$FILE" using 1:3 title "dosazeny soucet" lt rgb "#4B0082" with boxes
EOF

FILE="./solution/graphs/uf125.dat"
gnuplot << EOF
set terminal png
set output 'uf125.png'
set title "Reseni instanci uf125/538"
set xlabel "instance"
set ylabel "soucet vah"
set key top left
set style fill solid border -1
set xrange [-5:105]
plot "$FILE" using 1:2 title "maximalni soucet" lt rgb "#20B2AA" with boxes,\
     "$FILE" using 1:3 title "dosazeny soucet" lt rgb "#4B0082" with boxes
EOF

FILE="./solution/graphs/uf75.dat"
gnuplot << EOF
set terminal png
set output 'uf75.png'
set title "Reseni instanci uf75/325"
set xlabel "instance"
set ylabel "soucet vah"
set key top left
set style fill solid border -1
set xrange [-5:105]
plot "$FILE" using 1:2 title "maximalni soucet" lt rgb "#20B2AA" with boxes,\
     "$FILE" using 1:3 title "dosazeny soucet" lt rgb "#4B0082" with boxes
EOF

FILE="./solution/graphs/uf50.dat"
gnuplot << EOF
set terminal png
set output 'uf50.png'
set title "Reseni instanci uf50/218"
set xlabel "instance"
set ylabel "soucet vah"
set key top left
set style fill solid border -1
set xrange [-5:105]
plot "$FILE" using 1:2 title "maximalni soucet" lt rgb "#20B2AA" with boxes,\
     "$FILE" using 1:3 title "dosazeny soucet" lt rgb "#4B0082" with boxes
EOF

FILE="./solution/graphs/cs20.dat"
gnuplot << EOF
set terminal png
set output 'cs20.png'
set title "Reseni instanci cs20/76"
set xlabel "instance"
set ylabel "soucet vah"
set key top right
set style fill solid border -1
set xrange [-5:55]
plot "$FILE" using 1:2 title "maximalni soucet" lt rgb "#20B2AA" with boxes,\
     "$FILE" using 1:3 title "dosazeny soucet" lt rgb "#4B0082" with boxes
EOF

FILE="./output.txt"
gnuplot << EOF
set terminal png
set output 'annealing.png'
set title "Vyvoj optimalizacniho kriteria a teploty"
set xlabel "pocet iteraci"
set xtics rotate by 90 right
set ylabel "optimalizacni kriterium"
set y2label "teplota"
set y2tics
set ytics nomirror
set key bottom right
plot "$FILE" using 1:2 title "dataset" lt rgb "#4B0082", \
     "$FILE" using 1:3 title "temperature" axes x1y2 lt rgb "#20B2AA"
EOF
