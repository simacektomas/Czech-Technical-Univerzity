#BB n/time dependency
set terminal png
set output 'img/BB_time.png'
set title "Bound and branch - delka behu"
set xlabel "pocet predmetu"
set ylabel "cas vypoctu [s]"
set logscale y
set key top left
plot "BB.dat" using 1:3 title "normal dataset"

set terminal png
set output 'img/BB_exp_time.png'
set title "Bound and branch - exp - delka behu"
set xlabel "pocet predmetu"
set ylabel "cas vypoctu [s]"
set logscale y
plot "BB_exp.dat" using 1:3 title "experimental dataset"
