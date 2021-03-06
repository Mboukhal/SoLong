/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_analyzer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:45:17 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/24 14:37:25 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	clean_exit(char *msg, char *map)
{
	free(map);
	ft_putstr_fd("ERROR\n\t\033[0;31m", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putendl_fd("\033[0m", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	analize_map(t_comp	*comp, char *map)
{
	int		iter;
	int		i;

	iter = 0;
	i = 0;
	comp->count_fish = 0;
	comp->count_exit = 0;
	comp->count_player = 0;
	comp->map = ft_split(map, '\n');
	while (map[iter])
	{
		if (map[iter] != '1' && map[iter] != '\n' && map[iter] != 'C'
			&& map[iter] != 'P' && map[iter] != 'E' && map[iter] != '0')
			clean_exit("File hase undefined component :(", map);
		if (map[iter] == '\n' && i++ == 0)
			comp->map_size[0] = iter;
		if (map[iter] == 'C')
			comp->count_fish++;
		if (map[iter] == 'E')
			comp->count_exit++;
		if (map[iter] == 'P')
			comp->count_player++;
		iter++;
	}
	comp->map_size[1] = iter / comp->map_size[0];
}

static void	check_component(t_comp *comp, char *map)
{
	if (comp->count_exit != 1)
		clean_exit("Map Need One EXIT :(", map);
	if (comp->count_player != 1)
		clean_exit("Map Need One Player :(", map);
	if (comp->count_fish < 1)
		clean_exit("Map hase no fish :(", map);
}

static void	check_wall(char *map, t_comp *comp)
{
	int	iter;
	int	len;
	int	last_char;

	iter = 0;
	while (map[iter] != '\n')
		if (map[iter++] != '1')
			clean_exit("Wall has hol :(", map);
	last_char = 0;
	len = 0;
	while (map[last_char])
	{
		if (map[last_char++] == '\n' || len > comp->map_size[0])
		{
			len = 0;
			if (!(map[last_char - 2] == '1' && map[last_char] == '1'))
				clean_exit("Wall has hol in vertical sides :(", map);
		}
		len++;
	}
	len = last_char - iter;
	while (map[len])
		if (map[len++] != '1')
			clean_exit("Wall has hol or (\\n) in the end :(", map);
}

void	checks_and_start(char *map)
{
	t_comp	components;

	analize_map(&components, map);
	if (components.map_size[0] < 3)
		clean_exit("At lest need 3 colume :(", map);
	check_wall(map, &components);
	check_component(&components, map);
	main_game(&components, map);
	free(map);
}
