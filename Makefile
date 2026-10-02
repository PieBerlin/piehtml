flags=-O2 -Wall -std=c23
ldflags=-L/usr/local/lib -lpieutils

.PHONY: all clean

all: clean piehtml

piehtml: piehtml.o helpers.o constructors.o 
	cc ${flags} $^ -o $@ ${ldflags}


piehtml.o: piehtml.c piehtml.h 
	cc ${flags} -c $<

helpers.o: helpers.c
	cc ${flags} -c $<

constructors.o: constructors.c 
	cc ${flags} -c $<

clean:
	rm -f *.o piehtml 
