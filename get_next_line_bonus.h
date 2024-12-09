/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:02:31 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/09 15:57:54 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef	BUFFER_SIZE
# define	BUFFER_SIZE 69
# endif

#include <unistd.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);
int     check_retline(char * line);
char    *ft_strjoin(char *s1, char *s2);
char	*pass_next_line(char *line);
char	*pass_current_line(char *src_ln);
char	*get_next_line(int fd);

# endif