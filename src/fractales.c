/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:33:07 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/02 18:55:44 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void    mandelbrot(t_all *all)
{
    double      tmp;
    t_fractal   *f;

    f = all->fractal;
    f->row = -1;
    while (++f->row < all->win.h)
    {
        tmp = 0;
        f->col = -1;
        f->c_im = (f->row - all->win.h / 2.0 + all->mv->y) * 3.0 / (all->mv->z * all->win.h);
        while (++f->col < all->win.w)
        {
            f->c_re = (f->col - all->win.w / 1.5 + all->mv->x) * 3.0 / (all->mv->z * all->win.w);
            f->i = 0;
            f->x = 0;
            f->y = 0;
            while (f->i < all->mv->iter && ((f->x * f->x) + (f->y * f->y) <= 4))
            {
                tmp = (f->x * f->x) - (f->y * f->y) + f->c_re;
                f->y = 2 * f->x * f->y + f->c_im;
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
