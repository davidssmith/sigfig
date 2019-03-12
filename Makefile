ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

CC=cc
CFLAGS=-I. -O2
LFLAGS=-lm

sigfig: sigfig.o
	     $(CC) -o sigfig sigfig.o $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(LFLAGS)

clean:
	rm -f *.o sigfig

install: sigfig
	install -m 0755 sigfig $(PREFIX)/bin
