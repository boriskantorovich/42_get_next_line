/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:07:45 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/26 17:29:02 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdarg.h>
#include <stdio.h>

/*
#define _ft_va_arg_test(ap, t)	((ap) = (ap) + __ft_va_argsiz(t)),	*((t*) (void*) ((**ap) - __ft_va_argsiz(t))))

void	print_ints(int num, ...)
{
	va_list	args;
	int		i;
	int		value;

	i = 0;
	va_start(args, num);
	while (i < num)
	{
		value = va_arg(args, int);
		printf("%d:	%d\n", i, value);
		i++;
	}
	va_end(args);
}

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

size_t	___ft_va_argsiz_test(const char *t)
{
	return ((sizeof(t) + sizeof(int) - 1) / (sizeof(int) * sizeof(int)));
}

void	_ft_va_start_test(ft_va_list **ap, const char *pN)
{
	*ap = (ft_va_list *)&pN + ___ft_va_argsiz_test(pN);
}

void _simple_printf(const char* fmt, ...)
{
	ft_va_list args;
	ft_va_start(args, fmt);
	ft_va_list *test;
	_ft_va_start_test(&test, fmt);
	printf("HMM HMM HMMM %s HMMM HMMM HMMM\n" , *test);


	while (*fmt != '\0') {
		if (*fmt == 'd') {
			int i = *_ft_va_arg_test(test, int);
			ft_putnbr(i);
            printf("!\n%d\n", i);
        } else if (*fmt == 'c') {
            // A 'char' variable will be promoted to 'int'
            // A character literal in C is already 'int' by itself
            int c = _ft_va_arg_test(test, int);
            printf("%c\n", c);
        } else if (*fmt == 'f') {
            double d = ft_va_arg(args, double);
            printf("%f\n", d);
        }
        ++fmt;
    }

    ft_va_end(args);
}


** this is a test main function for gnl project. one should not submit
** it to defense
*/

int			main(int argc, char **argv)
{
	/*
	simple_printf("dcff", 3, 'a', 1.999, 42.5);
	_simple_printf("dcff", 3, 'a', 1.999, 42.5);
	print_ints(4, 2, 3, 100, -2190);*/
	int		i;
	int		fd;
	char		*line;

	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
			ft_putchar('c');
			ft_putchar('\n');
		}
		close(fd);
	}
	return (0);
}
