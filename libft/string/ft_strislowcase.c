/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strislowcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:06:40 by amartino          #+#    #+#             */
/*   Updated: 2019/09/11 14:36:22 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strislowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (0);
		i++;
	}
	return (1);
}
