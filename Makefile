NAME	=	fractol

SRC		=	init_sdl.c put_pixel_sdl.c destroy_sdl.c init_cl.c

$(NAME): all

SRC_FILES = $(addprefix src/, $(SRC))
all:
	@gcc main.c $(SRC_FILES) -I include -L lib -l SDL2 -framework OpenCL -o $(NAME)

clean:
	@rm -rf $(NAME)
