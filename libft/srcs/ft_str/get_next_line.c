/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:40:34 by blanna            #+#    #+#             */
/*   Updated: 2019/06/20 17:47:00 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_idisuda(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = NULL;
	s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!s3)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}

static int		ft_check_line(char **stack, char **line, int fd, int ret)
{
	char	*temp;
	int		i;

	i = 0;
	while (stack[fd][i] != '\n' && stack[fd][i] != '\0')
		i++;
	if (stack[fd][i] == '\n')
	{
		*line = ft_strsub(stack[fd], 0, i);
		temp = ft_strdup(stack[fd] + i + 1);
		free(stack[fd]);
		stack[fd] = temp;
		if (stack[fd][0] == '\0')
			ft_strdel(&stack[fd]);
	}
	else if (stack[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stack[MAX_FD];
	char		lay[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	if ((fd < 0 || fd > MAX_FD) || !line)
		return (-1);
	while ((ret = read(fd, lay, BUFF_SIZE)) > 0)
	{
		lay[ret] = '\0';
		if (!stack[fd])
			stack[fd] = ft_strnew(1);
		temp = ft_idisuda(stack[fd], lay);
		stack[fd] = temp;
		if (ft_strchr(lay, '\n'))
			break ;
	}
	if (ret == -1)
		return (-1);
	else if (ret == 0 && (!stack[fd] || stack[fd][0] == '\0'))
	{
		*line = ft_strnew(1);
		return (0);
	}
	return (ft_check_line(stack, line, fd, ret));
}
