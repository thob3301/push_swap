/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:30:51 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/18 20:42:59 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_commands	parse_command(const char *cmd, const char **command_strings)
{
	t_commands	i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(cmd, command_strings[i], 5))
			return (i);
		i++;
	}
	return (INVALID);
}

void	read_input_commands(t_all_queues *all_queues)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str)
			all_queues->command_list[parse_command(str,
				all_queues->command_text)](all_queues);
		else
			break ;
		free(str);
		str = NULL;
	}
}

bool	is_sorted(t_all_queues *all_queues)
{
	t_deque_elm	*element;

	element = all_queues->a_queue->head;
	while (element != all_queues->a_queue->tail)
	{
		if (element->num >= element->next->num)
			return (false);
		element = element->next;
	}
	if (all_queues->b_queue->size)
		return (false);
	return (true);
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
	read_input_commands(all_queues);
	sorted_y_n(is_sorted(all_queues));
	free_all_queues(all_queues);
}
