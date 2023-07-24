/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:29:04 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/24 20:53:45 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

#include <mlx.h>

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_img
{
	t_win	*win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_complex_plane
{
	t_img				*img_ptr;
	void				(* fractal_function)(struct s_complex_plane *);
	int					iter;
	double				x_s;
	double				x_e;
	double				y_s;
	double				y_e;
	double				x_gap;
	double				y_gap;
}			t_cplane;

typedef struct s_complex
{
	float				creal;
	float				cimagin;
}	t_complex;

#endif