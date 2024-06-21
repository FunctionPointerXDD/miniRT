/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:32:40 by chansjeo          #+#    #+#             */
/*   Updated: 2024/05/09 18:13:57 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTOR_H
# define FACTOR_H

# include "vector.h"

typedef enum e_element
{
	AMBIENT,
	CAMERA,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER,
}	t_element;

typedef struct s_ambient
{
	int		id;
	double	range; // ambient lighting ratio in range [0.0, 1.0]
	t_vec3	color; // R G B color [0-255]
}	t_ambient;

typedef struct s_camera
{
	int		id;
	t_vec3	view_pos; //not vector but coordinates of the cam point
	t_vec3	unit_vec; //3d normalized orientation vector. In range [-1,1]
	double	fov; //Horizontal field of view in degrees in range [0,180]
}	t_camera;

typedef struct s_light
{
	int		id;
	t_vec3	light_pos; //∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
	double	range;  //∗ the light brightness ratio in range [0.0,1.0]: 0.6
	t_vec3	color;//∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
}	t_light;

typedef struct s_sphere
{
	int		id;
	t_vec3	center_pos; //x,y,z coordinates of the sphere center: 0.0,0.0,20.6
	double	diameter; //지름 // ∗ the sphere diameter: 12.6
	t_vec3	color; //∗ R,G,B colors in range [0-255]: 10, 0, 255
}	t_sphere;

typedef struct s_plane
{
	int		id;
	t_vec3	plane_pos; //∗ x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
	t_vec3	unit_vec; //∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
	t_vec3	color; //∗ R,G,B colors in range [0-255]: 0,0,225
}	t_plane;

typedef struct s_cylinder
{
	int		id;
	t_vec3	center_pos; // ∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
	t_vec3	unit_vec; // ∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
	double	diameter; // ∗ the cylinder diameter: 14.2
	double	height; // ∗ the cylinder height: 21.42
	t_vec3	color; // ∗ R,G,B colors in range [0,255]: 10, 0, 255
}	t_cylinder;

typedef struct s_factor 
{
	int			tab[6];
	t_ambient	*amb;	
	t_camera	*cam;
	t_light		*light;
	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;
}	t_factor;

#endif