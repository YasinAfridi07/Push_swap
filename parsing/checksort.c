/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:14:30 by yusman            #+#    #+#             */
/*   Updated: 2023/07/15 21:10:20 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble(int *list, int top)
{
	int	j;
	int	i;

	i = 0;
	while (i < top)
	{
		j = 0;
		while (j < top - i)
		{
			if (list[j] < list[j + 1])
				swap(&list[j], &list[j + 1]);
			j++;
		}
		i++;
	}
}

int	*sort_chunk(t_stack *a)
{
	int	*list;
	int	i;

	i = 0;
	list = malloc((a->data[0] + 1) * sizeof(int));
	while (i++ <= a->data[0])
		list[i] = a->data[i];
	bubble(list, a->data[0]);
	return (list);
}

void	parsesort(t_stack *a, t_stack *b)
{
	b->flag = 0;
	if (a->size == 1 || issorted(a->data, a->size))
		free_all(a, b, 1);
	else if (a->size == 2)
	{
		if (a->data[0] > a->data[1])
			sa(a);
		free_data(a, b, 0);
	}
	else if (a->size == 3)
	{
		sort_three(a);
		free_data(a, b, 0);
	}
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		chunk_sort(a, b);
}

void	print_stack(t_stack *stk)
{
	int	i;

	i = 0;
	while (i < stk->size)
	{
		printf("%d\n", stk->data[i]);
		i++;
	}
	return ;
}
