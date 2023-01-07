/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:41:45 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/07 15:30:59 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_terminate_all(t_philosopher *list)
{
	while (list->data->nb_of_philo--)
		ft_set_protected_value(&list[list->data->nb_of_philo].end, 1);
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
			if (notepme && ft_get_protected_value(
					list[i].number_of_times_i_ate) < notepme)
				notepme = 0;
		}
		if (notepme)
			ft_terminate_all(list);
		ft_usleep(10);
	}
}
