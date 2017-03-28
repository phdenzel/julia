/* 
 * complex.c
 *
 * @author: phdenzel
 *
 * A complex number struct with basic complex operations
 *
 */

#include "complex.h"

double complex_real(complex_t* z) {
  return z->real;
  
}

double complex_imag(complex_t* z) {
  return z->imag;
  
}

void complex_setReal(complex_t* z, double r) {
  z->real = r;
  
}

void complex_setImag(complex_t* z, double i) {
  z->imag = i;
  
}

void complex_set(complex_t* z, double r, double i) {
  complex_setReal(z, r);
  complex_setImag(z, i);
  
}

void complex_add(complex_t* z2, complex_t* z1) {
  z1->real += z2->real;
  z1->imag += z2->real;
  
}

complex_t complex_addcpy(complex_t* z2, complex_t* z1) {
  complex_t z;
  z.real = z1->real + z2->real;
  z.imag = z1->imag + z2->imag;
  return z;
  
}

void complex_square(complex_t* z) {
  double re, im;
  re = z->real;
  im = z->imag;
  z->real = re*re - im*im;
  z->imag = 2*re*im;
  
}

complex_t complex_squarecpy(complex_t* z) {
  complex_t v;
  v.real = z->real*z->real - z->imag*z->imag;
  v.imag = 2*z->real*z->imag;
  return v;
  
}

double complex_abs2(complex_t* z) {
  return z->real*z->real+z->imag*z->imag;
  
}
