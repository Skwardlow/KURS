CC=g++
CFLAGS=-Wall -Werror

.PHONY: default clean

default: bin/kurs

bin/kurs: bin build/main.o
	$(CC) $(CFLAGS) build/main.o -o bin/kurs

build/main.o: build src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp -o build/main.o

bin:
	mkdir bin

build:
	mkdir build

clean:
	rm -rf bin build
