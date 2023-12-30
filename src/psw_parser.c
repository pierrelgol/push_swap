/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:47:58 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/19 11:47:59 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	psw_parser_typecheck(char *input)
{
	unsigned int	digit_count;
	int				ch;

	digit_count = 0;
	while (*input)
	{
		ch = *input++;
		if (char_is_digit(ch))
			digit_count++;
		else if (ch != '+' && ch != '-')
			return (0);
	}
	return (digit_count >= 1);
}

static int	psw_parser_analyze(t_psw *stacks, char **inputs, t_table *table)
{
	unsigned int	i;
	long			num;

	i = 0;
	while (inputs[i])
	{
		num = string_to_long(inputs[i]);
		if (psw_parser_typecheck(inputs[i]) == 0)
			return (0);
		else if (num < -2147483648 || num > 2147483647)
			return (0);
		if (table_entry_get(table, inputs[i]) != 0)
			return (0);
		stacks->sta[i] = num;
		table_entry_set(table, inputs[i], &stacks->sta[i]);
		++i;
	}
	return (1);
}

int	psw_parse(t_psw *c, char **inputs, int size)
{
	t_table	*table;
	int		is_valid;

	if (!c || !inputs || size == 0)
		return (0);
	table = table_create();
	if (!table)
		return (0);
	is_valid = psw_parser_analyze(c, inputs, table);
	table_destroy(table);
	return (is_valid);
}
