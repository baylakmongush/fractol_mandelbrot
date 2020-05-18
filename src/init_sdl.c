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
    fract.win = SDL_CreateWindow("mandelbrot", 
                                       SDL_WINDOWPOS_UNDEFINED,
                                       SDL_WINDOWPOS_UNDEFINED,
									   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    fract.renderer = SDL_CreateRenderer(fract.win, -1, SDL_RENDERER_ACCELERATED);
	fract.surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
	fract.texture = SDL_CreateTexture(fract.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
	return (fract);
}