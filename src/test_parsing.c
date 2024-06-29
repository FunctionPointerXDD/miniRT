/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:43:29 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 17:46:32 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

// ----------- TEST parsing -------------
void	test_parsing(t_factor *f)
{
	printf("\t\t\tA : [%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			C : [%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\t[%.2f]\n \
			L : [%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			pl: [%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			sp: [%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			sp: [%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			cy: [%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n",
			f->amb->range, f->amb->color.e[0], f->amb->color.e[1], f->amb->color.e[2], \
			f->cam->view_pos.e[0], f->cam->view_pos.e[1], f->cam->view_pos.e[2], f->cam->unit_vec.e[0],\
			f->cam->unit_vec.e[1], f->cam->unit_vec.e[2], f->cam->fov,
			f->light->light_pos.e[0], f->light->light_pos.e[1], f->light->light_pos.e[2], f->light->range,\
			f->light->color.e[0], f->light->color.e[1], f->light->color.e[2],
			f->pl->plane_pos.e[0], f->pl->plane_pos.e[1], f->pl->plane_pos.e[2], f->pl->unit_vec.e[0],\
			f->pl->unit_vec.e[1], f->pl->unit_vec.e[2], f->pl->color.e[0], f->pl->color.e[1], f->pl->color.e[2],
			f->sp->center_pos.e[0], f->sp->center_pos.e[1], f->sp->center_pos.e[2], f->sp->diameter,\
			f->sp->color.e[0], f->sp->color.e[1], f->sp->color.e[2],
			f->sp[1].center_pos.e[0], f->sp[1].center_pos.e[1], f->sp[1].center_pos.e[2], \
			f->sp[1].diameter, f->sp[1].color.e[0], f->sp[1].color.e[1], f->sp[1].color.e[2],
			f->cy->center_pos.e[0], f->cy->center_pos.e[1], f->cy->center_pos.e[2], f->cy->unit_vec.e[0],\
			f->cy->unit_vec.e[1], f->cy->unit_vec.e[2], f->cy->diameter, f->cy->height, f->cy->color.e[0], f->cy->color.e[1], f->cy->color.e[2]);
}

