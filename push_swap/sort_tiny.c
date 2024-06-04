/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:33:45 by davli             #+#    #+#             */
/*   Updated: 2024/06/03 11:33:45 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_i(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_3(t_stack **stack)
{
	int		highest;

	if (ft_is_sorted(*stack))
		return ;
	highest = highest_i(*stack);
	if ((*stack)->index == highest)
		rotate_a(stack);
	else if ((*stack)->next->index == highest)
		reverse_rotate_a(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
