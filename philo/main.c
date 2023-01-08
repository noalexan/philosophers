/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:09:14 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/08 19:15:15 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data			data;
	t_philosopher	*list;

	data = ft_parse_args(argc, argv);
	if (data.error)
	{
		write(2, USAGE_ERROR, 131);
		return (data.error);
	}
	ft_init_list(&list, &data);
	ft_launch(list);
	ft_end_checker(list);
	return (0);
}
