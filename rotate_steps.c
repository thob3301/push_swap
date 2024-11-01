/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_steps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:07:14 by miteixei          #+#    #+#             */
/*   Updated: 2024/11/01 20:28:59 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_n_steps(int steps, bool side,
		bool list, t_all_queues *all_queues)
{
	while (steps--)
	{
		if (list == A_LIST)
		{
			if (side == TOP)
				push_swap_record(RA, all_queues);
			else
				push_swap_record(RRA, all_queues);
		}
		if (list == B_LIST)
		{
			if (side == TOP)
				push_swap_record(RB, all_queues);
			else
				push_swap_record(RRB, all_queues);
		}
	}
}

void	nbr_of_steps_bottom(t_values *values, t_deque_elm *queue)
{
	t_deque_elm	*backup;

	if (!queue)
		return ;
	backup = queue;
	while (queue)
	{
		values->lowest_bottom_steps++;
		if (values->lowest_n == queue->num)
			break ;
		queue = queue->prev;
	}
	while (backup)
	{
		values->highest_bottom_steps++;
		if (values->highest_n == backup->num)
			break ;
		backup = backup->prev;
	}
}

void	nbr_of_steps_top(t_values *values, t_deque_elm *queue)
{
	t_deque_elm	*backup;

	if (!queue)
		return ;
	backup = queue;
	while (queue)
	{
		values->lowest_top_steps++;
		if (values->lowest_n == queue->num)
			break ;
		queue = queue->next;
	}
	while (backup)
	{
		values->highest_top_steps++;
		if (values->highest_n == backup->num)
			break ;
		backup = backup->next;
	}
}
