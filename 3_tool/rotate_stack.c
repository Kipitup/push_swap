/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:21:06 by fkante            #+#    #+#             */
/*   Updated: 2020/01/31 17:03:23 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a(t_stack *s)
{
	int32_t	first_elem;
	size_t	i;

	i = s->size_a;
	first_elem = s->a[s->size_a - 1];
	if (i > 0)
		shiftup_stack_a(s);
	s->a[0] = first_elem;
	s->color_nb = s->a[0];
}

void	rotate_stack_b(t_stack *s)
{
	int32_t	first_elem;
	size_t	i;

	i = s->size_b;
	first_elem = s->b[s->size_b - 1];
	if (i > 0)
		shiftup_stack_b(s);
	s->b[0] = first_elem;
	s->color_nb = s->b[0];
}

void	ra(t_stack *s)
{
	rotate_stack_a(s);
	vct_addstr(s->result, "ra\n");
}

void	rb(t_stack *s)
{
	rotate_stack_b(s);
	vct_addstr(s->result, "rb\n");
}
