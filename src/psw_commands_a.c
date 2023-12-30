/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:05:35 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/20 14:05:36 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	psw_sa(t_psw *c, int flag)
{
	if (c->al < 2)
		return ;
	psw_swap(&c->sta[0], &c->sta[1]);
	if (flag == PRINT_COMMAND)
		write(1, "sa\n", 3);
}

void	psw_pa(t_psw *c, int flag)
{
	if (!c->bl)
		return ;
	c->al++;
	memory_move(c->sta + 1, c->sta, sizeof(int) * (c->al - 1));
	c->sta[0] = c->stb[0];
	c->bl--;
	memory_move(c->stb, c->stb + 1, sizeof(int) * c->bl);
	if (flag == PRINT_COMMAND)
		write(1, "pa\n", 3);
}

void	psw_ra(t_psw *c, int flag)
{
	int	tmp;

	if (c->al < 2)
		return ;
	tmp = c->sta[0];
	memory_move(c->sta, c->sta + 1, (c->al - 1) * sizeof(int));
	c->sta[c->al - 1] = tmp;
	if (flag == PRINT_COMMAND)
		write(1, "ra\n", 3);
}

void	psw_rra(t_psw *c, int flag)
{
	int	tmp;

	if (c->al < 2)
		return ;
	tmp = c->sta[c->al - 1];
	memory_move(c->sta + 1, c->sta, (c->al - 1) * sizeof(int));
	c->sta[0] = tmp;
	if (flag == PRINT_COMMAND)
		write(1, "rra\n", 4);
}
