/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:57:10 by fkante            #+#    #+#             */
/*   Updated: 2020/02/12 13:42:37 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check(t_stack *s, int ac, char **av)
{
	int8_t		ret;

	s = init_struct(av, ac);
	if (s != NULL)
	{
		if (s->verbose == TRUE)
			print_stack(s, NO_OPE, 0);
		ret = read_checker(s);
		if (s->verbose == TRUE && ret == SUCCESS)
			print_stack(s, NO_OPE, 0);
		if (ret == SUCCESS)
			ret = is_it_sorted(s);
		if (ret == TRUE)
		{
			if ((ret = write(STD_OUT, "OK\n", 3)) == FAILURE)
				ft_print_err_void(STD_OUT_CLOSE, STD_ERR);
		}
		else if (ret == FALSE)
		{
			if ((ret = write(STD_OUT, "KO\n", 3)) == FAILURE)
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
		check(s, ac, av);
	}
	else
		ft_print_err_false("Not enough arguments", STD_ERR);
	return (SUCCESS);
}
