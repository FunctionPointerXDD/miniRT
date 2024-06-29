/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:56:30 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 20:03:28 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "vector_bonus.h"
# include "parsing_bonus.h"
# include "factor_bonus.h"

/* image.h */

# define WIDTH 800
# define HEIGHT 800
# define ESC 53

typedef struct s_img_tool	t_img_tool;
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_img_tool	*img_tool;
}	t_vars;

typedef struct s_img_tool
{
	int		img_width;
	int		img_height;
	double	viewport_height;
	double	viewport_width;	
}	t_img_tool;

typedef struct s_col_info
{
	t_vec3	pos;
	t_vec3	n_vec;
}	t_col_info;

int		create_rgb(int r, int g, int b);
int		create_unit_rgb(double r, double g, double b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);

void	*ft_calloc_adv(size_t count, size_t size);
char	**ft_split_adv(char *str);

t_vec3	ray_at(t_col_info *ray, double t);

#endif
