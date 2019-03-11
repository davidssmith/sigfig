ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

CC=cc
CFLAGS=-O2 -g
LFLAGS=-lm

objects = sigfig.o

all: sigfig

sigfig: $(objects)
	$(CC) $(objects) -o sigfig $(LFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -dc $< -o $@ $(LFLAGS)

clean:
	rm -f *.o sigfig

install: sigfig
	install -m 0755 sigfig $(PREFIX)/bin
