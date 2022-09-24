/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:12:27 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/24 18:39:11 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_main	*main;

	if (ac == 2)
	{
		ber_checker(av[1]);
		main = main_init(av[1]);
		map_check(main);
		
		mlx_loop(main->mlx);
		while(1);
	}
	write(1, "Wrong Argument", 14);
	//system("leaks so_long");
	return (0);
}
