/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:20:13 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/14 18:12:04 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
int		check_retline(char *line);
char	*ft_strjoin(char *s1, char *s2);
char	*pass_next_line(char **line);
char	*pass_current_line(char **src_ln);
char	*get_next_line(int fd);

#endif