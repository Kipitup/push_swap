/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:39:19 by amartino          #+#    #+#             */
/*   Updated: 2020/02/12 11:19:38 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t	read_checker(t_stack *s)
{
	static t_operfunc	func_ptr[NB_OPE] = {swap_stack_a, swap_stack_b,
										swap_both, push_stack_a, push_stack_b,
										rotate_stack_a, rotate_stack_b,
										rotate_both, reverse_rotate_stack_a,
										reverse_rotate_stack_b, reverse_both};
	t_vector			*line;
	size_t				count;
	int8_t				ret;

	count = 0;
	line = NULL;
	while ((ret = vct_read_line_for_push_swap(STD_IN, &line)) > 0)
	{
		ret = operation_checker(func_ptr, line, s, &count);
		vct_del(&line);
		if (ret == FAILURE)
		{
			vct_read_line_for_push_swap(CLEANUP, &line);
			return (FAILURE);
		}
	}
	if (ret == FAILURE)
		ft_print_err_failure(INPUT_TOO_LONG, STD_ERR);
	vct_read_line_for_push_swap(CLEANUP, &line);
	return (ret);
}

int8_t	operation_checker(t_operfunc *f_ptr, t_vector *line, t_stack *s,
							size_t *count)
{
	static char	*ope[NB_OPE] = {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};
	uint8_t		i;

	i = 0;
	while (i < NB_OPE)
	{
		if (ft_strequ(vct_getstr(line), ope[i]) == TRUE)
		{
			f_ptr[i](s);
			(*count)++;
			break ;
		}
		i++;
	}
	if (i == NB_OPE)
		return (ft_print_err_failure(WRONG_OPE, STD_ERR));
	if (s->verbose == TRUE)
	{
		print_stack(s, i, *count);
		usleep(50000);
	}
	return (SUCCESS);
}
