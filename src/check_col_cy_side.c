/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_cy_side.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:50:40 by sihong            #+#    #+#             */
/*   Updated: 2024/06/24 17:50:45 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/factor.h"
#include "../header/miniRT.h"

t_dic	get_side_dic(t_vec4 cam_pos, t_vec4 pl_pos, double diameter)
{
	t_dic	dic;

	dic.a = pow(pl_pos.e[X] - cam_pos.e[X], 2.0f) + \
		pow(pl_pos.e[Y] - cam_pos.e[Y], 2.0f);
	dic.b = 2 * (pl_pos.e[X] * cam_pos.e[X] + pl_pos.e[Y] * cam_pos.e[Y] \
		- pow(cam_pos.e[X], 2.0f) - pow(cam_pos.e[Y], 2.0f));
	dic.c = pow(cam_pos.e[X], 2.0f) + pow(cam_pos.e[Y], 2.0f) - pow(diameter, 2.0f);
	dic.dic = pow(dic.b, 2) - 4 * dic.a * dic.c;
	if (dic.dic < 0.0f)
	{
		dic.t_neg = 0.0f;
		dic.t_pos = 0.0f;
	}
	else if (dic.dic == 0.0f)
	{
		dic.t_neg = -dic.b / (2 * dic.a);
		dic.t_pos = -dic.b / (2 * dic.a);
	}
	else
	{
		dic.t_neg = (-dic.b - sqrt(dic.dic)) / (2 * dic.a);
		dic.t_pos = (-dic.b + sqrt(dic.dic)) / (2 * dic.a);
	}
	return (dic);
}

t_col_info	check_cy_height(t_vec4 cam_pos, t_vec4 pl_pos, t_cylinder cy, double t)
{
	double		z;
	t_col_info	col;
	t_vec3		ray_to_pixel;

	z = pl_pos.e[Z] * t + cam_pos.e[Z] * (1 - t);
	if (z > -cy.height / 2 && z < cy.height / 2)
		col.pos = scala_vec3_mul(t, contract_vec4_to_vec3(pl_pos));
	else
		return (get_fake_col());
	col.n_vec = vec3_normalize(vec3_sub(col.pos, make_vec3(0.0f, 0.0f, z)));
	ray_to_pixel = vec3_normalize(vec3_sub(contract_vec4_to_vec3(pl_pos), contract_vec4_to_vec3(cam_pos)));
	if (vec3_dot(vec3_normalize(ray_to_pixel), col.n_vec) < 0.0f)
		col.n_vec = vec3_normalize(vec3_sub(make_vec3(0.0f, 0.0f, z), col.pos));
	col.color = cy.color;
	return (col);
}

t_col_info	restore_to_origin(t_mat4x4 restore, t_col_info col)
{
	t_vec4		p;
	t_vec4		res_vec;
	t_col_info	res_col;

	res_vec = mat4x4_vec4_mul(restore, expanse_vec3_to_vec4(col.pos, 1.0f));
	p = expanse_vec3_to_vec4(vec3_add(col.pos, col.n_vec), 1.0f);
	p = mat4x4_vec4_mul(restore, p);
	res_col.pos = contract_vec4_to_vec3(res_vec);
	res_col.n_vec = vec3_sub(contract_vec4_to_vec3(p), res_col.pos);
	res_col.color = col.color;
	return (res_col);
}

t_col_info	check_col_cy_side(t_vec4 cam_pos, t_vec4 pl_pos, t_cylinder cy)
{
	t_dic		dic;
	t_col_info		col;
	t_mat4x4	restore;

	dic = get_side_dic(cam_pos, pl_pos, cy.diameter);
	if (dic.dic < 0.0f || -dic.b + sqrt(dic.dic) <= 0.0f)
		return (get_fake_col());
	else
	{
		if (dic.dic == 0.0f)
			col = check_cy_height(cam_pos, pl_pos, cy, dic.t_pos);
		else if (dic.dic > 0.0f)
		{
			if (-dic.b - sqrt(dic.dic) <= 0.0f)
				col = check_cy_height(cam_pos, pl_pos, cy, dic.t_pos);
			else
				col = check_cy_height(cam_pos, pl_pos, cy, dic.t_neg);
		}
	}
	if (vec3_iszero(col.n_vec) == FALSE)
	{
		restore = get_cy_matrix(cy);
		col = restore_to_origin(restore, col);
	} 
	return (col);
}
