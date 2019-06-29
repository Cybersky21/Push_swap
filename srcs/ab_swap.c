/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:34:52 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/19 19:16:32 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

void	op_sa(t_push_swap *temp)
{
	int swap;
	
	if (temp->ia < 2)
		return ;
	swap = temp->a[0];
	temp->a[0] = temp->a[1];
	temp->a[1] = swap;
	temp->flag ? ft_putstr("sa\n") : 0;
}

void	op_sb(t_push_swap *temp)
{
	int swap;
	
	if (temp->ib < 2)
		return ;
	swap = temp->b[0];
	temp->b[0] = temp->b[1];
	temp->b[1] = swap;
	temp->flag ? ft_putstr("sb\n") : 0;
}

void	op_ss(t_push_swap *temp)
{
	int swap;
	
	if (temp->ia < 2 || temp->ib < 2)
		return ;
	swap = temp->a[0];
	temp->a[0] = temp->a[1];
	temp->a[1] = swap;
	swap = temp->b[0];
	temp->b[0] = temp->b[1];
	temp->b[1] = swap;
	temp->flag ? ft_putstr("ss\n") : 0;
}
