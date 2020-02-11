/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:03:55 by amartino          #+#    #+#             */
/*   Updated: 2020/02/11 12:33:04 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	is_parent_valid(t_heap *heap, size_t child)
{
	size_t		parent;

	parent = get_parent(child);
	if ((heap->type == MIN_HEAP && heap->a[parent] > heap->a[child]) == TRUE
		|| (heap->type == MAX_HEAP && heap->a[parent] < heap->a[child]) == TRUE)
	{
		swap(heap, parent, child);
		is_parent_valid(heap, parent);
	}
}

void	heapify(t_heap *heap, size_t parent)
{
	size_t		l;
	size_t		r;
	size_t		extremum;

	l = get_left_child(parent);
	l = (int32_t)l > heap->a[HEAP_SIZE] ? parent : l;
	r = get_right_child(parent);
	r = (int32_t)r > heap->a[HEAP_SIZE] ? parent : r;
	if (heap->type == MIN_HEAP)
	{
		extremum = heap->a[parent] > heap->a[l] ? l : parent;
		extremum = heap->a[extremum] > heap->a[r] ? r : extremum;
	}
	else
	{
		extremum = heap->a[parent] < heap->a[l] ? l : parent;
		extremum = heap->a[extremum] < heap->a[r] ? r : extremum;
	}
	if (extremum != parent)
	{
		swap(heap, parent, extremum);
		heapify(heap, extremum);
	}
}
