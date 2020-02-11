/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:00:45 by amartino          #+#    #+#             */
/*   Updated: 2020/02/11 12:10:58 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Print the vector and a new line
*/

void	vct_print(t_vector *vector)
{
	if (vector != NULL && vector->str != NULL)
	{
		write(1, vector->str, vector->len);
		write(1, "\n", 1);
	}
}
