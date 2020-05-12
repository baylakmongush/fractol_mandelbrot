/*
 * Filename: /Users/Student/mandelbrot/destroy_sdl.c
 * Path: /Users/Student/mandelbrot
 * Created Date: Tuesday, May 12th 2020, 10:59:35 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#include "fractol.h"

void	destroy_sdl(t_fractol fract)
{
	SDL_FreeSurface(fract.surface);
    SDL_DestroyRenderer(fract.renderer);
    SDL_DestroyWindow(fract.win);
    SDL_Quit();
}