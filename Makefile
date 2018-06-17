CC=g++
CFLAGS= #-Wall -Werror

.PHONY: default clean

default: bin/kurs bin/verbs

bin/verbs: src/verbs
	cp src/verbs bin/verbs

bin/kurs: bin build/main.o
	$(CC) $(CFLAGS) build/main.o -o bin/kurs

build/main.o: build src/main.cpp src/data.h src/mainconst.h
	$(CC) $(CFLAGS) -c src/main.cpp -o build/main.o

bin:
	mkdir bin

build:
	mkdir build

clean:
	rm -rf bin build
