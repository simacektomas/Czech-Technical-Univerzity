#FPTAS n/time dependency
#set terminal png
#set output 'img/FPTAS_time.png'
#set title "FPTAS algoritmus - delka behu"
#set xlabel "pocet predmetu"
#set ylabel "cas vypoctu"
#plot "FPTAS.dat" using 1:3 title "normal dataset"

#set terminal png
#set output 'img/FPTAS_exp_time.png'
#set title "FPTAS algoritmus - exp - delka behu"
#set xlabel "pocet predmetu"
#set ylabel "cas vypoctu"
#plot "FPTAS_exp.dat" using 1:3 title "experimental dataset"
#FPTAS epsilon 0.01
set terminal png
set output 'img/FPTAS_0.01_time.png'
set title "FPTAS algoritmus - epsilon 0.01 - delka behu"
set xlabel "pocet predmetu"
set ylabel "cas vypoctu"
set key top left
plot "FPTAS_err_0.01.dat" using 1:3 title "DP - normal dataset", "FPTAS_err_0.01.dat" using 1:4 title "FPTAS 0.01 - normal dataset"
#FPTAS epsilon 0.01 error
set terminal png
set output 'img/FPTAS_0.01_err.png'
set title "FPTAS algoritmus - epsilon 0.01 - prumerna a maximalni chyba"
set xlabel "pocet predmetu"
set ylabel "relativni chyba"
set key top left
plot "FPTAS_err_0.01.dat" using 1:5 title "prumerna relativni chyba", "FPTAS_err_0.01.dat" using 1:6 title "maximalni relativni chyba"
#FPTAS epsilon 0.1
set terminal png
set output 'img/FPTAS_0.1_time.png'
set title "FPTAS algoritmus - epsilon 0.1 - delka behu"
set xlabel "pocet predmetu"
set ylabel "cas vypoctu"
set key top left
plot "FPTAS_err_0.1.dat" using 1:3 title "DP - normal dataset", "FPTAS_err_0.1.dat" using 1:4 title "FPTAS 0.1 - normal dataset"

#FPTAS epsilon 0.1 error
set terminal png
set output 'img/FPTAS_0.1_err.png'
set title "FPTAS algoritmus - epsilon 0.1 - prumerna a maximalni chyba"
set xlabel "pocet predmetu"
set ylabel "relativni chyba"
set key top right
plot "FPTAS_err_0.1.dat" using 1:5 title "prumerna relativni chyba", "FPTAS_err_0.1.dat" using 1:6 title "maximalni relativni chyba"

#FPTAS epsilon 0.3
set terminal png
set output 'img/FPTAS_0.3_time.png'
set title "FPTAS algoritmus - epsilon 0.3 - delka behu"
set xlabel "pocet predmetu"
set ylabel "cas vypoctu"
set key top left
plot "FPTAS_err_0.3.dat" using 1:3 title "DP - normal dataset", "FPTAS_err_0.3.dat" using 1:4 title "FPTAS 0.3 - normal dataset"

#FPTAS epsilon 0.3 error
set terminal png
set output 'img/FPTAS_0.3_err.png'
set title "FPTAS algoritmus - epsilon 0.3 - prumerna a maximalni chyba"
set xlabel "pocet predmetu"
set ylabel "relativni chyba"
set key top right
plot "FPTAS_err_0.3.dat" using 1:5 title "prumerna relativni chyba", "FPTAS_err_0.3.dat" using 1:6 title "maximalni relativni chyba"

#FPTAS epsilon 0.6
set terminal png
set output 'img/FPTAS_0.6_time.png'
set title "FPTAS algoritmus - epsilon 0.6 - delka behu" 
set xlabel "pocet predmetu"
set ylabel "cas vypoctu"
set key top left
plot "FPTAS_err_0.6.dat" using 1:3 title "DP - normal dataset", "FPTAS_err_0.6.dat" using 1:4 title "FPTAS 0.6 - normal dataset"

#FPTAS epsilon 0.6 error
set terminal png
set output 'img/FPTAS_0.6_err.png'
set title "FPTAS algoritmus - epsilon 0.6 - prumerna a maximalni chyba"
set xlabel "pocet predmetu"
set ylabel "relativni chyba"
set key top right
plot "FPTAS_err_0.6.dat" using 1:5 title "prumerna relativni chyba", "FPTAS_err_0.6.dat" using 1:6 title "maximalni relativni chyba"

#FPTAS epsilon 0.9
set terminal png 
set output 'img/FPTAS_0.9_time.png'
set title "FPTAS algoritmus - epsilon 0.9 - delka behu"
set xlabel "pocet predmetu"
set ylabel "cas vypoctu"
set key top left
plot "FPTAS_err_0.9.dat" using 1:3 title "DP - normal dataset", "FPTAS_err_0.9.dat" using 1:4 title "FPTAS 0.9 - normal dataset"

#FPTAS epsilon 0.9 error
set terminal png
set output 'img/FPTAS_0.9_err.png'
set title "FPTAS algoritmus - epsilon 0.9 - prumerna a maximalni chyba"
set xlabel "pocet predmetu"
set ylabel "relativni chyba"
set key top right
plot "FPTAS_err_0.9.dat" using 1:5 title "prumerna relativni chyba", "FPTAS_err_0.9.dat" using 1:6 title "maximalni relativni chyba"
