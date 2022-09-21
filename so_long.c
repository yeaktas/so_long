/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:12:27 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/21 00:50:37 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	main(int ac, char **av)
{
	t_vars	vars;
	void *img;
	int x, y;
	if(ac == 2)
	{	
		vars.mlx = mlx_init();
		ber_checker(av[1]);
		vars.win = mlx_new_window(vars.mlx, 200, 200, "so_long");
		img = mlx_xpm_file_to_image(vars.mlx, "img/1wall.xpm", &x, &y);
		mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
		mlx_loop(vars.mlx);
	}
	write(1, "eksik arguman", 13);
}
