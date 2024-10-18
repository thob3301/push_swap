/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:54:11 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/15 17:54:30 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_all_queues *all_queues)
{
	deque_push_back(all_queues->a_queue,
		deque_pop_front(all_queues->a_queue));
}

void	rb(t_all_queues *all_queues)
{
	deque_push_back(all_queues->b_queue,
		deque_pop_front(all_queues->b_queue));
}

void	rr(t_all_queues *all_queues)
{
	ra(all_queues);
	rb(all_queues);
}
