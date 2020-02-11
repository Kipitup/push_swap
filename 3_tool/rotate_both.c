/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:35:35 by fkante            #+#    #+#             */
/*   Updated: 2020/01/31 17:03:09 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack *s)
{
	rotate_stack_a(s);
	rotate_stack_b(s);
}

void	reverse_both(t_stack *s)
{
	reverse_rotate_stack_a(s);
	reverse_rotate_stack_b(s);
}

void	rr(t_stack *s)
{
	rotate_both(s);
	vct_addstr(s->result, "rr\n");
}

void	rrr(t_stack *s)
{
	reverse_both(s);
	vct_addstr(s->result, "rrr\n");
}
