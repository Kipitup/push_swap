/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:27:04 by amartino          #+#    #+#             */
/*   Updated: 2020/01/29 12:24:35 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perfect_sort_for_3_bis(t_stack *s, size_t one, size_t two, size_t three)
{
	if (one < two && one > three)
	{
		ra(s);
		sa(s);
		rra(s);
		sa(s);
	}
	else if (one > two && one > three && two < three)
	{
		sa(s);
		ra(s);
		sa(s);
		rra(s);
	}
	else if (one < two && two < three)
		return ;
	else
		ft_printf("not yet\n");
}

void	perfect_sort_for_3(t_stack *s)
{
	size_t	one;
	size_t	two;
	size_t	three;

	one = s->a[s->size_a - 1];
	two = s->a[s->size_a - 2];
	three = s->a[s->size_a - 3];
	if (one > two && two > three)
	{
		sa(s);
		ra(s);
		sa(s);
		rra(s);
		sa(s);
	}
	else if (one < two && one < three && two > three)
	{
		ra(s);
		sa(s);
		rra(s);
	}
	else if (one > two && one < three)
		sa(s);
	else
		perfect_sort_for_3_bis(s, one, two, three);
}
