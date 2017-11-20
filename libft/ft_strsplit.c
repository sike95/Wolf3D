/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 06:45:03 by mmpofu            #+#    #+#             */
/*   Updated: 2017/08/24 18:02:50 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *str, char c)
{
    int death;
    int	v;
    
    v = 0;
    death = 0;
    while (str[v])
    {
        while (str[v] == c)
            v++;
        if (str[v] != c && str[v] != '\0')
            death++;
        while (str[v] != c && str[v] != '\0')
            v++;
    }
    return (death);
}

static int	word(char const *str, char c)
{
    int	a;
    int	l;
    
    a = 0;
    l = 0;
    while (str[a] == c)
        a++;
    while (str[a] != c && str[a] != '\0')
    {
        a++;
        l++;
    }
    return (l);
}

char		**ft_strsplit(char const *s, char c)
{
    int		x;
    int		y;
    int		z;
    char	**str2;
    
    if (!s || !(str2 = (char **)malloc(sizeof(*str2) *
                                       (ft_countwords(s, c) + 1))))
        return (NULL);
    x = -1;
    y = 0;
    while (++x < ft_countwords(s, c))
    {
        z = 0;
        if (!(str2[x] = ft_strnew(word(&s[y], c) + 1)))
            str2[x] = NULL;
        while (s[y] == c)
            y++;
        while (s[y] != c && s[y])
            str2[x][z++] = s[y++];
        str2[x][z] = '\0';
    }
    str2[x] = 0;
    return (str2);
}
