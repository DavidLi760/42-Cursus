/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:30:59 by davli             #+#    #+#             */
/*   Updated: 2024/06/03 11:31:01 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = get_stack_size(temp_a);
	size_b = get_stack_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}

void	cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (ft_abs(temp->cost_a) + ft_abs(temp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(temp->cost_b) + ft_abs(temp->cost_a);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
