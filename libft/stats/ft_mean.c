/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:01:11 by amartino          #+#    #+#             */
/*   Updated: 2020/02/11 19:01:38 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t		ft_mean(int32_t *tab, size_t size)
{
	int32_t		total;
	size_t		i;

	i = 0;
	total = tab[i];
	if (size == 0)
		return (FALSE);
	while (i < size)
	{
		total += tab[i];
		i++;
	}
	return (total / size);
}
