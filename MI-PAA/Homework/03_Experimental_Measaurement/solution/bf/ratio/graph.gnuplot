set terminal png
set output "../bf_ratio.png"
set title "Brute force - zavislost pomeru kapacity batohu k sumarni vaze a casu"
set xlabel "pomer kapacity batohu k sumarni vaze"
set ylabel "cas vypoctu [s]"
set key top left
set logscale y
plot "solution.dat" using 1:4 title "dataset" 
