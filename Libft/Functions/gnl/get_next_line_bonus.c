/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:05:58 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/24 18:06:00 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Take the new line
	the read command keep the reader in the same spot so i can't backtrack
	we need to stock it in the static
	then we need to clean the static keeper otherwise it'll take too much space
	We need to handle -D flag
	Hypothesis : - stock a buffer
				- analyse it for a newline
				- extract the newline
				- clean the keeper for future iteration
		How : - 2D array of string
			- long string
			- linked list ? => tested but too complicated for me actually
			- linked list in queue ? same
		What i did : Long string + 2D array for multiple fd entries*/

char	*get_next_line(int fd)
{
	static char	*keeper[2048];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keeper[fd] = ft_extractfile(fd, keeper[fd]);
	if (!keeper[fd])
		return (NULL);
	line = ft_extractline(keeper[fd]);
	keeper[fd] = ft_delete(keeper[fd]);
	return (line);
}
/* It'll read the file, stock it in a buffer,
	put it in the keeper (static) while the reader doesnt return an error or EOF
	the while loop stop when a newline is encountered in the keeper */

char	*ft_extractfile(int fd, char *keeper)
{
	char	*buffer;
	int		reader;
	int		count;

	reader = 1;
	count = 0;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (reader != 0 && !ft_strrchrgnl(&(keeper[count]), 10, &count))
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(keeper);
			free(buffer);
			return (NULL);
		}
		buffer[reader] = '\0';
		keeper = ft_strjoingnl(keeper, buffer);
	}
	free(buffer);
	return (keeper);
}
/* we know there is a newline in the keeper
we find the location of the next newline,
	we malloc a new variable then we copy it*/

char	*ft_extractline(char *keeper)
{
	size_t	i;
	char	*line;

	if (!keeper[0])
		return (NULL);
	i = ft_strlengnl(keeper, 2);
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strlcpygnl(line, keeper, (i + 2));
	return (line);
}
/* we take the index
	+ 1 of the newline's location then we copy the rest in a new string
then we send it back into the 2D static array*/

char	*ft_delete(char *keeper)
{
	size_t	i;
	size_t	lentot;
	char	*rempl;

	i = ft_strlengnl(keeper, 2);
	lentot = ft_strlengnl(keeper, 1);
	if (!keeper[i])
	{
		free(keeper);
		return (NULL);
	}
	rempl = (char *)malloc(sizeof(char) * (lentot - i + 1));
	if (!rempl)
		return (NULL);
	ft_strlcpygnl(rempl, &(keeper[i + 1]), (lentot - i + 1));
	free(keeper);
	return (rempl);
}
