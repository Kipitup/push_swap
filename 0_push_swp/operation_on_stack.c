/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:34:04 by fkante            #+#    #+#             */
/*   Updated: 2020/01/31 12:33:59 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_highest(t_stack *s, size_t limit)
{
	size_t	index_highest;
	size_t	center;

	center = s->size_b / 2;
	index_highest = ft_get_high_in_range(s->b, s->size_b - limit, s->size_b);
	while (index_highest != s->size_b - 1)
	{
		if (index_highest > center)
		{
			rb(s);
			index_highest++;
		}
		else
		{
			rrb(s);
			if (index_highest == 0)
				index_highest = s->size_b - 1;
			else
				index_highest--;
		}
	}
	pa(s);
}

int8_t	pb_under_pivot(t_stack *s, size_t nth, size_t limit)
{
	size_t		last;
	ssize_t 	pivot_index;
	int32_t		pivot;
	uint8_t		start_or_end;

	pause_and_show(s);
	pivot_index = ft_get_n_smallest(s->a, nth, START, s->size_a);
	if (pivot_index == FAILURE)
		return (ft_print_err_failure(MALLOC_PIVOT, STD_ERR));
	pivot = s->a[pivot_index];
	start_or_end = ((size_t)pivot_index < limit && limit < s->size_a) ? START : END;
	while (limit > 0)
	{
		last = s->size_a - 1;
		if (start_or_end == END)
			s->a[last] <= pivot ? pb(s) : ra(s);
		else
		{
			rra(s);
			if (s->a[last] <= pivot)
				pb(s);

		}
		limit--;
	}
	return (SUCCESS);
}

int8_t	pa_above_pivot(t_stack *s, size_t nth, size_t limit)
{
	size_t		last;
	ssize_t 	pivot_index;
	int32_t		pivot;

	pause_and_show(s);
	pivot_index = ft_get_n_smallest(s->b, nth, START, s->size_b);
	if (pivot_index == FAILURE)
		return (ft_print_err_failure(MALLOC_PIVOT, STD_ERR));
	pivot = s->b[pivot_index];
	while (limit > 0)
	{
		last = s->size_b - 1;
		s->b[last] > pivot ? pa(s) : rb(s);
		limit--;
	}
	return (SUCCESS);
}
