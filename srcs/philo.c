/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:27:49 by cparodi           #+#    #+#             */
/*   Updated: 2024/10/12 10:21:55 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_philo(t_philo *philo, int i)
{
	int	j;

	j = 0;
	
	while (j < i)
	{
		printf("A new philosopher sat around the table, his ID is : #%ld\n",
		philo[j].id);
		pthread_create(&philo->global->philosopher[j], NULL,
		process, (void *)&philo[j]);
		usleep(100);
		j++;
	}
	j = 0;
	while (j < i)
	{
		pthread_join(philo->global->philosopher[philo->id - 1], NULL);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	*philo;

	if (argc < 2)
		return (0);
	philo = NULL;
	i = ft_atoi(argv[1]);
	philo = init_struct(philo, i, argv);
	start_philo(philo, i);
	free(philo);
	pthread_exit(NULL);
}

