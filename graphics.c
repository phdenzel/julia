/* 
 * graphics.c
 *
 * @author: phdenzel
 *
 * Graphics utility for Julia set generator
 *
 */

#include "graphics.h"
#include "complex.h"

#include <SDL2/SDL.h>

extern int WIDTH;
extern int HEIGHT;
extern double ORIGIN[2];
extern double PROJ[2];
extern complex_t cconst[9];


double linearMap(double val, double A, double B, double a, double b) {
  // linearly map a value in [A, B] -> [a, b]
  return (val-A)*(b-a)/(B-A) + a;
  
}

Uint32 singulettParulaCM(unsigned char c) {
  // give a value between 0...255 an rbg ratio
  Uint32 color;
  double r, g, b;
  
  if (0 <= c && c <= 13) {
    r = 0.2;
    g = linearMap(c, 0, 34, 0.15, 0.4);
    b = linearMap(c, 0, 34, 0.55, 0.9);
  } else if (13 < c && c <= 34) {
    r = linearMap(c, 13, 34, 0.2, 0);
    g = linearMap(c, 0, 34, 0.15, 0.4);
    b = linearMap(c, 0, 34, 0.55, 0.9);
  } else if (34 < c && c <= 63) {
    r = linearMap(c, 34, 64, 0, 0.1);
    g = linearMap(c, 34, 125, 0.4, 0.7);
    b = linearMap(c, 34, 100, 0.9, 0.75);
  } else if (63 < c && c <= 100) {
    r = linearMap(c, 63, 100, 0.1, 0);
    g = linearMap(c, 34, 125, 0.4, 0.7);
    b = linearMap(c, 34, 100, 0.9, 0.75);
  } else if (100 < c && c <= 125) {
    r = linearMap(c, 100, 212, 0, 1);
    g = linearMap(c, 34, 125, 0.4, 0.7);
    b = linearMap(c, 100, 255, 0.75, 0.05);
  } else if (125 < c && c <= 150) {
    r = linearMap(c, 100, 212, 0, 1);
    g = linearMap(c, 125, 150, 0.7, 0.75);
    b = linearMap(c, 100, 255, 0.75, 0.05);
  } else if (150 < c && c <= 212) {
    r = linearMap(c, 100, 212, 0, 1);
    g = linearMap(c, 150, 212, 0.75, 0.7);
    b = linearMap(c, 100, 255, 0.75, 0.05);
  } else if (212 < c && c <= 250) {
    r = linearMap(c, 212, 250, 1, 0.95);
    g = linearMap(c, 212, 255, 0.7, 1);
    b = linearMap(c, 100, 255, 0.75, 0.05);
  } else if (250 < c && c <= 254) {
    r = linearMap(c, 250, 255, 0.95, 0.96);
    g = linearMap(c, 212, 255, 0.7, 1);
    b = linearMap(c, 100, 255, 0.75, 0.05);
  } else {
    r = 0.2;
    g = 0.2;
    b = 0.2;
  }
  color = getPixelColor((unsigned char)(r*255),
                        (unsigned char)(g*255),
                        (unsigned char)(b*255),
                        255);
  return color;
  
}

Uint32 singulettMagmaCM(unsigned char c) {
  // give a value between 0...255 an rbg ratio
  Uint32 color;
  double r, g, b;
  
  if (0 <= c && c <= 26) {
    r = linearMap(c, 0, 26, 0, 0.1);
    g = linearMap(c, 0, 38, 0, 0.15);
    b = linearMap(c, 0, 51, 0, 0.475);
  } else if (26 < c && c <= 38) {
    r = linearMap(c, 26, 166, 0.1, 0.95);
    g = linearMap(c, 0, 38, 0, 0.15);
    b = linearMap(c, 0, 51, 0, 0.475);
  } else if (38 < c && c <= 51) {
    r = linearMap(c, 26, 166, 0.1, 0.95);
    g = linearMap(c, 38, 57, 0.15, 0.09);
    b = linearMap(c, 0, 51, 0, 0.475);
  } else if (51 < c && c <= 57) {
    r = linearMap(c, 26, 166, 0.1, 0.95);
    g = linearMap(c, 38, 57, 0.15, 0.09);
    b = linearMap(c, 51, 77, 0.475, 0.5);
  } else if (57 < c && c <= 77) {
    r = linearMap(c, 26, 166, 0.1, 0.95);
    g = linearMap(c, 57, 153, 0.15, 0.25);
    b = linearMap(c, 51, 77, 0.475, 0.5);
  } else if (77 < c && c <= 128) {
    r = linearMap(c, 26, 166, 0.1, 0.95);
    g = linearMap(c, 57, 153, 0.15, 0.25);
    b = linearMap(c, 77, 128, 0.5, 0.45);
  } else if (128 < c && c <= 153) {
    r = linearMap(c, 26, 166, 0.1, 0.95);
    g = linearMap(c, 57, 153, 0.15, 0.25);
    b = linearMap(c, 128, 178, 0.45, 0.35);
  } else if (153 < c && c <= 166) {
    r = linearMap(c, 26, 166, 0.1, 0.95);
    g = linearMap(c, 153, 255, 0.25, 0.98);
    b = linearMap(c, 128, 178, 0.45, 0.35);
  } else if (166 < c && c <= 178) {
    r = linearMap(c, 166, 204, 0.95, 1.0);
    g = linearMap(c, 153, 255, 0.25, 0.98);
    b = linearMap(c, 128, 178, 0.45, 0.35);
  } else if (178 < c && c <= 204) {
    r = linearMap(c, 166, 204, 0.95, 1.0);
    g = linearMap(c, 153, 255, 0.25, 0.98);
    b = linearMap(c, 178, 255, 0.35, 0.75);
  } else if (204 < c && c <= 255) {
    r = linearMap(c, 204, 255, 1.0, 0.98);
    g = linearMap(c, 153, 255, 0.25, 0.98);
    b = linearMap(c, 178, 255, 0.35, 0.75);
  } else {
    r = 0;
    g = 0;
    b = 0;
  }
  color = getPixelColor((unsigned char)(r*255),
                        (unsigned char)(g*255),
                        (unsigned char)(b*255),
                        255);
  return color;
  
}

Uint32 getPixelColor(unsigned char r, unsigned char g, unsigned char b,
                     unsigned char alpha) {
  // in hex format: 0x + ALPHA_hex + RED_hex + GREEN_hex + BLUE_hex
  return (alpha << 24) + (r << 16) + (g << 8) + b;
  
}

int processEvents(SDL_Window *window, int is_running, int mTracking) {
  // close in certain situations
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_WINDOWEVENT_CLOSE: {
      if (window) {
        SDL_DestroyWindow(window);
        window = NULL;
        is_running = 0;
      }
    } break;
    case SDL_MOUSEMOTION: {
      if (mTracking) {
        complex_t c = {linearMap(event.motion.x, 0, WIDTH, -1, 1),
                       linearMap(event.motion.y, 0, HEIGHT, -1, 1)};
        cconst[0] = c;
      } else {
        cconst[0] = cconst[1];
      }
    } break;
    case SDL_QUIT: {
      is_running = 0;
    } break;   
    }
  }
  
  return is_running;
  
}
