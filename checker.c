/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:33:01 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/24 18:53:35 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_checker(char *path)
{
	int	i;

	i = ft_strlen(path);
	if ((path[i - 1] == 'r') && (path[i - 2] == 'e')
		&& (path[i - 3] == 'b') && (path[i - 4] == '.'))
		write(1, ".ber ile bitiyor\n", 17);
	else
	{
		write(1, "Map name is wrong!", 18);
		exit(0);
	}
}

/* void map_check_top_bottom(t_main *main)
{
	int i;

	i = 0;
	write(1, "as", 2);
	while (i < main->map->x)
	{
		if(main->map->map[i][0] != '1')
			ft_error("Error!\nMap checker: The top is wrong.", main);
		else if(main->map->map[main->map->y - 1][i] != '1')	
			ft_error("Error!\nMap checker: The bottom is wrong.", main);
		i++;
	}
	i = 0;
	while (i < main->map->y - 1)
	{
		if (main->map->map[i][0] != '1')
			ft_error("Error\nMAP: (LEFT)", main);
		else if (main->map->map[i][main->map->x - 1] != '1')
			ft_error("Error\nMAP: (RIGHT)", main);
		i++;
	}
} */

int map_check(t_main *main)
{
	if(main->ecount <= 0)
		ft_error("Error\nExit not found.", main);
	else if(main->ecount > 1)
		ft_error("Error\nThere are multiple exits.", main);
	else if (main->ccount <= 0)
		ft_error("Error\nCollectible not found.", main);
	else if(main->pcount <= 0)
		ft_error("Error\nPlayer not found.", main);
	else if(main->pcount > 1)
		ft_error("Error\nThere are multiple player.", main);
	return (1);
}
