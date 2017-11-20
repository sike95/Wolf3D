/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 20:16:37 by mmpofu            #+#    #+#             */
/*   Updated: 2017/07/24 07:41:54 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tempd;
	char	*temps;

	tempd = (char *)dest;
	temps = (char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			tempd[n] = temps[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
