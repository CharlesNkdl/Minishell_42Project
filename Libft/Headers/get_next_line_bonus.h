/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:06:30 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/24 18:06:31 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

size_t	ft_strlengnl(char const *s, int version);
size_t	ft_strlcpygnl(char *dst, char const *src, size_t size);
char	*get_next_line(int fd);
char	*ft_extractfile(int fd, char *keeper);
char	*ft_extractline(char *keeper);
char	*ft_delete(char *keeper);
char	*ft_strjoingnl(char *s1, char *s2);
char	*ft_strrchrgnl(char const *s, int c, int *count);

#endif
