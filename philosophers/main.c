/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:45:07 by davli             #+#    #+#             */
/*   Updated: 2024/07/30 15:21:39 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroyer(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->var->nb)
		pthread_mutex_destroy(&philo->fork[i++]);
	i = 0;
	while (i < 4)
		pthread_mutex_destroy(&philo->var->mutex[i++]);
}

int	manage_mutex(t_philo *philo, t_var *var, int i)
{
	long long			l_meal;

	while (1)
	{
		pthread_mutex_lock(&var->mutex[MEAL]);
		l_meal = philo[i].last_meal;
		pthread_mutex_unlock(&var->mutex[MEAL]);
		if (l_meal && finished(philo, var))
		{
			pthread_mutex_lock(&var->mutex[END]);
			var->end = 1;
			pthread_mutex_unlock(&var->mutex[END]);
			break ;
		}
		if (l_meal && ((get_time() - l_meal) > var->t2d))
		{
			death(var);
			print_status(&philo[i], DIED);
			break ;
		}
		i = ((i + 1) % var->nb);
		usleep(200);
	}
	return (1);
}

int	create_thread(t_philo *philo)
{
	int			i;

	philo->var->thread = malloc(sizeof(pthread_t) * philo->var->nb);
	if (philo->var->thread == NULL)
		return (0);
	i = -1;
	while (++i < philo->var->nb)
	{
		if (pthread_create(&philo->var->thread[i], 0, routine, &philo[i]))
		{
			while (i--)
				pthread_join(philo->var->thread[i], NULL);
			return (free(philo->var->thread), 0);
		}
	}
	if (manage_mutex(philo, philo->var, 0) != 1)
		return (mutex_destroyer(philo), free(philo->var->thread), 0);
	i = -1;
	while (++i < philo->var->nb)
		if (pthread_join(philo->var->thread[i], NULL))
			return (0);
	return (mutex_destroyer(philo), free(philo->var->thread), 1);
}

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->num % 2 == 0)
	{
		print_status(philo, THINK);
		usleep(philo->var->t2e * 1000);
	}
	while (1)
	{
		if (is_dead(philo))
			break ;
		if (ft_eat(philo) != 1)
			break ;
		print_status(philo, THINK);
		usleep(500);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_var	*var;

	var = NULL;
	philo = NULL;
	if (argc != 5 && argc != 6)
		return (printf("Error : Incorrect arguments"));
	if (init(&philo, &var, argc, argv) != 1)
		return (ft_free(philo, var, 0));
	if (create_thread(philo) != 1)
		return (ft_free(philo, var, 0));
	return (ft_free(philo, var, 1));
}
