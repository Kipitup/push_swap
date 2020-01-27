/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:04:17 by fkante            #+#    #+#             */
/*   Updated: 2019/11/17 13:34:58 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "define.h"

void	ft_shuffle_tab(int32_t *table_int, uint32_t min, uint32_t max)
{
	uint32_t	i;
	uint32_t	nb_picked;
	uint32_t	size;
	int32_t		tmp;

	size = max - min;
	i = 0;
	for (i = 0; i < size; i++)
	{
		nb_picked = rand() % size;
		tmp = table_int[i];
		table_int[i] = table_int[nb_picked];
		table_int[nb_picked] = tmp;
	}
}

void	init_table(int32_t *table_int, int32_t min, int32_t max)
{
	uint32_t	i;
	uint32_t	size;

	size = max - min;
	i = 0;
	for (i = 0; i <= size; i++)
		table_int[i] = i + min;
	ft_shuffle_tab(table_int, min, max);
}

int8_t	test_gen(uint32_t test_nb, int32_t min, int32_t max)
{
	char		*nb_rand;
	int32_t		*nb_tab;
	uint32_t	i;
	int8_t		ret;
	int8_t		fd;

	ret = FAILURE;
	i = 0;
	if ((fd = creat("test_file", S_IRUSR | S_IWUSR)) >= 0)
	{
		nb_tab = ft_memalloc((max - min + 1) * sizeof(int));
		init_table(nb_tab, min, max);
		while (i < test_nb)
		{
			nb_rand = ft_itoa(nb_tab[i]);
			ft_putendl_fd(nb_rand, fd);
			i++;
		}
		ret = SUCCESS;
	}
	return (ret);
}

int		main(int ac, char **av)
{
	uint32_t	nb_test;
	int8_t		ret;

	ret = FAILURE;
	if (ac == 4)
	{
		nb_test = ft_atoi(av[1]);
		if (test_gen(nb_test, ft_atoi(av[2]), ft_atoi(av[3])) == SUCCESS)
		{
			ft_printf("Success, file test created with %d numbers", nb_test);
			ret = SUCCESS;
		}
		else
			ft_printf("Failure");
	}
	else
		ft_printf("Usage: .test_generator [size], [min], [max]");
	return (ret);
}
