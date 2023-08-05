/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:32:52 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/05 21:09:49 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	read_key(int press_key, t_all *all)
{
	if (press_key == ESC || !all->img)
		exit_win(&all->img->win);
	else if (press_key == SPACE)
		all->fractal->pause_mov *= -1;
	else if (press_key == ARROW_LEFT || press_key == A)
		all->mv->x -= 20.0f;
	else if (press_key == ARROW_RIGHT || press_key == D)
		all->mv->x += 20.0f;
	else if (press_key == ARROW_UP || press_key == WW)
		all->mv->y -= 20.0f;
	else if (press_key == ARROW_DOWN || press_key == S)
		all->mv->y += 20.0f;
	else if (press_key == NP_MIN)
		all->mv->iter -= 100;
	else if (press_key == NP_PLU)
		all->mv->iter += 100;
	else if (press_key == CTRL)
		all->fractal->plus_color *= 2;
	if (strncmp(all->fractal->name, "mandelbrot", 12) == 0)
		mandelbrot(all);
	else if (strncmp(all->fractal->name, "julia", 12) == 0)
		julia(all);
	else if (ft_strncmp(all->fractal->name, "ship", 12) == 0)
		ship(all);
	return (0);
}

int	read_mouse_scroll(int button, int x, int y, t_all *all)
{
	if (button == MOUSE_RIGHT_BUTTON)
	{
		all->mv->z /= 1.5;
		x = x - all->mv->x;
		y = y - all->mv->y;
		all->mv->x -= ((x / 1.5) - x);
		all->mv->y -= ((y / 1.5) - y);
	}
	else if (button == MOUSE_LEFT_BUTTON)
	{
		all->mv->z *= 1.5;
		x = x - all->mv->x;
		y = y - all->mv->y;
		all->mv->x -= ((x * 1.5) - x);
		all->mv->y -= ((y * 1.5) - y);
	}
	if (strncmp(all->fractal->name, "mandelbrot", 12) == 0)
		mandelbrot(all);
	else if (strncmp(all->fractal->name, "julia", 12) == 0)
		julia(all);
	else if (ft_strncmp(all->fractal->name, "ship", 12) == 0)
		ship(all);
	return (0);
}

int	mouse_move(int x, int y, t_all *all)
{
	float	mx;
	float	my;
	float	mz;

	mx = all->mv->x;
	my = all->mv->y;
	mz = all->mv->z;
	if (all->fractal->pause_mov == 1)
		return (0);
	if (x < W && x > 0 && y < H && y > 0)
	{
		all->fractal->julia1 = ((x - W / 1.5f + mx) * 3.0f / (mz * W) / 5.0f);
		all->fractal->julia2 = ((y - H / 2.0f + my) * 3.0f / (mz * H) / 5.0f);
		printf("%d, %d\n", x, y);
	}
	julia(all);
	return (0);
}

int	exit_win(t_win *win)
{
	if (win)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(EXIT_SUCCESS);
}
