CC=g++
CFLAGS="-std=c++11"

annealing: annealing.o main.o knapsack.o
	$(CC) -std=c++11 main.o annealing.o knapsack.o -o annealing

main.o: ./src/main.cpp
	$(CC) -std=c++11 -c ./src/main.cpp

annealing.o: ./src/annealing.cpp
	$(CC) -std=c++11 -c ./src/annealing.cpp

knapsack.o: ./src/knapsack.cpp
	$(CC) -std=c++11 -c ./src/knapsack.cpp

run: annealing
	./annealing

clean:
	rm annealing annealing.o main.o knapsack.o

