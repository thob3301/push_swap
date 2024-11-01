/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:10:45 by miteixei          #+#    #+#             */
/*   Updated: 2024/11/01 20:31:44 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	value_comp2(t_values *values,
		int *highest_lowest, bool *high_low_side)
{
	if (values->highest_side == TOP)
	{
		highest_lowest[0] = values->highest_top_steps;
		high_low_side[0] = TOP;
	}
	else
	{
		highest_lowest[0] = values->highest_bottom_steps;
		high_low_side[0] = BOTTOM;
	}
	if (highest_lowest[0] < highest_lowest[1])
	{
		values->final_steps = highest_lowest[0];
		values->final_side = high_low_side[0];
	}
	else
	{
		values->final_steps = highest_lowest[1];
		values->final_side = high_low_side[1];
	}
}

void	value_comp(t_values *values)
{
	int		highest_lowest[2];
	bool	high_low_side[2];

	if (values->lowest_side == TOP)
	{
		highest_lowest[1] = values->lowest_top_steps;
		high_low_side[1] = TOP;
	}
	else
	{
		highest_lowest[1] = values->lowest_bottom_steps;
		high_low_side[1] = BOTTOM;
	}
	value_comp2(values, highest_lowest, high_low_side);
}
