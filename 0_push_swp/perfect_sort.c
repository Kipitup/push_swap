/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:27:04 by amartino          #+#    #+#             */
/*   Updated: 2020/02/11 12:02:29 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	1st case : 3 2 1
**	2nd case : 3 1 2
**	3rd case : 2 1 3
**	4th case : 2 3 1
**	5th case : 1 3 2
**	6th case : 1 2 3
*/

void	sort_for_top_bis(t_stack *s, size_t one, size_t two, size_t three)
{
	if (one > two && one < three)
		sa(s);
	else if (one < two && one > three)
	{
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
	else if (one < two && two < three)
		return ;
}

void	perfect_sort_for_3_on_top_of_a(t_stack *s)
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
	else if (one > two && one > three && two < three)
	{
		sa(s);
		ra(s);
		sa(s);
		rra(s);
	}
	else
		sort_for_top_bis(s, one, two, three);
}

/*
**	1st case : 3 2 1
**	2nd case : 3 1 2
**	3rd case : 2 1 3
**	4th case : 2 3 1
**	5th case : 1 3 2
**	6th case : 1 2 3
*/

void	sort_for_bottom_ter(t_stack *s, size_t one, size_t two, size_t three)
{
	if (one < two && one > three)
	{
		rra(s);
		pb(s);
		rra(s);
		rra(s);
		pa(s);
	}
	else if (one < two && one < three && two > three)
	{
		rra(s);
		rra(s);
		sa(s);
		rra(s);
	}
	else if (one < two && two < three)
	{
		rra(s);
		rra(s);
		rra(s);
	}
}

void	sort_for_bottom_bis(t_stack *s, size_t one, size_t two, size_t three)
{
	if (one > two && one > three && two < three)
	{
		rra(s);
		rra(s);
		pb(s);
		rra(s);
		sa(s);
		pa(s);
	}
	else if (one > two && one < three)
	{
		rra(s);
		rra(s);
		rra(s);
		sa(s);
	}
	else
		sort_for_bottom_ter(s, one, two, three);
}

void	perfect_sort_for_3_at_the_bottom_of_a(t_stack *s)
{
	size_t	one;
	size_t	two;
	size_t	three;

	one = s->a[2];
	two = s->a[1];
	three = s->a[0];
	if (one > two && two > three)
	{
		rra(s);
		pb(s);
		rra(s);
		rra(s);
		sa(s);
		pa(s);
	}
	else
		sort_for_bottom_bis(s, one, two, three);
}
