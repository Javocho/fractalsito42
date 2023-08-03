/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:33:00 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/03 17:47:11 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void select_function(char *arg, t_all *all)
{
    if (ft_strncmp(arg, "mandelbrot", 12) == 0)
        mandelbrot(all);
    else if (ft_strncmp(arg, "julia", 12) == 0)
        julia(all);
}

int main(int argc, char **argv)
{
    t_move      mv;
    t_img       img;
    t_win       win;
    t_fractal   fractal;
    t_all   all;
    
    (void)argc;
    if (ft_strncmp(argv[1], "mandelbrot", 12) == 0 || ft_strncmp(argv[1], "julia", 12) == 0)
    {
        start_fractal(&fractal);
        win = new_program(W, H, "MANDELBROT");
        img = new_img(win);
        start_all(&img, win, &fractal, &mv, &all);
        all.fractal->name = argv[1];
        select_function(all.fractal->name, &all);
        mlx_key_hook(all.win.win_ptr, read_key, &all);
        mlx_hook(all.win.win_ptr, BUTTONPRESS, 0, read_mouse_scroll, &all);
        mlx_loop(all.win.mlx_ptr);
    }
}
