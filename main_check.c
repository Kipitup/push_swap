/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:57:10 by fkante            #+#    #+#             */
/*   Updated: 2020/02/03 11:11:58 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		is_it_sorted(t_stack *s, int32_t *sorted_stack)
{
	size_t		i;
	size_t		j;

	i = s->size_a - 1;
	j = 0;
	while (i > 0 && j < s->size_a)
	{
		if (s->a[i] != sorted_stack[j])
		{
			ft_printf("{c_red}KO{c_end}\n");
			return ;
		}
		i--;
		j++;
	}
	ft_printf("{c_green}OK{c_end}\n");
}

int			main(int ac, char **av)
{
	t_stack		*s;
	int32_t		*sorted_stack;

	s = NULL;
	if (ac >= 2)
	{
		++av;
		--ac;
		s = init_struct(av, ac);
		if (s == NULL)
			return (SUCCESS);
		sorted_stack = ft_sort(s->a, s->size_a);
		if (sorted_stack != NULL)
		{
			if (s->verbose == TRUE)
				print_stack(s, NO_OPE, 0);
			read_checker(s);
			is_it_sorted(s, sorted_stack);
		}
		clean_struct(&s);
	}
	else
		ft_print_err_false("Not enough arguments", STD_ERR);
	return (SUCCESS);
}
