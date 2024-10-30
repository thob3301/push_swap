/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:49:38 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/30 22:09:53 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Until empty, each top element of queue A is checked for its proximity to
//	  max and min elements every cycle.
//	If they're close enough they're pushed to B, otherwise queue A is rotated.
//	If the element being pushed is near max, queue B is rotated, so that near
//	  max elements pile at the bottom and near min elements pile at the top.
//	This is so queue B is 'nearly' sorted upside down.
//	Now every exact min and max elements are checked in queue B every cycle,
//	  and whichever is closest to the top or bottom, and takes the least number
//	  of moves to push to the other side will be chosen for that cycle, and are
//	  thus pushed to queue A.
//	Since queue B is 'nearly' sorted, the lowest and highest elements are
//	  close to the bottom and top, and will take few moves to sort.
//	Now every element should be sorted.
//	Every time a push_swap command is registered, the previous command is
//	  checked for optimization,
//	  i.e. sa + sb => ss; ra + rb => rr; rra + rrb => rrr

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

void	check_lowest(t_values *values, t_deque_elm *queue)
{
	if (!queue)
		return ;
	values->lowest_top_steps = -1;
	values->lowest_bottom_steps = 0;
	values->lowest_n = queue->num;
	queue = queue->next;
	while (queue)
	{
		if (values->lowest_n > queue->num)
			values->lowest_n = queue->num;
		queue = queue->next;
	}
}

void	check_highest(t_values *values, t_deque_elm *queue)
{
	if (!queue)
		return ;
	values->highest_top_steps = -1;
	values->highest_bottom_steps = 0;
	values->highest_n = queue->num;
	queue = queue->next;
	while (queue)
	{
		if (values->highest_n < queue->num)
			values->highest_n = queue->num;
		queue = queue->next;
	}
}

void	nbr_of_steps_bottom(t_values *values, t_deque_elm *queue)
{
	t_deque_elm	*backup;

	if (!queue)
		return ;
	backup = queue;
	while (queue)
	{
		values->lowest_bottom_steps++;
		if (values->lowest_n == queue->num)
			break ;
		queue = queue->prev;
	}
	while (backup)
	{
		values->highest_bottom_steps++;
		if (values->highest_n == backup->num)
			break ;
		backup = backup->prev;
	}
}

void	nbr_of_steps_top(t_values *values, t_deque_elm *queue)
{
	t_deque_elm	*backup;

	if (!queue)
		return ;
	backup = queue;
	while (queue)
	{
		values->lowest_top_steps++;
		if (values->lowest_n == queue->num)
			break ;
		queue = queue->next;
	}
	while (backup)
	{
		values->highest_top_steps++;
		if (values->highest_n == backup->num)
			break ;
		backup = backup->next;
	}
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
	else if (all_queues->push_swap_return_list->size
		&& ((all_queues->push_swap_return_list->tail->num == RRA
		&& command == RRB)
		|| (all_queues->push_swap_return_list->tail->num == RRB
		&& command == RRA)))
	{
		free(deque_pop_back(all_queues->push_swap_return_list));
		deque_push_back(all_queues->push_swap_return_list, init_deque_elm(RRR));
	}
	else
		deque_push_back(all_queues->push_swap_return_list, init_deque_elm(command));
	all_queues->command_list[command](all_queues);
}

void	rotate_n_steps(int steps, bool side,
		bool list, t_all_queues *all_queues)
{
	while (steps--)
	{
		if (list == A_LIST)
		{
			if (side == TOP)
				push_swap_record(RA, all_queues);
			else
				push_swap_record(RRA, all_queues);
		}
		if (list == B_LIST)
		{
			if (side == TOP)
				push_swap_record(RB, all_queues);
			else
				push_swap_record(RRB, all_queues);
		}
	}
}

void	step_comp(t_values *values)
{
	if (values->lowest_top_steps < values->lowest_bottom_steps)
		values->lowest_side = TOP;
	else
		values->lowest_side = BOTTOM;
	if (values->highest_top_steps < values->highest_bottom_steps)
		values->highest_side = TOP;
	else
		values->highest_side = BOTTOM;
}

