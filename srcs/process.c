/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:42:53 by cparodi           #+#    #+#             */
/*   Updated: 2024/10/12 10:20:46 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*process(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->id % 2 == 1)
		usleep(1000);
	while (1)
	{
		if (philo->id % 2 == 1)
		{
			pthread_mutex_lock(philo->left_fork);
			pthread_mutex_lock(philo->right_fork);
		}
		else
		{
			pthread_mutex_lock(philo->right_fork);
			pthread_mutex_lock(philo->left_fork);
		}
			thinking(philo, philo->id);
			usleep(100);
			eating(philo, philo->id);
			usleep(philo->global->time_to_eat * 1000);
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			sleeping(philo, philo->id);
			usleep(philo->global->time_to_sleep * 1000);
	}
	return (NULL);
}
