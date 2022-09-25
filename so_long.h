#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_opengl/mlx.h"
# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define PIXEL 32

typedef struct s_sprite
{
	int		sprite_h;
	int		sprite_w;
	void	*tile;
	void	*exit;
	void	*coin;
	void	*player;
	void	*wall;
}	t_sprite;

typedef struct s_map
{
	char **map;
	int x;
	int y;
}	t_map;

typedef struct	s_main {
	void		*mlx;
	void		*win;
	void		*img;
	int			pcount;
	int			ccount;
	int			ecount;
	int			mcount;
	t_map		*map;
	t_sprite	*sprite;
}	t_main;

//Checker
void	ber_checker(char *str);
int		map_check(t_main *main);

//Init
t_main	*main_init(char *path);

//Map
char	**map_init(char *bername, t_main *main);

//Utils
void	ft_free(t_main *main);
void	ft_error(char *errormsg, t_main *main);

#endif