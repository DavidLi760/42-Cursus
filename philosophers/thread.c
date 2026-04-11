/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:24:45 by davli             #+#    #+#             */
/*   Updated: 2024/07/30 15:29:13 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->var->mutex[DEATH]);
	if (philo->var->died)
	{
		pthread_mutex_unlock(&philo->var->mutex[DEATH]);
		return (1);
	}
	pthread_mutex_unlock(&philo->var->mutex[DEATH]);
	return (0);
}

int	ending(t_philo *philo)
{
	pthread_mutex_lock(&philo->var->mutex[END]);
	if (philo->var->end)
	{
		pthread_mutex_unlock(&philo->var->mutex[END]);
		return (1);
	}
	pthread_mutex_unlock(&philo->var->mutex[END]);
	return (0);
}

int	ft_eat(t_philo *p)
{
	if (take_fork(p) != 1)
		return (0);
	pthread_mutex_lock(&p->var->mutex[MEAL]);
	p->last_meal = get_time();
	p->meal_count++;
	pthread_mutex_unlock(&p->var->mutex[MEAL]);
	if (ending(p))
		return (ft_sleep(p), 0);
	usleep(p->var->t2e * 1000);
	ft_sleep(p);
	return (1);
}

int	take_fork(t_philo *p)
{
	if (p->right_fork > p->left_fork)
		p->max = p->right_fork;
	else
		p->max = p->left_fork;
	if (p->right_fork < p->left_fork)
		p->min = p->right_fork;
	else
		p->min = p->left_fork;
	pthread_mutex_lock(&p->fork[p->min]);
	print_status(p, FORK);
	if (p->left_fork == p->right_fork)
	{
		pthread_mutex_unlock(&p->fork[p->min]);
		return (0);
	}
	pthread_mutex_lock(&p->fork[p->max]);
	print_status(p, FORK);
	print_status(p, EAT);
	return (1);
}

int	ft_sleep(t_philo *p)
{
	if (p->right_fork > p->left_fork)
		p->max = p->right_fork;
	else
		p->max = p->left_fork;
	if (p->right_fork < p->left_fork)
		p->min = p->right_fork;
	else
		p->min = p->left_fork;
	print_status(p, SLEEP);
	pthread_mutex_unlock(&p->fork[p->min]);
	pthread_mutex_unlock(&p->fork[p->max]);
	usleep(p->var->t2s * 1000);
	return (1);
}
