/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_is_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:25:34 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/30 21:25:35 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

bool	char_is_spaces(int32_t ch)
{
	return (ch == ' ' || (ch >= 9 && ch <= 13));
}