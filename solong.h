/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:51:13 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/23 18:08:16 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "mlx.h"
# include "libft/libft.h"

# define ELEMENT_SIZE	50
									/* colors worck lick
									+---+---+---+---+
									| 0 | R | G | B |   color integer
									+---+---+---+---+
							decimal   0  255 255 255  black
							hex		    FF  FF  FF
									 */

# define UP_KEY			13
# define DOWN_KEY		1
# define RIGHT_KEY		2
# define LEFT_KEY		0
# define EXIT_BOTTON	17

typedef struct components
{
	int		count_fish;
	int		count_exit;
	int		count_player;
	void	*empty;
	void	*wall;
	void	*fish;
	void	*exit;
	void	*mlx;
	void	*win;
	void	*player_w;
	void	*player_s;
	void	*player_a;
	void	*player_d;
	int		pp_line[2];
	int		pp_index[2];
	int		map_size[2];
	int		move;
	char	**map;
}		t_comp;

void	checks_and_start(char *map);
void	main_game(t_comp *comp, char *map);
int		deal_key(int key, t_comp *comp);
void	key_right(t_comp *comp);
void	key_left(t_comp *comp);
void	key_up(t_comp *comp);
void	key_down(t_comp *comp);
int		exit_game(t_comp *comp);

#endif /* SOLONG_H */
