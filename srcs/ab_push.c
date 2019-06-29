/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:53:15 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/19 19:16:22 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

void	op_pa(t_push_swap *temp)
{
	int push;
	int i;

	i = 0;
	if (temp->ib == 0)
		return ;
	push = temp->b;
	i = temp->ia;
	while (i > 0)
	{
		temp->a[i] = temp->a[i + 1];
		i--;
	}
	temp->a[0] = push;
	temp->ia++;
	i = 0;
	while (i < temp->ib - 1)
	{
		temp->b[i] = temp->b[i + 1];
		i--;
	}
	temp->ib--;
	temp->flag ? ft_putstr("pa\n") : 0;
}

void	op_pb(t_push_swap *temp)
{
	int push;
	int i;

	i = 0;
	if (temp->ia == 0)
		return ;
	push = temp->a;
	i = temp->ib;
	while (i > 0)
	{
		temp->b[i] = temp->b[i + 1];
		i--;
	}
	temp->b[0] = push;
	temp->ib++;
	i = 0;
	while (i < temp->ia - 1)
	{
		temp->a[i] = temp->a[i + 1];
		i--;
	}
	temp->ia--;
	temp->flag ? ft_putstr("pb\n") : 0;
}
