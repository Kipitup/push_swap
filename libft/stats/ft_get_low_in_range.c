/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_low_in_range.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:15:01 by fkante            #+#    #+#             */
/*   Updated: 2020/01/17 16:01:02 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_get_low_in_range(int32_t *tab, size_t start, size_t end)
{
	int32_t		low;

	low = start;
	while (start < end)
	{
		if (tab[low] > tab[start])
			low = start;
		start++;
	}
	return (low);
}
