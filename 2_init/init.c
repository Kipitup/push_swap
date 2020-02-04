/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:43 by amartino          #+#    #+#             */
/*   Updated: 2020/02/04 16:45:14 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fill_in_static_variable(t_stack *s, char **tab, size_t size)
{
	s->size_a = size;
	s->verbose = check_for_bonus(tab, "-v");;
	s->color = check_for_bonus(tab, "-c");
	s->exponent_max = 0;
	while ((SUBLIST_MIN_SIZE * ft_pow_positive(2, s->exponent_max + 1)) <= size)
		s->exponent_max++;
}

t_stack		*fill_stack(t_stack *s, size_t start, char **tab, size_t len)
{
	int64_t		tmp;
	size_t		i;

	i = 0;
	while (len > start && s != NULL)
	{
		len--;
		tmp = ft_atol(tab[len]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			clean_struct(&s);
		else
			s->a[i] = (int)tmp;
		i++;
	}
	if (s == NULL)
		return (ft_print_err_null(INT_MAX_MIN, STD_ERR));
	if (check_no_double(s) == FALSE)
		clean_struct(&s);
	return (s == NULL ? ft_print_err_null(NB_DUPLICATE, STD_ERR) : s);
}

t_stack		*create_stack(char **tab, size_t len)
{
	t_stack		*s;
	ssize_t		start;

	s = NULL;
	start = parse_args(tab, len);
	if (start == FAILURE)
		return (ft_print_err_null(WRONG_INPUT, STD_ERR));
	s = ft_memalloc(sizeof(t_stack));
	if (s == NULL)
		return (ft_print_err_null(MALLOC_STRUCT, STD_ERR));
	fill_in_static_variable(s, tab, (len - (size_t)start));
	s->a = ft_memalloc(sizeof(int) * (len - start));
	s->b = ft_memalloc(sizeof(int) * (len - start));
	s->result = vct_new(ft_log2_n(s->size_a) * (3 * s->size_a));
	if (s->a == NULL || s->b == NULL || s->result == NULL)
	{
		clean_struct(&s);
		return (ft_print_err_null(MALLOC_STACK, STD_ERR));
	}
	s = fill_stack(s, start, tab, len);
	return (s);
}

t_stack		*init_struct(char **av, int ac)
{
	t_stack		*s;
	char		**tmp;
	size_t		i;

	s = NULL;
	tmp = NULL;
	i = 0;
	if (ac == 1)
	{
		tmp = ft_strsplit(av[0], ' ');
		if (tmp == NULL)
			return (ft_print_err_null(MALLOC_ERR, STD_ERR));
		while (tmp[i] != '\0')
			i++;
		s = create_stack(tmp, i);
		clean_tmp(&tmp, i);
	}
	else
		s = create_stack(av, (size_t)ac);
	return (s);
}
