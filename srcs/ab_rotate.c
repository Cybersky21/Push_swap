/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:54:59 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/20 16:18:49 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_ps *temp)
{
	int push;
	int i;

	i = 0;
	if (temp->ia == 0)
		return ;
	push = temp->a[0];
	while (i + 1 < temp->ia)
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
	if (temp->ib == 0)
		return ;
	push = temp->b[0];
	while (i + 1 < temp->ib)
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
	if (temp->ia < 0 || temp->ib < 0)
		return ;
	push = temp->a[0];
	while (i + 1 < temp->ia)
	{
		temp->a[i] = temp->a[i + 1];
		i++;
	}
	temp->a[i] = push;
	i = 0;
	push = temp->b[0];
	while (i + 1 < temp->ib)
	{
		temp->b[i] = temp->b[i + 1];
		i++;
	}
	temp->b[i] = push;
	temp->flag ? ft_putstr("rr\n") : 0;
}
