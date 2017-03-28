CC=gcc-6
CFLAGS=-Wall -g -O3
OMP= #-fopenmp
CFLAGS+= $(OMP)
SDLFLAGS=`sdl2-config --cflags --libs`

all: julia

julia: julia.o complex.o graphics.o
	$(CC) $(CFLAGS) $(SDLFLAGS) $^ -o $@

julia.o: julia.c julia.h
	$(CC) $(CFLAGS) -c $< -o $@

complex.o: complex.c complex.h
	$(CC) $(CFLAGS) -c $< -o $@

graphics.o: graphics.c graphics.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	-rm -rf *.o julia julia.dSYM
