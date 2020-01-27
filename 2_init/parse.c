/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:59 by amartino          #+#    #+#             */
/*   Updated: 2020/01/23 20:47:17 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint8_t		check_no_double(t_stack *s)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < s->size_a)
	{
		j = i + 1;
		while (j < s->size_a)
		{
			if (s->a[i] == s->a[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

uint8_t		check_for_bonus(char **tab, char *chr)
{
	uint8_t		ret;

	ret = FALSE;
	if ((ft_strequ(tab[0], chr) == TRUE) || (ft_strequ(tab[1], chr) == TRUE))
		ret = TRUE;
	return (ret);
}

int8_t		check_err(char *str, size_t j)
{
	int8_t		count;

	count = 0;
	if (str[j] == '-' && str[j + 1] != '\0')
	{
		j++;
		while (str[j] != '\0')
		{
			if (ft_isdigit((int)str[j]) == FALSE)
			{
				if (str[j] != 'v' && str[j] != 'c')
					return (FAILURE);
				else
					count++;
			}
			j++;
		}
	}
	else
		return (FAILURE);
	return (count);
}

ssize_t		parse_args(char **tab, int32_t len)
{
	size_t	i;
	size_t	j;
	ssize_t	ret;
	ssize_t	tmp;

	i = 0;
	ret = 0;
	while ((int32_t)i < len)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (ft_isdigit((int)tab[i][j]) == FALSE)
			{
				if ((tmp = check_err(tab[i], j)) == FAILURE)
					return (FAILURE);
				else
					ret += tmp;
				break ;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
