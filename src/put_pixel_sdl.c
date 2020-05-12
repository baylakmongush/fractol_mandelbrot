/*
 * Filename: /Users/Student/mandelbrot/put_pixel_sdl.c
 * Path: /Users/Student/mandelbrot
 * Created Date: Tuesday, May 12th 2020, 11:13:05 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#include "fractol.h"

void    put_pixel_sdl(t_fractol fract, int x, int y, t_color color)
{
    if (x > 0 && x <= SCREEN_WIDTH && y > 0 && y <= SCREEN_HEIGHT)
    {
        ((unsigned char*)fract.surface->pixels)[4 * (y * fract.surface->w + x) + 0] = color.b;
        ((unsigned char*)fract.surface->pixels)[4 * (y * fract.surface->w + x) + 1] = color.g;
        ((unsigned char*)fract.surface->pixels)[4 * (y * fract.surface->w + x) + 2] = color.r;
        ((unsigned char*)fract.surface->pixels)[4 * (y * fract.surface->w + x) + 3] = 1;
    }
}