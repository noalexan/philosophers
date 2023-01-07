/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:31:25 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/06 16:43:22 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_get_protected_value(t_protected_variable variable)
{
	long	value;

	pthread_mutex_lock(&variable.protector);
	value = variable.value;
	pthread_mutex_unlock(&variable.protector);
	return (value);
}

void	ft_set_protected_value(t_protected_variable *variable, long value)
{
	pthread_mutex_lock(&variable->protector);
	variable->value = value;
	pthread_mutex_unlock(&variable->protector);
}

t_protected_variable	ft_create_protected_variable(void)
{
	t_protected_variable	variable;

	pthread_mutex_init(&variable.protector, NULL);
	ft_set_protected_value(&variable, 0);
	return (variable);
}
