/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:37:21 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/26 12:38:46 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
/*
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
*/

void	*update_buffer-back2(char *buffer, int equal)
{
	char *aux;
	int i;

	i = -1;
	aux = buffer + equal;
	while (aux[++i] != '\0')
		buffer[i] = aux[i];
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_union(char *ptn, char *tmp, int equal)
{
	ptn = ft_strjoin(ptn, tmp, equal);
	if(!ptn)
		return (NULL);
	//free (tmp);
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
	static char	buffer[BUFFER_SIZE + 1];
	//char		*tmp;
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
		equal = hunt_nl(buffer);
		/*
		//tmp = ft_strdup((char *)&buffer, equal);
		if (!tmp)
		{
			free(ptn);
			return(NULL);
		}
		*/
		//printf("%s", tmp);
		ptn = ft_union(ptn, buffer, equal);
		if (!ptn)
		{
			//free(ptn);
			return(NULL);
		}
		if (equal != -1)
		{
			//ft_strlcpy((char *)buffer, (char *)buffer + equal, BUFFER_SIZE);
			update_buffer(buffer, equal);
			break;
		}
	}
	return(ptn);
}
