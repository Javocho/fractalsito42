/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:32:35 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/05 20:51:02 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	start_fractal(t_fractal *fractal)
{
	fractal->row = -1;
	fractal->col = -1;
	fractal->c_im = 0;
	fractal->c_re = 0;
	fractal->i = 0;
	fractal->x = 0;
	fractal->y = 0;
	fractal->julia1 = -0.7269;
	fractal->julia2 = 0.1889;
	fractal->plus_color = 2;
	fractal->pause_mov = -1;
}

void	start_mv(t_move *move)
{
	move->x = W / 1.5f;
	move->y = H / 2.0f;
	move->z = 1.0f;
	move->iter = 100;
}

t_all	start_all(t_img *img, t_win win, t_fractal *fractal, t_move *mv)
{
	t_all	all;

	start_mv(mv);
	all.fractal = fractal;
	all.img = img;
	all.win = win;
	all.mv = mv;
	return (all);
}
