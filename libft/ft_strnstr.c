/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 23:33:51 by mmpofu            #+#    #+#             */
/*   Updated: 2017/06/09 15:29:36 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		x;
	size_t	y;

	x = 0;
	y = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[x] != '\0' && len > 0)
	{
		if (big[x] == little[y])
		{
			y++;
			if (little[y] == '\0')
				break ;
		}
		len--;
		x++;
	}
	if (ft_strlen(little) == y)
	{
		y = x - (ft_strlen(little) - 1);
		return ((char *)big + y);
	}
	return (NULL);
}
