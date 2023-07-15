/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:33:31 by yusman            #+#    #+#             */
/*   Updated: 2022/12/18 16:46:00 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] != '\0')
	{
		n = 0;
		while (haystack[i + n] == needle[n] && (i + n) < len)
		{
			if (haystack[i + n] == '\0' && needle[n] == '\0')
				return ((char *)&haystack[i]);
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 		char *hay = "abcdef";
// 		char *ne = "cdef";
// 		printf("%s\n", ft_strnstr(hay, ne, 5));
// 		printf("%s", strnstr(hay, ne , 5));
// }
