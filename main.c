/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:07:45 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/25 23:49:59 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void simple_printf(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            printf("%d\n", i);
        } else if (*fmt == 'c') {
            // A 'char' variable will be promoted to 'int'
            // A character literal in C is already 'int' by itself
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            printf("%f\n", d);
        }
        ++fmt;
    }

    va_end(args);
}


int combine_strings(char **outputStr,...)
{
    va_list ap;
    char *s, *out=0;
    int len=0;

    va_start(ap,outputStr);
    while((s=va_arg(ap,char *)))
    {
      len+=strlen(s);
    }
    va_end(ap);


    if(!(out=malloc(len+1)))
        exit(1);

    *outputStr=out;

    va_start(ap,outputStr);
    while((s=va_arg(ap,char *)))
    {
      len=strlen(s);
      memcpy(out,s,len);
      out+=len;
    }
    va_end(ap);

    *out=0;

    return 0;
}

int		ft_add(int args, ...)
{
	va_list	ap;

	va_start(ap, args);

	int i = 0;
	int sum = 0;

	while (i < args)
	{
		sum += va_arg(ap, int);
	}

	va_end(ap);
	return (sum);
}

void		ft_print_ints(int num, ...)
{
	va_list	args;

	va_start(args, num);

	int i = 0;
	int value = 0;
	while (i < num)
	{
		value = (int)va_arg(args,int);
		printf("%d: %d\n", i, value);
		i++;
	}

	va_end(args);
}
/*
** this is a test main function for gnl project. one should not submit
** it to defense
*/
/*
void		print_ints(int nums, ...)
{
	ft_va_list	args;

	ft_va_start(args, nums);

	for(int i = 0; i < nums; i++)
	{
		int value = ft_va_arg(args, int);
		printf("%d: %d\n", i, value);
	}

	ft_va_end(args);
}
*/
int			main(void)
{
	ft_print_ints(5, NULL);
	simple_printf("dcff", 3, 'a', 1.999, 42.5);
  char * res;
  char * * output = &res;
  combine_strings(output, "FOO", "BAR", "BAZ", NULL);
  printf("%s\n", *output);
	//ft_print_ints(10);
	//int i = ft_add(1, 2, 3);
	//printf("%d", i);
/*	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
			ft_putstr(line);
		ft_putchar('\n');
		close(fd);
	}*/
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
