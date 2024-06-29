/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relocate_to_view_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:24:03 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 18:38:24 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/factor.h"
#include "../header/miniRT.h"

t_vec3	relocate_vertex_to_view_space(t_vec3 v3, t_mat4x4 view)
{
	t_vec4	v4;
	t_vec3	output;

	v4 = mat4x4_vec4_mul(view, expanse_vec3_to_vec4(v3, 1.0f));
	output = contract_vec4_to_vec3(v4);
	return (output);
}

void	relocate_lights_to_view_space(t_light *light, t_mat4x4 view)
{
	light->light_pos = \
		relocate_vertex_to_view_space(light->light_pos, view);
}

void	relocate_planes_to_view_space(int pl_num, t_plane *pl, t_mat4x4 view)
{
	t_vec3	tmp;
	int		i;

	i = 0;
	while (i < pl_num)
	{
		tmp = vec3_add(pl[i].plane_pos, pl[i].unit_vec);
		tmp = relocate_vertex_to_view_space(tmp, view);
		pl[i].plane_pos = \
			relocate_vertex_to_view_space(pl[i].plane_pos, view);
		pl[i].unit_vec = vec3_sub(tmp, pl[i].plane_pos);
		i += 1;
	}
}

void	relocate_spheres_to_view_space(int sp_num, t_sphere *sp, t_mat4x4 view)
{
	int		i;

	i = 0;
	while (i < sp_num)
	{
		sp[i].center_pos = \
			relocate_vertex_to_view_space(sp[i].center_pos, view);
		i += 1;
	}
}

void	relocate_cylinders_to_view_space(int sy_num, t_cylinder *cy, \
		t_mat4x4 view)
{
	t_vec3	tmp;
	int		i;

	i = 0;
	while (i < sy_num)
	{
		tmp = vec3_add(cy[i].center_pos, cy[i].unit_vec);
		tmp = relocate_vertex_to_view_space(tmp, view);
		cy[i].center_pos = \
			relocate_vertex_to_view_space(cy[i].center_pos, view);
		cy[i].unit_vec = vec3_sub(tmp, cy[i].center_pos);
		i += 1;
	}
}
