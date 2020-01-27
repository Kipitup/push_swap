/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2020/01/27 18:37:06 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "define_ps.h"

typedef struct	s_stack
{
	int32_t	*a;
	int32_t	*b;
	int32_t *sorted_s;
	size_t	size_a;
	size_t	size_b;
	int32_t	color_nb;
	uint8_t	exponent_max;
	int8_t	fd;
	uint8_t	verbose;
	uint8_t	color;
}				t_stack;

typedef struct 	s_stat
{
	int32_t		min_a;
	int32_t		max_a;
	int32_t		median_a;
	int32_t		min_b;
	int32_t		max_b;
	int32_t		median_b;
}				t_stat;

enum	e_operations
{
	E_SA,
	E_SB,
	E_SS,
	E_PA,
	E_PB,
	E_RA,
	E_RB,
	E_RR,
	E_RRA,
	E_RRB,
	E_RRR
};

/*
** ############################################################################
** ################################# INIT #####################################
** ############################################################################
*/
t_stack			*init_struct(char **av, int ac);
t_stack			*create_stack(char **tab, size_t len);
t_stack			*fill_stack(t_stack *s, size_t start, char **tab, size_t len);
uint8_t			check_no_double(t_stack *s);
ssize_t			parse_args(char **av, int32_t ac);
int8_t			check_err(char *str, size_t j);
uint8_t			check_for_bonus(char **tab, char *chr);

/*
** ############################################################################
** ################################ PUSH_SWAP #################################
** ############################################################################
*/
void			push_swp(t_stack *s, int ac, char **av);
int8_t			solve(t_stack *s);
void			pb_lowest(t_stack *s, size_t limit);
void			pa_highest(t_stack *s, size_t limit);
void			pb_under_pivot(t_stack *s, int32_t pivot, size_t limit);
void			pa_above_pivot(t_stack *s, int32_t pivot, size_t limit);
void			pivot_on_top_a(t_stack *s, int32_t pivot);
void			pivot_on_top_b(t_stack *s, int32_t pivot);
void			sort_sublist_on_b(t_stack *s);
void			push_next_sublist_on_b(t_stack *s, size_t size);
void			rra_the_remainder(t_stack *s);

/*
** ############################################################################
** ################################ CHECKER ###################################
** ############################################################################
*/
typedef	void	(*operfunc)(t_stack *s);
void			read_checker(t_stack *s);
void			operation_checker(operfunc *f, char *ln, t_stack *s, size_t *count);

/*
** ############################################################################
** ################################# BONUS ####################################
** ############################################################################
*/
void			print_stack(t_stack *s, int8_t ope, size_t count);
void			print_command(size_t count, int8_t ope, uint8_t	color, size_t size_a, size_t size_b);
t_stat 			*get_stat(t_stack *s);
ssize_t			get_nb_of_move();
ssize_t			collision_in_filename(t_vector *name, int8_t suffixe);
void			write_final_result(ssize_t fd);
void			save_final_result_in_file(t_stack *s);
void			pause_and_show(t_stack *s);


/*
** ############################################################################
** ################################# TOOL #####################################
** ############################################################################
*/
void			swap_stack_a(t_stack *s);
void			swap_stack_b(t_stack *s);
void			push_stack_a(t_stack *s);
void			push_stack_b(t_stack *s);
void			shiftup_stack_a(t_stack *s);
void			shiftup_stack_b(t_stack *s);
void			shiftdown_stack_a(t_stack *s);
void			shiftdown_stack_b(t_stack *s);
void			rotate_stack_a(t_stack *s);
void			rotate_stack_b(t_stack *s);
void			reverse_rotate_stack_a(t_stack *s);
void			reverse_rotate_stack_b(t_stack *s);
void			swap_nb(int32_t *stack1, int32_t *stack2);
void			swap_both(t_stack *s);
void			rotate_both(t_stack *s);
void			reverse_both(t_stack *s);
void			pa(t_stack *s);
void			pb(t_stack *s);
void			sa(t_stack *s);
void			sb(t_stack *s);
void			ss(t_stack *s);
void			ra(t_stack *s);
void			rb(t_stack *s);
void			rra(t_stack *s);
void			rrb(t_stack *s);
void			rr(t_stack *s);
void			rrr(t_stack *s);

/*
** ############################################################################
** ################################# CLEAN ####################################
** ############################################################################
*/
void			clean_struct(t_stack **s);
void			clean_tmp(char ***tmp, size_t i);


#endif
