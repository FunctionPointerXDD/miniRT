/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:26:11 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/21 15:45:40 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H

typedef struct s_vec3 
{
    double  e[3];
} t_vec3;

typedef struct s_vec4 
{
    double  e[4];
} t_vec4;

t_vec3	make_vec3(double e0, double e1, double e2);
t_vec3	vec3_add(const t_vec3 *u, const t_vec3 *v);
t_vec3	vec3_sub(const t_vec3 *u, const t_vec3 *v);
t_vec3	vec3_mul(const t_vec3 *u, const t_vec3 *v);
t_vec3	vec3_divide(const t_vec3 *v, double t);
t_vec3	vec3_scale(double t, const t_vec3 *v);
t_vec3	vec3_negate(const t_vec3 *v);
double	vec3_dot(const t_vec3 *u, const t_vec3 *v);
t_vec3	vec3_cross(const t_vec3 *u, const t_vec3 *v);
double	vec3_length(const t_vec3 *v);
double	vec3_length_squared(const t_vec3 *v);
void	vec3_output(const t_vec3 *v);
t_vec3	vec3_unit_vector(const t_vec3 *v);
double	vec3_x(const t_vec3 *v);
double	vec3_y(const t_vec3 *v);
double	vec3_z(const t_vec3 *v);

#endif