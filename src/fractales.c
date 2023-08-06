/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:33:07 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/06 10:12:05 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	count_iterations(t_fractal *f, t_all *all)
{
	float	tmp;

	tmp = 0;
	while (f->i < all->mv->iter && ((f->x * f->x) + (f->y * f->y) <= 4.0f))
	{
		tmp = (f->x * f->x) - (f->y * f->y) + f->c_re;
		f->y = 2.0f * f->x * f->y + f->c_im;
		f->x = tmp;
		f->i++;
	}
	return (f->i);
}

void	mandelbrot(t_all *all)
{
	t_fractal	*f;

	f = all->fractal;
	f->row = -1;
	while (++f->row < H)
	{
		f->col = -1;
		f->c_im = (f->row - all->mv->y) * 3.0f / (all->mv->z * H);
		while (++f->col < W)
		{
			f->c_re = (f->col - all->mv->x) * 3.0f / (all->mv->z * W);
			f->i = 0;
			f->x = 0;
			f->y = 0;
			f->i = count_iterations(f, all);
			if (f->i < all->mv->iter)
				put_color_px(f->i, f, all->img, all->mv->iter);
			else
				my_mlx_pixel_put(all->img, f->col, f->row, 0x00000080);
		}
	}
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->img->img, 0, 0);
}

void	julia(t_all *all)
{
	t_fractal	*f;

	f = all->fractal;
	f->row = -1;
	while (++f->row < H)
	{
		f->col = -1;
		while (++f->col < W)
		{
			f->i = 0;
			f->x = (f->row - all->mv->x) * 3.0f / (all->mv->z * W);
			f->y = (f->col - all->mv->y) * 3.0f / (all->mv->z * H);
			f->i = count_iterations(f, all);
			if (f->i < all->mv->iter)
				put_color_px(f->i, f, all->img, all->mv->iter);
			else
				my_mlx_pixel_put(all->img, f->col, f->row, 0x00000080);
		}
	}
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->img->img, 0, 0);
}

// void draw_sierpinski(int x, int y, int size, t_img *img)
// {
// 	if (size == 1)
// 	{
// 		my_mlx_pixel_put(img, x, y, 0xFFFFFF); // Draw a white pixel
// 		return;
// 	}

// 	int halfSize = size / 2;

// 	draw_sierpinski(x, y, halfSize, img); // Top point
// 	draw_sierpinski(x + halfSize, y, halfSize, img); // Bottom right point
// 	draw_sierpinski(x + halfSize / 2, y + halfSize, halfSize, img);
// }

// void sierpienski(t_all *all)
// {
// 	t_img *img = all->img;

// 	// Clear the image
// 	for (int y = 0; y < H; y++)
// 	{
// 		for (int x = 0; x < W; x++)
// 		{
// 			my_mlx_pixel_put(img, x, y, 0x000000); // Set to black
// 		}
// 	}

// 	int triangleSize = W; // You can adjust the triangle size here
// 	int triangleX = (W - triangleSize) / 2;
// 	int triangleY = (H - triangleSize) / 2;

// 	draw_sierpinski(triangleX, triangleY, triangleSize, img);

// 	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, img->img, 0, 0);
// }

float	absolutvodka(float f)
{
	if (f < 0)
		f = -f;
	return (f);
}

void	ship(t_all *all)
{
	t_fractal	*f;

	f = all->fractal;
	f->row = -1;
	while (++f->row < H)
	{
		f->col = -1;
		f->c_im = (f->row - all->mv->y) * 3.0f / (all->mv->z * H);
		while (++f->col < W)
		{
			f->c_re = (f->col - all->mv->x) * 3.0f / (all->mv->z * W);
			f->i = 0;
			f->x = 0;
			f->y = 0;
			f->i = count_iterations(f, all);
			if (f->i < all->mv->iter)
				put_color_px(f->i, f, all->img, all->mv->iter);
			else
				my_mlx_pixel_put(all->img, f->col, f->row, 0x00000080);
		}
	}
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->img->img, 0, 0);
}
