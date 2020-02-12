/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:00:45 by amartino          #+#    #+#             */
/*   Updated: 2020/02/12 11:10:26 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Print the vector on the given file descriptor
*/

ssize_t	vct_print_fd(t_vector *vector, ssize_t fd)
{
	ssize_t	ret;

	ret = FAILURE;
	if (vector != NULL && vector->str != NULL)
		ret = write(fd, vector->str, vector->len);
	return (ret);
}
