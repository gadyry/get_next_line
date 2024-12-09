/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:37:06 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/09 21:10:30 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	cpt;

	cpt = 0;
	while (str && str[cpt])
		cpt++;
	return (cpt);
}

int	check_retline(char * line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strdup(char *s)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
static char	*check_one_if_null(char *s1, char *s2)
{
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	return (NULL);
}

static void	copy_strings(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*str;
	size_t	len;
	size_t	j;
	char	*check_res;
	int		len1;
	int		len2;
	
	if (!s1 && !s2)
		return (NULL);
	check_res = check_if_one_null(s1, s2);
	if (check_res)
		return(check_res);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	copy_strings(str,s1,s2);
	free(s1);
	return (str);
}
