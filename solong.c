/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:32:00 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/22 20:51:44 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	check_lines(int iter, int fd)
{
	if (iter > 1850)
	{
		close(fd);
		ft_putstr_fd("ERROR\n\t\033[0;31mMap to lang more then (31) element :(\033[0m\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	read_all_check_size(int fd, char *tmp, int *iter, char *file)
{
	int size;
	int	i;

	i = 0;
	size = 1;
	while (size != 0)
	{
		size = read(fd, &tmp[(*iter)], 1);
		if (size == -1)
		{
			perror(file);
			exit (EXIT_FAILURE);
		}
		if (tmp[(*iter)] == '\n' && i++ == 0)
		{
			if ((*iter) > 57)
			{
				close(fd);
				ft_putstr_fd("ERROR\n\t\033[0;31mMap to lang more then (57) element :(\033[0m\n", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
		}
		check_lines((*iter)++, fd);
	}
}

					/*
						get file in dynamic memo
						and check game full size TODO (2000)
						max size TODO
						x = 57 * y = 31
					*/
char	*gfile(int fd, char *file)
{
	char	tmp[1900];
	char	*str;
	int		iter;
	int		size;

	iter = 0;
	read_all_check_size(fd, tmp, &iter, file);
	str = malloc(sizeof(char) * iter);
	if (!str)
		return(NULL);
	size = 0;
	while (size < iter)
	{
		str[size] = tmp[size];
		size++;
	}
	str[iter - 1] = '\0';
	close(fd);
	return (str);
}

static void	check_exteniton(char *file)
{
	int	iter;

	iter = 0;
	while (file[iter])
	{
		if ((file[iter] == '.' && file[iter + 4] == '\0') || file[iter + 1] == '\0')
		{
			if (ft_strncmp(&file[iter], ".ber", 4) || file[iter + 1] == '\0')
			{
				ft_putstr_fd("ERROR\n\t\033[0;31m", STDERR_FILENO);
				ft_putstr_fd(file, STDERR_FILENO);
				ft_putstr_fd(": is not a \".ber\" file :(\033[0m\n", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			else
				break ;
		}
		iter++;
	}
}

					/*
						main :
							1 - check args
							2 - check extention
							3 - open file
							4 - file check and start game 
					*/
int	main(int ac, char **av)
{
	int	fd;

	errno = 0;
	if (ac != 2)
	{
		ft_putstr_fd("ERROR\n\t\033[0;31mNeed map file :(\033[0m\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	check_exteniton(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror (av[1]);
		return (EXIT_FAILURE);
	}
	checks_and_start(gfile(fd, av[1]));
	return (EXIT_SUCCESS);
}
