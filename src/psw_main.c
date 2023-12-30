/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:05:57 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/20 14:05:58 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	psw_init_stacks(t_psw *stacks, char **inputs)
{
	int	size;

	size = split_size(inputs);
	stacks->al = size;
	stacks->bl = 0;
	stacks->sta = memory_create(size, sizeof(int));
	if (!stacks->sta)
		return (0);
	stacks->stb = memory_create(size, sizeof(int));
	if (!stacks->stb)
		return (0);
	return (1);
}

void	psw_start(char **inputs)
{
	t_psw	stacks;

	if (!psw_init_stacks(&stacks, inputs))
		return ((void)write(2, "Error\n", 6));
	if (psw_parse(&stacks, inputs, stacks.al) == 1)
		psw_sort(&stacks, stacks.al);
	else
		write(2, "Error\n", 6);
	memory_destroy(stacks.sta);
	memory_destroy(stacks.stb);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (ac == 2)
			av = split(av[1], ' ');
		else
			++av;
		psw_start(av);
		return (0);
	}
	return (0);
}
