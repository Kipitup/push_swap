/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/01/31 12:44:25 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t		split_stack_in_2_big_part(t_stack *s)
{
	size_t		sublist_size;
	size_t		nth;

	if (s->size_b == 0)
	{
		sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, (s->exponent_max - 1));
		nth = s->size_a - sublist_size;
		if (pb_under_pivot(s, nth, s->size_a) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	}
	else
	{
		s->exponent_max = 0;
		while ((SUBLIST_MIN_SIZE * ft_pow_positive(2, s->exponent_max + 1)) <= s->size_b)
			s->exponent_max++;
		sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, (s->exponent_max - 1));
		nth = s->size_b - sublist_size;
		if (pa_above_pivot(s, nth, s->size_b) == FAILURE)
			return (FAILURE);
		return (sublist_size);
	}
}

int8_t		organize_a_in_unsorted_sublist(t_stack *s, size_t to_ignore)
{
	size_t		size;
	int8_t		ret;

	ret = SUCCESS;
	if (s->size_a > (SUBLIST_MIN_SIZE + to_ignore))
	{
		size = s->size_a - to_ignore;
		ret = pb_under_pivot(s, (size / 2), size);
		if (ret == SUCCESS)
			ret = organize_a_in_unsorted_sublist(s, to_ignore);
	}
	return (ret);
}

int8_t		let_the_magic_of_recursion_happen(t_stack *s, size_t exponent, size_t exponent_max)
{
	size_t		sublist_size;
	int8_t		ret;

	ret = SUCCESS;
	sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, exponent);
	if (exponent == 0 && ret == SUCCESS)
		sort_sublist_on_b(s, SUBLIST_MIN_SIZE);
	else
	{
		ret = push_next_sublist_on_a(s, sublist_size);
		if (ret == SUCCESS)
			ret = organize_a_in_unsorted_sublist(s, (s->size_a - sublist_size));
		if (ret == SUCCESS)
			ret = pb_under_pivot(s, (SUBLIST_MIN_SIZE / 2), SUBLIST_MIN_SIZE);
		sort_sublist_on_b(s, (SUBLIST_MIN_SIZE / 2));
		if (ret == SUCCESS)
			ret = let_the_magic_of_recursion_happen(s, 0, (exponent - 1));
	}
	if (exponent < exponent_max && ret == SUCCESS)
		ret = let_the_magic_of_recursion_happen(s, (exponent + 1), exponent_max);
	return (ret);
}

int8_t		solve(t_stack *s)
{
	ssize_t		size;
	int8_t		ret;

	ret = SUCCESS;
	if (s->exponent_max > 0)
	{
		size = split_stack_in_2_big_part(s);
		ret = size == FAILURE ? FAILURE : SUCCESS;
		size = size > 0 ? s->size_a - size : size;
		if (ret == SUCCESS)
			ret = organize_a_in_unsorted_sublist(s, (size_t)size);
		if (ret == SUCCESS)
			ret = pb_under_pivot(s, (SUBLIST_MIN_SIZE / 2), SUBLIST_MIN_SIZE);
		sort_sublist_on_b(s, (SUBLIST_MIN_SIZE / 2));
		if (s->exponent_max > 1 && ret == SUCCESS)
		{
			ret = let_the_magic_of_recursion_happen(s, 0, (s->exponent_max - 2));
			if (ret == SUCCESS)
				ret = solve(s);
		}
	}
	if (ret == SUCCESS)
		while (s->size_b > 0)
			pa_highest(s, s->size_b);
	return (ret);
}
