/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:34:04 by fkante            #+#    #+#             */
/*   Updated: 2020/01/23 21:10:29 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_lowest(t_stack *s, size_t limit)
{
	size_t	min_index;
	size_t	center;

	center = s->size_a / 2;
	min_index = ft_get_low_in_range(s->a, s->size_a - limit, s->size_a);
	while (min_index != s->size_a - 1)
	{
		if (min_index > center)
		{
			ra(s);
			min_index++;
		}
		else
		{
			rra(s);
			if (min_index == 0)
				min_index = s->size_a - 1;
			else
				min_index--;
		}
	}
	pb(s);
}

void	pa_highest(t_stack *s, size_t limit)
{
	size_t	max_index;
	size_t	center;

	center = s->size_b / 2;
	max_index = ft_get_high_in_range(s->b, s->size_b - limit, s->size_b);
	while (max_index != s->size_b - 1)
	{
		if (max_index > center)
		{
			rb(s);
			max_index++;
		}
		else
		{
			rrb(s);
			if (max_index == 0)
				max_index = s->size_b - 1;
			else
				max_index--;
		}
	}
	pa(s);
}

void	pb_under_pivot(t_stack *s, int32_t pivot, size_t limit)
{
	size_t	i;
	size_t	last;

	i = limit;
	while (i > 0)
	{
		last = s->size_a - 1;
		s->a[last] <= pivot ? pb(s) : ra(s);
		i--;
	}
}

void	pa_above_pivot(t_stack *s, int32_t pivot, size_t limit)
{
	size_t	i;
	size_t	last;

	i = limit;
	while (i > 0)
	{
		last = s->size_b - 1;
		s->b[last] >= pivot ? pa(s) : rb(s);
		i--;
	}
}
