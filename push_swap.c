/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:49:38 by miteixei          #+#    #+#             */
/*   Updated: 2024/11/01 20:13:07 by miteixei         ###   ########.fr       */
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

void	push_close_enough(t_values *values, t_all_queues *all_queues)
{
	if (all_queues->a_queue->head->num
		<= values->lowest_n + 25)
		push_swap_record(PB, all_queues);
	else if (all_queues->a_queue->head->num
		>= values->highest_n - 25)
	{
		push_swap_record(PB, all_queues);
		push_swap_record(RB, all_queues);
	}
	else
		push_swap_record(RA, all_queues);
}

void	push_b(t_values *values, t_all_queues *all_queues)
{
	ft_bzero(values, sizeof(t_values));
	check_lowest(values, all_queues->a_queue->head);
	check_highest(values, all_queues->a_queue->head);
	nbr_of_steps_bottom(values, all_queues->a_queue->tail);
	nbr_of_steps_top(values, all_queues->a_queue->head);
	push_close_enough(values, all_queues);
}

void	push_a(t_values *values, t_all_queues *all_queues)
{
	ft_bzero(values, sizeof(t_values));
	check_mid_low(values, all_queues);
	check_mid_high(values, all_queues);
	nbr_of_steps_bottom(values, all_queues->b_queue->tail);
	nbr_of_steps_top(values, all_queues->b_queue->head);
	step_comp(values);
	value_comp(values);
	rotate_n_steps(values->final_steps, values->final_side,
		B_LIST, all_queues);
	push_swap_record(PA, all_queues);
	if (all_queues->a_queue->head->num == values->highest_n
		&& all_queues->a_queue->size > 1)
		push_swap_record(RA, all_queues);
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
	while (all_queues->a_queue->size > 1)
		push_b(&values, all_queues);
	while (all_queues->b_queue->size)
		push_a(&values, all_queues);
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
