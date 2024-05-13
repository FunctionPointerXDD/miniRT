/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:58:21 by chansjeo          #+#    #+#             */
/*   Updated: 2024/05/08 16:51:57 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

// Constructors
t_vec3	make_vec3(double e0, double e1, double e2)
{
	t_vec3 v;

	v.e[0] = e0;
	v.e[1] = e1;
	v.e[2] = e2;
	return (v);
}

// Getters
double	vec3_x(const t_vec3 *v)
{
	return (v->e[0]);
}

double	vec3_y(const t_vec3 *v)
{
	return (v->e[1]);
}

double	vec3_z(const t_vec3 *v)
{
	return (v->e[2]);
}

// Unary operators
t_vec3	vec3_negate(const t_vec3 *v)
{
	return (make_vec3(-v->e[0], -v->e[1], -v->e[2]));
}

// Binary operators
t_vec3	vec3_add(const t_vec3 *u, const t_vec3 *v)
{
	return (make_vec3(u->e[0] + v->e[0], u->e[1] + v->e[1], u->e[2] + v->e[2]));
}

t_vec3	vec3_sub(const t_vec3 *u, const t_vec3 *v)
{
	return (make_vec3(u->e[0] - v->e[0], u->e[1] - v->e[1], u->e[2] - v->e[2]));
}

t_vec3	vec3_mul(const t_vec3 *u, const t_vec3 *v)
{
	return (make_vec3(u->e[0] * v->e[0], u->e[1] * v->e[1], u->e[2] * v->e[2]));
}

t_vec3	vec3_scale(double t, const t_vec3 *v)
{
	return (make_vec3(t * v->e[0], t * v->e[1], t * v->e[2]));
}

t_vec3	vec3_divide(const t_vec3 *v, double t)
{
	return (vec3_scale(1.0 / t, v));
}

// Utility functions
double	vec3_length_squared(const t_vec3 *v)
{
	return (v->e[0] * v->e[0] + v->e[1] * v->e[1] + v->e[2] * v->e[2]);
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

double	vec3_dot(const t_vec3 *u, const t_vec3 *v) //내적
{
	return (u->e[0] * v->e[0] + u->e[1] * v->e[1] + u->e[2] * v->e[2]);
}

t_vec3	vec3_cross(const t_vec3 *u, const t_vec3 *v) //외적
{
	return (make_vec3(u->e[1] * v->e[2] - u->e[2] * v->e[1],
					  u->e[2] * v->e[0] - u->e[0] * v->e[2],
					  u->e[0] * v->e[1] - u->e[1] * v->e[0]));
}

// Output
void	vec3_output(const t_vec3 *v)
{
	printf("%f %f %f\n", v->e[0], v->e[1], v->e[2]);
}
