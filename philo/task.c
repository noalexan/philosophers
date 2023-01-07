/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:37:36 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/07 14:28:34 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print(t_philosopher *philosopher, const char *message)
{
	long	timestamp;

	pthread_mutex_lock(&philosopher->data->print);
	timestamp = ft_actual_time() - philosopher->data->time_at_start;
	if (!ft_get_protected_value(philosopher->end))
		printf("%ld	%d	%s\n", timestamp, philosopher->id, message);
	pthread_mutex_unlock(&philosopher->data->print);
}

void	ft_take_a_fork(t_philosopher *philosopher, pthread_mutex_t *fork)
{
	if (!ft_get_protected_value(philosopher->end))
	{
		pthread_mutex_lock(fork);
		ft_print(philosopher, "has taken a fork");
	}
}

void	ft_eat(t_philosopher *philosopher)
{
	ft_take_a_fork(philosopher, &philosopher->right);
	ft_take_a_fork(philosopher, philosopher->left);
	if (!ft_get_protected_value(philosopher->end))
		ft_print(philosopher, "is eating");
	ft_set_protected_value(&philosopher->eat, 1);
	if (!ft_get_protected_value(philosopher->end))
	{
		ft_usleep(philosopher->data->time_to_eat);
		pthread_mutex_unlock(&philosopher->right);
		pthread_mutex_unlock(philosopher->left);
	}
	ft_set_protected_value(&philosopher->time_of_last_eat, ft_actual_time());
	ft_set_protected_value(&philosopher->eat, 0);
	ft_set_protected_value(&philosopher->number_of_times_i_ate,
		ft_get_protected_value(philosopher->number_of_times_i_ate) + 1);
}

void	ft_sleep(t_philosopher *philosopher)
{
	if (!ft_get_protected_value(philosopher->end))
	{
		ft_print(philosopher, "is sleeping");
		ft_usleep(philosopher->data->time_to_sleep);
	}
}

void	ft_think(t_philosopher *philosopher)
{
	ft_print(philosopher, "is thinking");
}
