/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:42:53 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/20 16:21:06 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		freetemp(t_ps *temp)
{
	if (temp)
	{
		free(temp->a);
		free(temp->b);
		free(temp);
	}
	return (0);
}

int		ft_error(int *valid)
{
	write(2, "Error\n", 6);
	(*valid) = 0;
	exit(1);
	return (0);
}

void	ft_clean_args(char **args)
{
	size_t i;

	i = 0;
	while (args && args[i])
		free(args[i++]);
	if (args)
		free(args);
}

int		ft_check(const int *arr, int k)
{
	int i;

	i = 0;
	if (k == 0 || k == 1)
		return (0);
	while (i < k - 1)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

t_ps	*ft_fill(int argc)
{
	t_ps	*temp;
	int		i;

	i = -1;
	if (!(temp = (t_ps *)malloc(sizeof(t_ps))))
		exit(1);
	if (!(temp->a = (int *)malloc(sizeof(int) * (argc + 1))))
		exit(1);
	if (!(temp->b = (int *)malloc(sizeof(int) * (argc + 1))))
		exit(1);
	while (++i < argc)
		temp->b[i] = 0;
	temp->ia = argc;
	temp->ib = 0;
	temp->flag = 1;
	return (temp);
}
