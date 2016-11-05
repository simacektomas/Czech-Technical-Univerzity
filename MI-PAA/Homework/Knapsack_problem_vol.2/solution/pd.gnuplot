#PD n/time dependency
set terminal png
set output 'img/PD_time.png'
set title "Dynamicke programovani - cena - delka behu"
set xlabel "pocet predmetu"
set ylabel "cas vypoctu [s]"
plot "PD.dat" using 1:3 title "normal dataset"

set terminal png
set output 'img/PD_exp_time.png'
set title "Dynamicke programovani - cena - exp - delka behu"
set xlabel "pocet predmetu"
set ylabel "cas vypoctu [s]"
plot "PD_exp.dat" using 1:3 title "experimental dataset"
