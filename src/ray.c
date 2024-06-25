/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:58:43 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/21 15:24:57 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vector.h"
#include "../header/miniRT.h"
 
/*
// ray --> P(t) = A + t * B
// P(t) : 3D position
// A : ray origin
// B : ray direction
// t : real number
*/
/*
t_vec3	ray_at(t_col_info *ray, double t)
{
	t_vec3	out;

	out.e[0] = ray->pos.e[0] + t * ray->n_vec.e[0]; 
	out.e[1] = ray->pos.e[1] + t * ray->n_vec.e[1]; 
	out.e[2] = ray->pos.e[2] + t * ray->n_vec.e[2]; 
	return (out);
}
*/

t_col_info	get_fake_col()
{
	t_col_info	col;

	col.pos = make_vec3(0.0f, 0.0f, 0.0f);
	col.n_vec = make_vec3(0.0f, 0.0f, 0.0f);
	col.color = make_vec3(0.0f, 0.0f, 0.0f);
	return (col);
}

t_col_info	get_closer_coord(t_col_info v1, t_col_info v2)
{
	if (vec3_iszero(v1.n_vec) == TRUE && vec3_iszero(v2.n_vec) == TRUE)
		return (v1);
	else if (vec3_iszero(v1.n_vec) == TRUE && vec3_iszero(v2.n_vec) == FALSE)
		return (v2);
	else if (vec3_iszero(v1.n_vec) == FALSE && vec3_iszero(v2.n_vec) == TRUE)
		return (v1);
	else if (vec3_get_norm(v1.pos) > vec3_get_norm(v2.pos))
		return (v2);
	else
		return (v1);
}
