/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:26:11 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 19:55:34 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define X 0
# define Y 1
# define Z 2
# define W 3

# define FALSE 0
# define TRUE 1

# define PIE 3.141592

typedef struct s_vec3
{
	double	e[3];
}	t_vec3;

typedef struct s_vec4
{
	double	e[4];
}	t_vec4;

typedef struct s_mat4x4
{
	double	e[4][4];
}	t_mat4x4;

typedef struct s_col_info
{
	t_vec3	pos;
	t_vec3	n_vec;
	t_vec3	color;
}	t_col_info;

//chansjeo
t_vec3		make_vec3(double e0, double e1, double e2);
t_vec3		vec3_add(const t_vec3 u, const t_vec3 v);
t_vec3		vec3_sub(const t_vec3 u, const t_vec3 v);
t_vec3		vec3_mul(const t_vec3 u, const t_vec3 v);
//t_vec3	vec3_divide(const t_vec3 *v, double t);
//t_vec3	vec3_scale(double t, const t_vec3 *v);
t_vec3		vec3_negate(const t_vec3 v);
double		vec3_dot(const t_vec3 u, const t_vec3 v);
t_vec3		vec3_cross(const t_vec3 u, const t_vec3 v);
//double	vec3_length(const t_vec3 *v);
//double	vec3_length_squared(const t_vec3 *v);
//void		vec3_output(const t_vec3 *v);
//t_vec3	vec3_unit_vector(const t_vec3 *v);
//double	vec3_x(const t_vec3 *v);
//double	vec3_y(const t_vec3 *v);
//double	vec3_z(const t_vec3 *v);
//t_vec3	ray_at(t_col_info *ray, double t);
t_col_info	get_fake_col(void);
t_col_info	get_closer_coord(t_col_info v1, t_col_info v2);

//sihong
//calculator.c
double		vec3_get_norm(t_vec3 v);
t_vec3		vec3_normalize(t_vec3 v);
t_vec4		mat4x4_vec4_mul(t_mat4x4 m, t_vec4 v);
t_mat4x4	get_zero_mat4x4(void);
t_mat4x4	mat4x4_mat4x4_mul(t_mat4x4 m2, t_mat4x4 m1);
int			vec3_iszero(t_vec3 v);
t_vec3		scala_vec3_mul(double scalar, t_vec3 v);
t_vec4		make_vec4(double x, double y, double z, double w);
t_vec4		expanse_vec3_to_vec4(t_vec3 v, double w);
t_vec3		contract_vec4_to_vec3(t_vec4 v);
double		get_radian(double angle);
double		max(double a, double b);

#endif
