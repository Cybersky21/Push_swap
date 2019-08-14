/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:42:14 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/13 18:42:14 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		median(int *arr, int len)
{
	int	tmp[len];
	int	i;
	int med;

	i = -1;
	med = 0;
	while (++i < len)
		tmp[i] = arr[i];
	i = 0;
	while (len - 1 > i)
	{
		if (tmp[i] > tmp[i + 1])
		{
			ft_swap(&tmp[i], &tmp[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	med = tmp[len / 2];
	return (med);
}

int			check_move_a(int *arr, int len, int med)
{
	len--;
	while (len >= 0)
	{
		if (arr[len] < med)
			return (len);
		len--;
	}
	return (len);
}

void		move_a(t_ps *temp, int *countb, int *blocks)
{
	int med;
	int	pos;

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
		}
		pos--;
	}
}

void	ft_sorting1(t_ps *temp, int *sort)
{
	if (temp->ia == 3)
	{
		ft_last_3a(temp);
		(*sort) = 3;
	}
	else if (temp->ia == 2)
	{
		if (temp->a[0] > temp->a[1])
			op_sa(temp);
		(*sort) = 2;
	}
	else if (temp->ia == 1)
		(*sort) = 1;
}

void	ft_sorting(t_ps *temp, int *countb, int *blocks, int *sort)
{
	while (temp->ia > 3)
	{
		if (check_args(temp->ia, temp, 0))
		{
			(*sort) = temp->ia;
			return ;
		}
		move_a(temp, countb, blocks);
	}
	ft_sorting1(temp, sort);
}
