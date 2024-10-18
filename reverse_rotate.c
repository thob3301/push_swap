/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:54:40 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/15 17:54:58 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_all_queues *all_queues)
{
	deque_push_front(all_queues->a_queue,
		deque_pop_back(all_queues->a_queue));
}

void	rrb(t_all_queues *all_queues)
{
	deque_push_front(all_queues->b_queue,
		deque_pop_back(all_queues->b_queue));
}

void	rrr(t_all_queues *all_queues)
{
	rra(all_queues);
	rrb(all_queues);
}
