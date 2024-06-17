/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:20:01 by davli             #+#    #+#             */
/*   Updated: 2024/06/17 18:40:53 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	int				cost;
	bool			above_median;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

t_stack		*fill_stack(char **av);

int			is_sorted(t_stack *stack);
void		sort_3(t_stack **stack);

int			get_lowest(t_stack **stack);
char		**ft_split(char const *s, char c);
void		free_split(int ac, char **av);
void		free_both(t_stack **a, t_stack **b);

void		get_cost(t_stack *stack_a, t_stack *stack_b);
void		sort_stacks(t_stack **stack_a, t_stack **stack_b);
void		init_a(t_stack *a, t_stack *b);
t_stack		*get_cheapest(t_stack *stack);
t_stack		*find_max(t_stack *stack);
t_stack		*find_min(t_stack *stack);
void		prepare_push(t_stack **stack, t_stack *top, char stack_name);
void		get_position(t_stack *stack);
void		init_b(t_stack *a, t_stack *b);
void		move_a_to_b(t_stack **a, t_stack **b);
void		move_b_to_a(t_stack **a, t_stack **b);
void		min_on_top(t_stack **a);

void		move(t_stack **a, t_stack **b, int cost_a, int cost_b);

void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);

t_stack		*get_last(t_stack *stack);
t_stack		*get_before_last(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

void		ft_free(t_stack **stack);
long		ft_atol(const char *str);
void		ft_putstr(char *str);
int			absolu(int nb);

void		exit_error(t_stack **stack_a, t_stack **stack_b);

int			ft_check_arg(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbrcmp(const char *s1, const char *s2);

#endif
