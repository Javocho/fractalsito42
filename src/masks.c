/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:32:52 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/04 18:06:57 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int read_key(int press_key, t_all *all)
{
    if (press_key == ESC || !all->img)
        exit_win(&all->img->win);
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
	if (strncmp(all->fractal->name, "mandelbrot", 12) == 0)
        mandelbrot(all);
    else if (strncmp(all->fractal->name, "julia", 12) == 0)
        julia(all);
	return (0);
}

int read_mouse_scroll(int button, int x, int y, t_all *all)
{
    if (button == MOUSE_SCROLL_UP)
    {
        all->mv->z += 0.5f;
        printf("Zoom in: %f x: %i, y:%i\n", all->mv->z, x, y);
    }
    else if (button == MOUSE_SCROLL_DOWN)
    {
        all->mv->z -= 0.5f;
        printf("Zoom out: %f, x: %i, y:%i\n", all->mv->z, x, y);
    }
    else if (button == MOUSE_LEFT_BUTTON)
    {
        all->mv->z += 1;
        all->mv->x += x - (W / 2);
        all->mv->y += y - (H / 2);
    }
    if (strncmp(all->fractal->name, "mandelbrot", 12) == 0)
        mandelbrot(all);
    else if (strncmp(all->fractal->name, "julia", 12) == 0)
        julia(all);
    return (0);
}

int mouse_move(int x, int y, t_all *all)
{
    if (x < W && x > 0 && y < H && y > 0)
    {
        all->fractal->juliaarg1 = (x - W / 1.5f + all->mv->x) * 3.0f / (all->mv->z * W);
        all->fractal->juliaarg2 = (y - H / 2.0f + all->mv->y) * 3.0f / (all->mv->z * H);
        printf("%d, %d\n", x, y);
    }
    julia(all);
    return (0);
}

int exit_win(t_win *win)
{
    if (win)
        mlx_destroy_window(win->mlx_ptr, win->win_ptr);
    exit(EXIT_SUCCESS);
}
