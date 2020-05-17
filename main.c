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
    size_t			local = 64;
	size_t			global = SCREEN_HEIGHT * SCREEN_WIDTH;
    t_fractol   fract;
    t_color     color;
    t_cl        cl;

    fract = init_sdl();
    cl = init_cl();
    fract.is_running = 1;
    while (fract.is_running) {
        while (SDL_PollEvent(&fract.event)) {
            if (fract.event.type == SDL_QUIT || fract.event.key.keysym.sym == SDLK_ESCAPE) {
                fract.is_running = 0;
       		}
    	}
        if (fract.event.key.keysym.sym == SDLK_0)
        {
            cl.data = clCreateBuffer(cl.context, CL_MEM_WRITE_ONLY, 600 * 800 * sizeof(int), NULL, &cl.err);
           // clEnqueueWriteBuffer(cl.commands, cl.data, CL_TRUE, 0, 600 * 800 * sizeof(int),  , 0, NULL, NULL);
            cl.err  = clSetKernelArg(cl.kernel, 0, sizeof(cl_mem), &cl.data);
            cl.err = clEnqueueNDRangeKernel(cl.commands, cl.kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
            cl.err = clEnqueueReadBuffer(cl.commands, cl.data, CL_FALSE, 0, 600 * 800 * sizeof(int), fract.surface->pixels, 0, NULL, NULL);
        }
    	fract.texture = SDL_CreateTextureFromSurface(fract.renderer, fract.surface);
        SDL_RenderCopy(fract.renderer, fract.texture, NULL, NULL);    
        SDL_DestroyTexture(fract.texture);
        SDL_RenderPresent(fract.renderer);
	}
    clFinish(cl.commands);
	clReleaseMemObject(cl.data);
    clReleaseCommandQueue(cl.commands);
    clReleaseContext(cl.context);
    destroy_sdl(fract);
    return (0);
}