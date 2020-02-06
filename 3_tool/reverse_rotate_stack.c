/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:01:39 by fkante            #+#    #+#             */
/*   Updated: 2020/02/06 13:40:47 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reverse_rotate_stack_a(t_stack *s)
{
	int32_t	first_elem;
	size_t	i;

	i = 0;
	first_elem = s->a[0];
	if (i < s->size_a)
		shiftdown_stack_a(s);
	s->a[s->size_a - 1] = first_elem; //same shit
	s->color_nb = s->a[s->size_a - 1];
}

void		reverse_rotate_stack_b(t_stack *s)
{
	int32_t	first_elem;
	size_t	i;

	i = 0;
	first_elem = s->b[0];
	if (i < s->size_b)
		shiftdown_stack_b(s);
	// if (s->size_b > 0) //to check
		s->b[s->size_b - 1] = first_elem; //WARNING
	s->color_nb = s->b[s->size_b - 1];
}

void	rra(t_stack *s)
{
	reverse_rotate_stack_a(s);
	vct_addstr(s->result, "rra\n");
}

void	rrb(t_stack *s)
{
	reverse_rotate_stack_b(s);
	vct_addstr(s->result, "rrb\n");
}
