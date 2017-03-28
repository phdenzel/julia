/* 
 * complex.h
 *
 * @author: phdenzel
 *
 * A complex number struct with basic complex operations
 *
 */

#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex {

  double real;
  double imag;
  
} complex_t;


double complex_real(complex_t *);
double complex_imag(complex_t *);
void complex_setReal(complex_t *, double);
void complex_setImag(complex_t *, double);
void complex_set(complex_t *, double, double);
void complex_add(complex_t *, complex_t *);
complex_t complex_addcpy(complex_t *, complex_t *);
void complex_square(complex_t *);
complex_t complex_squarecpy(complex_t *);
double complex_abs2(complex_t *);

#endif
