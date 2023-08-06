/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:30:55 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/06 10:24:20 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "macros.h"

# define ESC 53
# define H 1000
# define W 1000
# define S_UP 4
# define S_DOWN 5

typedef struct s_win
{
	void	*mptr;
	void	*wptr;
	int		h;
	int		w;
}			t_win;

typedef struct s_img {
	t_win	win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	int		row;
	int		col;
	float	c_re;
	float	c_im;
	int		i;
	float	x;
	float	y;
	char	*name;
	float	julia1;
	float	julia2;
	int		plus_color;
	int		pause_mov;
}			t_fractal;

typedef struct s_move
{
	float	x;
	float	y;
	float	z;
	int		iter;
}			t_move;

typedef struct s_all
{
	t_win		win;
	t_img		*img;
	t_fractal	*fractal;
	t_move		*mv;
}				t_all;

typedef int	(*t_colors)(int);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_win	new_program(int w, int h, char *str);
t_img	new_img(t_win window);

t_all	start_all(t_img *img, t_win win, t_fractal *fractal, t_move *mv);
void	start_fractal(t_fractal *fractal);
float	absolutvodka(float f);

/*HOOKS*/
int		read_key(int press_key, t_all *all);
int		read_mouse_scroll(int button, int x, int y, t_all *all);
int		mouse_move(int x, int y, t_all *all);

/*MASKS FT*/
int		exit_win(t_win *win);
void	zoom(t_all *all, int n);

/* FRACTALES */
void	mandelbrot(t_all *all);
void	julia(t_all *all);
void	ship(t_all *all);
//void	sierpienski(t_all *all);

/* COLORS */
void	put_color_px(int i, t_fractal *fractal, t_img *img, int iter);
#endif