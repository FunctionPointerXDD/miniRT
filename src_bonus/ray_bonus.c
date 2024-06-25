/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:58:43 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/21 15:30:10 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/vector_bonus.h"
#include "../header_bonus/miniRT_bonus.h"
 
/*
// ray --> P(t) = A + t * B
// P(t) : 3D position
// A : ray origin
// B : ray direction
// t : real number
*/
t_vec3	ray_at(t_col_info *ray, double t)
{
	t_vec3	out;

	out.e[0] = ray->pos.e[0] + t * ray->n_vec.e[0]; 
	out.e[1] = ray->pos.e[1] + t * ray->n_vec.e[1]; 
	out.e[2] = ray->pos.e[2] + t * ray->n_vec.e[2]; 
	return (out);
}
