/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:11:35 by chansjeo          #+#    #+#             */
/*   Updated: 2024/04/30 21:04:52 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static char	*ft_strpbrk(const char *cs, const char *ct)
{
	const char	*sc;

	sc = cs;
	while (*sc != '\0')
	{
		if (ft_strchr(ct, *sc))
			return (char *)sc;
		++sc;
	}
	return (NULL);
}

char	*ft_strsep(char **s, const char *ct)
{
	char	*sbegin;
	char	*end;

	sbegin = *s;
	if (sbegin == NULL)
		return NULL;
	end = ft_strpbrk(sbegin, ct);
	if (end)
		*end++ = '\0';
	*s = end;
	return (sbegin);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	main(void)
{
	char	*buf;
	char	*str;
	int		cnt;

	cnt = 0;
	str = malloc(sizeof(char) * 100);
	memset(str, 0, 100);
	memcpy(str, "hello,world,asdf,", 50);
	while (1)
	{
		buf = ft_strsep(&str, ",");
		if (!buf)
			break ;
		printf("%s\n", buf);
		cnt++;
	}
	if (cnt != 3)
		printf("3 point only!\n");
	return 0;
}
*/
