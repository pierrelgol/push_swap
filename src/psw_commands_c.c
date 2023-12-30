/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:05:50 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/20 14:05:50 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	psw_ss(t_psw *c, int flag)
{
	if (c->al < 2 || c->bl < 2)
		return ;
	psw_swap(&c->sta[0], &c->sta[1]);
	psw_swap(&c->stb[0], &c->stb[1]);
	if (flag == PRINT_COMMAND)
		write(1, "ss\n", 3);
}

void	psw_rr(t_psw *c, int flag)
{
	int	tmp;

	if (c->al < 2 || c->bl < 2)
		return ;
	tmp = c->sta[0];
	memory_move(c->sta, c->sta + 1, (c->al - 1) * sizeof(int));
	c->sta[c->al - 1] = tmp;
	tmp = c->stb[0];
	memory_move(c->stb, c->stb + 1, (c->bl - 1) * sizeof(int));
	c->stb[c->bl - 1] = tmp;
	if (flag == PRINT_COMMAND)
		write(1, "rr\n", 3);
}

void	psw_rrr(t_psw *c, int flag)
{
	int	tmp;

	if (c->al < 2 || c->bl < 2)
		return ;
	tmp = c->sta[c->al - 1];
	memory_move(c->sta + 1, c->sta, (c->al - 1) * sizeof(int));
	c->sta[0] = tmp;
	tmp = c->stb[c->bl - 1];
	memory_move(c->stb + 1, c->stb, (c->bl - 1) * sizeof(int));
	c->stb[0] = tmp;
	if (flag == PRINT_COMMAND)
		write(1, "rrr\n", 4);
}
