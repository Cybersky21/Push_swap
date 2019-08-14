/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:42:53 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/14 17:24:59 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

int		freetemp(t_ps *temp)
{
	if (temp)
	{
		free(temp->a);
		free(temp->b);
		free(temp);
	}
	return (0);
}

int		ft_error(int *valid)
{
	write(2, "Error\n", 6);
	(*valid) = 0;
	exit(1);
	return (0);
}

t_ps	*ft_fill(int argc)
{
	t_ps	*temp;
	int		i;
	
	i = -1;
	if (!(temp = (t_ps *)malloc(sizeof(t_ps))))
		exit(1);
	if (!(temp->a = (int *)malloc(sizeof(int) * (argc + 1))))
		exit(1);
	if (!(temp->b = (int *)malloc(sizeof(int) * (argc + 1))))
		exit(1);
	while (++i < argc)
		temp->b[i] = 0;
	temp->ia = argc;
	temp->ib = 0;
	temp->flag = 1;
	return (temp);
}
