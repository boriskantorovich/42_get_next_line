/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfisher <dfisher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:13:47 by dfisher           #+#    #+#             */
/*   Updated: 2019/07/20 21:13:24 by dfisher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# define	BUFF_SIZE 100000
# include "libft.h"
/*exclude this includes for release */
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int	get_next_line(const int fd, char **line);

#endif