/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line-back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:37:21 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/19 12:26:48 by tvillare         ###   ########.fr       */
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

char	*get_next_line-back(int fd)
{
	static char	buffer[1024];
	char		*ptn;
	int			i;
	int			numbytes;

	i = 0;
	ptn = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ptn)
		return(NULL);
	while (BUFFER_SIZE > i)
	{
		numbytes = read(fd, &buffer, sizeof(char));
		/*if (i == 0 && *buffer == '\n' && numbytes > 0)
		{
			numbytes = read(fd, &buffer, sizeof(char));
			while (*buffer == '\n' && numbytes > 0)
			{
				numbytes = read(fd, &buffer, sizeof(char));
			}
		}*/
		if (numbytes < 0 || *buffer == '\0')
		{
			free(ptn);
			return (NULL);
		}
		else if (*buffer == '\n')
		{
			//numbytes = read(fd, &buffer, sizeof(char));
			ptn[i] = 10;
			ptn[++i] = '\0';
			return (ptn);
		}
		ptn[i] = *buffer;
		i++;
	}
	while (*buffer != '\n' && numbytes > 0)
		numbytes = read(fd, &buffer, sizeof(char));
	ptn[i] = '\0';
	return (ptn);
}

