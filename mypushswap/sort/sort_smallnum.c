/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:45:43 by yusman            #+#    #+#             */
/*   Updated: 2023/05/14 20:00:19 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	sort_three(t_stack *a)
{
	if (a->data[0] > a->data[1] && a->data[1] < a->data[2]
		&& a->data[0] < a->data[2])
		sa(a);
		// ok
	else if (a->data[0] > a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] > a->data[2])
	{
		sa(a);
		rra(a);
	}
	// ok
	else if (a->data[0] > a->data[1] && a->data[1] < a->data[2]
		&& a->data[0] > a->data[2])
		ra(a);
		//ok
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] > a->data[2])
	{
		rra(a);
	}
	// ok
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] < a->data[2])
	{
		sa(a);
		ra(a);
	}
	// ok
}
#include <stdio.h>

void	sort_four(t_stack *a, t_stack *b)
{
	int min;
	min = a->data[smallnumber(a)];
	while (min != a->data[0])
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int min;
	min = a->data[smallnumber(a)];
	while (min != a->data[0])
		ra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);

}
//5 1 2 3 4