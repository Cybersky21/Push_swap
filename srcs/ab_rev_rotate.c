/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:55:43 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/19 19:16:25 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

void	op_rra(t_push_swap *temp)
{
	int push;
	int i;

	i = 0;
	if (!temp->ia)
		return ;
	push = temp->a[temp->ia - 1];
	i = temp->ia - 1;
	while (i > 0)
	{
		temp->a[i] = temp->a[i - 1];
		i--;
	}
	temp->a[0] = push;
	temp->flag ? ft_putstr("rra\n") : 0;
}

void	op_rrb(t_push_swap *temp)
{
	int push;
	int i;

	i = 0;
	if (!temp->ib)
		return ;
	push = temp->b[temp->ib - 1];
	i = temp->ib - 1;
	while (i > 0)
	{
		temp->b[i] = temp->b[i - 1];
		i--;
	}
	temp->b[0] = push;
	temp->flag ? ft_putstr("rrb\n") : 0;
}

void	op_rrr(t_push_swap *temp)
{
	int push;
	int i;

	i = 0;
	if (!temp->ia || !temp->ib)
		return ;
	push = temp->a[temp->ia - 1];
	i = temp->ia - 1;
	while (i > 0)
	{
		temp->a[i] = temp->a[i - 1];
		i--;
	}
	temp->a[0] = push;
	i = 0;
	push = temp->b[temp->ib - 1];
	i = temp->ib - 1;
	while (i > 0)
	{
		temp->b[i] = temp->b[i - 1];
		i--;
	}
	temp->b[0] = push;
	temp->flag ? ft_putstr("rrr\n") : 0;
}
