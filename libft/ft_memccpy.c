/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 20:15:24 by mmpofu            #+#    #+#             */
/*   Updated: 2017/06/06 22:17:06 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*strd;
	char	*strs;

	i = 0;
	strd = (char *)dest;
	strs = (char *)src;
	while (i < n)
	{
		strd[i] = strs[i];
		if ((char)c == strd[i])
			return (&strd[i + 1]);
		i++;
	}
	return (NULL);
}
