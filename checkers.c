/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:33:01 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/23 20:12:50 by yaktas           ###   ########.fr       */
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
		write(1, "hatali map ismi", 10);
		exit(0);
	}
}
