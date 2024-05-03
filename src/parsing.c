/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:23:53 by chansjeo          #+#    #+#             */
/*   Updated: 2024/05/03 16:34:34 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	free_in_gnl(char *line, char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	free(line);
}

t_factor	*input_info(t_factor *factor, int fd, char *line, char **args)
{
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		args = ft_split_adv(line);
		if (ft_strncmp(args[0], "A", 2) == 0)
			get_amb(factor->amb, args);
		else if (ft_strncmp(args[0], "C", 2) == 0)
			get_cam(factor->cam, args);
		else if (ft_strncmp(args[0], "L", 2) == 0)
			get_light(factor->light, args);
		else if (ft_strncmp(args[0], "pl", 3) == 0)
			get_pl(factor->pl, args);
		else if (ft_strncmp(args[0], "sp", 3) == 0)
			get_sp(factor->sp, args);
		else if (ft_strncmp(args[0], "cy", 3) == 0)
			get_cy(factor->cy, args);
		else if (!is_space(args[0]))
		{
			ft_putstr_fd(args[0], 2);
			ft_error_msg("-> invalud element!\n", 1);
		}
		free_in_gnl(line, args);
	}
	close(fd);
	return (factor);
}

t_factor	*get_factor(const char *path)
{
	t_factor	*factor;
	int			fd;
	char		*line;
	char		**args;

	line = 0;
	args = 0;
	check_filename(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error_msg("open failed\n", 1);
	factor = ft_calloc_adv(1, sizeof(t_factor));
	factor->amb = ft_calloc_adv(1, sizeof(t_ambient));
	factor->cam = ft_calloc_adv(1, sizeof(t_camera));
	factor->light = ft_calloc_adv(1, sizeof(t_light));
	factor->pl = ft_calloc_adv(1, sizeof(t_plane));
	factor->sp = ft_calloc_adv(1, sizeof(t_sphere));
	factor->cy = ft_calloc_adv(1, sizeof(t_cylinder));
	return (input_info(factor, fd, line, args)); 
}

