/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_delete_order.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:55:35 by amartino          #+#    #+#             */
/*   Updated: 2020/02/23 19:58:14 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	delete_case_4(t_rb_tree *node, t_rb_tree * sibling)
{
	unsigned int	s_child1_color : 1;
	unsigned int	s_child2_color : 1;

	s_child1_color = (sibling->right != NULL) ? sibling->right->color : BLACK;
	s_child2_color = (sibling->left != NULL) ? sibling->left->color : BLACK;
	if ((node->parent->color == RED) && (sibling->color == BLACK)
			&& (s_child1_color == BLACK) && (s_child2_color == BLACK))
	{
		sibling->color = RED;
		n->parent->color = BALCK;
	}
	else
		delete_case_5(node,  sibling);
}

void	delete_case_3(t_rb_tree *node, t_rb_tree * sibling)
{
	unsigned int	s_child1_color : 1;
	unsigned int	s_child2_color : 1;

	s_child1_color = (sibling->right != NULL) ? sibling->right->color : BLACK;
	s_child2_color = (sibling->left != NULL) ? sibling->left->color : BLACK;
	if ((node->parent->color == BLACK) && (sibling->color == BLACK)
			&& (s_child1_color == BLACK) && (s_child2_color == BLACK))
	{
		sibling->color = RED;
		delete_case_1(node->parent);
	}
	else
		delete_case_4(node, sibling);
}

void	delete_case_2(t_rb_tree *node, t_rb_tree * sibling)
{
	if (sibling->color == RED)
	{
		node->parent->color = RED;
		sibling->color = BLACK;
		if (node == node->parent->left)
			left_rotate(node->parent);
		else
			right_rotate(node->parent);
	}
	delete_case_3(node, sibling);
}

/*
** The node is the new root, we are done
*/
void	delete_case_1(t_rb_tree *node)
{
	t_rb_tree	*sibling;

	if (get_parent(node) != NULL)
	{
		sibling = get_sibling(node);
		if (sibling !=  NULL)
			delete_case_2(node, sibling);
	}
}


// void	delete_case_3(t_rb_tree *node)
// {
// 	t_rb_tree		*sibling;
// 	unsigned int	s_child1_color : 1;
// 	unsigned int	s_child2_color : 1;
//
// 	sibling = get_sibling(node);
// 	if (sibling != NULL)
// 	{
// 		s_child1_color = sibling->right != NULL ? sibling->right->color : BLACK;
// 		s_child2_color = (sibling->left != NULL) ? sibling->left->color : BLACK;
// 		if (node->parent->color == BLACK && sibling->color == BLACK
// 				&& s_child1_color == BLACK && s_child2_color == BLACK)
// 		{
// 			sibling->color = RED;
// 			delete_case_1(node->parent);
// 		}
// 		else
// 			delete_case_4(node);
// 	}
// 	else
// 		delete_case_4(node);
// }
