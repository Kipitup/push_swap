/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/02/12 11:10:59 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swp(t_stack *s, int ac, char **av)
{
	int8_t		ret;

	s = init_struct(av, ac);
	if (s != NULL)
	{
		mkdir("result", 0700);
		ret = is_it_sorted(s);
		if (ret == FAILURE)
			ft_print_err_void(MALLOC_ERR, STD_ERR);
		else if (ret == FALSE)
		{
			ret = s->exponent_max == EXP_0 ? solve_when_too_small(s) : solve(s);
			if (ret == SUCCESS)
				optimize_result(s->result);
			save_final_result_in_file(s, ac, av);
			if (s->verbose == TRUE)
				print_stack(s, NO_OPE, 0);
			if (ret == SUCCESS)
				if ((ret = vct_print_fd(s->result, STD_OUT)) == FAILURE)
					ft_print_err_void(STD_OUT_CLOSE, STD_ERR);
		}
		clean_struct(&s);
	}
}

int			main(int ac, char **av)
{
	t_stack		*s;

	s = NULL;
	if (ac >= 2)
	{
		++av;
		--ac;
		push_swp(s, ac, av);
	}
	else
		ft_print_err_false("Not enough arguments", STD_ERR);
	return (SUCCESS);
}
