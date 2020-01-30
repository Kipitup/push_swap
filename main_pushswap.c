/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:18 by amartino          #+#    #+#             */
/*   Updated: 2020/01/30 17:27:35 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swp(t_stack *s, int ac, char **av)
{
	t_stat		*stat;

	stat = NULL;
	s = init_struct(av, ac);
	s->verbose = TRUE;
	s->color = TRUE;
	if (s == NULL)
		return ;
	stat = get_stat(s);
	mkdir("result", 0700);
	s->fd = open("result/tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0744);
	if (s->fd == FAILURE)
	{
		clean_struct(&s);
		return (ft_print_err_void("when creating result file", STD_ERR));
	}
	if (solve(s) == FAILURE)
		return ; //need protection, clean and quit
	if (s->verbose == TRUE)
		print_stack(s, NO_OPE, 0);
	ft_printf("gonna save result\n");
	save_final_result_in_file(s);
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
