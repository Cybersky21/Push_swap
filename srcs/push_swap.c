/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:41:56 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/20 16:21:58 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_swap(t_ps *temp)
{
	int len;
	int sort;
	int *countb;
	int blocks;

	len = temp->ia;
	sort = 0;
	blocks = -1;
	countb = ft_memalloc(999);
	ft_sorting(temp, countb, &blocks, &sort);
	while (sort != len)
	{
		sorting2(temp, countb, &blocks);
		sorting1(temp, countb, &blocks, &sort);
		if (countb[blocks] == 0)
			blocks--;
	}
	free(countb);
	return (1);
}

static int	ps_one_arg(char **argv)
{
	t_ps	*temp;
	int		i;
	char	**args;
	int		len;
	int		valid;

	i = -1;
	valid = 1;
	args = ft_strsplit(argv[1], ' ');
	len = strcnt((const char **)args);
	temp = ft_fill(len);
	while (++i < len)
	{
		temp->a[i] = atoi_ps(args[i], &valid);
		check_double(temp, i, temp->a[i], &valid);
		if (!valid)
			return (freetemp(temp));
	}
	if (!check_args(i, temp))
		push_swap(temp);
	ft_clean_args(args);
	freetemp(temp);
	return (1);
}

static int	ps_args(int argc, char **argv)
{
	int		i;
	int		valid;
	t_ps	*temp;

	i = -1;
	valid = 1;
	temp = ft_fill(argc - 1);
	while (++i < argc - 1)
	{
		temp->a[i] = atoi_ps(argv[i + 1], &valid);
		check_double(temp, i, temp->a[i], &valid);
		if (!valid)
			return (freetemp(temp));
	}
	if (!check_args(i, temp))
		push_swap(temp);
	freetemp(temp);
	return (1);
}

int			main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		return (ft_error(&i));
	if (argc == 2)
	{
		if (!ps_one_arg(argv))
			return (0);
	}
	else
	{
		if (!ps_args(argc, argv))
			return (0);
	}
	return (1);
}
