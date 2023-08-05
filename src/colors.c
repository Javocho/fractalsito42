/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:31:09 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/05 21:34:24 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	psychedelic_colors(int pos)
{
	static int	pastel[11] = {0xFF1493, 0x00CED1, 0xFF00FF, 0x0000FF, \
		0xFF0000, 0x00FFFF, 0xFFA500};

	return (pastel[pos]);
}

int	my_colors(int pos)
{
	static int	colors[11] = {0x00000000, 0x0032ff03, 0x007aff6e, 0x0090e7a3, \
		0x00afffcd, 0x009ffafd, 0x0000BFFF};

	return (colors[pos]);
}

void	put_color_px(int i, t_fractal *fractal, t_img *img, int iter)
{
	int	fc;

	if (fractal->plus_color >= MAX_COLOR)
		fractal->plus_color = 1;
	fc = fractal->plus_color;
	if (i < iter / 10)
		my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00000000);
	else
	{
		if (i < iter / 8)
			my_mlx_pixel_put(img, fractal->col, fractal->row, 0x0032ff03 * fc);
		else if (i < iter / 6)
			my_mlx_pixel_put(img, fractal->col, fractal->row, 0x007aff6e * fc);
		else if (i < iter / 4)
			my_mlx_pixel_put(img, fractal->col, fractal->row, 0x0090e7a3 * fc);
		else if (i < iter / 3)
			my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00afffcd * fc);
		else if (i < iter / 2)
			my_mlx_pixel_put(img, fractal->col, fractal->row, 0x009ffafd * fc);
		else
			my_mlx_pixel_put(img, fractal->col, fractal->row, 0x0000BFFF * fc);
	}
}
