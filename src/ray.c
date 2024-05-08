/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:58:43 by chansjeo          #+#    #+#             */
/*   Updated: 2024/05/08 16:01:19 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.h"
#include "../miniRT.h"
 
/*
// ray --> P(t) = A + t * B
// P(t) : 3D position
// A : ray origin
// B : ray direction
// t : real number
*/

t_vec3	ray_at(t_ray *ray, double t)
{
	t_vec3	out;

	out.e[0] = ray->orig.e[0] + t * ray->dir.e[0]; 
	out.e[1] = ray->orig.e[1] + t * ray->dir.e[1]; 
	out.e[2] = ray->orig.e[2] + t * ray->dir.e[2]; 
	return (out);
}
