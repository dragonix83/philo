/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:17:12 by cparodi           #+#    #+#             */
/*   Updated: 2024/10/09 12:38:30 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// struct

typedef struct s_philo
{
	long			id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	long			last_meal_time;
	struct s_global	*global;
}					t_philo;

typedef struct s_global
{
	int				nb_philo;
	pthread_mutex_t	*forks;
	pthread_t		*philosopher;
	long			start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				dead_philo;
}					t_global;

t_philo				*init_struct(t_philo *philo, int i, char **argv);
void				init_forks(t_global *global);
void				init_philosophers(t_philo *philos);

// process

void				*process(void *param);
void 				thinking(t_philo *philo, long id);
void 				eating(t_philo *philo, long id);
void 				sleeping(t_philo *philo, long id);

// Utils

int					ft_atoi(char *nptr);

#endif
