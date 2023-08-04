/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:33:07 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/04 18:22:13 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void    mandelbrot(t_all *all)
{
    float      tmp;
    t_fractal   *f;

    f = all->fractal;
    f->row = -1;
    while (++f->row < H)
    {
        tmp = 0;
        f->col = -1;
        f->c_im = (f->row - H / 2.0f + all->mv->y) * 3.0f / (all->mv->z * H);
        while (++f->col < W)
        {
            f->c_re = (f->col - W / 1.5f + all->mv->x) * 3.0f / (all->mv->z * W);
            f->i = 0;
            f->x = 0;
            f->y = 0;
            while (f->i < all->mv->iter && ((f->x * f->x) + (f->y * f->y) <= 2.0f))
            {
                tmp = (f->x * f->x) - (f->y * f->y) + f->c_re;
                f->y = 2.0f * f->x * f->y + f->c_im;
                f->x = tmp;
                f->i++;
            }

            if (f->i < all->mv->iter)
                put_color_px(f->i, f, all->img);
            else
                my_mlx_pixel_put(all->img, f->col, f->row, 0x00000080);
        }
    }
    mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->img->img, 0, 0);
}

void    julia(t_all *all)
{
    float      tmp;
    t_fractal   *f;

    f = all->fractal;
    f->row = -1;
    while (++f->row < H)
    {
        tmp = 0;
        f->col = -1;
        while (++f->col < W)
        {
            f->i = 0;
            f->x = (f->row - W / 2.0f + all->mv->x) * 3.0f / (all->mv->z * W);
            f->y = (f->col - H / 2.0f + all->mv->y) * 3.0f / (all->mv->z * H);
            while (f->i < all->mv->iter && ((f->x * f->x) + (f->y * f->y) <= 4.0f))
            {
                tmp = (f->x * f->x) - (f->y * f->y) + all->fractal->juliaarg1;
                f->y = 2.0f * f->x * f->y + all->fractal->juliaarg2;
                f->x = tmp;
                f->i++;
            }

            if (f->i < all->mv->iter)
                put_color_px(f->i, f, all->img);
            else
                my_mlx_pixel_put(all->img, f->col, f->row, 0x00000080);
        }
    }
    mlx_put_image_to_window(all->win.mlx_ptr, all->win.win_ptr, all->img->img, 0, 0);
}