/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:09:14 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/07 12:13:52 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data			data;

	data = ft_parse_args(argc, argv);
	if (data.error)
	{
		write(2, USAGE_ERROR, 131);
		return (data.error);
	}
	return (0);
}
