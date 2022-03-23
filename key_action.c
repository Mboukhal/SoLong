/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:08:04 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/23 16:29:22 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


void    key_right(t_comp *comp)
{
		if (comp->map[comp->pp_line[0]][comp->pp_line[1] + 1] == 'E' && comp->count_fish == 0)
			exit_game(comp);
		if (comp->map[comp->pp_line[0]][comp->pp_line[1] + 1] != '1' 
						&& comp->map[(comp->pp_line[0])][comp->pp_line[1] + 1] != 'E')
		{
			mlx_put_image_to_window(comp->mlx, comp->win,
						comp->empty, comp->pp_index[1], comp->pp_index[0]);
			comp->map[comp->pp_line[0]][comp->pp_line[1]] = '0';
			comp->pp_index[1] += ELEMENT_SIZE;
			comp->pp_line[1]++;
			if (comp->map[comp->pp_line[0]][comp->pp_line[1]] == 'C')
			{
				comp->map[comp->pp_line[0]][comp->pp_line[1]] = '0';
				comp->count_fish--;
			}
			comp->map[comp->pp_line[0]][comp->pp_line[1]] = 'P';
			mlx_put_image_to_window(comp->mlx, comp->win, 
						comp->player_d, comp->pp_index[1], comp->pp_index[0]);
		}
}

void    key_left(t_comp *comp)
{
		if (comp->map[comp->pp_line[0]][comp->pp_line[1] - 1] == 'E' && comp->count_fish == 0)
			exit_game(comp);
		if (comp->map[comp->pp_line[0]][comp->pp_line[1] - 1] != '1' 
						&& comp->map[comp->pp_line[0]][comp->pp_line[1] - 1] != 'E')
		{
			mlx_put_image_to_window(comp->mlx, comp->win,
						comp->empty, comp->pp_index[1], comp->pp_index[0]);
			comp->map[(comp->pp_line[0])][comp->pp_line[1]] = '0';
			comp->pp_index[1] -= ELEMENT_SIZE;
			comp->pp_line[1]--;
			if (comp->map[comp->pp_line[0]][comp->pp_line[1]] == 'C')
			{
				comp->map[comp->pp_line[0]][comp->pp_line[1]] = '0';
				comp->count_fish--;
			}
			comp->map[comp->pp_line[0]][comp->pp_line[1]] = 'P';
			mlx_put_image_to_window(comp->mlx, comp->win, 
						comp->player_a, comp->pp_index[1], comp->pp_index[0]);
		}
}

void    key_up(t_comp *comp)
{
		if (comp->map[comp->pp_line[0] - 1][comp->pp_line[1]] == 'E' && comp->count_fish == 0)
			exit_game(comp);
		if (comp->map[comp->pp_line[0] - 1][comp->pp_line[1]] != '1' 
						&& comp->map[comp->pp_line[0] - 1][comp->pp_line[1]] != 'E')
		{
			mlx_put_image_to_window(comp->mlx, comp->win,
						comp->empty, comp->pp_index[1], comp->pp_index[0]);
			comp->map[comp->pp_line[0]][comp->pp_line[1]] = '0';
			comp->pp_index[0] -= ELEMENT_SIZE;
			comp->pp_line[0]--;
			if (comp->map[comp->pp_line[0]][comp->pp_line[1]] == 'C')
			{
				comp->map[comp->pp_line[0]][comp->pp_line[1]] = '0';
				comp->count_fish--;
			}
			comp->map[comp->pp_line[0]][comp->pp_line[1]] = 'P';
			mlx_put_image_to_window(comp->mlx, comp->win, 
						comp->player_w, comp->pp_index[1], comp->pp_index[0]);
		}
}


void    key_down(t_comp *comp)
{
		if (comp->map[comp->pp_line[0] + 1][comp->pp_line[1]] == 'E' && comp->count_fish == 0)
			exit_game(comp);
		if (comp->map[comp->pp_line[0] + 1][comp->pp_line[1]] != '1' 
						&& comp->map[comp->pp_line[0] + 1][comp->pp_line[1]] != 'E')
		{
			mlx_put_image_to_window(comp->mlx, comp->win,
						comp->empty, comp->pp_index[1], comp->pp_index[0]);
			comp->map[comp->pp_line[0]][comp->pp_line[1]] = '0';
			comp->pp_index[0] += ELEMENT_SIZE;
			comp->pp_line[0]++;
			if (comp->map[comp->pp_line[0]][comp->pp_line[1]] == 'C')
			{
				comp->map[comp->pp_line[0]][comp->pp_line[1]] = '0';
				comp->count_fish--;
			}
			comp->map[comp->pp_line[0]][comp->pp_line[1]] = 'P';
			mlx_put_image_to_window(comp->mlx, comp->win, 
						comp->player_s, comp->pp_index[1], comp->pp_index[0]);
		}
}