/*
 * Filename: /Users/Student/mandelbrot/init_sdl.c
 * Path: /Users/Student/mandelbrot
 * Created Date: Tuesday, May 12th 2020, 10:42:02 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#include "fractol.h"

t_fractol		init_sdl()
{
	t_fractol	fract;

	SDL_Init(SDL_INIT_EVERYTHING);
    fract.win = SDL_CreateWindow("SDL2 Pixel Drawing",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	fract.renderer = SDL_CreateRenderer(fract.win, -1, 0);
   	fract.texture = SDL_CreateTexture(fract.renderer,
        SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);
    fract.pixels = malloc(sizeof(Uint32) * 640 * 480);//new Uint32[640 * 480];
    memset(fract.pixels, 255, 640 * 480 * sizeof(Uint32));
	return (fract);
}