/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_sort_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:03:04 by amartino          #+#    #+#             */
/*   Updated: 2020/02/11 12:03:16 by amartino         ###   ########.fr       */
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

void	perfect_sort_for_size_a_3(t_stack *s)
{
	size_t	one;
	size_t	two;
	size_t	three;

	one = s->a[2];
	two = s->a[1];
	three = s->a[0];
	if (one > two && two > three)
	{
		ra(s);
		sa(s);
	}
	else if (one > two && one > three && two < three)
		ra(s);
	else if (one > two && one < three)
		sa(s);
	else if (one < two && one > three)
		rra(s);
	else if (one < two && one < three && two > three)
	{
		sa(s);
		ra(s);
	}
	else if (one < two && two < three)
		return ;
}
