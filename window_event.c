/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:40:23 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/23 18:25:38 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	exit_game(t_comp *comp)
{
	int	iter;

	mlx_destroy_image(comp->mlx, comp->empty);
	mlx_destroy_image(comp->mlx, comp->exit);
	mlx_destroy_image(comp->mlx, comp->fish);
	mlx_destroy_image(comp->mlx, comp->wall);
	mlx_destroy_image(comp->mlx, comp->player_a);
	mlx_destroy_image(comp->mlx, comp->player_s);
	mlx_destroy_image(comp->mlx, comp->player_w);
	mlx_destroy_image(comp->mlx, comp->player_d);
	iter = 0;
	while (comp->map[iter])
		free(comp->map[iter++]);
	mlx_destroy_window(comp->mlx, comp->win);
	free(comp->map);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

						/* key controle {01} */
int	deal_key(int key, t_comp *comp)
{
	if (key == UP_KEY || key == DOWN_KEY || key == LEFT_KEY || key == RIGHT_KEY)
	{
		comp->move++;
		ft_putstr_fd("\033[0;32mMove number = ", STDOUT_FILENO);
		ft_putnbr_fd(comp->move, STDOUT_FILENO);
		ft_putstr_fd("\033[0m\n", STDOUT_FILENO);
	}
	if (key == 53)
		exit_game(comp);
	if (key == UP_KEY)
		key_up(comp);
	if (key == DOWN_KEY)
		key_down(comp);
	if (key == LEFT_KEY)
		key_left(comp);
	if (key == RIGHT_KEY)
		key_right(comp);
	return (EXIT_SUCCESS);
}
