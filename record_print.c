/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:08:43 by miteixei          #+#    #+#             */
/*   Updated: 2024/11/01 20:29:48 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commands(t_all_queues *all_queues)
{
	t_deque_elm	*current_elm;

	current_elm = all_queues->push_swap_return_list->head;
	while (current_elm)
	{
		ft_putstr_fd((char *)all_queues->command_text[current_elm->num], 1);
		current_elm = current_elm->next;
	}
}

static void	push_swap_record2(t_commands command, t_all_queues *all_queues)
{
	if (all_queues->push_swap_return_list->size
		&& ((all_queues->push_swap_return_list->tail->num == RRA
				&& command == RRB)
			|| (all_queues->push_swap_return_list->tail->num == RRB
				&& command == RRA)))
	{
		free(deque_pop_back(all_queues->push_swap_return_list));
		deque_push_back(all_queues->push_swap_return_list, init_deque_elm(RRR));
	}
	else
		deque_push_back(all_queues->push_swap_return_list,
			init_deque_elm(command));
}

void	push_swap_record(t_commands command, t_all_queues *all_queues)
{
	if (all_queues->push_swap_return_list->size
		&& ((all_queues->push_swap_return_list->tail->num == SA
				&& command == SB)
			|| (all_queues->push_swap_return_list->tail->num == SB
				&& command == SA)))
	{
		free(deque_pop_back(all_queues->push_swap_return_list));
		deque_push_back(all_queues->push_swap_return_list, init_deque_elm(SS));
	}
	else if (all_queues->push_swap_return_list->size
		&& ((all_queues->push_swap_return_list->tail->num == RA
				&& command == RB)
			|| (all_queues->push_swap_return_list->tail->num == RB
				&& command == RA)))
	{
		free(deque_pop_back(all_queues->push_swap_return_list));
		deque_push_back(all_queues->push_swap_return_list, init_deque_elm(RR));
	}
	else
		push_swap_record2(command, all_queues);
	all_queues->command_list[command](all_queues);
}