void	value_comp(t_values *values)
{
	int		highest;
	int		lowest;
	bool	high_side;
	bool	low_side;

	if (values->lowest_side == TOP)
	{
		lowest = values->lowest_top_steps;
		low_side = TOP;
	}
	else
	{
		lowest = values->lowest_bottom_steps;
		low_side = BOTTOM;
	}
	if (values->highest_side == TOP)
	{
		highest = values->highest_top_steps;
		high_side = TOP;
	}
	else
	{
		highest = values->highest_bottom_steps;
		high_side = BOTTOM;
	}
	if (highest < lowest)
	{
		values->final_steps = highest;
		values->final_side = high_side;
	}
	else
	{
		values->final_steps = lowest;
		values->final_side = low_side;
	}
}
	
//void	push_swap(t_all_queues *all_queues)
//{
//	t_values	values;
//
//	while (all_queues->a_queue->size)
//	{
//		ft_bzero(&values, sizeof(t_values));
//		check_lowest(&values, all_queues->a_queue->head);
//		check_highest(&values, all_queues->a_queue->head);
//		nbr_of_steps_bottom(&values, all_queues->a_queue->tail);
//		nbr_of_steps_top(&values, all_queues->a_queue->head);
//		step_comp(&values);
//		value_comp(&values);
//		rotate_n_steps(values.final_steps, values.final_side, all_queues);
//		push_swap_record(PB, all_queues);
//		if (all_queues->b_queue->head->num == values.highest_n
//			&& all_queues->b_queue->size > 1)
//			push_swap_record(RB, all_queues);
//	}
//	while (all_queues->b_queue->size)
//		push_swap_record(PA, all_queues);
//	ft_bzero(&values, sizeof(t_values));
//	check_lowest(&values, all_queues->a_queue->head);
//	nbr_of_steps_bottom(&values, all_queues->a_queue->tail);
//	nbr_of_steps_top(&values, all_queues->a_queue->head);
//	if (values.lowest_top_steps < values.lowest_bottom_steps)
//		rotate_n_steps(values.lowest_top_steps, TOP, all_queues);
//	else
//		rotate_n_steps(values.lowest_bottom_steps, BOTTOM, all_queues);
//}

void	push_close_enough(t_values *values, t_all_queues *all_queues)
{
	if (all_queues->a_queue->head->num
		<= values->lowest_n + 30)//(values->avg_dist))
		push_swap_record(PB, all_queues);
	else if(all_queues->a_queue->head->num
		>= values->highest_n - 25)//(values->avg_dist))
	{
		push_swap_record(PB, all_queues);
		push_swap_record(RB, all_queues);
	}
	else
		push_swap_record(RA, all_queues);
}

void	push_swap_3(t_values *values, t_all_queues *all_queues)
{
	if (all_queues->a_queue->head->num == values->lowest_n &&
		all_queues->a_queue->tail->num == values->highest_n)
		return ;
	else if (all_queues->a_queue->head->num != values->lowest_n &&
		all_queues->a_queue->tail->num == values->highest_n)
	{
		push_swap_record(SA, all_queues);
		return ;
	}
	else if ((all_queues->a_queue->tail->num == values->lowest_n
		&& all_queues->a_queue->head->num == values->highest_n)
		|| all_queues->a_queue->head->num == values->lowest_n)
	{
		push_swap_record(SA, all_queues);
		if (all_queues->a_queue->tail->num == values->lowest_n)
			push_swap_record(RRA, all_queues);
		else
			push_swap_record(RA, all_queues);
		return ;
	}
	else if (all_queues->a_queue->tail->num == values->lowest_n)
	{
		push_swap_record(RRA, all_queues);
		return ;
	}
	else if (all_queues->a_queue->head->num == values->highest_n)
		push_swap_record(RA, all_queues);
}

