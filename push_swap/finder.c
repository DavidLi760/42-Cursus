/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:36:18 by davli             #+#    #+#             */
/*   Updated: 2024/06/15 14:27:31 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	long	max;
	t_stack	*max_stack;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_stack = stack;
		}
		stack = stack->next;
	}
	return (max_stack);
}

t_stack	*find_min(t_stack *stack)
{
	long	min;
	t_stack	*min_stack;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_stack = stack;
		}
		stack = stack->next;
	}
	return (min_stack);
}

void	prepare_push(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	get_position(t_stack *stack)
{
	int		i;
	int		median;

	i = 0;
	if (!stack)
		return ;
	median = (get_stack_size(stack) / 2);
	while (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	long	smallest;
	t_stack	*cheapest;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->cost < smallest)
		{
			smallest = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}
