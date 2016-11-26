#!/bin/bash
# Max weight differs
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 21 -C 40 -d 0 2>/dev/null > ../weight/weight_21.dat  
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 32 -C 40 -d 0 2>/dev/null > ../weight/weight_32.dat  
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 64 -C 40 -d 0 2>/dev/null > ../weight/weight_64.dat  
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 128 -C 40 -d 0 2>/dev/null > ../weight/weight_128.dat  
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 256 -C 40 -d 0 2>/dev/null > ../weight/weight_256.dat  
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 512 -C 40 -d 0 2>/dev/null > ../weight/weight_512.dat  
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 1024 -C 40 -d 0 2>/dev/null > ../weight/weight_1024.dat  
# Max price differs
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 16 -d 0 2>/dev/null > ../price/price_16.dat
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 32 -d 0 2>/dev/null > ../price/price_32.dat
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 64 -d 0 2>/dev/null > ../price/price_64.dat
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 128 -d 0 2>/dev/null > ../price/price_128.dat
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 256 -d 0 2>/dev/null > ../price/price_256.dat
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 512 -d 0 2>/dev/null > ../price/price_512.dat
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 1024 -d 0 2>/dev/null > ../price/price_1024.dat
# Ratio of capacity and weight summary
./knapgen -n 20 -N 50 -m 0.1 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../ratio/ratio_0.1.dat
./knapgen -n 20 -N 50 -m 0.2 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../ratio/ratio_0.2.dat
./knapgen -n 20 -N 50 -m 0.3 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../ratio/ratio_0.3.dat
./knapgen -n 20 -N 50 -m 0.4 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../ratio/ratio_0.4.dat
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../ratio/ratio_0.5.dat
./knapgen -n 20 -N 50 -m 0.6 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../ratio/ratio_0.6.dat
./knapgen -n 20 -N 50 -m 0.7 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../ratio/ratio_0.7.dat
./knapgen -n 20 -N 50 -m 0.8 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../ratio/ratio_0.8.dat
./knapgen -n 20 -N 50 -m 0.9 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../ratio/ratio_0.9.dat
./knapgen -n 20 -N 50 -m 1 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../ratio/ratio_1.dat
# Granularity
./knapgen -n 20 -N 50 -m 0.5 -k 0.25 -W 30 -C 40 -d -1 2>/dev/null > ../granul/negative/granul_0.25
./knapgen -n 20 -N 50 -m 0.5 -k 0.5 -W 30 -C 40 -d -1 2>/dev/null > ../granul/negative/granul_0.5
./knapgen -n 20 -N 50 -m 0.5 -k 1 -W 30 -C 40 -d -1 2>/dev/null > ../granul/negative/granul_1
./knapgen -n 20 -N 50 -m 0.5 -k 1.5 -W 30 -C 40 -d -1 2>/dev/null > ../granul/negative/granul_1.5
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 40 -d -1 2>/dev/null > ../granul/negative/granul_2
./knapgen -n 20 -N 50 -m 0.5 -k 3 -W 30 -C 40 -d -1 2>/dev/null > ../granul/negative/granul_3

./knapgen -n 20 -N 50 -m 0.5 -k 0.25 -W 30 -C 40 -d 0 2>/dev/null > ../granul/neutral/granul_0.25
./knapgen -n 20 -N 50 -m 0.5 -k 0.5 -W 30 -C 40 -d 0 2>/dev/null > ../granul/neutral/granul_0.5
./knapgen -n 20 -N 50 -m 0.5 -k 1 -W 30 -C 40 -d 0 2>/dev/null > ../granul/neutral/granul_1
./knapgen -n 20 -N 50 -m 0.5 -k 1.5 -W 30 -C 40 -d 0 2>/dev/null > ../granul/neutral/granul_1.5
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 40 -d 0 2>/dev/null > ../granul/neutral/granul_2
./knapgen -n 20 -N 50 -m 0.5 -k 3 -W 30 -C 40 -d 0 2>/dev/null > ../granul/neutral/granul_3

./knapgen -n 20 -N 50 -m 0.5 -k 0.25 -W 30 -C 40 -d 1 2>/dev/null > ../granul/positive/granul_0.25
./knapgen -n 20 -N 50 -m 0.5 -k 0.5 -W 30 -C 40 -d 1 2>/dev/null > ../granul/positive/granul_0.5
./knapgen -n 20 -N 50 -m 0.5 -k 1 -W 30 -C 40 -d 1 2>/dev/null > ../granul/positive/granul_1
./knapgen -n 20 -N 50 -m 0.5 -k 1.5 -W 30 -C 40 -d 1 2>/dev/null > ../granul/positive/granul_1.5
./knapgen -n 20 -N 50 -m 0.5 -k 2 -W 30 -C 40 -d 1 2>/dev/null > ../granul/positive/granul_2
./knapgen -n 20 -N 50 -m 0.5 -k 3 -W 30 -C 40 -d 1 2>/dev/null > ../granul/positive/granul_3


