/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:43:00 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/24 15:11:18 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_count(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	return (i);
}

int	column_count(char *buffer)
{
	int	i;
	int	column;

	column = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			column++;
		i++;
	}
	return (column + 1);
}

//string dizisi oluşturuyoruz. 
//aynı zamanda E,P,C countu buluyoruz.

char	**map_split2(t_main *main, int column, int line, char *buffer)
{
	char	**map;
	int		y;
	int		x;

	y = 0;
	map = (char **) malloc(sizeof(char *) * column);
	while (y < column)
	{
		x = 0;
		map[y] = (char *) malloc(sizeof(char) * line + 2);
		while (x < line + 1)
		{
			if (buffer[(y * (line + 1) + x)] == 'E')
				main->ecount++;
			else if (buffer[y * (line + 1) + x] == 'P')
				main->pcount++;
			else if (buffer[(y * (line + 1) + x)] == 'C')
				main->ccount++;
			map[y][x] = buffer[(y * (line + 1) + x)];
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	return (map);
}

char	**map_split(char *buffer, t_main *main)
{
	char	**map;
	int		column;
	int		line;

	main->ecount = 0;
	main->pcount = 0;
	main->ccount = 0;
	column = column_count(buffer);
	line = line_count(buffer);
	map = map_split2(main, column, line, buffer);
	main->map->x = line;
	main->map->y = column;
	return (map);
}

// bir dosyaya girdi çıktı yapabilmek için dosyayı açabilmemiz gerekir. açık olan dosyayı tekrar kullanabilmek
// içinde bir yerde tutmamız gerekir. bunun için int tipinde bir değişken kullanıyoruz. Bu değişkenin adına
// file descriptor(fd) adını veriyoruz.
// open fonksiyonun alacağı degerler dosya yolu ve flagler.
// read(fd, buffer, x) fonksiyonu fdden x kadar okuyup buffera yazdırıyor. hata olursa -1 return ediyor.

char **map_init(char *bername, t_main *main)
//char *map_init(char *bername)
{
	char	**map;
	char	buffer[10000];
	int		i;
	int		bytes;
	int		fd;

	fd = open(bername, O_RDONLY);
	i = 0;
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, &buffer[i], 1);
		if (bytes == -1)
		{
			write(1, "map okuma hatali", 16);
			exit(1);
		}
		i++;
	}
	buffer[i] = '\0';
	map = map_split(buffer, main);
	close(fd);
	return (map);
}

