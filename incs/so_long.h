/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:10:02 by yaktas            #+#    #+#             */
/*   Updated: 2022/09/27 18:20:21 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_opengl/mlx.h"
# include "../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define PIXEL 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_sprite
{
	void	*tile;
	void	*exit;
	void	*coin;
	void	*player;
	void	*wall;
	int		sprite_h;
	int		sprite_w;
}	t_sprite;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_main
{
	void		*mlx;
	void		*win;
	void		*img;
	int			pcount;
	int			ccount;
	int			ecount;
	int			mcount;
	int			player_x;
	int			player_y;
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

//Draw
void	draw_map(t_main *main);
void	sprite_draw(t_main *main, void *sprite, int x, int y);
void	convert(t_main *main);

//Utils
void	ft_free(t_main *main);
void	ft_error(char *errormsg, t_main *main);
int		ft_x_button(t_main *main);

//Event
int		key_hook(int keycode, t_main *main);

//Render
int		render(t_main *main);

#endif