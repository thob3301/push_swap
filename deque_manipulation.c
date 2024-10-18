/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:50:53 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/18 17:29:20 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque_elm	*deque_pop_front(t_deque *queue)
{
	t_deque_elm	*element;

	if (!queue->head)
		return (NULL);
	element = queue->head;
	if (queue->head->next)
	{
		queue->head->next->prev = NULL;
		queue->head = queue->head->next;
	}
	if (queue->tail == element)
		queue->tail = NULL;
	element->next = NULL;
	queue->size--;
	return (element);
}

t_deque_elm	*deque_pop_back(t_deque *queue)
{
	t_deque_elm	*element;

	if (!queue->tail)
		return (NULL);
	element = queue->tail;
	if (queue->tail->prev)
	{
		queue->tail->prev->next = NULL;
		queue->tail = queue->tail->prev;
	}
	if (queue->head == element)
		queue->head = NULL;
	element->prev = NULL;
	queue->size--;
	return (element);
}

void	deque_push_front(t_deque *queue, t_deque_elm *element)
{
	if (!queue || !element)
		return ;
	element->next = queue->head;
	if (queue->head)
		queue->head->prev = element;
	else
		queue->tail = element;
	queue->head = element;
	queue->size++;
}

void	deque_push_back(t_deque *queue, t_deque_elm *element)
{
	if (!queue || !element)
		return ;
	element->prev = queue->tail;
	if (queue->tail)
		queue->tail->next = element;
	else
		queue->head = element;
	queue->tail = element;
	queue->size++;
}