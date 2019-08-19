/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:55:43 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/17 17:20:51 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

void	op_rra(t_ps *temp)
{
	int push;
	int i;

	i = 0;
	if (temp->ia < 2)
		return ;
	i = temp->ia - 1;
	push = temp->a[i];
	while (i > 0)
	{
		temp->a[i] = temp->a[i - 1];
		i--;
	}
	temp->a[0] = push;
	temp->flag ? ft_putstr("rra\n") : 0;
}

void	op_rrb(t_ps *temp)
{
	int push;
	int i;

	i = 0;
	if (temp->ib < 2)
		return ;
	i = temp->ib - 1;
	push = temp->b[i];
	while (i > 0)
	{
		temp->b[i] = temp->b[i - 1];
		i--;
	}
	temp->b[0] = push;
	temp->flag ? ft_putstr("rrb\n") : 0;
}

void	op_rrr(t_ps *temp)
{
	int push;
	int i;

	i = 0;
	if (temp->ia < 2 || temp->ib < 2)
		return ;
	i = temp->ia - 1;
	push = temp->a[i];
	while (i > 0)
	{
		temp->a[i] = temp->a[i - 1];
		i--;
	}
	temp->a[0] = push;
	i = temp->ib - 1;
	push = temp->b[i];
	while (i > 0)
	{
		temp->b[i] = temp->b[i - 1];
		i--;
	}
	temp->b[0] = push;
	temp->flag ? ft_putstr("rrr\n") : 0;
}
