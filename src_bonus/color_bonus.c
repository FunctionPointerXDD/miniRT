/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:56:49 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/21 15:27:45 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/miniRT_bonus.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	create_unit_rgb(double r, double g, double b)
{
  int ur;
  int ug;
  int ub;

  ur = (int)(255.999 * r);
  ug = (int)(255.999 * g);
  ub = (int)(255.999 * b);
  return (ur << 16 | ug << 8 | ub);
}

void  my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
  char  *dst;

  if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
    return;
  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

int	get_t(int trgb)
{
  return (trgb & (0xFF << 24));
}

int get_r(int trgb)
{
  return (trgb & (0xFF << 16));
}

int get_g(int trgb)
{
  return (trgb & (0xFF << 8));
}

int get_b(int trgb)
{
  return (trgb & 0xFF);
}
