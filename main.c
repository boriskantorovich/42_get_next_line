/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:07:45 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/26 20:16:39 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdarg.h>
#include <stdio.h>


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
			int i = ft_va_arg(test, int);
			ft_putnbr(i);
            printf("!\n%d\n", i);
        } else if (*fmt == 'c') {
            // A 'char' variable will be promoted to 'int'
            // A character literal in C is already 'int' by itself
            int c = ft_va_arg(test, int);
            printf("%c\n", c);
        } else if (*fmt == 'f') {
            double d = ft_va_arg(args, double);
            printf("%f\n", d);
        }
        ++fmt;
    }

    ft_va_end(args);
}

/*
int		ft_compare(char *content, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (content[i])
	{
		printf("\ncontent[i]?	%c\n", content[i]);
		j = 0;
		printf("\nstr[j]?		%c\n", str[j]);
		while(content[i] && content[i] != str[j] && str[j])
		{
			printf("\n# str[j]?	%c\n", str[j]);
			j++;
		}
		if (content[i] == str[j])
		{
			printf("\n# content[%c] == str[%c]\n", content[i],  str[j]);
			return (i);
		}
		i++;
	}
	printf("%zu | %d\n", ft_strlen(content), i);
	return (i);
}
*/
int			main(int argc, char **argv)
{
	//char *content = "But a lovely\nHe shaved evenly and with care, \nephen said. I can’t wear them if they are grey.";
	//char *str = "ya";

	//ft_compare(content, str);

	simple_printf("dcff", 3, 'a', 1.999, 42.5);
	_simple_printf("dcff", 3, 'a', 1.999, 42.5);
/*
	int		i;
	int		fd;
	char		*line;

	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
			printf("%s\n", line);
		close(fd);
	}
	return (0);
	*/
}
