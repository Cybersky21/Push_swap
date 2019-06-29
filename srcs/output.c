/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:42:53 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/20 17:25:30 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "push_swap.h"

void		error(t_push_swap *temp)
{
	int i;

	i = 0;
	write(2, "Error\n", 6);
	free(temp->flag);
	free(temp->a);
	free(temp->b);
	free(temp);
	exit(1);
	// (*valid) = 0; wat int *valid
	//return (0);
}


