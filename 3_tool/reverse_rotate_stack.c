/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:01:39 by fkante            #+#    #+#             */
/*   Updated: 2020/01/15 20:04:58 by fkante           ###   ########.fr       */
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
	s->a[s->size_a - 1] = first_elem;
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
	s->b[s->size_b - 1] = first_elem;
	s->color_nb = s->b[s->size_b - 1];
}

void	rra(t_stack *s)
{
	reverse_rotate_stack_a(s);
	ft_putendl_fd("rra", s->fd);
}

void	rrb(t_stack *s)
{
	reverse_rotate_stack_b(s);
	ft_putendl_fd("rrb", s->fd);
}
