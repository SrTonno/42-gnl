/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:38:43 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/02 11:05:03 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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
