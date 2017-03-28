/* 
 * mandelbrot.h
 *
 * @author: phdenzel
 *
 * The Julia set generator
 *
 */

#ifndef JULIA_H
#define JULIA_H

#include "complex.h"


complex_t iterator(complex_t*, complex_t*);
int mandelbrot(complex_t*, complex_t*, double, double);
int julia(complex_t*, complex_t*, double, double);


#endif
