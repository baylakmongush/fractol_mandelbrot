/*
 * Filename: /Users/Student/mandelbrot/main.c
 * Path: /Users/Student/mandelbrot
 * Created Date: Tuesday, May 12th 2020, 9:35:08 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#include "fractol.h"
#include <stdio.h>

int             main()
{
    size_t			local = 64;
    t_fractol       fract;
	size_t			global[] = {800, 600};
    t_color     color;
    t_cl        cl;

    fract = init_sdl();
    cl = init_cl();
    cl.data = clCreateBuffer(cl.context, CL_MEM_WRITE_ONLY, 800 * 600 * sizeof(int), NULL, &cl.err);
    cl.err  = clSetKernelArg(cl.kernel, 0, sizeof(cl_mem), &cl.data);
    cl.err = clEnqueueNDRangeKernel(cl.commands, cl.kernel, 1, NULL, global, NULL, 0, 0, 0);
    cl.err = clEnqueueReadBuffer(cl.commands, cl.data, CL_TRUE, 0, 800 * 600 * sizeof(int), fract.surface->pixels, 0, NULL, NULL);
   /* if (!cl.err)
    {
        printf("ERROR\n");
        exit(0);
    }*/
    SDL_UpdateTexture(fract.texture, NULL, fract.surface->pixels, fract.surface->pitch);
    SDL_RenderCopy(fract.renderer, fract.texture, NULL, NULL);    
    SDL_DestroyTexture(fract.texture);
    SDL_RenderPresent(fract.renderer);
    fract.is_running = 1;
    while (fract.is_running) {
        while (SDL_PollEvent(&fract.event)) {
            if (fract.event.type == SDL_QUIT || fract.event.key.keysym.sym == SDLK_ESCAPE) {
                fract.is_running = 0;
       		}
    	}
	}
    clFinish(cl.commands);
	clReleaseMemObject(cl.data);
    clReleaseCommandQueue(cl.commands);
    clReleaseContext(cl.context);
    destroy_sdl(fract);
    return (0);
}