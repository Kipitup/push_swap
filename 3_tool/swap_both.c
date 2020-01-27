/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:28:01 by fkante            #+#    #+#             */
/*   Updated: 2020/01/15 19:29:46 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack *s)
{
	swap_stack_a(s);
	swap_stack_b(s);
}

void	ss(t_stack *s)
{
	swap_both(s);
	ft_putendl_fd("ss", s->fd);
}
