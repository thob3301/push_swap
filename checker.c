/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:30:51 by miteixei          #+#    #+#             */
/*   Updated: 2024/11/01 20:55:30 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Every space separated argument, including those inside quotes, are read,
// and pushed into the queue in reverse as to preserve the argument order.
// The commands are read from standard input and executed imediately.
// The queue is checked for if it's sorted and the appropriate output is
// made.
int	main(int argc, char **argv)
{
	t_all_queues	*all_queues;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	all_queues = init_structs();
	while (argc-- > 1)
		split_args_push_queue(*(++argv), all_queues);
	destroy_y_n(all_queues, check_duplicates(all_queues->a_queue));
	read_input_commands(all_queues);
	sorted_y_n(is_sorted(all_queues));
	free_all_queues(all_queues);
}
