/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:56:30 by chansjeo          #+#    #+#             */
/*   Updated: 2024/05/03 16:15:29 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

/* vector.h */
typedef struct s_vec3 
{
    double e[3];
} t_vec3;

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

/* element.h */
typedef enum e_element
{
	AMBIENT,
	CAMERA,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER	
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
	t_vec3	view_pos;
	t_vec3	unit_vec; //3d normalized orientation vector. In range [-1,1]
	double		fov; //Horizontal field of view in degrees in range [0,180]
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
	int	id;
	t_vec3	center_pos; // ∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
	t_vec3	unit_vec; // ∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
	double	diameter; // ∗ the cylinder diameter: 14.2
	double	height; // ∗ the cylinder height: 21.42
	t_vec3	color; // ∗ R,G,B colors in range [0,255]: 10, 0, 255
}	t_cylinder;

typedef struct s_factor 
{
	t_ambient	*amb;	
	t_camera	*cam;
	t_light		*light;
	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;
}	t_factor;

/* image.h */

# define WIDTH 800
# define HEIGHT 800
# define ESC 53

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	scale;
	int		color;
}	t_vars;

int	create_rgb(int r, int g, int b);
int	get_t(int trgb);
int get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);

void	*ft_calloc_adv(size_t count, size_t size);
char	**ft_split_adv(char *str);

/* parsing.c */
void		ft_error_msg(char *str, int exit_status);
double		ft_atof(char *str);
t_factor	*get_factor(const char *path);
t_factor	*input_info(t_factor *factor, int fd, \
						char *line, char **args);
int		is_space(const char *str);
char	*ft_strsep(char **s, const char *ct);
int		check_filename(const char *path);

void	get_three_pos(t_vec3 *v, char *arg);
void	get_amb(t_ambient *amb, char **args);
void	get_cam(t_camera *cam, char **args);
void	get_light(t_light *light, char **args);
void	get_pl(t_plane *pl, char **args);
void	get_sp(t_sphere *sp, char **args);
void	get_cy(t_cylinder *cy, char **args);


#endif
