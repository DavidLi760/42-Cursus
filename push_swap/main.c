/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:42:16 by davli             #+#    #+#             */
/*   Updated: 2024/06/17 18:35:59 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (!is_sorted(*stack_a))
	{
		if (stack_size == 2)
			sa(stack_a);
		else if (stack_size == 3)
			sort_3(stack_a);
		else if (stack_size > 3)
			sort_stacks(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		i;

	i = 0;
	if (ac < 2 || !av[1][0])
		return (0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		while (av[i])
			av[i++] = av[i + 1];
	if (!ft_check_arg(av))
	{
		free_split(ac, av);
		exit_error(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = fill_stack(av);
	stack_size = get_stack_size(stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	free_both(&stack_a, &stack_b);
	free_split(ac, av);
	return (0);
}
