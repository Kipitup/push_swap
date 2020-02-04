/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/02/04 18:54:05 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swp(t_stack *s, int ac, char **av)
{
	int8_t		ret;

	s = init_struct(av, ac);
	if (s == NULL)
		return ;
	mkdir("result", 0700);
	// s->verbose = TRUE;
	// s->color = TRUE;
	ret = s->exponent_max == 0 ? solve_when_too_small(s) : solve(s);
	if (ret == SUCCESS)
	{
		optimize_result(s->result);
		save_final_result_in_file(s);
	}
	if (s->verbose == TRUE)
		print_stack(s, NO_OPE, 0);
	ft_dprintf(STD_OUT, "%s", vct_getstr(s->result));
	clean_struct(&s);
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

// __attribute__((destructor))void	dest_end()
// {
// 	ft_printf("coucou\n");
// 	while(1);
// }
