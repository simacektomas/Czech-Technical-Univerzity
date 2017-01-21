CC=g++
CFLAGS="-std=c++11"

satannealing: annealing.o main.o satannealing.o
	$(CC) -O3 -std=c++11 main.o annealing.o satannealing.o -o annealing

main.o: ./src/main.cpp
	$(CC) -O3 -std=c++11 -c ./src/main.cpp

annealing.o: ./src/annealing.cpp
	$(CC) -O3 -std=c++11 -c ./src/annealing.cpp

satannealing.o: ./src/satannealing.cpp
	$(CC) -O3 -std=c++11 -c ./src/satannealing.cpp

clean:
	rm annealing annealing.o main.o satannealing.o

