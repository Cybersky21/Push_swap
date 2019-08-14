/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:42:19 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/14 17:12:40 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

void	ft_last_3b(t_ps *temp, int *countb, int *blocks)
{
	if (countb[(*blocks)] == 3)
	{
		op_pa(temp);
		op_pa(temp);
		op_pa(temp);
	}
	else if (countb[(*blocks)] == 2)
	{
		op_pa(temp);
		op_pa(temp);
	}
	else if (countb[(*blocks)] == 1)
	{
		op_pa(temp);
	}
	countb[(*blocks)] = 0;
}

void	check_val2(t_ps *temp, int *countb, int *blocks)
{
	int len;

	len = countb[(*blocks)];
	while (len)
	{
		op_pa(temp);
		len--;
	}
	countb[(*blocks)] = 0;
}

int		check_val(t_ps *temp, int *countb, int *blocks)
{
	int len;
	int	i;

	len = countb[(*blocks)];
	i = 0;
	while (i < len - 1)
	{
		if (temp->b[i] < temp->b[i + 1])
			return (0);
		i++;
	}
	check_val2(temp, countb, blocks);
	return(1);
}

void	sorting2(t_ps *temp, int *countb, int *blocks)
{
	int len;

	len = 0;
	if (check_val(temp, countb, blocks))
		return ;
	if (countb[(*blocks)] <= 3)
		ft_last_3b(temp, countb, blocks);
	else
	{
		move_b2a(temp, countb, blocks, &len);
		if ((*blocks) != 0)
			sort_rev_b(temp, len); // &
	}
}

void	ft_last_3a(t_ps *t)
{
	if (t->a[0] > t->a[2] && t->a[2] > t->a[1])
		op_ra(t);
	else if (t->a[1] > t->a[0] && t->a[0] > t->a[2])
		op_rra(t);
	else if (t->a[0] > t->a[1] && t->a[0] < t->a[2])
		op_sa(t);
	else if (t->a[0] > t->a[1] && t->a[1] > t->a[2])
	{
		op_ra(t);
		op_sa(t);
	}
	else if (t->a[1] > t->a[0] && t->a[2] > t->a[0])
	{
		op_rra(t);
		op_sa(t);
	}
}
