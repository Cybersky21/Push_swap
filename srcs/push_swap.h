/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:35:47 by acrooks           #+#    #+#             */
/*   Updated: 2019/08/21 14:25:36 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct		s_ps
{
	int				*a;
	int				*b;
	int				ia;
	int				ib;
	char			flag : 1;
}					t_ps;

int					main(int argc, char **argv);

void				op_sa(t_ps *temp);
void				op_sb(t_ps *temp);
void				op_ss(t_ps *temp);
void				op_pa(t_ps *temp);
void				op_pb(t_ps *temp);
void				op_ra(t_ps *temp);
void				op_rb(t_ps *temp);
void				op_rr(t_ps *temp);
void				op_rra(t_ps *temp);
void				op_rrb(t_ps *temp);
void				op_rrr(t_ps *temp);

t_ps				*ft_fill(int argc);
int					ft_error(int *valid);
int					freetemp(t_ps *temp);
int					median(int *arr, int len);
size_t				strcnt(const char **str);

int					check_args(int len, t_ps *temp);
int					check_double(t_ps *temp, int len, int val, int *valid);
int					val_nbr(const char *str, int *valid);
int					atoi_ps(const char *str, int *valid);
void				ft_sorting(t_ps *temp, int *countb, int *blocks, int *sort);

void				ft_sorting1(t_ps *temp, int *sort);
int					check_move_a(int *arr, int len, int med);
void				ft_last_3a(t_ps *t);
int					move_a2b(t_ps *temp, int *countb, int *blocks, int notsort);
void				sorting2(t_ps *temp, int *countb, int *blocks);

int					check_val(t_ps *temp, int *countb, int *blocks);
void				check_val2(t_ps *temp, int *countb, int *blocks);
void				ft_last_3b(t_ps *temp, int *countb, int *blocks);
void				move_b2a(t_ps *temp, int *countb, int *blocks, int *len);
int					check_move_b(int *arr, int len, int med);

void				sort_rev_b(t_ps *temp, int len);
void				sorting1(t_ps *temp, int *countb, int *blocks, int *sort);
void				ft_last_3a_block(t_ps *temp, int *sort, int notsort);
void				sort_top_a(t_ps *temp);
void				sort_top_a2(t_ps *temp);
void				move_a(t_ps *temp, int *countb, int *blocks);
int					ft_check(const int *arr, int k);

int					ft_args(int argc, char **argv);
int					ft_one_arg(char **argv);
int					commands(t_ps *temp, char *str);
int					ft_error_checker(t_ps *temp);
int					ft_com_check(t_ps *temp);
void				ft_ok_ko(t_ps *temp);
void				ft_clean_args(char **args);

#endif
