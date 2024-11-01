/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:02:56 by miteixei          #+#    #+#             */
/*   Updated: 2024/11/01 20:29:25 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_lowest(t_values *values, t_deque_elm *queue)
{
	if (!queue)
		return ;
	values->lowest_top_steps = -1;
	values->lowest_bottom_steps = 0;
	values->lowest_n = queue->num;
	queue = queue->next;
	while (queue)
	{
		if (values->lowest_n > queue->num)
			values->lowest_n = queue->num;
		queue = queue->next;
	}
}

void	check_highest(t_values *values, t_deque_elm *queue)
{
	if (!queue)
		return ;
	values->highest_top_steps = -1;
	values->highest_bottom_steps = 0;
	values->highest_n = queue->num;
	queue = queue->next;
	while (queue)
	{
		if (values->highest_n < queue->num)
			values->highest_n = queue->num;
		queue = queue->next;
	}
}

void	check_mid_low(t_values *values, t_all_queues *all_queues)
{
	t_deque_elm	*queue;

	values->lowest_top_steps = -1;
	values->lowest_bottom_steps = 0;
	values->lowest_n = INT_MIN;
	queue = all_queues->b_queue->head;
	while (queue)
	{
		if (values->lowest_n < queue->num
			&& queue->num < all_queues->a_queue->head->num)
			values->lowest_n = queue->num;
		queue = queue->next;
	}
}

void	check_mid_high(t_values *values, t_all_queues *all_queues)
{
	t_deque_elm	*queue;

	values->highest_top_steps = -1;
	values->highest_bottom_steps = 0;
	values->highest_n = INT_MAX;
	queue = all_queues->b_queue->head;
	while (queue)
	{
		if (values->highest_n > queue->num
			&& queue->num > all_queues->a_queue->tail->num)
			values->highest_n = queue->num;
		queue = queue->next;
	}
}
