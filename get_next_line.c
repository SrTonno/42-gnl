/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:37:21 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/28 13:23:58 by tvillare         ###   ########.fr       */
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

void	*update_buffer(char *text, int equal)
{
/*
	int		i;
	char	*aux;

	i = 0;
	equal = 0;
	//equal = equal;
	while (buffer[equal] && buffer[equal] != '\n')
		equal++;
	if (!buffer[equal])
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[equal] == '\n')
		equal++;
	aux = ft_calloc((ft_strlen(buffer) - equal) + 1, sizeof(char));
	if (!aux)
		return (NULL);
	//equal++;
	if (buffer[equal])
	{
		aux[i++] = buffer[equal++];
		//i++;
	}
	aux[i] = '\0';
	free(buffer);
	return (aux);
	*/
	char	*aux;
	int		counter;
	int		counter_aux;
	(void)equal;

	counter = 0;
	while (text[counter] && text[counter] != '\n')
		counter++;
	if (!text[counter])
	{
		free(text);
		return (NULL);
	}
	aux = NULL;
	if (text[counter] == '\n')
		counter++;
	aux = ft_calloc((ft_strlen(text) - counter) + 1, sizeof(char));
	if (!aux)
		return (NULL);
	counter_aux = 0;
	while (text[counter])
		aux[counter_aux++] = text[counter++];
	free(text);
	return (aux);
}

char	*ft_union(char *input, char *tmp)
{
	char	*aux;

	aux = ft_strjoin(input, tmp);
	if(!aux)
		return (NULL);
	free(input);
	return (aux);
}

int	hunt_nl(char *tmp)
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

char	*ft_reader(char *input, int fd)
{
	char	*tmp;
	int		numbytes;

	if (input == NULL)
	{
		input = ft_calloc(1, sizeof(char));
		//if (input == NULL)
			//return (NULL);
	}
	numbytes = 1;
	tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (tmp == NULL)
			return (NULL);
	while (0 < numbytes)
	{
		numbytes = read(fd, tmp, BUFFER_SIZE);
		if (numbytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[numbytes] = '\0';
		input = ft_union(input, tmp);
		//if (!input)
			//return(NULL);
		if (hunt_nl(tmp) > -1)
			break;
	}
	free(tmp);
	return (input);
}
/*
char	*create_nl(char *input, int equal)
{
	char	*ptn;
	//if (ft_strlen(input) == equal)
		//return (input);
	ptn = ft_strdup(input, equal);
	if (!ptn)
		return (NULL);
	return (ptn);

}
*/
char	*get_next_line(int fd)
{
	//static char	buffer[BUFFER_SIZE + 1];
	static char	*buffer;
	char		*tmp;
	int 		equal;

	//printf("inicio\n");
	if (read(fd, 0, 0) < 0)
	{
		if(buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = ft_reader(buffer, fd);
	if (!buffer)
		return (NULL);
	///printf("(%s)", buffer);
	equal = hunt_nl(buffer);
	//printf("%d\n", equal);
	tmp = ft_strdup(buffer, equal);
	buffer = update_buffer(buffer, equal);
	//printf("[%s]", buffer);
	//printf("fin\n");
	return (tmp);
}
