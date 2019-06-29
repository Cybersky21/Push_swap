/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:35:47 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/20 19:11:56 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
// # include "libft.h"

typedef struct	s_push_swap
{
	int				*a;
	int				*b;
	unsigned int	ia;
	unsigned int	ib;
	char			flag : 1; // max 1 symbol // 1 - print 0 - not print
}				t_push_swap;

void				op_sa(t_push_swap *temp);
void				op_sb(t_push_swap *temp);
void				op_ss(t_push_swap *temp);
void				op_pa(t_push_swap *temp);
void				op_pb(t_push_swap *temp);
void				op_ra(t_push_swap *temp);
void				op_rb(t_push_swap *temp);
void				op_rr(t_push_swap *temp);
void				op_rra(t_push_swap *temp);
void				op_rrb(t_push_swap *temp);
void				op_rrr(t_push_swap *temp);

int					main(int argc, char **argv);
void				error(t_push_swap *temp);
void				freetemp(t_push_swap *temp);
int					median(int *arr, int len);

#endif
