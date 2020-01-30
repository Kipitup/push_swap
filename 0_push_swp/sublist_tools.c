/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sublist_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:13:54 by amartino          #+#    #+#             */
/*   Updated: 2020/01/30 19:43:37 by amartino         ###   ########.fr       */
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
		pause_and_show(s);
	}
	while (size > 0)
	{
		pa_highest(s, s->size_b);
		size--;
	}
	pause_and_show(s);
}

int8_t		push_next_sublist_on_a(t_stack *s, size_t size)
{
	size_t		max_size;
	size_t		position;
	ssize_t	 	pivot_index;


	max_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, (s->exponent_max - 1));
	if (max_size == size)
	{
		position = s->size_b - size;
		pivot_index = ft_get_n_smallest(s->b, position, START, s->size_b);
		if (pivot_index == FAILURE)
			return (ft_print_err_failure(MALLOC_PIVOT, STD_ERR));
		pa_above_pivot(s, (size_t)pivot_index, s->size_b);
	}
	else
	{
		while (size > 0)
		{
			pa(s);
			size--;
		}
	}
	pause_and_show(s);
	return (SUCCESS);
}
