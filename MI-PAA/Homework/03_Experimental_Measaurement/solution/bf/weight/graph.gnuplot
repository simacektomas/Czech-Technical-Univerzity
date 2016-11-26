set terminal png
set output "../bf_weight.png"
set title "Brute force - zavislost maximalni vahy a casu"
set xlabel "maximalni vaha"
set ylabel "cas vypoctu [s]"
set key top left
set logscale y
plot "solution.dat" using 1:4 title "dataset" 
