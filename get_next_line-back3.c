/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:37:21 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/26 18:11:11 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line-back3.h"
/*
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
*/

void	*update_buffer(char *buffer, int equal)
{
	int		i;

	i = 0;
	while (buffer[equal] != '\0')
		buffer[i++] = buffer[equal++];
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_union(char *ptn, char *tmp, int equal)
{
	ptn = ft_strjoin(ptn, tmp, equal);
	if(!ptn)
		return (NULL);
	free(tmp);
	return (ptn);
}

int hunt_nl(char *tmp)
{
	int i;

	i = 0;
	while (BUFFER_SIZE > i)
	{
		if (tmp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
char	*get_next_line(int fd)
{
	//static char	buffer[BUFFER_SIZE + 1];
	static char	*buffer;
	char		*tmp;
	char		*ptn;
	int			numbytes;
	int			equal;

 	numbytes = 1;
	ptn = ft_calloc(1, 1);
	if (!ptn)
		return(NULL);
	if (read(fd, 0, 0) < 0)
	{
		if(buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	while (0 < numbytes)
	{
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
		numbytes = read(fd, &buffer, BUFFER_SIZE);
		if (numbytes == -1)
		{
			free (ptn);
			return (NULL);
		}
		//tmp = buffer;

		//tmp = ft_strdup(&buffer, 0);
		//if (!tmp)
		//{
		//	free(tmp);
		//	return(NULL);
		//}

		printf("a");
		equal = hunt_nl(buffer);
		printf("%d", equal);
		printf("%d", equal);
		ptn = ft_union(ptn, buffer, equal);
		if (!ptn)
		{
			free(ptn);
			return(NULL);
		}
		free(buffer);
		if (equal != -1)
		{
			//update_buffer(buffer, equal);
			break;
		}
	}
	return(ptn);
}
