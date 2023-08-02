/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:32:52 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/02 20:20:33 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int read_key(int press_key, t_all *all)
{
    if (press_key == ESC || !all->img)
        exit_win(&all->img->win);
    else if (press_key == ARROW_LEFT || press_key == A)
		all->mv->x -= 20.0;
	else if (press_key == ARROW_RIGHT || press_key == D)
		all->mv->x += 20.0;
	else if (press_key == ARROW_UP || press_key == WW)
		all->mv->y -= 20.0;
	else if (press_key == ARROW_DOWN || press_key == S)
		all->mv->y += 20.0;
	else if (press_key == NP_MIN)
		all->mv->iter -= 100;
	else if (press_key == NP_PLU)
		all->mv->iter += 100;
	mandelbrot(all);
	return (0);
}

int read_mouse_scroll(int button, int x, int y, t_all *all)
{
     if (button == MOUSE_SCROLL_UP)
    {
        all->mv->z += 0.5;
        printf("Zoom in: %f x: %i, y:%i\n", all->mv->z, x, y);
    }
    else if (button == MOUSE_SCROLL_DOWN)
    {
        all->mv->z -= 0.5;
        printf("Zoom out: %f, x: %i, y:%i\n", all->mv->z, x, y);
    }
    mandelbrot(all);
    return (0);
}

// void    zoom(t_all *all, int n)
// {
//     t_move *mv; 

//     mv = all->mv;
//     if (n == 1)
        
//     else if (n == 2)
        
//     mandelbrot(all);
// }

int exit_win(t_win *win)
{
    if (win)
        mlx_destroy_window(win->mlx_ptr, win->win_ptr);
    exit(EXIT_SUCCESS);
}
