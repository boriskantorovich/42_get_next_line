/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:07:45 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/25 21:26:41 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

/*
** this is a test main function for gnl project. one should not submit
** it to defense
*/

int			main(int argc, char **argv)
{

	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
			ft_putstr(line);
		ft_putchar('\n');
		close(fd);
	}
	return (0);
}
