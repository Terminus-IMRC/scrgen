CFLAGS=-O3

all: scrgen
scrgen: scrgen.o
scrgen.o: scrgen.c
clean:
	$(RM) scrgen.o scrgen

.PHONY: clean
