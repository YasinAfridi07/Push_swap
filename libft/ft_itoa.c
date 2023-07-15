/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:49:40 by yusman            #+#    #+#             */
/*   Updated: 2022/12/18 20:02:22 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// max_int function to check if the number is the max value of int
// digits_len function to check how many number we got
// fill_digits
//

#include "libft.h"

static char	*max_int(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
	}
	else
	{
		str = malloc(sizeof(char) * 2);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, "0", 2);
	}
	return (str);
}

static int	digits_len(int num)
{
	int	num_digits;

	num_digits = 0;
	while (num > 0)
	{
		num /= 10;
		num_digits++;
	}
	return (num_digits);
}

static char	*fill_digits(char *str, int num, int num_digits, int is_neg)
{
	int	i;

	i = num_digits + is_neg - 1;
	while (i >= 0)
	{
		str[i--] = num % 10 + '0';
		num /= 10;
	}
	if (is_neg)
		str[0] = '-';
	str[num_digits + is_neg] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		nb;
	char	*str;
	int		i;

	i = 0;
	if (n == 0 || n == -2147483648)
		return (max_int(n));
	else if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	nb = digits_len(n);
	str = malloc(sizeof(char) * (nb + i + 1));
	if (str == NULL)
		return (NULL);
	fill_digits(str, n, nb, i);
	return (str);
}

// int main(void)
// {
// 	printf("%s\n", ft_itoa(-312));
// }
