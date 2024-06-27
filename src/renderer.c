/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:50:34 by sihong            #+#    #+#             */
/*   Updated: 2024/06/21 16:50:36 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/factor.h"
#include "../header/miniRT.h"

void	translate_to_view_space(t_factor *f)
{
	t_mat4x4	view;

	view = get_view_matrix(f->cam);
	relocate_lights_to_view_space(f->light, view);
	relocate_planes_to_view_space(f->tab[PLANE], f->pl, view);
	relocate_spheres_to_view_space(f->tab[SPHERE], f->sp, view);
	relocate_cylinders_to_view_space(f->tab[CYLINDER], f->cy, view);
}

double	get_focal_length(double fov)
{
	double	fov_rad;

	fov_rad = get_radian(fov / 2.0f);
	if (sin(fov_rad) == 0.0f)
		return (-1.0f);
	else
		return (cos(fov_rad) / sin(fov_rad));
}

void	renderer(t_vars *vars, t_factor *f)
{
	translate_to_view_space(f);
	raytracer(vars, f);
}