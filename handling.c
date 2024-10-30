/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:13:24 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/21 19:17:45 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_split(char **split_str)
{
	int	arr_i;

	arr_i = 0;
	while (split_str[arr_i])
		free(split_str[arr_i++]);
	free(split_str);
}

bool	is_number(char *nstr)
{
	if (*nstr && (*nstr == '-' || *nstr == '+'))
		nstr++;
	if (!(*nstr) || !ft_isdigit(*nstr))
		return (0);
	while (*nstr && ft_isdigit(*nstr))
		nstr++;
	if (*nstr != '\0')
		return (0);
	return (1);
}

// Splits a string received by spaces and checks if they're valid numbers,
// if so it pushes them to the end of queue A.
// If it's not a valid number it frees everything and terminates the program 
// after printing an error.
// Likewise if the number is larger than an int, which is checked by simply
// converting the number into a long long and then comparing the two.
// If the int overflowed or underflowed it's probably not going to match the
// long conversion.
void	split_args_push_queue(char *arg, t_all_queues *all_queues)
{
	int		arr_i;
	char	**split_str;

	split_str = ft_split(arg, ' ');
	arr_i = 0;
	while (split_str[arr_i])
	{
		if (is_number(split_str[arr_i]))
		{
			deque_push_back(all_queues->a_queue,
				init_deque_elm(ft_atoi(split_str[arr_i])));
		}
		else
			escape_now(all_queues, split_str);
		if (ft_atol(split_str[arr_i]) != all_queues->a_queue->tail->num)
			escape_now(all_queues, split_str);
		arr_i++;
	}
	free_split(split_str);
}
