/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:37:17 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/20 21:45:41 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	alloc_check(void *ptr)
{
	if (ptr == NULL)
		exit(-1);
}

// Sets up static variables storing the commands and corresponding functions,
// and saves them in the all purposes struct.
// Note: as I'm typing this I realise I could have kept the all_queues struct
// in the stack with main, as I've done before. I keep taking 2 steps forward
// and 1 step back in my journey with learning how to program.
// But the whole command list, function pointer list, enum token thing is
// pretty neat, right, you have to admit?
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
		return (NULL);
	element->num = num;
	return (element);
}
