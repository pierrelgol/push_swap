/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:06:22 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/20 14:06:23 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	psw_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	psw_top_is_sorted(int *stack)
{
	t_vec3	vec;

	vec = psw_top_to_vec3(stack);
	return (vec.a < vec.b && vec.b < vec.c);
}

t_vec3	psw_top_to_vec3(int *stack)
{
	return ((t_vec3){.a = stack[0], .b = stack[1], .c = stack[2]});
}

int	psw_is_stack_sorted(int *stack, int size, int order)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (order == ASCEND && stack[i - 1] > stack[i])
			return (0);
		if (order == DESCEND && stack[i - 1] < stack[i])
			return (0);
		i++;
	}
	return (1);
}
