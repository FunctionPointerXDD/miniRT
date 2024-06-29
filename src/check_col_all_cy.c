/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_all_cy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:15:31 by sihong            #+#    #+#             */
/*   Updated: 2024/06/29 18:11:49 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/factor.h"
#include "../header/miniRT.h"

t_col_info	get_col_cy_cap(int sign, t_vec4 cam_pos, t_vec4 pl_pos, \
							t_cylinder cy)
{
	double		t;
	t_col_info	p;
	t_vec3		ray_to_pixel;

	if (pl_pos.e[Y] == cam_pos.e[Y])
		return (get_fake_col());
	if (sign > 0)
		t = (-cam_pos.e[Y] + cy.height / 2.0f) / (pl_pos.e[Y] - cam_pos.e[Y]);
	else
		t = (-cam_pos.e[Y] - cy.height / 2.0f) / (pl_pos.e[Y] - cam_pos.e[Y]);
	if (t <= 0.0f)
		return (get_fake_col());
	else
		p.pos = vec3_add(scala_vec3_mul(t, contract_vec4_to_vec3(pl_pos)), \
				scala_vec3_mul(1.0f - t, contract_vec4_to_vec3(cam_pos)));
	if (pow(p.pos.e[X], 2.0) + pow(p.pos.e[Z], 2.0) > pow(cy.diameter / 2.0, 2.0))
		return (get_fake_col());
	if (sign > 0)
		p.n_vec = make_vec3(0.0f, 1.0f, 0.0f);
	else
		p.n_vec = make_vec3(0.0f, -1.0f, 0.0f);
	ray_to_pixel = vec3_normalize(vec3_sub(contract_vec4_to_vec3(pl_pos), contract_vec4_to_vec3(cam_pos)));
	if (vec3_dot(p.n_vec, ray_to_pixel) > 0.0f)
		p.n_vec.e[Y] = p.n_vec.e[Y] * -1.0f;
	return (p);
}

t_col_info	check_col_cy_cap(t_vec4 cam_pos, t_vec4 pl_pos, t_cylinder cy)
{
	t_col_info	col;
	t_col_info	p1;
	t_col_info	p2;
	t_mat4x4	restore;

	if (cam_pos.e[Y] == pl_pos.e[Y] && \
		(pl_pos.e[Y] == cy.height / 2 || pl_pos.e[Y] == -cy.height / 2))
		return (get_fake_col());
	p1 = get_col_cy_cap(1, cam_pos, pl_pos, cy);
	if (vec3_iszero(p1.n_vec) == FALSE)
	{
		restore = get_cy_matrix(cy);
		p1 = restore_to_origin(restore, p1);
	}
	p2 = get_col_cy_cap(-1, cam_pos, pl_pos, cy);
	if (vec3_iszero(p2.n_vec) == FALSE)
	{
		restore = get_cy_matrix(cy);
		p2 = restore_to_origin(restore, p2);
	}
	col = get_closer_coord(p1, p2);
	col.color = cy.color;
	return (col);
}

t_col_info	check_col_all_cy(t_vec3 ray_to_pixel, int cy_num, t_cylinder *cy)
{
	t_mat4x4	rev_cy;
	t_vec4		cam_pos;
	t_vec4		pl_pos;
	t_col_info	col;
	int			i;

	i = 0;
	col = get_fake_col();
	while (i < cy_num)
	{
		rev_cy = get_rev_cy_matrix(cy[i]);
		cam_pos = mat4x4_vec4_mul(rev_cy, make_vec4(0.0f, 0.0f, 0.0f, 1.0f));
		pl_pos = mat4x4_vec4_mul(rev_cy, \
				expanse_vec3_to_vec4(ray_to_pixel, 1.0f));
		col = get_closer_coord(col, check_col_cy_side(cam_pos, pl_pos, cy[i]));
		col = get_closer_coord(col, check_col_cy_cap(cam_pos, pl_pos, cy[i]));
		i++;
	}
	return (col);
}
