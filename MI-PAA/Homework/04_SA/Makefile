CC=g++
CFLAGS="-std=c++11"

knapcooling: knapcooling.o
	$(CC) -std=c++11 knapcooling.o -o knapcooling

knapcooling.o: ./src/knapcooling.cpp
	$(CC) -std=c++11 -c ./src/knapcooling.cpp 

run: knapcooling
	./knapcooling

clean:
	rm knapcooling knapcooling.o

