/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:23:30 by chansjeo          #+#    #+#             */
/*   Updated: 2024/05/01 14:53:01 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	get_three_pos(t_vec3 *v, char *arg) 
{
	char	*buf;
	int		cnt;

	cnt = 0;
	while (1)
	{
		buf = ft_strsep(&arg, ",");
		if (!buf || *buf == '\0')
			break ;
		v->e[cnt] = ft_atof(buf);
		cnt++;
	}
	if (cnt != 3)
		ft_error_msg("There must be only three points.\n", 1);
}

void	get_amb(t_ambient *amb, char **args)
{
	amb->range = ft_atof(args[1]);
	get_three_pos(&amb->color, args[2]);
}

void	get_cam(t_camera *cam, char **args)
{
	get_three_pos(&cam->view_pos, args[1]);
	get_three_pos(&cam->unit_vec, args[2]);
	cam->fov = ft_atof(args[3]);
}

void	get_light(t_light *light, char **args)
{
	get_three_pos(&light->light_pos, args[1]);
	light->range = ft_atof(args[2]);
	get_three_pos(&light->color, args[3]);
}

void	get_pl(t_plane *pl, char **args)
{
	get_three_pos(&pl->plane_pos, args[1]);
	get_three_pos(&pl->unit_vec, args[2]);
	get_three_pos(&pl->color, args[3]);
}

void	get_sp(t_sphere *sp, char **args)
{
	get_three_pos(&sp->center_pos, args[1]);
	sp->diameter = ft_atof(args[2]);
	get_three_pos(&sp->color, args[3]);
}

void	get_cy(t_cylinder *cy, char **args)
{
	get_three_pos(&cy->center_pos, args[1]);
	get_three_pos(&cy->unit_vec, args[2]);
	cy->diameter = ft_atof(args[3]);
	cy->height = ft_atof(args[4]);
	get_three_pos(&cy->color, args[5]);
}
