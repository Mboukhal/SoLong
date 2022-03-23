/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:10:45 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/15 10:54:29 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (NULL);
	s2len = ft_strlen(s2);
	s1len = ft_strlen(s1);
	str = ft_calloc(s1len + s2len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, s2, s2len + ft_strlcat (str, s1, s1len + 1) + 1);
	return (str);
}
