/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:18:40 by yusman            #+#    #+#             */
/*   Updated: 2022/12/18 22:37:31 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	msize;
	char	*str;

	if (!s)
		return (NULL);
	msize = ft_strlen(&s[start]);
	if (len > msize)
		len = msize;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	size = ft_strlen(s);
	i = start;
	j = 0;
	while (i < size && j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}

// int main ()
// {
// 		char *sub = ft_substr("tripouille", 0, 42000);
// 		printf("%s\n", sub);
// 		*sub = substring("tripouille", 0, 42000);
// 		printf("%s\n", sub);
// }
