/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-14 11:04:16 by cparodi           #+#    #+#             */
/*   Updated: 2024-10-14 11:04:16 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void thinking(t_philo *philo, long id)
{
    (void)philo;
	printf("Philosopher #%ld est en train de \e[0;1;31mpenser\e[0m\n", id);
}

void eating(t_philo *philo, long id)
{
    (void)philo;
	printf("Philosopher #%ld est en train de \e[0;1;32mmanger\e[0m\n", id);
}

void sleeping(t_philo *philo, long id)
{
    (void)philo;
	printf("Philosopher #%ld est en train de \e[0;1;34mdormir\e[0m\n", id);
}
