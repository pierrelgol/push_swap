/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_growth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:26:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/02/14 14:26:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

void	queue_growth(t_queue *self)
{
	struct s_allocator	*allocator;
	t_list				*new_node;
	uint64_t			new_size;
	uint64_t			i;

	allocator = self->allocator;
	new_size = self->size * 2;
	i = self->size;
	while (i < new_size)
	{
		new_node = list_create(allocator);
		list_push_at(&self->freelist, new_node, 0);
		++i;
	}
	self->size = new_size;
}
