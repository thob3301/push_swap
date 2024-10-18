/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:52:42 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/15 17:53:07 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_all_queues *all_queues)
{
	t_deque_elm	*element1;
	t_deque_elm	*element2;

	element1 = deque_pop_front(all_queues->a_queue);
	element2 = deque_pop_front(all_queues->a_queue);
	deque_push_front(all_queues->a_queue, element1);
	deque_push_front(all_queues->a_queue, element2);
}

void	sb(t_all_queues *all_queues)
{
	t_deque_elm	*element1;
	t_deque_elm	*element2;

	element1 = deque_pop_front(all_queues->b_queue);
	element2 = deque_pop_front(all_queues->b_queue);
	deque_push_front(all_queues->b_queue, element1);
	deque_push_front(all_queues->b_queue, element2);
}

void	ss(t_all_queues *all_queues)
{
	sa(all_queues);
	sb(all_queues);
}
