/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:24:05 by pyammoun          #+#    #+#             */
/*   Updated: 2022/03/17 19:06:25 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFER_SIZE 20

size_t		ft_strlen2(char *buffjoin);
int			ft_isn(char *buffjoin);
char		*ft_strjoin2(char *s1, char *s2);
char		*ft_strndup(char *buffjoin, size_t n);
char		*get_next_line(int fd);
#endif 
