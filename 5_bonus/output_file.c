/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:14:47 by amartino          #+#    #+#             */
/*   Updated: 2020/01/31 18:59:54 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t		get_nb_of_move(t_vector *vector)
{
	ssize_t		nb_of_move;

	nb_of_move = vct_chr_count(vector, '\n');

	return (nb_of_move);
}

ssize_t		collision_in_filename(t_vector *name, int8_t suffixe)
{
	ssize_t		fd;

	vct_addstr(name, "_");
	vct_addnb(name, suffixe);
	fd = open(vct_getstr(name), O_RDWR | O_CREAT | O_EXCL, 0744);
	if (fd == FAILURE)
	{
		vct_pop(name, (1 + ft_int64_t_len((int64_t)suffixe, 10)));
		suffixe++;
		fd = collision_in_filename(name, suffixe);
	}
	return (fd);
}

void		save_final_result_in_file(t_stack *s)
{
	t_vector	*name;
	ssize_t		fd;

	name = vct_newstr("result/");
	vct_addnb(name, (s->size_a + s->size_b));
	vct_addstr(name, "_nb_in_");
	vct_addnb(name, (int64_t)get_nb_of_move(s->result));
	vct_addstr(name, "_moves");
	fd = open(vct_getstr(name), O_RDWR | O_CREAT | O_EXCL, 0744);
	if (fd == FAILURE)
		fd = collision_in_filename(name, 1);
	ft_dprintf(fd, "%s", vct_getstr(s->result));
	vct_del(&name);
}
