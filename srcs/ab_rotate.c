/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:54:59 by acrooks           #+#    #+#             */
/*   Updated: 2019/07/21 01:44:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

void	op_ra(t_ps *temp)
{
	int push;
	int i;

	i = 0;
	if (!temp->a)
		return ;
	push = temp->a[0];
	while (i < temp->ia - 1)
	{
		temp->a[i] = temp->a[i + 1];
		i++;
	}
	temp->a[i] = push;
	temp->flag ? ft_putstr("ra\n") : 0;
}

void	op_rb(t_ps *temp)
{
	int push;
	int i;

	i = 0;
	if (!temp->b)
		return ;
	push = temp->b[0];
	while (i < temp->ib - 1)
	{
		temp->b[i] = temp->b[i + 1];
		i++;
	}
	temp->b[i] = push;
	temp->flag ? ft_putstr("rb\n") : 0;
}

void	op_rr(t_ps *temp)
{
	int push;
	int i;

	i = 0;
	if (!temp->a || !temp->b)
		return ;
	push = temp->a[0];
	while (i < temp->ia - 1)
	{
		temp->a[i] = temp->a[i + 1];
		i++;
	}
	temp->a[i] = push;
	i = 0;
	push = temp->b[0];
	while (i < temp->ib - 1)
	{
		temp->b[i] = temp->b[i + 1];
		i++;
	}
	temp->b[i] = push;
	temp->flag ? ft_putstr("rr\n") : 0;
}
