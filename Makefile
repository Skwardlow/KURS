CC=g++
CFLAGS=-w

.PHONY: all default test clean

all: default test

default: bin/kurs bin/verbs

test: bin/test bin/verbs
	bin/test

bin/test: bin build/test.o
	$(CC) $(CFLAGS) build/test.o -o bin/test

build/test.o: build test/main.cpp src/data.h src/mainconst.h
	$(CC) $(CFLAGS) -I src -c test/main.cpp -o build/test.o

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
