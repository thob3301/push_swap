/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:37:17 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/19 19:40:17 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	alloc_check(void *ptr)
{
	if (ptr == NULL)
		exit(-1);
}

t_all_queues	*init_structs(void)
{
	t_all_queues		*queues;
	static const char	*command_strings[]
		= {"sa\n", "sb\n", "ss\n",
		"pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n",
		"rra\n", "rrb\n", "rrr\n"};
	static void			(*functions[])(t_all_queues *)
		= {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr, free_all_queues};

	queues = ft_calloc(1, sizeof(t_all_queues));
	alloc_check(queues);
	queues->a_queue = ft_calloc(1, sizeof(t_deque));
	alloc_check(queues->a_queue);
	queues->b_queue = ft_calloc(1, sizeof(t_deque));
	alloc_check(queues->b_queue);
	queues->command_list = functions;
	queues->command_text = command_strings;
	queues->push_swap_return_list = ft_calloc(1, sizeof(t_deque));
	alloc_check(queues->push_swap_return_list);
	return (queues);
}

t_deque_elm	*init_deque_elm(int num)
{
	t_deque_elm	*element;

	element = ft_calloc(1, sizeof(t_deque_elm));
	if (!element)
		exit(-1);
	element->num = num;
//	element->next = (t_deque_elm *)NULL;
//	element->prev = (t_deque_elm *)NULL;
	return (element);
}
