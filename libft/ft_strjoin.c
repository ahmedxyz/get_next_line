/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:26:45 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/09 16:39:04 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*js;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	js = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!js)
		return (NULL);
	i = 0;
	while (*s1)
	{
		js[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		js[i] = *s2;
		i++;
		s2++;
	}
	js[i] = '\0';
	return (js);
}
