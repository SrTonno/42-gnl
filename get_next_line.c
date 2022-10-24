/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:37:21 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/24 17:45:13 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
*/


char	*ft_union(char *ptn, char *tmp)
{
	ptn = ft_strjoin(ptn, tmp);
	if(!ptn)
		return (NULL);
	free (tmp);
	return (ptn);
}

int hunt_nl(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	char		*ptn;
	int			numbytes;
	int			equal;

	numbytes = 1;
	ptn = ft_calloc(1, 1);
	if (!ptn)
		return(NULL);
	while (numbytes > 0)
	{
		numbytes = read(fd, &buffer, BUFFER_SIZE);
		//printf("(%d)", numbytes);
		if (numbytes == -1)
		{
			//printf("%d - null-", numbytes);
			return (NULL);
		}
		equal = hunt_nl((char *)&buffer);
		tmp = ft_strdup((char *)&buffer, equal);
		if (!tmp)
		{
			free(ptn);
			return(NULL);
		}
		//printf("%s", tmp);
		ptn = ft_union(ptn, tmp);
		if (!ptn)
		{
			free(ptn);
			return(NULL);
		}
		if (equal != -1)
		{
			ft_strlcpy((char *)buffer, (char *)buffer + equal, (BUFFER_SIZE - equal));
			//buffer = &buffer[equal];
			//buffer[equal] = 0;
			break;
		}
	}
	return(ptn);
}
