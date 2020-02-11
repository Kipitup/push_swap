/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:04:17 by fkante            #+#    #+#             */
/*   Updated: 2020/02/11 14:01:00 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shuffle_tab(int32_t *table_int, uint32_t min, uint32_t max)
{
	uint32_t	i;
	uint32_t	nb_picked;
	uint32_t	size;
	int32_t		tmp;

	size = max - min;
	i = 0;
	while (i < size)
	{
		nb_picked = rand() % size;
		tmp = table_int[i];
		table_int[i] = table_int[nb_picked];
		table_int[nb_picked] = tmp;
		i++;
	}
}

void	init_table(int32_t *table_int, int32_t min, int32_t max)
{
	uint32_t	i;
	uint32_t	size;

	size = max - min;
	i = 0;
	while (i <= size)
	{
		table_int[i] = i + min;
		i++;
	}
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
	if ((fd = creat("generated_file", S_IRUSR | S_IWUSR)) >= 0)
	{
		nb_tab = ft_memalloc((max - min + 1) * sizeof(int));
		init_table(nb_tab, min, max);
		while (i < test_nb)
		{
			nb_rand = ft_itoa(nb_tab[i]);
			ft_dprintf(fd, "%s ", nb_rand);
			i++;
		}
		ret = SUCCESS;
	}
	return (ret);
}

int		main(int ac, char **av)
{
	uint32_t	nb_test;
	int32_t		max;
	int32_t		min;
	int8_t		ret;

	ret = FAILURE;
	if (ac == 4)
	{
		nb_test = ft_atoi(av[1]);
		min = ft_atoi(av[2]);
		max = ft_atoi(av[3]);
		if (nb_test < (max - min))
			ret = test_gen(nb_test, min, max);
		if (ret == SUCCESS)
			ft_printf("Success, file test created with %d numbers\n", nb_test);
		else
			ft_printf("Failure\n");
	}
	else
		ft_printf("Usage: .test_generator [size], [min], [max]");
	return (SUCCESS);
}
