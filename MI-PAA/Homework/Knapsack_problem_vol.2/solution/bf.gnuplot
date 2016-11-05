#BF n/time dependency
set terminal png
set output 'img/BF_time.png'
set title "Hruba sila - delka behu"
set xlabel "pocet predmetu"
set ylabel "cas vypoctu [s]"
set logscale y
plot "BF.dat" using 1:3 title "normal dataset"
