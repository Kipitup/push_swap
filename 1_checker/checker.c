/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:39:19 by amartino          #+#    #+#             */
/*   Updated: 2020/01/20 16:59:19 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_checker(t_stack *s)
{
	operfunc	func_ptr[NB_OPE] = {swap_stack_a, swap_stack_b, swap_both,
							push_stack_a, push_stack_b, rotate_stack_a,
							rotate_stack_b, rotate_both, reverse_rotate_stack_a,
							reverse_rotate_stack_b, reverse_both};
	char		*line;
	size_t		count;

	count = 0;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		operation_checker(func_ptr, line, s, &count);
		ft_strdel(&line);
	}
}

void	operation_checker(operfunc *f_ptr, char *line, t_stack *s, size_t *count)
{
	char		*oper[NB_OPE] = {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};
	uint8_t 	i;

	i = 0;
	while (i < NB_OPE)
	{
		if (ft_strequ(line, oper[i]) == TRUE)
		{
			f_ptr[i](s);
			(*count)++;
			break ;
		}
		i++;
	}
	if (s->verbose == TRUE)
		print_stack(s, i, *count);
	if (i == NB_OPE)
		ft_print_err_void("Wrong input", STD_ERR);
}
