/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:57:10 by fkante            #+#    #+#             */
/*   Updated: 2020/02/05 19:00:43 by amartino         ###   ########.fr       */
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
			ft_printf("KO\n");
			return ;
		}
		i--;
		j++;
	}
	ft_printf("OK\n");
}

int			main(int ac, char **av)
{
	t_stack		*s;
	int32_t		*sorted_stack;

	s = NULL;
	if (ac == 45)
	{
		++av;
		--ac;
		s = init_struct(av, ac);
		if (s == NULL)
			return (SUCCESS);
		// s->verbose = TRUE;
		// s->color = TRUE;
		sorted_stack = ft_sort(s->a, s->size_a);
		if (sorted_stack != NULL)
		{
			read_checker(s);
			if (s->verbose == TRUE)
				print_stack(s, NO_OPE, 0);
			is_it_sorted(s, sorted_stack); //to clean
			ft_memdel((void**)&sorted_stack);
		}
		clean_struct(&s);
	}
	else
	{
		t_vector	*vector;
		ssize_t		fd;

		vector = NULL;
		fd = open(av[1], O_RDWR, 0744);
		vct_read_line(fd, &vector);
		vct_print(vector);
		vct_del(&vector);
	}
		// ft_print_err_false("Not enough arguments", STD_ERR);
	return (SUCCESS);
}
