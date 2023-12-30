/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:06:06 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/20 14:06:07 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	psw_find_median(int *pvt, int *arr, int size)
{
	int	*median;

	median = memory_create(size, sizeof(int));
	if (!median)
		return (0);
	memory_copy(median, arr, (size) * sizeof(int));
	psw_median_sort(median, size);
	*pvt = median[size / 2];
	memory_destroy(median);
	return (1);
}

int	psw_sort_small_a(t_psw *c, int len)
{
	int	*a;

	a = c->sta;
	if (len == 3 && c->al == 3)
		psw_sort3(c);
	else if (len == 2 && a[0] > a[1])
		psw_sa(c, PRINT_COMMAND);
	else if (len == 3)
	{
		while (len != 3 || !psw_top_is_sorted(a))
		{
			if ((len == 3 && a[0] > a[1]) || (a[0] > a[1]))
				psw_sa(c, PRINT_COMMAND);
			else if (len == 3 && !(a[2] > a[0] && a[2] > a[1]))
				len = psw_sort_push(c, len, 0);
			else if (len++)
				psw_pa(c, PRINT_COMMAND);
		}
	}
	return (1);
}

int	psw_sort_small_b(t_psw *c, int len)
{
	int	*a;
	int	*b;

	a = c->sta;
	b = c->stb;
	if (len == 1)
		psw_pa(c, PRINT_COMMAND);
	else if (len == 2 && psw_sort2(c, 1))
		while (len--)
			psw_pa(c, PRINT_COMMAND);
	else if (len == 3)
	{
		while (len || !psw_top_is_sorted(a))
		{
			if (len == 1 && a[0] > a[1])
				psw_sa(c, PRINT_COMMAND);
			else if ((len == 1 || b[0] > b[1]) || (len == 3 && b[0] > b[2]))
				len = psw_sort_push(c, len, 1);
			else
				psw_sb(c, PRINT_COMMAND);
		}
	}
	return (1);
}

int	psw_qsort_a(t_psw *c, int high, int low)
{
	int	pivot;
	int	idx;

	if (psw_is_stack_sorted(c->sta, high, ASCEND) == 1)
		return (1);
	if (high <= 3)
		return (psw_sort_small_a(c, high));
	if (!low && !psw_find_median(&pivot, c->sta, high))
		return (0);
	idx = high;
	while (high != idx / 2 + idx % 2)
	{
		if (c->sta[0] < pivot && (high--))
			psw_pb(c, PRINT_COMMAND);
		else if (++low)
			psw_ra(c, PRINT_COMMAND);
	}
	while (idx / 2 + idx % 2 != c->al && low--)
		psw_rra(c, PRINT_COMMAND);
	return (psw_qsort_a(c, idx / 2 + idx % 2, 0) && psw_qsort_b(c, idx / 2, 0));
}

int	psw_qsort_b(t_psw *c, int high, int low)
{
	int	pivot;
	int	idx;

	if (!low && psw_is_stack_sorted(c->stb, high, DESCEND) == 1)
		while (high--)
			psw_pa(c, PRINT_COMMAND);
	if (high <= 3)
		return (psw_sort_small_b(c, high));
	if (!psw_find_median(&pivot, c->stb, high))
		return (0);
	idx = high;
	while (high != idx / 2)
	{
		if (c->stb[0] >= pivot && high--)
			psw_pa(c, PRINT_COMMAND);
		else if (++low)
			psw_rb(c, PRINT_COMMAND);
	}
	while (idx / 2 != c->bl && low--)
		psw_rrb(c, PRINT_COMMAND);
	return (psw_qsort_a(c, idx / 2 + idx % 2, 0) && psw_qsort_b(c, idx / 2, 0));
}
