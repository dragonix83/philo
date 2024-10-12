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
	if (philo->id % 2 == 0)
		usleep(100);
	if (pthread_mutex_lock(philo[philo->id].left_fork) == 0
		&& pthread_mutex_lock(philo[philo->id].right_fork) == 0)
	{
		sleep(1);
		printf("Philosopher #%ld est en train de penser\n", philo->id);
		sleep(1);
		printf("Philosopher #%ld est en train de manger\n", philo->id);
		sleep(1);
		printf("Philosopher #%ld est en train de dormir\n", philo->id);
		sleep(1);
		pthread_mutex_unlock(philo[philo->id].left_fork);
		pthread_mutex_unlock(philo[philo->id].right_fork);
	}
	return (NULL);
}
