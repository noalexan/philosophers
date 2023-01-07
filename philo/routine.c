/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:38:05 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/07 13:16:06 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->data->print);
	printf("Hello, I'm %d\n", philosopher->id);
	pthread_mutex_unlock(&philosopher->data->print);
	return (NULL);
}
