CC=g++
CFLAGS="-std=c++11"

knapsack.vol2: knapsack.vol2.o
	$(CC) -std=c++11 knapsack.vol2.o -o knapsack.vol2

knapsack.vol2.o: ./src/knapsack.vol2.cpp
	$(CC) -std=c++11 -c ./src/knapsack.vol2.cpp 

run: knapsack.vol2
	./knapsack.vol2

clean:
	rm knapsack.vol2 knapsack.vol2.o

