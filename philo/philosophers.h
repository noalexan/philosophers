/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:28:43 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/07 14:43:04 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define USAGE_ERROR "usage: ./philo [number_of_philosophers] [time_to_die] [ti\
me_to_eat] [time_to_sleep] ([number_of_times_each_philosopher_must_eat])\n"

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

// structure how define a protected variable to avoid datarace
typedef struct s_protected_variable {
	long			value;
	pthread_mutex_t	protector;
}		t_protected_variable;

// structure how define a philosopher
typedef struct s_philosopher
{
	int						id;
	t_protected_variable	end;
	t_protected_variable	eat;
	t_protected_variable	number_of_times_i_ate;
	t_protected_variable	time_of_last_eat;
	t_data					*data;
	pthread_t				thread;
	pthread_mutex_t			right;
	pthread_mutex_t			*left;
}		t_philosopher;

// args.c
t_data					ft_parse_args(int argc, char **argv);

// thread.c
void					ft_init_list(t_philosopher **list, t_data data);
void					ft_launch(t_philosopher *list);

// protected.c
long					ft_get_protected_value(t_protected_variable variable);
void					ft_set_protected_value(t_protected_variable *v, long i);
t_protected_variable	ft_create_protected_variable(void);

// time.c
long					ft_actual_time(void);
void					ft_usleep(long int ms);

// task.c
void					ft_print(t_philosopher *philosopher, const char *m);
void					ft_eat(t_philosopher *philosopher);
void					ft_sleep(t_philosopher *philosopher);
void					ft_think(t_philosopher *philosopher);

// routine.c
void					*ft_routine(t_philosopher *philosopher);

// end.c
void					ft_end_checker(t_philosopher *list);

#endif
