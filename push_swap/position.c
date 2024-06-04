/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:33:01 by davli             #+#    #+#             */
/*   Updated: 2024/06/03 11:33:02 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

int	get_lowest(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_index;
	int		lowest_pos;

	temp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = temp->pos;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			lowest_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (lowest_pos);
}

static int	get_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index > b_idx && temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		target_pos;

	temp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (temp_b)
	{
		target_pos = get_target(a, temp_b->index, INT_MAX, target_pos);
		temp_b->target_pos = target_pos;
		temp_b = temp_b->next;
	}
}
