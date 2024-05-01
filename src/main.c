/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:54:26 by chansjeo          #+#    #+#             */
/*   Updated: 2024/05/01 18:14:44 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	exit_hook(void)
{
	exit(0);
}

static int key_hook(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

static void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit(1);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "miniRT");
	if (vars->win == NULL)
		exit(1);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (vars->img == NULL)
		exit(1);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, \
			&vars->line_length, &vars->endian);
	if (vars->addr == NULL)
		exit(1);
	vars->scale = 1.0;
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_factor	*e;

	if (argc != 2)
		ft_error_msg("usage: ./miniRT [filename].rt\n", 1);
	e = get_factor(argv[1]);
	printf("\t\t\tA : [%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			C : [%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\t[%.2f]\n \
			L : [%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			pl: [%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			sp: [%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			cy: [%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n",
		   e->amb->range, e->amb->color.e[0], e->amb->color.e[1], e->amb->color.e[2],
		   e->cam->view_pos.e[0], e->cam->view_pos.e[1], e->cam->view_pos.e[2], e->cam->unit_vec.e[0], e->cam->unit_vec.e[1], e->cam->unit_vec.e[2], e->cam->fov,
		   e->light->light_pos.e[0], e->light->light_pos.e[1], e->light->light_pos.e[2], e->light->range, e->light->color.e[0], e->light->color.e[1], e->light->color.e[2],
		   e->pl->plane_pos.e[0], e->pl->plane_pos.e[1], e->pl->plane_pos.e[2], e->pl->unit_vec.e[0], e->pl->unit_vec.e[1], e->pl->unit_vec.e[2], e->pl->color.e[0], e->pl->color.e[1], e->pl->color.e[2],
		   e->sp->center_pos.e[0], e->sp->center_pos.e[1], e->sp->center_pos.e[2], e->sp->diameter, e->sp->color.e[0], e->sp->color.e[1], e->sp->color.e[2],
		   e->cy->center_pos.e[0], e->cy->center_pos.e[1], e->cy->center_pos.e[2], e->cy->unit_vec.e[0], e->cy->unit_vec.e[1], e->cy->unit_vec.e[2], e->cy->diameter, e->cy->height, e->cy->color.e[0], e->cy->color.e[1], e->cy->color.e[2]);
	/* -------------ray tracing START!------------ */
	init_window(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	/* -------------ray tracing END!------------ */
	return (0);
}
