/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:14:47 by amartino          #+#    #+#             */
/*   Updated: 2020/02/11 12:09:32 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		write_in_file(t_stack *s, ssize_t fd, int ac, char **av)
{
	char		**tmp;
	size_t		i;

	tmp = NULL;
	i = 0;
	if (ac == 1)
	{
		tmp = ft_strsplit(av[0], ' ');
		if (tmp == NULL)
			return (ft_print_err_void(MALLOC_ERR, STD_ERR));
		while (tmp[i] != '\0')
		{
			ft_dprintf(fd, "%s ", tmp[i]);
			i++;
		}
		clean_tmp(&tmp, i);
	}
	else
		while (i < (s->size_a + s->size_b))
			ft_dprintf(fd, "%s ", av[i++]);
	ft_dprintf(fd, "\n\n%s", vct_getstr(s->result));
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
		fd = collision_in_filename(name, (suffixe + 1));
	}
	return (fd);
}

void		save_final_result_in_file(t_stack *s, int ac, char **av)
{
	t_vector	*name;
	ssize_t		fd;

	name = vct_newstr("result/");
	vct_addnb(name, (s->size_a + s->size_b));
	vct_addstr(name, "_nb_in_");
	vct_addnb(name, vct_chr_count(s->result, '\n'));
	vct_addstr(name, "_moves");
	fd = open(vct_getstr(name), O_RDWR | O_CREAT | O_EXCL, 0744);
	if (fd == FAILURE)
		fd = collision_in_filename(name, 1);
	if (fd != FAILURE)
		write_in_file(s, fd, ac, av);
	close(fd);
	vct_del(&name);
}
