/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:33:00 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/02 19:56:14 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int main()
{
    t_move      mv;
    t_img       img;
    t_win       win;
    t_fractal   fractal;
    t_all   all;
    
    start_fractal(&fractal);
    win = new_program(W, H, "MANDELBROT");
    img = new_img(win);
    start_all(&img, win, &fractal, &mv, &all);
    mandelbrot(&all);
    mlx_key_hook(all.win.win_ptr, read_key, &all);
    mlx_hook(all.win.win_ptr, BUTTONPRESS, 0, read_mouse_scroll, &all);
    mlx_loop(all.win.mlx_ptr);
}
