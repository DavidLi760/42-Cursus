/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:24:56 by davli             #+#    #+#             */
/*   Updated: 2024/07/30 15:29:20 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	long	nbr;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (0);
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - '0');
		if (nbr > INT_MAX)
			return (0);
	}
	return (nbr * sign);
}

int	init_thread(t_philo **philo, t_var *var)
{
	pthread_mutex_t	*fork;
	int				i;

	fork = malloc(sizeof(pthread_mutex_t) * var->nb);
	if (!fork)
		return (0);
	i = 0;
	while (i < var->nb)
		pthread_mutex_init(&fork[i++], NULL);
	i = 0;
	while (i < var->nb)
	{
		(*philo)[i].num = (i + 1);
		(*philo)[i].last_meal = var->start;
		(*philo)[i].meal_count = 0;
		(*philo)[i].left_fork = i;
		if ((i - 1) < 0)
			(*philo)[i].right_fork = (var->nb - 1);
		else
			(*philo)[i].right_fork = (i - 1);
		(*philo)[i].fork = fork;
		(*philo)[i].var = var;
		++i;
	}
	return (1);
}

int	init_mutex(t_var **var)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = malloc(sizeof(pthread_mutex_t) * 4);
	if (mutex == NULL)
		return (0);
	i = 0;
	while (i < 4)
		pthread_mutex_init(&mutex[i++], NULL);
	(*var)->mutex = mutex;
	return (1);
}

int	init_var(t_var **var, int argc, char **argv)
{
	(*var)->start = get_time();
	(*var)->nb = ft_atol(argv[1]);
	(*var)->t2d = ft_atol(argv[2]);
	(*var)->t2e = ft_atol(argv[3]);
	(*var)->t2s = ft_atol(argv[4]);
	(*var)->eat_count = -1;
	if (argc == 6)
		(*var)->eat_count = ft_atol(argv[5]);
	(*var)->end = 0;
	(*var)->died = 0;
	if (!init_mutex(var))
		return (0);
	return (1);
}

int	init(t_philo **philo, t_var **var, int argc, char **argv)
{
	(*var) = malloc(sizeof(t_var));
	if (*var == NULL)
		return (0);
	(*var)->mutex = NULL;
	(*var)->thread = NULL;
	if (init_var(var, argc, argv) != 1)
		return (0);
	(*philo) = malloc(sizeof(t_philo) * (*var)->nb);
	if (*philo == NULL)
		return (0);
	(*philo)->fork = NULL;
	if (init_thread(philo, *var) != 1)
		return (0);
	return (1);
}
