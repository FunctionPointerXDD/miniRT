/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:58:21 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/21 15:23:52 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

// Constructors
t_vec3	make_vec3(double e0, double e1, double e2)
{
	t_vec3 v;

	v.e[X] = e0;
	v.e[Y] = e1;
	v.e[Z] = e2;
	return (v);
}

// Getters
/*
double	vec3_x(const t_vec3 *v)
{
	return (v->e[X]);
}

double	vec3_y(const t_vec3 *v)
{
	return (v->e[Y]);
}

double	vec3_z(const t_vec3 *v)
{
	return (v->e[Z]);
}
*/

// Unary operators
t_vec3	vec3_negate(const t_vec3 v)
{
	return (make_vec3(-v.e[X], -v.e[Y], -v.e[Z]));
}

// Binary operators
t_vec3	vec3_add(const t_vec3 u, const t_vec3 v)
{
	return (make_vec3(u.e[X] + v.e[X], u.e[Y] + v.e[Y], u.e[Z] + v.e[Z]));
}

t_vec3	vec3_sub(const t_vec3 u, const t_vec3 v)
{
	return (make_vec3(u.e[X] - v.e[X], u.e[Y] - v.e[Y], u.e[Z] - v.e[Z]));
}

t_vec3	vec3_mul(const t_vec3 u, const t_vec3 v)
{
	return (make_vec3(u.e[X] * v.e[X], u.e[Y] * v.e[Y], u.e[Z] * v.e[Z]));
}
/*
t_vec3	vec3_scale(double t, const t_vec3 *v)
{
	return (make_vec3(t * v->e[X], t * v->e[Y], t * v->e[Z]));
}

t_vec3	vec3_divide(const t_vec3 *v, double t)
{
	return (vec3_scale(1.0 / t, v));
}
*/
// Utility functions
/*
double	vec3_length_squared(const t_vec3 *v)
{
	return (v->e[X] * v->e[X] + v->e[Y] * v->e[Y] + v->e[Z] * v->e[Z]);
}

double	vec3_length(const t_vec3 *v)
{
	return (sqrt(vec3_length_squared(v)));
}

t_vec3	vec3_unit_vector(const t_vec3 *v)
{
	double len = vec3_length(v);
	return (vec3_divide(v, len));
}
*/

double	vec3_dot(const t_vec3 u, const t_vec3 v) //내적
{
	return (u.e[X] * v.e[X] + u.e[Y] * v.e[Y] + u.e[Z] * v.e[Z]);
}

t_vec3	vec3_cross(const t_vec3 u, const t_vec3 v) //외적
{
	return (make_vec3(u.e[Y] * v.e[Z] - u.e[Z] * v.e[Y],
					  u.e[Z] * v.e[X] - u.e[X] * v.e[Z],
					  u.e[X] * v.e[Y] - u.e[Y] * v.e[X]));
}

// Output
/*
void	vec3_output(const t_vec3 *v)
{
	printf("%f %f %f\n", v->e[X], v->e[Y], v->e[Z]);
}
*/