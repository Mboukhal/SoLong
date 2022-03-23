/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:58:13 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/23 16:43:57 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void set_images(t_comp *comp)
{
	int		width;
	int		height;

    comp->wall = mlx_xpm_file_to_image(comp->mlx, "images/wall.xpm", &width, &height);
	comp->exit = mlx_xpm_file_to_image(comp->mlx, "images/exit.xpm", &width, &height);
	comp->fish = mlx_xpm_file_to_image(comp->mlx, "images/fish.xpm", &width, &height);
	comp->player_d = mlx_xpm_file_to_image(comp->mlx, "images/dlphi_r.xpm", &width, &height);
	comp->player_a = mlx_xpm_file_to_image(comp->mlx, "images/dlphi_l.xpm", &width, &height);
	comp->player_w = mlx_xpm_file_to_image(comp->mlx, "images/dlphi_up.xpm", &width, &height);
	comp->player_s = mlx_xpm_file_to_image(comp->mlx, "images/dlphi_down.xpm", &width, &height);
	comp->empty = mlx_xpm_file_to_image(comp->mlx, "images/empty.xpm", &width, &height);
}


static void    set_map(t_comp *comp)
{
	int	iter;
	int	iter2;
	int	x;
	int	y;

	iter = 0;
	x = 0;
	y = 0;
    while (comp->map[iter])
    {
		iter2 = 0;
		x = 0;
		while (comp->map[iter][iter2])
		{
			if (comp->map[iter][iter2] == '1')
				mlx_put_image_to_window(comp->mlx, comp->win, comp->wall, x, y);
			if (comp->map[iter][iter2] == '0')
				mlx_put_image_to_window(comp->mlx, comp->win, comp->empty, x, y);
			if (comp->map[iter][iter2] == 'C')
				mlx_put_image_to_window(comp->mlx, comp->win, comp->fish, x, y);
			if (comp->map[iter][iter2] == 'E')
				mlx_put_image_to_window(comp->mlx, comp->win, comp->exit, x, y);
			if (comp->map[iter][iter2] == 'P')
			{
				comp->pp_index[0] = y;
				comp->pp_index[1] = x;
				comp->pp_line[0] = iter;
				comp->pp_line[1] = iter2;
				mlx_put_image_to_window(comp->mlx, comp->win, comp->player_d, x, y);
			}
			iter2++;
			x += ELEMENT_SIZE;
		}
		y += ELEMENT_SIZE;
		iter++;
    }
}

void    main_game(t_comp *comp, char *map, int *size)
{
	comp->map = ft_split(map, '\n');
	comp->mlx = mlx_init();
	comp->win = mlx_new_window(comp->mlx, 
						(size[0] * ELEMENT_SIZE), (size[1] * ELEMENT_SIZE), "SoLong");
    set_images(comp);
    set_map(comp);

	mlx_hook(comp->win, 17, 0L, deal_key, comp);
	mlx_key_hook(comp->win, deal_key, comp);
    mlx_loop(comp->mlx);
}
