/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:24:04 by yusman            #+#    #+#             */
/*   Updated: 2022/12/18 19:56:24 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dstr;
	char	*srcr;

	dstr = (char *)dst;
	srcr = (char *)src;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (n--)
		{
			dstr[n] = srcr[n];
		}
		return (dst);
	}
	else
	{
		while (n--)
		{
			*dstr++ = *srcr++;
		}
		return (dst);
	}
}
