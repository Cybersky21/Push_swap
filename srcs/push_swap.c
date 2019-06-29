/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:41:56 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/20 21:43:39 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

void		freetemp(t_push_swap *temp)
{
	int i;

	i = 0;
	free(temp->a);
	free(temp->b);
}

int			read_args(int argc, char **argv)
{
	
}

int			main(int argc, char **argv)
{
	// int	err;
	t_push_swap	temp;

	if (argc == 1)
		return (0);
	ft_bzero(&temp, sizeof(temp));
	// fill
	if (!read_args(argc, argv))
	{
		freetemp(&temp);
		exit(0);
	}
	// swap
	freetemp(&temp);
	return (0);
}

