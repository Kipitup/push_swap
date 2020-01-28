/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sublist_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:13:54 by amartino          #+#    #+#             */
/*   Updated: 2020/01/28 19:26:40 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_sublist_on_b(t_stack *s)
{
	size_t		size;

	size = SUBLIST_MIN_SIZE;
	while (size > 0)
	{
		pa_highest(s, s->size_b);
		size--;
	}
	ft_printf("sort_sublist_on_b\n");
	pause_and_show(s);
}

void		sort_sublist_on_a(t_stack *s, uint8_t start_or_end)
{
	size_t		size;

	if (start_or_end == END)
	{
		size = SUBLIST_MIN_SIZE;
		while (size > 0)
		{
			rra(s);
			size--;
		}

	}
	perfect_sort_for_3(s);
	ft_printf("sort_sublist_on_a\n");
	pause_and_show(s);
}

void		push_next_sublist_on_a(t_stack *s, size_t size)
{
	while (size > 0)
	{
		pa(s);
		size--;
	}
	ft_printf("push_next_sublist_on_a\n");
	pause_and_show(s);
}

void		rra_the_remainder(t_stack *s)
{
	size_t		remainder_size;
	size_t		largest_sublist;

	largest_sublist = SUBLIST_MIN_SIZE * ft_pow_positive(2, s->exponent_max);
	remainder_size = s->size_a + s->size_b - largest_sublist;
	while (remainder_size > 0)
	{
		rra(s);
		remainder_size--;
	}
}
