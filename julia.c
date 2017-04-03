/* 
 * mandelbrot.c
 *
 * @author: phdenzel
 *
 * The Julia set generator
 *
 */

#include "julia.h"
#include "complex.h"
#include "graphics.h"

#include <SDL2/SDL.h>


/* Global variables */
const int NMAX = 255;
int WIDTH = 640;
int HEIGHT = 480;
//double ORIGIN[2] = {-0.75, 0.};
double ORIGIN[2] = {0., 0.};
double PROJ[2] = {4, 4*0.75};
// the first index is being used for mouse events
complex_t cconst[9] = { {0., 0.},
                        {-0.8, 0.156},
                        {-0.7269, 0.1889},
                        {-0.61803398875, 0.},
                        {-0.4, 0.6},
                        {0.285, 0.01},
                        {-0.70176, 0.3842},
                        {-0.835, -0.2321},
                        {0, -0.8} };


/* Functions */
complex_t iterator(complex_t* z, complex_t* c) {
  complex_t z2 = complex_squarecpy(z);
  complex_t fz = complex_addcpy(&z2, c);
  return fz;
  
}

int mandelbrot(complex_t* z, complex_t* c, double x, double y) {

  c->real = linearMap(x, 0, WIDTH, ORIGIN[0]-PROJ[0]/2, ORIGIN[0]+PROJ[0]/2);
  c->imag = linearMap(y, 0, HEIGHT, ORIGIN[1]-PROJ[1]/2, ORIGIN[1]+PROJ[1]/2);
  
  int n = 0;
  while (n < NMAX) {
    if (complex_abs2(z) > 4) {
      break;
    }
    *z = iterator(z, c);
    n++;
  }
  *z = *c;
  return n;
  
}

int julia(complex_t* z, complex_t* c, double x, double y) {

  z->real = linearMap(x, 0, WIDTH, ORIGIN[0]-PROJ[0]/2, ORIGIN[0]+PROJ[0]/2);
  z->imag = linearMap(y, 0, HEIGHT, ORIGIN[1]-PROJ[1]/2, ORIGIN[1]+PROJ[1]/2);

  int n = 0;
  while (n < NMAX) {
    if (complex_abs2(z) > 4) {
      break;
    }
    *z = iterator(z, c);
    n++;
  }
  return n;
  
}


/* Main */
int main(void) {

  /* Init graphics */
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* texture;
  int is_running = 1;
  
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Mandelbrot",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            WIDTH, HEIGHT,
                            0);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  texture = SDL_CreateTexture(renderer,
                              SDL_PIXELFORMAT_ARGB8888,
                              SDL_TEXTUREACCESS_STATIC,
                              WIDTH, HEIGHT);
  
  Uint32* pixels = malloc(WIDTH*HEIGHT*sizeof(Uint32));
  memset(pixels, 0, WIDTH*HEIGHT*sizeof(Uint32));
  
  /* Mandelbrot algorithm */
  complex_t z = {0.0, 0.0};
  complex_t c = cconst[1];
  int n = 0;
  int x = 0;
  int y = 0;
  
  /* Clean-up */
  while (is_running) {
    
    is_running = processEvents(window, is_running, 1); // w/ mouse tracking
    #pragma omp simd
    for (int i = 0; i<WIDTH*HEIGHT; i++) {
      c = cconst[0];
      // linear map pixel coordinates
      x = i%WIDTH; // pixel coord in x
      y = i/WIDTH; // pixel coord in y
      /* n = mandelbrot(&z, &c, x, y); */
      n = julia(&z, &c, x, y);
      /* pixels[i] = getPixelColor(n, n, n, 255); */
      /* pixels[i] = singulettMagmaCM(n%256);  */
      pixels[i] = singulettParulaCM(n%256);
    }
    /* Project to Renderer and then to Window */
    SDL_UpdateTexture(texture, NULL, pixels, WIDTH*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_Delay(100);
      
  }
  
  free(pixels);
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texture);
  SDL_Quit();
  
}
