/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_divide_conquer_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:07:30 by yusman            #+#    #+#             */
/*   Updated: 2023/07/15 21:07:34 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_move(t_psinfo *info, char *f, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_strncmp(f, "rra", 3))
			rra(&info->a);
		else if (!ft_strncmp(f, "rrb", 3))
			rrb(&info->b);
		i++;
	}
}
