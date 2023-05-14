/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:02:47 by yusman            #+#    #+#             */
/*   Updated: 2023/05/14 21:00:04 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free (str);
}

void free_all(t_stack *a, t_stack *b, int flag)// changed
{
	free(a->data);
	free(b->data);
//	free(chunk->data);
	if(flag == 0)
		exit(EXIT_FAILURE);
	else if (flag == 1)
		exit(EXIT_SUCCESS);
}

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// void	init_chunk(t_stack *a, t_stack *chunk)
// {
// 	chunk->data = sort_chunk(a);
// 	chunk->top = a->top;
// }

void	free_data(t_stack *a, t_stack *b, int flag)
{
	if (b->data[0] == -1)
	{
		free(a->data);
		free(b->data);
		exit(flag);
	}
}
