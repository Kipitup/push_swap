/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/01/31 19:10:03 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swp(t_stack *s, int ac, char **av)
{
	t_stat		*stat;

	stat = NULL;
	s = init_struct(av, ac);
	if (s == NULL)
		return ;
	stat = get_stat(s);
	mkdir("result", 0700);
	s->verbose = TRUE;
	s->color = TRUE;
	if (s->exponent_max == 0)
	{
		if (solve_when_too_small(s) == SUCCESS)
			save_final_result_in_file(s);
	}
	else
		if (solve(s) == SUCCESS)
			save_final_result_in_file(s);
	ft_printf("%s", vct_getstr(s->result));
	ft_printf("\nra/nrra number : %d\n", vct_chr_str_count(s->result, "\nra\nrra\n"));
	// print_stack(s, NO_OPE, 0);
	clean_struct(&s);
	ft_memdel((void**)&stat);
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
