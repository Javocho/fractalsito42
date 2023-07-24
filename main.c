/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:54:34 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/24 19:43:15 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

static int	is_stable(double _Complex inum, double _Complex z_num, int iter);

int	main(int argc, char **argv)
{
	t_win		*window;
	t_img		*image1;
	t_cplane	*cp;

	window = new_program(1000, 800, "window 1");
	if (!window->mlx_ptr || !window->win_ptr)
		return (1);
	image1 = new_img(1000, 800, window);
	cp = new_cplane(image1, argc, argv);
	cp->fractal_function = maldelbrot(cp);

	// mlx_put_image_to_window(image1.win.mlx_ptr, image1.win.win_ptr, image1.img_ptr, 0, 0);
	// mlx_hook(window.win_ptr, 17, 1L << 0, exit_window, &window);
	// mlx_loop(window.mlx_ptr);
	return (0);
}

static int	is_stable(double _Complex inum, double _Complex z_num, int iter)
{
	double _Complex	temp;
	int				i;

	i = 0;
	temp = inum;
	while (i++ < iter)
	{
		temp = iplus(ipow(temp), z_num);
		if (norm(temp) > 2)
			return (i);
	}
	return (0);
}

