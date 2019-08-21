/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 19:30:14 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/20 16:24:09 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_top_a2(t_ps *temp)
{
	if (temp->a[0] < temp->a[1] && temp->a[0] > temp->a[2])
	{
		op_ra(temp);
		op_sa(temp);
		op_rra(temp);
		op_sa(temp);
	}
	else if (temp->a[0] > temp->a[1] && temp->a[1] > temp->a[2])
	{
		op_ra(temp);
		op_sa(temp);
		op_rra(temp);
		op_sa(temp);
		op_ra(temp);
		op_sa(temp);
		op_rra(temp);
	}
	else if (temp->a[0] > temp->a[1] && temp->a[0] < temp->a[2])
		op_sa(temp);
}

void	sort_top_a(t_ps *temp)
{
	if (temp->a[0] < temp->a[1] && temp->a[1] < temp->a[2])
		return ;
	else if (temp->a[0] < temp->a[2] && temp->a[1] > temp->a[2])
	{
		op_ra(temp);
		op_sa(temp);
		op_rra(temp);
	}
	else if (temp->a[0] > temp->a[2] && temp->a[2] > temp->a[1])
	{
		op_sa(temp);
		op_ra(temp);
		op_sa(temp);
		op_rra(temp);
	}
	else
		sort_top_a2(temp);
}

void	ft_last_3a_block(t_ps *temp, int *sort, int notsort)
{
	if (notsort == 1)
		(*sort)++;
	else if (notsort == 2)
	{
		if (temp->a[0] > temp->a[1])
			op_sa(temp);
		(*sort) += 2;
	}
	else if (notsort == 3)
	{
		sort_top_a(temp);
		(*sort) += 3;
	}
}

void	sorting1(t_ps *temp, int *countb, int *blocks, int *sort)
{
	int len;
	int	notsort;

	notsort = temp->ia - (*sort);
	if (check_args(notsort, temp))
	{
		(*sort) += notsort;
		return ;
	}
	if (notsort <= 3)
		ft_last_3a_block(temp, sort, notsort);
	else
	{
		len = move_a2b(temp, countb, blocks, notsort);
		while (len)
		{
			op_rra(temp);
			len--;
		}
		sorting1(temp, countb, blocks, sort);
	}
}
