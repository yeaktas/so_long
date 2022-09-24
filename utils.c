/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:40:09 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/24 15:21:07 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free(t_main *main)
{
	free(main->mlx);
	free(main->win);
	free(main->map);
	free(main->sprite);
}

void ft_error(char *errormsg, t_main *main)
{
	int i;

	i = 0;
	while (errormsg[i])
	{
		write(1, &errormsg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	ft_free(main);
	exit(0);
}
