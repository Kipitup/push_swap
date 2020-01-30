/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/01/30 19:49:29 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t 		split_stack_in_2_big_part(t_stack *s)
{
	size_t		sublist_size;
	size_t		nth;
	int8_t		ret;

	ret = SUCCESS;
	sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, (s->exponent_max - 1));
	nth = s->size_a - sublist_size;
	ret = pb_under_pivot(s, nth, s->size_a);
	return (ret);
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

int8_t		sort_remainder(t_stack *s)
{
	int8_t		ret;

	ret = SUCCESS;
	s->exponent_max = 0;
	while ((SUBLIST_MIN_SIZE * ft_pow_positive(2, s->exponent_max + 1)) <= s->size_b)
		s->exponent_max++;
	if (s->exponent_max > 0)
	{
		ret = let_the_magic_of_recursion_happen(s, (s->exponent_max - 1), (s->exponent_max - 1));
		if (s->exponent_max > 1 && ret == SUCCESS)
			ret = let_the_magic_of_recursion_happen(s, (s->exponent_max - 1), (s->exponent_max - 1));
	}
	return (ret);
}

int8_t		solve(t_stack *s)
{
	int8_t		ret;

	ret = SUCCESS;
	if (s->exponent_max > 0)
	{
		split_stack_in_2_big_part(s);
		ret = organize_a_in_unsorted_sublist(s, 0);
		if (ret == SUCCESS)
			ret = pb_under_pivot(s, (s->size_a / 2), s->size_a);
		sort_sublist_on_b(s, (SUBLIST_MIN_SIZE / 2));
		if (s->exponent_max > 1 && ret == SUCCESS)
			ret = let_the_magic_of_recursion_happen(s, 0, (s->exponent_max - 1));
		sort_remainder(s);
	}
	if (ret == SUCCESS)
		while (s->size_b > 0)
			pa_highest(s, s->size_b);
	return (ret);
}
