/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2020/02/12 11:43:45 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "define_ps.h"

typedef struct	s_stack
{
	int32_t		*a;
	int32_t		*b;
	t_vector	*result;
	size_t		size_a;
	size_t		size_b;
	int32_t		color_nb;
	uint8_t		exponent_max;
	uint8_t		verbose;
	uint8_t		color;
}				t_stack;

typedef struct	s_stat
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
t_stack			*create_stack(char **av, size_t len);
t_stack			*fill_stack(t_stack *s, size_t start, char **av, size_t len);
uint8_t			check_no_double(t_stack *s);
ssize_t			parse_args(char **av, int32_t ac);
int8_t			check_err(char *str, size_t j);
uint8_t			bonus(char **av, char *chr);
int8_t			check_for_bonus(char **av);

/*
** ############################################################################
** ################################ PUSH_SWAP #################################
** ############################################################################
*/
void			push_swp(t_stack *s, int ac, char **av);
int8_t			solve(t_stack *s);
int8_t			solve_when_too_small(t_stack *s);
void			pa_highest(t_stack *s, size_t limit);
int8_t			pb_under_pivot(t_stack *s, size_t nth, size_t limit);
int8_t			pa_above_pivot(t_stack *s, size_t nth, size_t limit);
void			optimize_result(t_vector *vector);
void			selection_sort_sublist_on_b(t_stack *s, size_t size);
void			perfect_sort_for_3_on_top_of_a(t_stack *s);
void			perfect_sort_for_3_at_the_bottom_of_a(t_stack *s);
void			perfect_sort_for_size_a_3(t_stack *s);
size_t			sub_size_for_exponent(size_t exponent);

/*
** ############################################################################
** ################################ CHECKER ###################################
** ############################################################################
*/
typedef	void	(*t_operfunc)(t_stack *s);
int8_t			read_checker(t_stack *s);
int8_t			operation_checker(t_operfunc *f_ptr, t_vector *line, t_stack *s,
									size_t *count);

/*
** ############################################################################
** ################################# BONUS ####################################
** ############################################################################
*/
void			print_stack(t_stack *s, int8_t ope, size_t count);
void			print_command(size_t count, int8_t ope, t_stack *s);
int8_t			check_ope(t_stack *s, size_t size, int8_t ope, int8_t stack);
void			print_with_color(t_stack *s, int8_t ope);
t_stat			*get_stat(t_stack *s);
void			handle_a(t_stack *s, size_t size, int8_t ope, t_stat *stat);
void			handle_b(t_stack *s, size_t size, int8_t ope, t_stat *stat);
ssize_t			get_nb_of_move();
ssize_t			collision_in_filename(t_vector *name, int8_t suffixe);
void			write_final_result(ssize_t fd);
void			save_final_result_in_file(t_stack *s, int ac, char **av);
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
int8_t			is_it_sorted(t_stack *s);

/*
** ############################################################################
** ################################# CLEAN ####################################
** ############################################################################
*/
void			clean_struct(t_stack **s);
void			clean_tmp(char ***tmp, size_t i);

#endif
