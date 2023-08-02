/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:31:09 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/02 17:32:16 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void    put_color_px(int i, t_fractal *fractal, t_img *img)
{
    int res;

    res = i % 4;
    if (i < 14)
        my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00000000);
    else {
        if (res == 0)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x0032ff03);
        else if (res == 1)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x007aff6e);
        else if (res == 2)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x0090e7a3);
        else if (res == 3)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x00afffcd);
        else if (res == 4)
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x009ffafd);
        else
            my_mlx_pixel_put(img, fractal->col, fractal->row, 0x0000BFFF);
    }
}