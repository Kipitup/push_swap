/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/01/29 20:31:19 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 		split_stack_in_2_big_part(t_stack *s)
{
	size_t		sublist_size;
	size_t		pivot_index;
	int32_t		pivot;

	sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, (s->exponent_max - 1));
	pivot_index = s->size_a - sublist_size - 1;
	pivot = s->sorted_s[pivot_index];
	pivot_index = 0;
	while (pivot_index < s->size_a)
	{
		if (s->a[pivot_index] == pivot)
			break ;
		pivot_index++;
	}
	pb_under_pivot(s, (size_t)pivot_index, s->size_a);
}

int8_t		organize_a_in_unsorted_sublist(t_stack *s, size_t to_ignore)
{
	size_t		size;
	int32_t 	pivot_index;
	int8_t		ret;

	ret = SUCCESS;
	pause_and_show(s);
	if (s->size_a > (SUBLIST_MIN_SIZE + to_ignore))
	{
		size = s->size_a - to_ignore;
		pivot_index = ft_get_n_smallest(s->a, (size / 2), START, s->size_a);
		if (pivot_index == FAILURE)
			return (ft_print_err_failure(MALLOC_PIVOT, STD_ERR));
		pb_under_pivot(s, (size_t)pivot_index, size);
		ret = organize_a_in_unsorted_sublist(s, to_ignore); //need to rra before sorting again
	}
	pb(s);
	pb(s);
	pb(s);
	pb(s);
	pb(s);
	pb(s);
	return (ret);
}

int8_t		let_the_magic_of_recursion_happen(t_stack *s, size_t exponent, size_t exponent_max)
{
	size_t		sublist_size;
	int8_t		ret;

	ret = SUCCESS;
	sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, exponent);
	if (exponent == 0 && ret == SUCCESS)
	{
		sort_sublist_on_b(s);
	}
	else if (ret == SUCCESS)
	{
		ret = push_next_sublist_on_a(s, sublist_size);
		ret = organize_a_in_unsorted_sublist(s, (s->size_a - sublist_size));
		if (ret == FAILURE)
			return (FAILURE);
		sort_sublist_on_b(s);
		ret = let_the_magic_of_recursion_happen(s, 0, (exponent - 1));
	}
	if (exponent < exponent_max && ret == SUCCESS)
		ret = let_the_magic_of_recursion_happen(s, (exponent + 1), exponent_max);
	return (ret);
}

int8_t		solve(t_stack *s)
{
	int8_t		ret;

	ret = SUCCESS;
	if (s->exponent_max > 0)
	{
		split_stack_in_2_big_part(s);
		pause_and_show(s);
		ret = organize_a_in_unsorted_sublist(s, 0);
		pause_and_show(s);
		sort_sublist_on_b(s);
		pause_and_show(s);
		if (s->exponent_max > 1 && ret == SUCCESS)
			ret = let_the_magic_of_recursion_happen(s, 0, (s->exponent_max - 1));
	}
	if (ret == SUCCESS)
		while (s->size_b > 0)
			pa_highest(s, s->size_b);
	return (ret);
}


// s->exponent_max = 0;
// while ((SUBLIST_MIN_SIZE * ft_pow_positive(2, s->exponent_max + 1)) <= s->size_b)
// 	s->exponent_max++;
// if (s->exponent_max > 0 && ret == SUCCESS)
// {
// 	ret = let_the_magic_of_recursion_happen(s, (s->exponent_max - 1), (s->exponent_max - 1));
// 	// if (s->exponent_max > 1 && ret == SUCCESS)
// 	ret = let_the_magic_of_recursion_happen(s, (s->exponent_max - 1), (s->exponent_max - 1));
// }
