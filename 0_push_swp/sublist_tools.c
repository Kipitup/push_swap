/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sublist_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:13:54 by amartino          #+#    #+#             */
/*   Updated: 2020/02/03 21:57:07 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_sublist_on_b(t_stack *s, size_t size)
{
	if (size == (SUBLIST_MIN_SIZE / 2))
	{
		if (ft_high(s->a, s->size_a) == s->a[0] && s->size_a > SUBLIST_MIN_SIZE)
			perfect_sort_for_3_on_top_of_a(s);
		else
			perfect_sort_for_3_at_the_bottom_of_a(s);
		// pause_and_show(s);
	}
	while (size > 0)
	{
		pa_highest(s, s->size_b);
		size--;
	}
	// pause_and_show(s);
}

int8_t		push_next_sublist_on_a(t_stack *s, size_t size)
{
	size_t		max_size;
	size_t		nth;
	ssize_t	 	pivot_index;


	max_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, (s->exponent_max - 1));
	if (max_size == size)
	{
		nth = s->size_b - size;
		pivot_index = ft_get_n_smallest(s->b, nth, START, s->size_b);
		if (pivot_index == FAILURE)
			return (ft_print_err_failure(MALLOC_PIVOT, STD_ERR));
		pa_above_pivot(s, (size_t)pivot_index, s->size_b);
	}
	else
	{
		while (size > 0)
		{
			pa(s);
			// ft_printf("pa");
			pause_and_show(s);
			size--;
		}
	}
	pause_and_show(s);
	return (SUCCESS);
}

int8_t		solve_when_too_small(t_stack *s)
{
	if (s->size_a == 1)
		return (SUCCESS);
	else if (s->size_a == 2)
	{
		if (s->a[0] < s->a[1])
			sa(s);
	}
	else if (s->size_a == 3)
		perfect_sort_for_size_a_3(s);
	else
	{
		if (pb_under_pivot(s, (s->size_a - 3), s->size_a) == FAILURE)
			return (FAILURE);
		perfect_sort_for_size_a_3(s);
		while (s->size_b > 0)
			pa_highest(s, s->size_b);
	}
	return (SUCCESS);
}
