/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:03:54 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/13 12:39:02 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*pass_current_line(char	**res_line)
{
	size_t	cpt_buff;
	char	*rt_line;
	size_t	i;

	if (!*res_line)
		return (NULL);
	cpt_buff = 0;
	while ((*res_line)[cpt_buff] && (*res_line)[cpt_buff] != '\n')
		cpt_buff++;
	cpt_buff += ((*res_line)[cpt_buff] == '\n');
	rt_line = malloc(cpt_buff + 1);
	if (!rt_line)
		return (free((*res_line)), (*res_line) = NULL, NULL);
	i = 0;
	while ((*res_line)[i] && (*res_line)[i] != '\n')
	{
		rt_line[i] = (*res_line)[i];
		i++;
	}
	if ((*res_line)[i] == '\n')
		rt_line[i++] = '\n';
	rt_line[i] = '\0';
	return (rt_line);
}

char	*pass_next_line(char **old_line)
{
	size_t	i;
	char	*new_line;
	size_t	j;

	if (!*old_line)
		return (NULL);
	i = 0;
	while ((*old_line)[i] && (*old_line)[i] != '\n')
		i++;
	if (!(*old_line)[i] || !(*old_line)[i + 1])
		return (free(*old_line), *old_line = NULL, NULL);
	i += ((*old_line)[i] == '\n');
	new_line = malloc(ft_strlen(*old_line) - i + 1);
	if (!new_line)
		return (free(*old_line), NULL);
	j = 0;
	while ((*old_line)[i + j])
	{
		new_line[j] = (*old_line)[i + j];
		j++;
	}
	new_line[j] = '\0';
	free(*old_line);
	return (new_line);
}

static void	*check_rd_if_fail(char **get_ln, char **ln_fd, ssize_t rd_b)
{
	if (rd_b == -1)
	{
		free(*get_ln);
		free(*ln_fd);
		*ln_fd = NULL;
		return (NULL);
	}
	return (*get_ln);
}

char	*get_next_line(int fd)
{
	char		*get_line;
	static char	*res_line[OPEN_MAX];
	ssize_t		read_bytes;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	get_line = malloc((size_t)BUFFER_SIZE + 1);
	if (!get_line)
		return (free(res_line[fd]), res_line[fd] = NULL, NULL);
	read_bytes = 1;
	while (!check_retline(res_line[fd]) && read_bytes != 0)
	{
		read_bytes = read(fd, get_line, BUFFER_SIZE);
		if (!check_rd_if_fail(&get_line, &res_line[fd], read_bytes))
			return (NULL);
		get_line[read_bytes] = '\0';
		res_line[fd] = ft_strjoin(res_line[fd], get_line);
	}
	free(get_line);
	if (!res_line[fd] || *res_line[fd] == '\0')
		return (free(res_line[fd]), res_line[fd] = NULL, NULL);
	get_line = pass_current_line(&res_line[fd]);
	res_line[fd] = pass_next_line(&res_line[fd]);
	return (get_line);
}
