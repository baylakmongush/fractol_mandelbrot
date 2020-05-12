/*
 * Filename: /Users/Student/mandelbrot/main.c
 * Path: /Users/Student/mandelbrot
 * Created Date: Tuesday, May 12th 2020, 9:35:08 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#include "fractol.h"

int             main()
{
    t_fractol   fract;
    t_color     color;
    t_cl        cl;

    fract = init_sdl();
    cl = init_cl();
    fract.is_running = 1;
    while (fract.is_running) {
        while (SDL_PollEvent(&fract.event)) {
            if (fract.event.type == SDL_QUIT) {
                fract.is_running = 0;
       		}
    	}

        color.r = 0, color.g = 0, color.b = 255;
        put_pixel_sdl(fract, 120, 120, color);
        color.r = 0, color.g = 0, color.b = 255;
        put_pixel_sdl(fract, 121, 121, color);

    	fract.texture = SDL_CreateTextureFromSurface(fract.renderer, fract.surface);
        SDL_RenderCopy(fract.renderer, fract.texture, NULL, NULL);    
        SDL_DestroyTexture(fract.texture);
        SDL_RenderPresent(fract.renderer);
	}
    destroy_sdl(fract);
    return (0);
}