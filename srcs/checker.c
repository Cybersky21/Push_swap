/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:20:30 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/21 14:17:20 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		commands(t_ps *temp, char *str)
{
	if (ft_strequ(str, "rra"))
		op_rra(temp);
	else if (ft_strequ(str, "rrb"))
		op_rrb(temp);
	else if (ft_strequ(str, "rrr"))
		op_rrr(temp);
	else if (ft_strequ(str, "sa"))
		op_sa(temp);
	else if (ft_strequ(str, "sb"))
		op_sb(temp);
	else if (ft_strequ(str, "ss"))
		op_ss(temp);
	else if (ft_strequ(str, "pa"))
		op_pa(temp);
	else if (ft_strequ(str, "pb"))
		op_pb(temp);
	else if (ft_strequ(str, "ra"))
		op_ra(temp);
	else if (ft_strequ(str, "rb"))
		op_rb(temp);
	else if (ft_strequ(str, "rr"))
		op_rr(temp);
	else
		return (0);
	return (1);
}

int		ft_one_arg(char **argv)
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
	temp->flag = 0;
	while (++i < len)
	{
		temp->a[i] = atoi_ps(args[i], &valid);
		check_double(temp, i, temp->a[i], &valid);
		if (!valid)
			return (freetemp(temp));
	}
	if (ft_com_check(temp))
		ft_ok_ko(temp);
	ft_clean_args(args);
	freetemp(temp);
	return (1);
}

int		ft_args(int argc, char **argv)
{
	t_ps	*temp;
	int		i;
	int		valid;
	char	*str;

	i = -1;
	valid = 1;
	temp = ft_fill(argc - 1);
	temp->flag = 0;
	while (++i < argc - 1)
	{
		temp->a[i] = atoi_ps(argv[i + 1], &valid);
		check_double(temp, i, temp->a[i], &valid);
		if (!valid)
			return (freetemp(temp));
	}
	if (ft_com_check(temp))
		ft_ok_ko(temp);
	freetemp(temp);
	return (1);
}

int		main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (0);
	if (argc == 2)
		ft_one_arg(argv);
	else
		ft_args(argc, argv);
	return (0);
}
