/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:54:26 by chansjeo          #+#    #+#             */
/*   Updated: 2024/05/13 12:10:15 by chansjeo         ###   ########.fr       */
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
	/*
	int image_width = 400;

	// Calculate the image height, and ensure that it's at least 1.
	int image_height = (int)(WIDTH / ASPECT_RATIO);
	image_height = (image_height < 1) ? 1 : image_height;

	// Viewport widths less than one are ok since they are real valued.
	double viewport_height = 2.0;
	double viewport_width = viewport_height * ((double)(image_width) / image_height);
	*/

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
}

void	free_factor(t_factor *f)
{
	free(f->amb);
	free(f->cam);
	free(f->light);
	free(f->cy);
	free(f->pl);
	free(f->sp);
	free(f);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_factor	*f;

	if (argc != 2)
		ft_error_msg("usage: ./miniRT [filename].rt\n", 1);
	f = get_factor(argv[1]);
	/* ----------- TEST parsing -------------
	printf("\t\t\tA : [%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			C : [%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\t[%.2f]\n \
			L : [%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			pl: [%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			sp: [%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			sp: [%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n \
			cy: [%.2f],[%.2f],[%.2f]\t[%.2f],[%.2f],[%.2f]\t[%.2f]\t[%.2f]\t[%.2f],[%.2f],[%.2f]\n",
		   f->amb->range, f->amb->color.e[0], f->amb->color.e[1], f->amb->color.e[2],
		   f->cam->view_pos.e[0], f->cam->view_pos.e[1], f->cam->view_pos.e[2], f->cam->unit_vec.e[0], f->cam->unit_vec.e[1], f->cam->unit_vec.e[2], f->cam->fov,
		   f->light->light_pos.e[0], f->light->light_pos.e[1], f->light->light_pos.e[2], f->light->range, f->light->color.e[0], f->light->color.e[1], f->light->color.e[2],
		   f->pl->plane_pos.e[0], f->pl->plane_pos.e[1], f->pl->plane_pos.e[2], f->pl->unit_vec.e[0], f->pl->unit_vec.e[1], f->pl->unit_vec.e[2], f->pl->color.e[0], f->pl->color.e[1], f->pl->color.e[2],
		   f->sp->center_pos.e[0], f->sp->center_pos.e[1], f->sp->center_pos.e[2], f->sp->diameter, f->sp->color.e[0], f->sp->color.e[1], f->sp->color.e[2],
		   f->sp[1].center_pos.e[0], f->sp[1].center_pos.e[1], f->sp[1].center_pos.e[2], f->sp[1].diameter, f->sp[1].color.e[0], f->sp[1].color.e[1], f->sp[1].color.e[2],
		   f->cy->center_pos.e[0], f->cy->center_pos.e[1], f->cy->center_pos.e[2], f->cy->unit_vec.e[0], f->cy->unit_vec.e[1], f->cy->unit_vec.e[2], f->cy->diameter, f->cy->height, f->cy->color.e[0], f->cy->color.e[1], f->cy->color.e[2]);
	*/
	init_window(&vars);
	double i = 0, j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			int pixel_color = create_unit_rgb((double)(j / (WIDTH - 1)), (double)(i / (HEIGHT - 1)), 0);
			my_mlx_pixel_put(&vars, j, i, pixel_color);
			j++;
		}
		i++;
	}
	/* -------------ray tracing START!------------ */
	///////////////////
	//               //
	//  ray_tracing  //
	//               //
	///////////////////
	/* -------------ray tracing END!------------ */
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	free_factor(f);
	return (0);
}
