/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:45:14 by davli             #+#    #+#             */
/*   Updated: 2024/07/30 15:34:12 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

# define PRINT 0
# define MEAL 1
# define END 2
# define DEATH 3

typedef struct s_var
{
	int				nb;
	long long		t2d;
	long long		t2e;
	long long		t2s;
	int				eat_count;
	long long		start;
	int				end;
	int				died;
	pthread_mutex_t	*mutex;
	pthread_t		*thread;
}			t_var;

typedef struct s_philo
{
	int				num;
	long long		last_meal;
	int				meal_count;
	int				max;
	int				min;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	*fork;
	t_var			*var;
}			t_philo;

void		*routine(void *args);
int			ft_free(t_philo *philo, t_var *var, int ret);
int			is_dead(t_philo *philo);
void		death(t_var *var);
int			ending(t_philo *philo);
int			finished(t_philo *philo, t_var *var);
void		mutex_destroyer(t_philo *philo);
int			init(t_philo **philo, t_var **var, int argc, char **argv);
long		ft_atol(char *str);
long long	get_time(void);
void		print_status(t_philo *philo, char *str);
int			ft_eat(t_philo *p);
int			take_fork(t_philo *p);
int			ft_sleep(t_philo *p);

#endif
