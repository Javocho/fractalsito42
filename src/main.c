/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:33:00 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/05 20:23:43 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	valid_function(char *s)
{
	if (ft_strncmp(s, "mandelbrot", 12) == 0)
		return (1);
	else if (ft_strncmp(s, "julia", 12) == 0)
		return (1);
	else if (ft_strncmp(s, "ship", 12) == 0)
		return (1);
	return (0);
}

void	select_function(char *arg, t_all *all)
{
	if (ft_strncmp(arg, "mandelbrot", 12) == 0)
		mandelbrot(all);
	else if (ft_strncmp(arg, "julia", 12) == 0)
		julia(all);
	else if (ft_strncmp(arg, "ship", 12) == 0)
		ship(all);
}

int	main(int argc, char **argv)
{
	t_move		mv;
	t_img		img;
	t_win		win;
	t_fractal	fractal;
	t_all		all;

	if (argc == 1)
		write(1, "invalid: mandelbrot, julia, ship", 33);
	if (argc == 2)
	{
		if (!valid_function(argv[1]))
			return (write(1, "invalid: mandelbrot, julia, ship", 33));
		start_fractal(&fractal);
		win = new_program(W, H, "FRACTALSITO");
		img = new_img(win);
		all = start_all(&img, win, &fractal, &mv);
		all.fractal->name = argv[1];
		select_function(all.fractal->name, &all);
		mlx_key_hook(all.win.win_ptr, read_key, &all);
		mlx_hook(all.win.win_ptr, BUTTONPRESS, 0, read_mouse_scroll, &all);
		if (ft_strncmp(argv[1], "julia", 12) == 0)
			mlx_hook(all.win.win_ptr, MOTIONNOTIFY, 0, mouse_move, &all);
		mlx_hook(all.win.win_ptr, DESTROYNOTIFY, 0, exit_win, &all);
		mlx_loop(all.win.mlx_ptr);
	}
}
