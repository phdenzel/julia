# julia

A Julia set generator programmed in C using the SDL2 library.

Fractals are of great mathematical as well as artistical interest. They can be generated in different ways, **strange attractors** and **Lindenmayer systems** being some of the more prominent keys. 
The easiest way however, is **iterating a system of functions**, which probably reflects the self-similar, repetitive nature of fractals best.

Using 

```math
f(z) = z*z + c   | z,c are complex numbers
```
as iterative function, we can generate Julia sets, of which the Mandelbrot set is a specific variant.

### Install

To compile the code, cd into the directory and type

```bash
make julia
```

Prerequisite is the GNU compiler `gcc-6` or any other c-compiler. Just make sure to apply according adjustments to the `Makefile` if you want to use another compiler.

Another requirement is the c-library `<SDL2/SDL.h>`, for real-time graphics.
