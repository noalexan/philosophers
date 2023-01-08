/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:41:45 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/08 20:36:15 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_terminate_all(t_philosopher *list)
{
	while (list->data->nb_of_philo--)
		ft_set_protected_value(&list[list->data->nb_of_philo].end, 1);
}

int	ft_is_dead(t_philosopher *list, int i)
{
	if (!ft_get_protected_value(list[i].eat) && ft_actual_time()
		- ft_get_protected_value(list[i].time_of_last_eat)
		>= list->data->time_to_die)
	{
		pthread_mutex_lock(&list->data->print);
		printf("%ld	%d	died\n",
			ft_actual_time() - list->data->time_at_start, i + 1);
		ft_terminate_all(list);
		return (1);
	}
	return (0);
}

void	ft_end_checker(t_philosopher *list)
{
	int	i;
	int	notepme;

	while (!ft_get_protected_value(list->end))
	{
		notepme = 0;
		if (list->data->notepme > 0)
			notepme = list->data->notepme;
		i = list->data->nb_of_philo;
		while (i--)
		{
			// printf("notepme %d: %ld\n", list[i].id, list[i].number_of_times_i_ate.value);
			if (notepme && ft_get_protected_value(
					list[i].number_of_times_i_ate) < notepme)
				notepme = 0;
			if (ft_is_dead(list, i))
				break ;
		}
		if (notepme)
			ft_terminate_all(list);
		ft_usleep(10);
	}
}
