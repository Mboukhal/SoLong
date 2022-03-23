/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:26 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/19 16:32:52 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

				// string serch first {c} in {s}
char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	size_t		str_len;
	char		*str;

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	str = (char *)s;
	while (i <= str_len)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
