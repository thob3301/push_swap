/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:33:45 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/20 20:04:30 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef enum e_commands
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	INVALID
}	t_commands;

typedef struct s_deque_elm
{
	int					num;
	struct s_deque_elm	*prev;
	struct s_deque_elm	*next;
}		t_deque_elm;

typedef struct s_deque
{
	int			size;
	t_deque_elm	*head;
	t_deque_elm	*tail;
}		t_deque;

typedef struct s_all_queues
{
	struct s_deque	*a_queue;
	struct s_deque	*b_queue;
	void			(**command_list)(struct s_all_queues*);
	const char		**command_text;
	struct s_deque	*push_swap_return_list;
}		t_all_queues;

void			sa(t_all_queues *queues);
void			sb(t_all_queues *queues);
void			ss(t_all_queues *queues);
void			pa(t_all_queues *queues);
void			pb(t_all_queues *queues);
void			ra(t_all_queues *queues);
void			rb(t_all_queues *queues);
void			rr(t_all_queues *queues);
void			rra(t_all_queues *queues);
void			rrb(t_all_queues *queues);
void			rrr(t_all_queues *queues);

t_deque_elm		*init_deque_elm(int num);
t_deque_elm		*deque_pop_front(t_deque *queue);
t_deque_elm		*deque_pop_back(t_deque *queue);
void			deque_push_front(t_deque *queue, t_deque_elm *element);
void			deque_push_back(t_deque *queue, t_deque_elm *element);

void			free_all_queues(t_all_queues *all_queues);

t_all_queues	*init_structs(void);
t_deque_elm		*init_deque_elm(int num);

void			sorted_y_n(bool answer);
void			destroy_y_n(t_all_queues *all_queues, bool answer);
bool			check_duplicates(t_deque *a_queue);

// handling.c
void			split_args_push_queue(char *arg, t_all_queues *all_queues);

#endif
