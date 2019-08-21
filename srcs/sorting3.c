/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 19:11:17 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/20 16:24:41 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		move_a2b(t_ps *temp, int *countb, int *blocks, int notsort)
{
	int med;
	int	pos;
	int len;

	len = 0;
	med = median(temp->a, countb[(*blocks)]);
	(*blocks)++;
	pos = check_move_a(temp->a, notsort, med) + 1;
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

	med = median(temp->b, countb[(*blocks)]);
	pos = check_move_b(temp->b, countb[(*blocks)] - 1, med) + 1;
	while (pos)
	{
		if (temp->b[0] > med)
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
