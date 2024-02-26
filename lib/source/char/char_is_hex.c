/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_is_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:26:53 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/30 21:26:54 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool	char_is_hex(int32_t ch)
{
	return (char_is_digit(ch) || ((ch | 32) >= 'a' && (ch | 32) <= 'f'));
}