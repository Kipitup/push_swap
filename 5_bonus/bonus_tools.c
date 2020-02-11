/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:38:35 by amartino          #+#    #+#             */
/*   Updated: 2020/02/11 12:07:15 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pause_and_show(t_stack *s)
{
	char	*line;

	line = NULL;
	if (PAUSE_AND_SHOW == OFF)
		return ;
	print_stack(s, NO_OPE, 0);
	get_next_line(0, &line);
	ft_strdel(&line);
}

t_stat	*get_stat(t_stack *s)
{
	t_stat		*stat;

	stat = ft_memalloc(sizeof(t_stat));
	if (stat != NULL)
	{
		stat->min_a = ft_low(s->a, s->size_a);
		stat->max_a = ft_high(s->a, s->size_a);
		ft_median(s->a, s->size_a, &stat->median_a);
		stat->min_b = ft_low(s->b, s->size_b);
		stat->max_b = ft_high(s->b, s->size_b);
		ft_median(s->b, s->size_b, &stat->median_b);
	}
	return (stat);
}

void	handle_a(t_stack *s, size_t size, int8_t ope, t_stat *stat)
{
	if ((check_ope(s, size, ope, STACK_A) == TRUE))
		return ;
	else if (s->a[size] == stat->min_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_yellow}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == stat->max_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_red}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == stat->median_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_blue}%d{c_end}\t\t| |\t", s->a[size]);
	else
		ft_printf("\t|\t\t%d\t\t| |\t", s->a[size]);
}

void	handle_b(t_stack *s, size_t size, int8_t ope, t_stat *stat)
{
	if ((check_ope(s, size, ope, STACK_B) == TRUE))
		return ;
	else if (s->b[size] == stat->min_b && s->size_b > 4)
		ft_printf("\t{c_yellow}%d{c_end}\t\t|\n", s->b[size]);
	else if (s->b[size] == stat->max_b && s->size_b > 4)
		ft_printf("\t{c_red}%d{c_end}\t\t|\n", s->b[size]);
	else if (s->b[size] == stat->median_b && s->size_b > 4)
		ft_printf("\t{c_blue}%d{c_end}\t\t|\n", s->b[size]);
	else
		ft_printf("\t%d\t\t|\n", s->b[size]);
}
