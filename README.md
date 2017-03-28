# julia

A Julia set generator programmed in C using the SDL2 library.

Fractals are both mathematically as well as artistically highly interesting. They can be generated in different ways, **strange attractors** and **Lindenmayer systems** being some of the more prominent methods. 
The easiest way though is **iterating a system of functions**, which probably reflects the self-similar, repetitive nature of fractals the best.

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
