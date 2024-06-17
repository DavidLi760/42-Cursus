/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:42:28 by davli             #+#    #+#             */
/*   Updated: 2024/06/17 18:13:28 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(char **av)
{
	t_stack		*stack_a;
	long		nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 0)
			stack_a = stack_new((int)nb);
		if (i > 0)
			stack_add(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void	sort_3(t_stack **stack)
{
	int		max;
	int		i;
	t_stack	*temp;

	temp = *stack;
	if (is_sorted(*stack))
		return ;
	i = 0;
	max = temp->value;
	while (i < 2)
	{
		temp = temp->next;
		if (temp->value > max)
			max = (temp->value);
		i++;
	}
	if ((*stack)->value == max)
		ra(stack);
	else if ((*stack)->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = get_stack_size(*stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (len_a-- > 3 && !is_sorted(*stack_a))
	{
		init_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (*stack_b)
	{
		init_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	get_position(*stack_a);
	min_on_top(stack_a);
}
