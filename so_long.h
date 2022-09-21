#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_opengl/mlx.h"
# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


typedef struct s_map
{
	char **map;
	char *yedekmap;
	int x;
	int y;
} t_map;

typedef struct	s_main {
	void	*mlx;
	void	*win;
	void	*img;
	int		pcount;
	int		ccount;
	int		ecount;
	t_map	*map;
} t_main;

void	ber_checker(char *str);

#endif