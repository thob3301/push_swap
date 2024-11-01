/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:12:34 by miteixei          #+#    #+#             */
/*   Updated: 2024/11/01 20:29:38 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_3(t_values *values, t_all_queues *all_queues)
{
	if (!(all_queues->a_queue->head->num == values->lowest_n
			&& all_queues->a_queue->tail->num == values->highest_n)
		&& !(all_queues->a_queue->head->num == values->highest_n
			&& all_queues->a_queue->head->next->num == values->lowest_n)
		&& !(all_queues->a_queue->tail->num == values->lowest_n
			&& all_queues->a_queue->tail->prev->num == values->highest_n))
		push_swap_record(SA, all_queues);
	if (!(all_queues->a_queue->head->num == values->lowest_n
			&& all_queues->a_queue->tail->num == values->highest_n)
		&& !(all_queues->a_queue->tail->num == values->lowest_n
			&& all_queues->a_queue->tail->prev->num == values->highest_n))
		push_swap_record(RA, all_queues);
	if (!(all_queues->a_queue->head->num == values->lowest_n
			&& all_queues->a_queue->tail->num == values->highest_n))
		push_swap_record(RRA, all_queues);
}

void	push_swap_5(t_values *values, t_all_queues *all_queues)
{
	int	i;

	i = 2;
	while (i--)
	{
		ft_bzero(values, sizeof(t_values));
		check_lowest(values, all_queues->a_queue->head);
		nbr_of_steps_bottom(values, all_queues->a_queue->tail);
		nbr_of_steps_top(values, all_queues->a_queue->head);
		if (values->lowest_top_steps < values->lowest_bottom_steps)
			rotate_n_steps(values->lowest_top_steps, TOP, A_LIST, all_queues);
		else
			rotate_n_steps(values->lowest_bottom_steps,
				BOTTOM, A_LIST, all_queues);
		push_swap_record(PB, all_queues);
	}
	ft_bzero(values, sizeof(t_values));
	check_lowest(values, all_queues->a_queue->head);
	check_highest(values, all_queues->a_queue->head);
	push_swap_3(values, all_queues);
	while (++i < 2)
		push_swap_record(PA, all_queues);
}
