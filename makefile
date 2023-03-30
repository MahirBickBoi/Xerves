FILENAME = main
SOURCES = $(wildcard *.c)

all:
	gcc -O3 $(SOURCES) -o $(FILENAME)