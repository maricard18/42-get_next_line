/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:59:52 by maricard          #+#    #+#             */
/*   Updated: 2022/12/10 10:38:23 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//C libraries
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

//Buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//Function Prototypes
char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *stash);
char	*ft_get_line(char *stash);
char	*ft_remove_line(char *stash);

//Utility functions
int		ft_strchr(char *buf, char c);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);

#endif
