/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:30:51 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/20 21:16:36 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Parses commands by comparing them to a list saved in a static variable.
// Returns a token, defined in an enum, that corresponds to the command and its
// respective function by index.
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

// Reads standard input, a token is retrieved from each command received,
// and the corresponding function is run on the lists.
// If no match occurs the free_all_queues() function is automatically run,
// and the program quits.
void	read_input_commands(t_all_queues *all_queues)
{
	char		*str;
	t_commands	command;

	while (1)
	{
		str = get_next_line(0);
		if (str)
		{
			command = parse_command(str, all_queues->command_text);
			all_queues->command_list[command](all_queues);
			if ((int)command == 11)
			{
				free(str);
				ft_putstr_fd("ERROR\n", 2);
				exit(-1);
			}
		}
		else
			break ;
		free(str);
	}
}

// Checks whether the list A is sorted by comparing every adjacent pair
// and then if list B is empty.
// Also checks if list A is empty.
bool	is_sorted(t_all_queues *all_queues)
{
	t_deque_elm	*element;

	element = all_queues->a_queue->head;
	if (!all_queues->a_queue->size)
		return (false);
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

// Every space separated argument, including those inside quotes, are read,
// and pushed into the queue in reverse as to preserve the argument order.
// The commands are read from standard input and executed imediately.
// The queue is checked for if it's sorted and the appropriate output is
// made.
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
