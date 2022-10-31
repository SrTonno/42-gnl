/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:38:43 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/31 16:43:58 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>


char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s1);
void	*ft_calloc(size_t count, size_t size);
char	*ft_union(char *ptn, char *tmp);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*update_buffer(char *buffer);
char	*ft_reader(char *input, int fd);

#endif
