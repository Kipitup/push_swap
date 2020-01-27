/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:35:22 by fkante            #+#    #+#             */
/*   Updated: 2019/07/15 15:55:38 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countchar(char const *s, char c)
{
	int i;

	i = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static int	countword(char const *s, char c)
{
	int		count;
	int		i;
	int		state;

	count = 0;
	i = 0;
	state = 0;
	while (s[i])
	{
		if (s[i + 1] == c)
			state = 0;
		else if (state == 0 || s[i + 1] == '\0')
		{
			state = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	**free_s(char **s, size_t i)
{
	while (i-- != 0)
		ft_strdel(&(s[i]));
	ft_memdel((void**)&s);
	s = NULL;
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str_splited;
	int		nb_word;
	int		nb_char;
	int		index;

	if (s == NULL || c == 0)
		return (NULL);
	nb_word = countword(s, c);
	index = 0;
	if (!(str_splited = (char**)ft_memalloc((nb_word + 1) * sizeof(char*))))
		return (NULL);
	while (index < nb_word - 1)
	{
		while (*s == c)
			s++;
		nb_char = countchar(s, c);
		if (!(str_splited[index] = ft_strsub(s, 0, nb_char)))
			return (free_s(str_splited, index));
		s = s + nb_char;
		index++;
	}
	str_splited[index] = NULL;
	return (str_splited);
}