void	push_swap_5(t_values *values, t_all_queues *all_queues)
{
	ft_bzero(values, sizeof(t_values));
	check_lowest(values, all_queues->a_queue->head);
	nbr_of_steps_bottom(values, all_queues->a_queue->tail);
	nbr_of_steps_top(values, all_queues->a_queue->head);
	if (values->lowest_top_steps < values->lowest_bottom_steps)
		rotate_n_steps(values->lowest_top_steps, TOP, A_LIST, all_queues);
	else
		rotate_n_steps(values->lowest_bottom_steps, BOTTOM, A_LIST, all_queues);
	push_swap_record(PB, all_queues);
	ft_bzero(values, sizeof(t_values));
	check_lowest(values, all_queues->a_queue->head);
	nbr_of_steps_bottom(values, all_queues->a_queue->tail);
	nbr_of_steps_top(values, all_queues->a_queue->head);
	if (values->lowest_top_steps < values->lowest_bottom_steps)
		rotate_n_steps(values->lowest_top_steps, TOP, A_LIST, all_queues);
	else
		rotate_n_steps(values->lowest_bottom_steps, BOTTOM, A_LIST, all_queues);
	push_swap_record(PB, all_queues);
	ft_bzero(values, sizeof(t_values));
	check_lowest(values, all_queues->a_queue->head);
	check_highest(values, all_queues->a_queue->head);
	push_swap_3(values, all_queues);
	push_swap_record(PA, all_queues);
	push_swap_record(PA, all_queues);
}

void	push_swap(t_all_queues *all_queues)
{
	t_values	values;

	ft_bzero(&values, sizeof(t_values));
	check_lowest(&values, all_queues->a_queue->head);
	check_highest(&values, all_queues->a_queue->head);
	if (all_queues->a_queue->size == 3)
	{
		push_swap_3(&values, all_queues);
		return ;
	}
	if (all_queues->a_queue->size == 5)
	{
		push_swap_5(&values, all_queues);
		return ;
	}
	//values.avg_dist = (values.highest_n - values.lowest_n + 1) / 10;
		/// all_queues->a_queue->size;
	while (all_queues->a_queue->size)
	{
		ft_bzero(&values, sizeof(t_values));
		check_lowest(&values, all_queues->a_queue->head);
		check_highest(&values, all_queues->a_queue->head);
		nbr_of_steps_bottom(&values, all_queues->a_queue->tail);
		nbr_of_steps_top(&values, all_queues->a_queue->head);
		push_close_enough(&values, all_queues);
	} // Crazy idea: Instead of the following B loop, leave the mid element in list A
	  // and push every element closest to it back. <5500?
	while (all_queues->b_queue->size)
	{
		ft_bzero(&values, sizeof(t_values));
//		check_lowest(&values, all_queues->b_queue->head);
		check_highest(&values, all_queues->b_queue->head);
		nbr_of_steps_bottom(&values, all_queues->b_queue->tail);
		nbr_of_steps_top(&values, all_queues->b_queue->head);
		step_comp(&values);
		value_comp(&values);
		rotate_n_steps(values.final_steps, values.final_side,
			B_LIST, all_queues);
		push_swap_record(PA, all_queues);
		if (all_queues->a_queue->head->num == values.lowest_n
			&& all_queues->a_queue->size > 1)
			push_swap_record(RA, all_queues);
	}
	ft_bzero(&values, sizeof(t_values));
	check_lowest(&values, all_queues->a_queue->head);
	nbr_of_steps_bottom(&values, all_queues->a_queue->tail);
	nbr_of_steps_top(&values, all_queues->a_queue->head);
	if (values.lowest_top_steps < values.lowest_bottom_steps)
		rotate_n_steps(values.lowest_top_steps, TOP, A_LIST, all_queues);
	else
		rotate_n_steps(values.lowest_bottom_steps, BOTTOM, A_LIST, all_queues);
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
	if (!is_sorted(all_queues))
		push_swap(all_queues);
	print_commands(all_queues);
	free_all_queues(all_queues);
}
