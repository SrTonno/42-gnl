/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:21:59 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/28 10:33:06 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptn;
	size_t	len;
	size_t	i;

	i = 0;
	len = size * count;
	if (len && len / size != count)
		return (NULL);
	ptn = malloc(len);
	if (ptn == NULL)
		return (ptn);
	while (len > i)
		((char *)ptn)[i++] = '\0';
	return (ptn);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x1;
	int		x2;
	int		i;
	int		j;
	char	*pnt;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x1 = ft_strlen((char *)s1);
	x2 = ft_strlen((char *)s2);
	i = -1;
	j = 0;
	pnt = ft_calloc(sizeof(char), (x1 + x2 + 1));
	if (pnt == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		pnt[i] = (char)s1[i];
	while (s2[j] != '\0')
		pnt[i++] = (char)s2[j++];
	pnt[i] = '\0';
	return (pnt);
}

char	*ft_strdup(const char *s1, int equal)
{
	int		i;
	char	*s2;

	i = 0;
	//if (equal == -1)
		//equal = ft_strlen(s1);
	s2 = ft_calloc(sizeof(char), (equal + 1));
	if (NULL == s2)
		return (NULL);
	while (equal > i)
	{
		s2[i] = s1[i];
		i++;
	}
	if (s1[i] && s1[i] == '\n')
		s2[i++] = '\n';
	s2[i] = '\0';
	return (s2);
}

