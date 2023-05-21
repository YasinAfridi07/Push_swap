/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:45:43 by yusman            #+#    #+#             */
/*   Updated: 2023/05/21 21:43:15 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->data[0] > a->data[1] && a->data[1] < a->data[2]
		&& a->data[0] < a->data[2])
		sa(a);
	else if (a->data[0] > a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] > a->data[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->data[0] > a->data[1] && a->data[1] < a->data[2]
		&& a->data[0] > a->data[2])
		ra(a);
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] > a->data[2])
	{
		rra(a);
	}
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] < a->data[2])
	{
		sa(a);
		ra(a);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min;

	min = a->data[smallnumber(a)];
	while (min != a->data[0])
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;

	min = a->data[smallnumber(a)];
	while (min != a->data[0])
		ra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
