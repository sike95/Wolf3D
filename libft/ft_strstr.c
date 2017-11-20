/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 00:42:58 by mmpofu            #+#    #+#             */
/*   Updated: 2017/08/31 14:40:48 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int x;
	int y;

	x = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[x] != '\0')
	{
		y = 0;
		while (big[x + y] == little[y])
		{
			y++;
			if (little[y] == '\0')
				return ((char *)big + x);
		}
		x++;
	}
	return (NULL);
}
