/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:49:04 by amartino          #+#    #+#             */
/*   Updated: 2020/01/16 15:40:38 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BTREE_H
# define BTREE_H

#include "libft.h"
#include <stdio.h>

# define HEAP_SIZE		0
# define NB_OF_SPACE	10
# define MAX_HEAP		0
# define MIN_HEAP		1
# define ROOT			1
# define STD_IN			0
# define STD_OUT		1
# define STD_ERR		2

/*
** ############################################################################
** ################################# HEAP #####################################
** ############################################################################
*/
typedef struct			s_heap
{
	int32_t			*A;
	uint8_t			type;
}						t_heap;

/*
*****************************************************************************
**	Heap tree start at index 1. Index 0 store the HEAP SIZE
**
**	2 type of tree : MAX heap (0) and MIN heap (1). Check define above.
**
**	Doc : https://s.42l.fr/heap_tree
*****************************************************************************
*/
t_heap		*heap_tree(int32_t *tab, size_t size, uint8_t type);
void		fill_tree(t_heap *heap, int32_t *tab, size_t size);
void		insert(t_heap *heap, int32_t nb, size_t index);
void		delete_root(t_heap *heap);
void		clean_heap_tree(t_heap **heap);


void 		is_parent_valid(t_heap *heap, size_t child);
void		heapify(t_heap *heap, size_t parent);

size_t		get_parent(size_t index);
size_t		get_left_child(size_t index);
size_t		get_right_child(size_t index);
size_t		deepness(size_t max);
void		swap(t_heap *heap, size_t parent, size_t child);

void		print_heap_tree(t_heap *heap, size_t index, size_t deep);

#endif
