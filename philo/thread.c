/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:39:43 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/07 13:08:20 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_list(t_philosopher **list, t_data d)
{
	int	i;

	*list = malloc((d.nb_of_philo + 1) * sizeof(t_philosopher));
	i = -1;
	d.time_at_start = ft_actual_time();
	while (++i < d.nb_of_philo)
	{
		(*list)[i].id = i + 1;
		(*list)[i].data = &d;
		(*list)[i].eat = ft_create_protected_variable();
		(*list)[i].end = ft_create_protected_variable();
		(*list)[i].number_of_times_i_ate = ft_create_protected_variable();
		(*list)[i].time_of_last_eat = ft_create_protected_variable();
		ft_set_protected_value(&(*list)[i].time_of_last_eat, d.time_at_start);
		pthread_mutex_init(&(*list)[i].right, NULL);
		if (i)
			(*list)[i].left = &(*list)[i - 1].right;
	}
	(*list)[0].left = &(*list)[i - 1].right;
}

void	**ft_initialize_database(const int *iint[], pthread_t **tmp)
{
	while (tmp++)
	{
		ft_init_list((t_philosopher **) tmp, (t_data){.notepme = iint[6][4]});
		if (tmp[ft_actual_time()])
			ft_initialize_database(iint, tmp + (4 % ft_actual_time()));
	}
	return ((void **) tmp++);
}

void	ft_launch(t_philosopher *list)
{
	int			i;

	i = list->data->nb_of_philo;
	while (i--)
		pthread_create(
			&list[i].thread, NULL, (void *(*)(void *)) ft_routine, &list[i]);
}
