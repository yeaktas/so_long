/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:29:53 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/25 20:28:44 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_image(t_main *main)
{
	int x;
	int y;

	x = main->sprite->sprite_h;
	y = main->sprite->sprite_w;
	main->sprite->tile = mlx_xpm_file_to_image(main->mlx, ".img/0gras.xpm", &x, &y);
	main->sprite->wall = mlx_xpm_file_to_image(main->mlx, ".img/1wall.xpm", &x, &y);
	main->sprite->coin = mlx_xpm_file_to_image(main->mlx, ".img/Cfindux.xpm", &x, &y);
	main->sprite->exit = mlx_xpm_file_to_image(main->mlx, ".img/Edoor.xpm", &x, &y);
	main->sprite->player = mlx_xpm_file_to_image(main->mlx, ".img/Prat.xpm", &x, &y);
}

t_main *main_init(char *path)
{
	t_main *main;

	main = (t_main *) malloc(sizeof(t_main));
	main->map = (t_map *)malloc(sizeof(t_map));
	main->sprite = (t_sprite *)malloc(sizeof(t_sprite));
	main->mcount = 0;
	main->map->map = map_init(path, main);
	main->mlx = mlx_init();
	xpm_to_image(main);
	main->win = mlx_new_window(main->mlx, main->map->x * PIXEL, main->map->y * PIXEL, "so_long");
	return (main);
}
