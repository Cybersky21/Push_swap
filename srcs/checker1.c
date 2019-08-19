/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:21:03 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/19 19:27:52 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

int		ft_com_check(t_ps *temp)
{
	char	*str;
	
	while (get_next_line(0, &str))
	{
		if (!commands(temp, str))
		{
			write(2, "Error\n", 6);
			free(str);
			exit(1);
			return (0);
		}
		if (str != NULL)
			free(str);
	}
	return (1);
}

void	ft_ok_ko(t_ps *temp)
{
	if (ft_check(temp->a, temp->ia) == 0 && temp->ib == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
