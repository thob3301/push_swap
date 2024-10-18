/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:53:33 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/15 17:53:55 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_all_queues *all_queues)
{
	deque_push_front(all_queues->a_queue,
		deque_pop_front(all_queues->b_queue));
}

void	pb(t_all_queues *all_queues)
{
	deque_push_front(all_queues->b_queue,
		deque_pop_front(all_queues->a_queue));
}
