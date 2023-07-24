/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:54:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/24 19:24:39 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

t_win *new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win *) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

t_img	*new_img(int w, int h, t_win *window)
{
	t_img	*image;

	image->win = window;
	image->img_ptr = mlx_new_image(window->mlx_ptr, w, h);
	image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp),
			&(image->line_len), &(image->endian));
	image->w = w;
	image->h = h;
	return (image);
}

t_cplane	*new_cplane(t_img *img, int ac, char **av)
{
	t_cplane	*plane;

	plane = (t_cplane *)malloc(sizeof(t_cplane));
	if (!plane)
		return (NULL);
	plane->x_s = -2.0f;
	plane->x_e = 2.0f;
	plane->y_s = 2.0f;
	plane->y_e = -2.0f;
	plane->x_gap = (fabs(plane->x_e) + fabs(plane->x_s)) / (img->w);
	plane->y_gap = (fabs(plane->y_e) + fabs(plane->y_s)) / (img->h);
	plane->img_ptr = img;
	if (ac >= 3)
		plane->iter = ft_atoi(av[2]);
	else
		plane->iter = 100;
	plane->creal = 0.285f;
	plane->cimagin = 0.01f;
	return (plane);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

int	exit_window(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}
