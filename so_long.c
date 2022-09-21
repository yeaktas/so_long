/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:12:27 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/21 15:08:55 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_main	main;
	int		x;
	int		y;

	if (ac == 2)
	{	
		main.mlx = mlx_init();
		ber_checker(av[1]);
		main.win = mlx_new_window(main.mlx, 1920, 1080, "so_long");
		main.img = mlx_xpm_file_to_image(main.mlx, "img/1wall.xpm", &x, &y);
		mlx_put_image_to_window(main.mlx, main.win, main.img, 32, 32);
		mlx_loop(main.mlx);
	}
	write(1, "eksik arguman", 13);
}
