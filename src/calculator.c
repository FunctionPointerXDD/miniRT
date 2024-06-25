/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:14:24 by sihong            #+#    #+#             */
/*   Updated: 2024/06/21 17:14:27 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

double	vec3_get_norm(t_vec3 v)
{
	return (sqrt(pow(v.e[X], 2) + pow(v.e[Y], 2) + pow(v.e[Z], 2)));
}

t_vec3	vec3_normalize(t_vec3 v)
{
	double	norm;

	norm = vec3_get_norm(v);
	if (norm == 0.0f)
		return (v);
	return (make_vec3(v.e[X] / norm, v.e[Y] / norm, v.e[Z] / norm));
}

t_vec4	mat4x4_vec4_mul(t_mat4x4 m, t_vec4 v)
{
	t_vec4	mv;
	int		i;
	int		j;

	mv = make_vec4(0.0f, 0.0f, 0.0f, 0.0f);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mv.e[i] += m.e[i][j] * v.e[j];
			j++;
		}
		i++;
	}
	return (mv);
}

t_mat4x4	get_zero_mat4x4()
{
	t_mat4x4	m;

	m.e[0][0] = 0.0f;
	m.e[0][1] = 0.0f;
	m.e[0][2] = 0.0f;
	m.e[0][3] = 0.0f;
	m.e[1][0] = 0.0f;
	m.e[1][1] = 0.0f;
	m.e[1][2] = 0.0f;
	m.e[1][3] = 0.0f;
	m.e[2][0] = 0.0f;
	m.e[2][1] = 0.0f;
	m.e[2][2] = 0.0f;
	m.e[2][3] = 0.0f;
	m.e[3][0] = 0.0f;
	m.e[3][1] = 0.0f;
	m.e[3][2] = 0.0f;
	m.e[3][3] = 0.0f;
	return (m);
}

t_mat4x4	mat4x4_mat4x4_mul(t_mat4x4 m2, t_mat4x4 m1)
{
	t_mat4x4	m;
	int			i;
	int			j;
	int			k;

	m = get_zero_mat4x4();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				m.e[i][j] += m2.e[i][k] * m1.e[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (m);
}

int	vec3_iszero(t_vec3 v)
{
	if (v.e[X] == 0.0f && v.e[Y] == 0.0f && v.e[Z] == 0.0f)
		return (TRUE);
	else
		return (FALSE);
}

t_vec3	scala_vec3_mul(double scalar, t_vec3 v)
{
	return (make_vec3(scalar * v.e[X], scalar * v.e[Y], scalar * v.e[X]));
}

t_vec4	make_vec4(double x, double y, double z, double w)
{
	t_vec4	v;

	v.e[X] = x;
	v.e[Y] = y;
	v.e[Z] = z;
	v.e[W] = w;
	return (v);
}

t_vec4	expanse_vec3_to_vec4(t_vec3 v, double w)
{
	if (w == 0.0f)
		return (make_vec4(v.e[X], v.e[Y], v.e[Z], w));
	else
		return (make_vec4(v.e[X], v.e[Y], v.e[Z], 1.0f));
}

t_vec3	contract_vec4_to_vec3(t_vec4 v)
{
	return (make_vec3(v.e[X], v.e[Y], v.e[Z]));
}

double	get_radian(double angle)
{
	if (angle < 0.0f)
		return (-1.0f);
	return (PIE / 180.0f * angle);
}

double	max(double a, double b)
{
	if (a < b)
		return (b);
	else
		return (a);
}