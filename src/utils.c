/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:40:09 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/27 18:42:07 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_free(t_main *main)
{
	free(main->map);
	free(main->sprite);
}

void	ft_error(char *errormsg, t_main *main)
{
	int	i;

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

int	ft_x_button(t_main *main)
{
	mlx_destroy_image(main->mlx, main->win);
	exit(0);
	return (0);
}
