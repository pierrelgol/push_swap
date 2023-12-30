/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:06:14 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/20 14:06:15 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	psw_median_sort(int *med, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && med[j - 1] > med[j])
		{
			psw_swap(&med[j - 1], &med[j]);
			--j;
		}
		i++;
	}
}

int	psw_sort2(t_psw *c, int is_b)
{
	int	*b;
	int	*a;

	b = c->stb;
	a = c->sta;
	if (b[0] < b[1] && is_b)
		psw_sb(c, PRINT_COMMAND);
	else if (a[0] > a[1] && !is_b)
		psw_sa(c, PRINT_COMMAND);
	return (1);
}

void	psw_sort3(t_psw *s)
{
	t_vec3	a;

	a = psw_top_to_vec3(s->sta);
	if (a.a > a.b && a.a < a.c && a.b < a.c)
		psw_sa(s, PRINT_COMMAND);
	if (a.a > a.b && a.a > a.c && a.b > a.c)
	{
		psw_sa(s, PRINT_COMMAND);
		psw_rra(s, PRINT_COMMAND);
	}
	if (a.a > a.b && a.a > a.c && a.b < a.c)
		psw_ra(s, PRINT_COMMAND);
	if (a.a < a.b && a.a < a.c && a.b > a.c)
	{
		psw_sa(s, PRINT_COMMAND);
		psw_ra(s, PRINT_COMMAND);
	}
	if (a.a < a.b && a.a > a.c && a.b > a.c)
		psw_rra(s, PRINT_COMMAND);
}

int	psw_sort(t_psw *c, int size)
{
	if (psw_is_stack_sorted(c->sta, c->al, ASCEND) == 0)
	{
		if (size == 2)
			psw_sa(c, PRINT_COMMAND);
		else if (size == 3)
			psw_sort3(c);
		else
			psw_qsort_a(c, size, 0);
	}
	return (0);
}

int	psw_sort_push(t_psw *c, int len, int flag)
{
	if (flag == 0)
		psw_pb(c, PRINT_COMMAND);
	else
		psw_pa(c, PRINT_COMMAND);
	return (--len);
}
