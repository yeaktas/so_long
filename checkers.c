/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:33:01 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/21 00:50:15 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen(char *len)
{
	int i = 0;
	while(len[i])
		i++;
	return (i);
}

void ber_checker(char *str)
{
	int i;
	i = ft_strlen(str);;
	if ((str[i - 1] == 'r') && (str[i - 2] == 'e') && (str[i - 3] == 'b') && (str[i - 4] == '.'))
		write(1, "everything its ok", 17);
	else
		write(1, "hatali map", 10);
}