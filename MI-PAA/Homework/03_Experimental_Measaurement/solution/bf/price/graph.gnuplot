set terminal png
set output "../bf_price.png"
set title "Brute force - zavislost maximalni ceny a casu"
set xlabel "maximalni cena"
set ylabel "cas vypoctu [s]"
set key top left
set logscale y
plot "solution.dat" using 1:4 title "dataset" 
