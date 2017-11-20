/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 20:16:11 by mmpofu            #+#    #+#             */
/*   Updated: 2017/06/06 22:16:13 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*strb;
	char	*stra;

	i = 0;
	stra = (char *)src;
	strb = (char *)dest;
	while (i < n)
	{
		strb[i] = stra[i];
		i++;
	}
	return (strb);
}
