/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:30:18 by amartino          #+#    #+#             */
/*   Updated: 2020/02/11 17:35:13 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t		is_it_sorted(t_stack *s)
{
	int32_t 	*sorted_stack;
	size_t		i;
	size_t		j;

	j = 0;
	i = s->size_a - 1;
	sorted_stack = ft_sort(s->a, s->size_a);
	if (sorted_stack != NULL)
	{
		while (i > 0 && j < s->size_a)
		{
			if (s->a[i] != sorted_stack[j])
			{
				ft_memdel((void**)&sorted_stack);
				return (FALSE);
			}
			i--;
			j++;
		}
		ft_memdel((void**)&sorted_stack);
		return (TRUE);
	}
	return (FAILURE);
}
