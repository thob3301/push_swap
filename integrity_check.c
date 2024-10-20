/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integrity_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:32:35 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/20 21:57:28 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_y_n(bool answer)
{
	if (answer)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

void	destroy_y_n(t_all_queues *all_queues, bool answer)
{
	if (answer)
		free_all_queues(all_queues);
	else
		return ;
	ft_putstr_fd("ERROR\n", 2);
	exit(-1);
}

// Comapares every number on the list with the numbers ahead. It never checks
// two elements twice.
bool	check_duplicates(t_deque *a_queue)
{
	t_deque_elm	*starter;
	t_deque_elm	*comperand;

	starter = a_queue->head;
	while (starter)
	{
		comperand = starter->next;
		while (comperand)
		{
			if (starter->num == comperand->num)
				return (1);
			comperand = comperand->next;
		}
		starter = starter->next;
	}
	return (0);
}
