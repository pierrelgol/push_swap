/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:05:43 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/20 14:05:44 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	psw_sb(t_psw *c, int flag)
{
	if (c->bl < 2)
		return ;
	psw_swap(&c->stb[0], &c->stb[1]);
	if (flag == PRINT_COMMAND)
		write(1, "sb\n", 3);
}

void	psw_pb(t_psw *c, int flag)
{
	if (!c->al)
		return ;
	c->bl++;
	memory_move(c->stb + 1, c->stb, sizeof(int) * (c->bl - 1));
	c->stb[0] = c->sta[0];
	c->al--;
	memory_move(c->sta, c->sta + 1, sizeof(int) * c->al);
	if (flag == PRINT_COMMAND)
		write(1, "pb\n", 3);
}

void	psw_rb(t_psw *c, int flag)
{
	int	tmp;

	if (c->bl < 2)
		return ;
	tmp = c->stb[0];
	memory_move(c->stb, c->stb + 1, (c->bl - 1) * sizeof(int));
	c->stb[c->bl - 1] = tmp;
	if (flag == PRINT_COMMAND)
		write(1, "rb\n", 3);
}

void	psw_rrb(t_psw *c, int flag)
{
	int	tmp;

	if (c->bl < 2)
		return ;
	tmp = c->stb[c->bl - 1];
	memory_move(c->stb + 1, c->stb, (c->bl - 1) * sizeof(int));
	c->stb[0] = tmp;
	if (flag == PRINT_COMMAND)
		write(1, "rrb\n", 4);
}
