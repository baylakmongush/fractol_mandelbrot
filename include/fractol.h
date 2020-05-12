/*
 * Filename: /Users/Student/mandelbrot/include/fractol.h
 * Path: /Users/Student/mandelbrot/include
 * Created Date: Tuesday, May 12th 2020, 10:09:25 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#ifdef __APPLE__ 
# include <OpenCL/OpenCL.h> 
# else
# include <OpenCL/cl.h> 
#endif

#ifndef FRACTOL_H
# define FRACTOL_H
# define SCREEN_HEIGHT	600
# define SCREEN_WIDTH	800
# include "SDL2/SDL.h"
# include <unistd.h>

typedef struct			s_fractol
{
	SDL_Window			*win;
	SDL_Event			event;
	SDL_Renderer		*renderer;
	SDL_Surface			*surface;
	SDL_Texture			*texture;
	int					is_running;
}						t_fractol;

typedef struct			s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

typedef struct			s_cl
{
	int					err;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				input;
	cl_mem				output;
	char				*fractol;
}						t_cl;

t_fractol				init_sdl();
void    				put_pixel_sdl(t_fractol fract, int x, int y, t_color color);
void					destroy_sdl(t_fractol fract);
t_cl					init_cl();

#endif