/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franzu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 00:16:45 by franzu            #+#    #+#             */
/*   Updated: 2021/01/03 00:16:46 by franzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_count(char const *s, char c)
{
    size_t  i;
    size_t  h;
    i = 0;
    h = 0;
    while (s[i])
    {
        if (s[i] == c && s[i] != s[i + 1])
            h++;
        i++;
    }
    return (h);
}
char        **ft_split(char const *s, char c)
{
    char    **strs;
    size_t  word;
    size_t  i;
    i = 0;
    if (!s)
        return (0);
    word = ft_count(s, c);
    strs = (char **)ft_calloc((word + 1), sizeof(char *));
    if (!strs)
        return (0);
    word = 0;
    while (*s)
    {
        if (*s == c)
        {
            s++;
            continue ;
        }
        while (*s != c && *s)
        {
            s++;
            i++;
        }
        strs[word++] = ft_substr(s - i, 0, i);
        i = 0;
    }
    return (strs);
}