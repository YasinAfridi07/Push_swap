/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:08:32 by yusman            #+#    #+#             */
/*   Updated: 2023/07/15 21:11:02 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free (str);
}

void	free_all(t_stack *a, t_stack *b, int flag)
{
	free(a->data);
	free(b->data);
	if (flag == 0)
		exit(EXIT_FAILURE);
	else if (flag == 1)
		exit(EXIT_SUCCESS);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	free_data(t_stack *a, t_stack *b, int flag)
{
	if (b->data[0] == -1)
	{
		free(a->data);
		free(b->data);
		exit(flag);
	}
}
