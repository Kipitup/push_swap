/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:23:57 by amartino          #+#    #+#             */
/*   Updated: 2020/01/24 12:52:23 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pause_and_show(t_stack *s)
{
	char	*line;

	line = NULL;
	// (void)s;
	print_stack(s, NO_OPE, 0);
	get_next_line(0, &line);
	ft_strdel(&line);
}

void	print_command(size_t count, int8_t ope, uint8_t	color, size_t size_a, size_t size_b)
{
	ft_printf("\tCount = %u\n\tSize = %zu\tSize_a = %zu \tSize_b = %zu\n\n\t", count, (size_a + size_b), size_a, size_b);
	if (color == TRUE && (ope >= 0 && ope <= 2))
		ft_printf("{c_b_green}Swap\t\tA: sa\tB: sb\tBoth: ss{c_end}\n", count);
	else
		ft_printf("Swap\t\tA: sa\tB: sb\tBoth: ss\n", count);
	if (color == TRUE && (ope == 3 || ope == 4))
		ft_printf("\t{c_b_green}Push\t\tA: pa\tB: pb{c_end}\n");
	else
		ft_printf("\tPush\t\tA: pa\tB: pb\n");
	if (color == TRUE && (ope >= 5 && ope <= 7))
		ft_printf("\t{c_b_green}Rotate up\tA: ra\tB: rb\tBoth: rr{c_end}\n");
	else
		ft_printf("\tRotate up\tA: ra\tB: rb\tBoth: rr\n");
	if (color == TRUE && (ope >= 8 && ope <= 10))
		ft_printf("\t{c_b_green}Rotate down\tA: rra\tB: rrb\tBoth: rrr{c_end}\n");
	else
		ft_printf("\tRotate down\tA: rra\tB: rrb\tBoth: rrr\n");
	if (color == TRUE)
	{
		ft_printf("\n\tCOLOR:\n\t{c_b_green}Last action{c_end}\n");
		ft_printf("\t{c_yellow}Minimum{c_end}\n\t{c_blue}Median{c_end}\n\t{c_red}Maximum{c_end}\n");
		ft_printf("{c_end}\n");
	}
}

void	print_no_color(t_stack *s)
{
	size_t		a;
	size_t		b;

	a = s->size_a;
	b = s->size_b;
	while (a > 0 || b > 0)
	{
		if (a > 0)
		{
			a--;
			ft_printf("\t|\t\t%d\t\t| |\t", s->a[a]);
		}
		else
			ft_printf("\t|\t\t\t\t| |\t");
		if (b > 0)
		{
			b--;
			ft_printf("\t%d\t\t|\n", s->b[b]);
		}
		else
			ft_printf("\t\t\t|\n");
	}
}

t_stat 	*get_stat(t_stack *s)
{
	t_stat		*stat;

	stat = ft_memalloc(sizeof(t_stat));
	if (stat != NULL)
	{
		stat->min_a = ft_low(s->a, s->size_a);
		stat->max_a = ft_high(s->a, s->size_a);
		ft_median(s->a, s->size_a, &stat->median_a);
		stat->min_b = ft_low(s->b, s->size_b);
		stat->max_b = ft_high(s->b, s->size_b);
		ft_median(s->b, s->size_b, &stat->median_b);
	}
	return (stat);
}

int8_t	check_ope(t_stack *s, size_t size, int8_t ope, int8_t stack)
{
	size_t	ret;
	size_t	len;

	ret = 0;
	len = s->size_a - 1;
	if (stack == STACK_A && ope != NO_OPE)
	{
		if ((ope == 7 && size == 0) || (ope == 10 && size == len)
				|| (ope == 0 && size == len - 1) || (s->a[size] == s->color_nb)
				|| (ope == 2 && (size == len || size == len - 1)))
			ret = ft_printf("\t|\t\t{c_b_green}%d{c_end}\t\t| |\t", s->a[size]);
	}
	else if (stack == STACK_B && ope != NO_OPE)
	{
		if ((ope == 1 && size == s->size_b - 2) || (s->b[size] == s->color_nb)
				|| (ope == 2 && size == s->size_b - 2))
			ret = ft_printf("\t{c_b_green}%d{c_end}\t\t|\n", s->b[size]);
	}
	return (ret > 0 ? TRUE : FALSE);
}

void	handle_stack_a(t_stack *s, size_t size, int8_t ope, t_stat *stat)
{
	if ((check_ope(s, size, ope, STACK_A) == TRUE))
		return ;
	else if (s->a[size] == stat->min_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_yellow}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == stat->max_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_red}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == stat->median_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_blue}%d{c_end}\t\t| |\t", s->a[size]);
	else
		ft_printf("\t|\t\t%d\t\t| |\t", s->a[size]);
}

void	handle_stack_b(t_stack *s, size_t size, int8_t ope, t_stat *stat)
{
	if ((check_ope(s, size, ope, STACK_B) == TRUE))
		return ;
	else if (s->b[size] == stat->min_b && s->size_b > 4)
		ft_printf("\t{c_yellow}%d{c_end}\t\t|\n", s->b[size]);
	else if (s->b[size] == stat->max_b && s->size_b > 4)
		ft_printf("\t{c_red}%d{c_end}\t\t|\n", s->b[size]);
	else if (s->b[size] == stat->median_b && s->size_b > 4)
		ft_printf("\t{c_blue}%d{c_end}\t\t|\n", s->b[size]);
	else
		ft_printf("\t%d\t\t|\n", s->b[size]);
}

void	print_with_color(t_stack *s, int8_t ope)
{
	t_stat		*stat;
	size_t		size_a;
	size_t		size_b;

	size_a = s->size_a;
	size_b = s->size_b;
	stat = get_stat(s);
	if (stat != NULL)
	{
		while (size_a > 0 || size_b > 0)
		{
			if (size_a > 0)
			{
				size_a--;
				handle_stack_a(s, size_a, ope, stat);
			}
			else
				ft_printf("\t|\t\t\t\t| |\t");
			if (size_b > 0)
			{
				size_b--;
				handle_stack_b(s, size_b, ope, stat);
			}
			else
				ft_printf("\t\t\t|\n");
		}
	}
	ft_memdel((void**)&stat);
}

void	print_stack(t_stack *s, int8_t ope, size_t count)
{
	t_vector	*head;
	t_vector	*foot;
	(void)ope;

	head = vct_newstr("\t _______________________________   \
_____________________________\n\t|\t\tSTACK A\t\t| |\t\tSTACK B\t\t|\n\
\t ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n\
\t _______________________________   _____________________________\n");
	foot = vct_newstr("\t ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔   \
▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
	ft_printf("\e[1;1H\e[2J");
	vct_print(head);
	vct_del(&head);
	s->color == TRUE ? print_with_color(s, ope) : print_no_color(s);
	vct_print(foot);
	vct_del(&foot);
	print_command(count, ope, s->color, s->size_a, s->size_b);
}
