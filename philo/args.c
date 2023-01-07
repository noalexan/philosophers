/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:30:21 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/05 00:18:13 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_atoi(const char *a)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	while ('0' <= a[++i] && a[i] <= '9')
	{
		result *= 10;
		result += a[i] - '0';
	}
	if (a[i])
		return (0);
	return (result);
}

t_data	ft_parse_args(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return ((t_data){.error = 1});
	data.nb_of_philo = ft_atoi(argv[1]);
	if (data.nb_of_philo < 1)
		return ((t_data){.error = 2});
	data.time_to_die = ft_atoi(argv[2]);
	if (data.time_to_die < 60)
		return ((t_data){.error = 3});
	data.time_to_eat = ft_atoi(argv[3]);
	if (data.time_to_eat < 60)
		return ((t_data){.error = 4});
	data.time_to_sleep = ft_atoi(argv[4]);
	if (data.time_to_sleep < 60)
		return ((t_data){.error = 5});
	if (argc == 6)
		data.notepme = ft_atoi(argv[5]);
	else
		data.notepme = -1;
	if (argc == 6 && data.notepme < 1)
		return ((t_data){.error = 6});
	data.error = 0;
	pthread_mutex_init(&data.print, NULL);
	return (data);
}
