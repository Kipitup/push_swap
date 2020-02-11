/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:24:51 by amartino          #+#    #+#             */
/*   Updated: 2020/02/11 11:40:06 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_with_color(t_stack *s, int8_t ope)
{
	t_stat		*stat;
	size_t		size_a;
	size_t		size_b;

	size_a = s->size_a;
	size_b = s->size_b;
	stat = get_stat(s);
	if (stat != NULL)
	{
		while (size_a > 0 || size_b > 0)
		{
			if (size_a > 0)
				handle_a(s, --size_a, ope, stat);
			else
				ft_printf("\t|\t\t\t\t| |\t");
			if (size_b > 0)
				handle_b(s, --size_b, ope, stat);
			else
				ft_printf("\t\t\t|\n");
		}
	}
	ft_memdel((void**)&stat);
}
