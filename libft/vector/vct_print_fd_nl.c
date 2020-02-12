/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print_fd_nl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:08:02 by amartino          #+#    #+#             */
/*   Updated: 2020/02/12 11:10:49 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Print the vector on the given file descriptor with a new line
*/

ssize_t	vct_print_fd_nl(t_vector *vector, ssize_t fd)
{
	ssize_t	ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL)
	{
		ret = write(fd, vector->str, vector->len);
		if (ret != FAILURE)
			write(fd, "\n", 1);
	}
	return (ret);
}
