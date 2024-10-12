/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:52:38 by cparodi           #+#    #+#             */
/*   Updated: 2024/10/12 10:22:12 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		pthread_mutex_init(&global->forks[i], NULL);
		i++;
	}
}

void	init_philosophers(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->global->nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &philos->global->forks[i];
		philos[i].right_fork = &philos->global->forks[(i + 1)
			% philos->global->nb_philo];
		philos[i].global = philos->global;
		philos[i].last_meal_time = 0;
		i++;
	}
}

t_philo	*init_struct(t_philo *philo, int i, char **argv)
{
	philo = malloc(sizeof(t_philo) * i);
	philo->global = malloc(sizeof(t_global));
	philo->global->philosopher = malloc(sizeof(pthread_t) * i);
	philo->global->forks = malloc(sizeof(pthread_mutex_t) * i);
	philo->global->nb_philo = i;
	philo->global->time_to_die = ft_atoi(argv[2]);
	philo->global->time_to_eat = ft_atoi(argv[3]);
	philo->global->time_to_sleep = ft_atoi(argv[4]);
	philo->global->dead_philo = 0;
	init_forks(philo->global);
	init_philosophers(philo);
	return (philo);
}
