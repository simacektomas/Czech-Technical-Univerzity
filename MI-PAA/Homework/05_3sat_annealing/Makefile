CC=g++
CFLAGS="-std=c++11"

satannealing: annealing.o main.o satannealing.o
	$(CC) -std=c++11 main.o annealing.o satannealing.o -o annealing

main.o: ./src/main.cpp
	$(CC) -std=c++11 -c ./src/main.cpp

annealing.o: ./src/annealing.cpp
	$(CC) -std=c++11 -c ./src/annealing.cpp

satannealing.o: ./src/satannealing.cpp
	$(CC) -std=c++11 -c ./src/satannealing.cpp

clean:
	rm annealing annealing.o main.o satannealing.o

