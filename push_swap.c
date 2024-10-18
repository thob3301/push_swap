/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:49:38 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/17 17:22:28 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	allocate and initialize two queues
//	put numbers into the first queue
//	allocate and initialize command queue
//	until empty, queue 'a' is searched from top and bottom for
//		largest or smallest element
//	the queue is rotated until the element is at the top and is then pushed
//	if it's a large element queue 'b' is rotated for it to be at the bottom
//	once every element is pushed queue 'b' is rotated and finally pushed to 'a'
//	now every element should be sorted
//	the command queue is then searched for optimization and entries are replaced
//	finally, every command queue element is removed sequentially
//		 and printed to the screen
//	queues 'a' and 'b' are freed

//	Program execution

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

void	push_swap(t_all_queues *all_queues)
{
	(void)all_queues;
}

int	main(int argc, char **argv)
{
	t_all_queues	*all_queues;

	if (argc == 1)
		return (0);
	all_queues = init_structs();
	while (argc-- > 1)
		split_args_push_queue(*(++argv), all_queues);
	destroy_y_n(all_queues, check_duplicates(all_queues->a_queue));
	push_swap(all_queues);
	print_commands(all_queues);
	free_all_queues(all_queues);
}
