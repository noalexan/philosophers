/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:28:43 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/07 12:14:29 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>

# define USAGE_ERROR "usage: ./philo [number_of_philosophers] [time_to_die] [time_\
to_eat] [time_to_sleep] ([number_of_times_each_philosopher_must_eat])\n"

// structure used to stock parameters
typedef struct s_data
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				notepme;
	int				error;
	long			time_at_start;
	pthread_mutex_t	print;
}		t_data;

// args.c
t_data	ft_parse_args(int argc, char **argv);

#endif
