/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:17:16 by sihong            #+#    #+#             */
/*   Updated: 2024/07/02 15:38:23 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/factor_bonus.h"
#include "../header_bonus/miniRT_bonus.h"

t_col_info	get_collision_location(t_vec3 ray_to_pixel, t_factor *f)
{
	t_col_info	col;
	t_col_info	tmp;

	col = get_fake_col();
	tmp = check_col_all_sp(ray_to_pixel, f->tab[SPHERE], f->sp);
	col = get_closer_coord(col, tmp);
	tmp = check_col_all_cy(ray_to_pixel, f->tab[CYLINDER], f->cy);
	col = get_closer_coord(col, tmp);
	tmp = check_col_all_pl(ray_to_pixel, f->tab[PLANE], f->pl);
	col = get_closer_coord(col, tmp);
	return (col);
}

int	check_light_collision(int lit_num, t_vec3 col_pos, t_factor *f)
{
	if (check_lit_col_all_sp(lit_num, col_pos, f) == TRUE)
		return (TRUE);
	if (check_lit_col_all_cy(lit_num, col_pos, f) == TRUE)
		return (TRUE);
	if (check_lit_col_all_pl(lit_num, col_pos, f) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_vec3	get_pixel_color(t_col_info col, t_factor *f)
{
	t_vec3	l;
	t_vec3	r;
	t_vec3	v;
	t_phong	phong;
	t_vec3	color;
	int		i;

	if (vec3_iszero(col.n_vec) == TRUE)
		return (get_vec3(0.0f, 0.0f, 0.0f));
	phong.obj_color = vec3_scale(1.0f / 255.0f, col.color);
	phong.ambient = vec3_scale(f->amb->range, vec3_mul(vec3_scale(1.0f \
					/ 255.0f, f->amb->color), phong.obj_color));
	v = vec3_normalize(col.pos);
	phong.diffuse = get_vec3(0.0f, 0.0f, 0.0f);
	phong.specular = get_vec3(0.0f, 0.0f, 0.0f);
	i = 0;
	while (i < f->tab[LIGHT])
	{
		l = vec3_normalize(vec3_sub(f->light[i].light_pos, col.pos));
		if (vec3_dot(col.n_vec, l) < 0.0f || check_light_collision(i, col.pos, f) == 1)
		{
			i++;
			continue;
		}
		phong.diffuse = vec3_add(phong.diffuse, vec3_scale(f->light[i].range \
			* max(vec3_dot(col.n_vec, l), 0.0f), vec3_mul(phong.obj_color, \
			vec3_scale(1.0f / 255.0f, f->light[i].color))));
		r = vec3_sub(vec3_scale(2.0f * vec3_dot(l, col.n_vec), col.n_vec), l);
		phong.specular = vec3_add(phong.specular, vec3_scale(pow(max(-vec3_dot(r, v), 0.0f), 64.0f) \
				* f->light[i].range, get_vec3(1.0f, 1.0f, 1.0f)));
		i++;
	}
	color = vec3_add(phong.ambient, phong.diffuse);
	color = vec3_add(color, phong.specular);
	color = clip_color(color);
	return (color);
}

t_vec3	shoot_ray_to_pixel(t_vec3 ray_to_pixel, t_factor *f)
{
	t_col_info	col;
	t_vec3		color;

	col = get_collision_location(ray_to_pixel, f);
	color = get_pixel_color(col, f);
	return (color);
}

/** if (f->cam->fov < 1.0f) --> black screen! */
void	raytracer(t_vars *vars, t_factor *f)
{
	t_vec3	up_left_pixel;

	if (f->cam->fov < 1.0f)
	{
		black_screen(vars);
		return ;
	}
	up_left_pixel = get_vec3(-1.0f, 1.0f, -get_focal_length(f->cam->fov));
	distribute_to_thread(4, 4, vars, f);
}
