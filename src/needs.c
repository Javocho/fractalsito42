/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:32:46 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/02 17:32:47 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	if (x > 0 && y > 0 && x < img->win.w && y < img->win.h)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int*)dst = color;
	}
}


t_win new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

t_img	new_img(t_win window)
{
	t_img	image;

	image.win = window;
	image.img = mlx_new_image(window.mlx_ptr, window.w, window.h);
	image.addr = mlx_get_data_addr(image.img, &(image.bpp), 
			&(image.line_len), &(image.endian));
	return (image);
}
