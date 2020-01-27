/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:36:48 by fkante            #+#    #+#             */
/*   Updated: 2020/01/16 18:36:40 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nb(int32_t *stack1, int32_t *stack2)
{
	int32_t tmp;

	tmp = *stack1;
	*stack1 = *stack2;
	*stack2 = tmp;
}

void	shiftup_stack_a(t_stack *s)
{
	size_t	i;

	i = s->size_a;
	while (i > 0)
	{
		swap_nb(&s->a[i], &s->a[i - 1]);
		i--;
	}
}

void	shiftup_stack_b(t_stack *s)
{
	size_t	i;

	i = s->size_b;
	while (i > 0)
	{
		swap_nb(&s->b[i], &s->b[i - 1]);
		i--;
	}
}

void	shiftdown_stack_a(t_stack *s)
{
	size_t	i;

	i = 0;
	while (i < s->size_a)
	{
		swap_nb(&s->a[i], &s->a[i + 1]);
		i++;
	}
}

void	shiftdown_stack_b(t_stack *s)
{
	size_t	i;

	i = 0;
	while (i < s->size_b)
	{
		swap_nb(&s->b[i], &s->b[i + 1]);
		i++;
	}
}
