/* 
 * graphics.h
 *
 * @author: phdenzel
 *
 * Graphics utility for Julia set generator
 *
 */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

double linearMap(double, double, double, double, double);
Uint32 getPixelColor(unsigned char, unsigned char, unsigned char,
                     unsigned char);
Uint32 singulettParulaCM(unsigned char);
Uint32 singulettMagmaCM(unsigned char);
int processEvents(SDL_Window *, int, int);

#endif
