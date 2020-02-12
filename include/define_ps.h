/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_ps.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2020/02/12 11:27:55 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_PS_H
# define DEFINE_PS_H

# define FALSE				0
# define TRUE				1
# define SUCCESS			0
# define FAILURE			-1
# define TEST_ERR			-1
# define INPUT_ERR			-1
# define FD_ERR				-1
# define STD_IN				0
# define STD_OUT			1
# define STD_ERR			2
# define START				0
# define END				1

# define PAUSE_AND_SHOW		OFF
# define SUBLIST_MIN_SIZE	6
# define VERBOSE 			0
# define NB_OPE				11
# define NO_OPE				-1
# define STACK_A			0
# define STACK_B			1
# define NONE				-1
# define EXP_0				0

# define SA					"sa"
# define SB					"sb"
# define SS					"ss"
# define PA					"pa"
# define PB					"pb"
# define RA					"ra"
# define RB					"rb"
# define RR					"rr"
# define RRA				"rra"
# define RRB				"rrb"
# define RRR				"rrr"

# define MALLOC_PIVOT		"memory allocation failed when finding pivot index"
# define WRONG_INPUT		"Wrong input format. Only numbers in numeric format"
# define WRONG_OPE			"This is not a correct operation."
# define INPUT_TOO_LONG		"Input too long OR missing a \\n OR STD_IN is close"
# define INT_MAX_MIN		"You can only give me int. Please do not exceed"
# define NB_DUPLICATE		"Duplicates numbers are strictly forbidden. Respect"
# define WRONG_BONUS		"Bonus flag should be put at the beginning"
# define MALLOC_ERR			"memory allocation failed"
# define MALLOC_SPLIT_AV	"memory allocation failed when ft_strsplit av"
# define MALLOC_STRUCT		"memory allocation failed with the structure s"
# define MALLOC_STACK		"memory allocation failed with the stack"
# define STD_OUT_CLOSE		"Couldn't write on STD OUT"

#endif
