/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:07:45 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/23 19:48:46 by dfisher          ###   ########.fr       */
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
	/*
	char		*line;
	int			fd;
	//int			ret;
	//int			count_lines;
	char		*filename;
	//int			errors;

	filename = "gnl1_1.txt";
	fd = open(filename, O_RDONLY);
	while ((get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		//ft_putchar('\n');
	}
	close(fd);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n", line);
			printf("%d\n", count_lines);
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break;
		}
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
	*/
	return (0);
}
