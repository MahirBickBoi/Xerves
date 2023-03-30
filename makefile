FILENAME = main

all:
	gcc -O3 Xerves.c init.c -o $(FILENAME)