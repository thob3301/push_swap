/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:55:36 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/21 19:14:30 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	escape_now(t_all_queues *all_queues, char **split_str)
{
	free_all_queues(all_queues);
	free_split(split_str);
	ft_putstr_fd("ERROR\n", 2);
	exit(-1);
}

// Loops over every element of the queue and frees memory until it's empty.
// deque_pop_front decrements queue->size automatically.
static void	deque_destroy(t_deque *queue)
{
	while (queue->size)
		free(deque_pop_front(queue));
}

void	free_all_queues(t_all_queues *all_queues)
{
	deque_destroy(all_queues->a_queue);
	free(all_queues->a_queue);
	deque_destroy(all_queues->b_queue);
	free(all_queues->b_queue);
	deque_destroy(all_queues->push_swap_return_list);
	free(all_queues->push_swap_return_list);
	free(all_queues);
}
