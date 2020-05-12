/*
 * Filename: /Users/Student/mandelbrot/src/init_cl.c
 * Path: /Users/Student/mandelbrot/src
 * Created Date: Tuesday, May 12th 2020, 11:50:22 pm
 * Author: Student
 * 
 * Copyright (c) 2020 Your Company
 */

#include "fractol.h"

t_cl		init_cl()
{
	t_cl	cl;

	cl.err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &cl.device_id, NULL);
	if (cl.err != CL_SUCCESS)
	{
		write(1, "Error: Failed to create a device group!\n", 40);
	}
	cl.context = clCreateContext(0, 1, &cl.device_id, NULL, NULL, &cl.err);
	if (!cl.context)
	{
		write(1, "Error: Failed to create a compute context!\n", 43);
	}
	cl.commands = clCreateCommandQueue(cl.context, cl.device_id, 0, &cl.err);
	// check cl.commands printf("Error: Failed to create a command commands!\n");
	cl.program = clCreateProgramWithSource(cl.context, 1, (const char **) & cl.fractol, ls, &cl.err);
	// check cl.program printf("Error: Failed to create compute program!\n");
	return (cl);
}