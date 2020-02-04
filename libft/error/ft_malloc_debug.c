/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:25:39 by amartino          #+#    #+#             */
/*   Updated: 2020/02/04 17:45:53 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void		*ft_malloc_debug(size_t size, const char *file, int line, const char *function)
{
	void	*ptr;
	srand(time(NULL)); 	  // Initialization, should only be called once.
	uint32_t r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
	uint32_t res;

	printf("Allocated bytes:\t%-10zu in %-40s at line %8d |\t%-20s\n", size, file, line, function);
	res = (r * (size * line)) % 5;
	printf("res %d\n", res);
	if (res == 0 && ft_strequ(function, "vct_new") == FALSE)
	{
		printf("FAILED\n");
		return (NULL);
	}
	ptr = (void *)malloc(size);
	ft_bzero(ptr, size);
	return (ptr);
}
