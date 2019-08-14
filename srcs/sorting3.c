/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 19:11:17 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/14 13:31:00 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

int		move_a2b(t_ps *temp, int *countb, int *blocks, int notsort)
{
	int med;
	int	pos;
	int len;

	len = 0;
	med = median(temp->a, temp->ia);
	(*blocks)++;
	pos = check_move_a(temp->a, temp->ia, med) + 1;
	while (pos)
	{
		if (temp->a[0] < med)
		{
			op_pb(temp);
			countb[(*blocks)]++;
		}
		else
		{
			op_ra(temp);
			len++;
		}
		pos--;
	}
	return (len);
}

void	sort_rev_b(t_ps *temp, int len)
{
	while (len)
	{
		op_rrb(temp);
		len--;
	}
}

int		check_move_b(int *arr, int len, int med)
{
	while (len >= 0)
	{
		if (arr[len] > med)
			return (len);
		len--;
	}
	return (len);
}

void	move_b2a(t_ps *temp, int *countb, int *blocks, int *len)
{
	int med;
	int	pos;

	med = median(temp->b, temp->ib);
	pos = check_move_b(temp->b, temp->ib, med) - 1;
	while (pos)
	{
		if (temp->a[0] > med)
		{
			op_pa(temp);
			countb[(*blocks)]--;
		}
		else
		{
			op_rb(temp);
			(*len)++;
		}
		pos--;
	}
}
