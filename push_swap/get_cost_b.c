/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:29:22 by davli             #+#    #+#             */
/*   Updated: 2024/06/13 20:08:08 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void    get_target_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp_a;
    t_stack *temp_b;
    long    big;

    temp_b = *stack_b;
    while (temp_b)
    {
        big = LONG_MAX;
        temp_a = *stack_a;
        while (temp_a)
        {
            if (temp_b->value > temp_a->value && temp_a->value <= big)
            {
                big = temp_a->value;
                temp_b->target = temp_a;
            }
            temp_a = temp_a->next;
        }
        if (big == LONG_MAX)
            temp_b->target = find_max(stack_a);
        temp_b = temp_b->next;
    }
}
*/
static void	get_target_b(t_stack *a, t_stack *b)
{
	t_stack	*temp_a;
	t_stack	*target_b;
	long	bigger;

	while (b)
	{
		bigger = LONG_MAX;
		temp_a = a;
		while (temp_a)
		{
			if (temp_a->value > b->value && temp_a->value < bigger)
			{
				bigger = temp_a->value;
				target_b = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (bigger == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_b;
		b = b->next;
	}
}

void	init_b(t_stack *a, t_stack *b)
{
	get_position(a);
	get_position(b);
	get_target_b(a, b);
}
