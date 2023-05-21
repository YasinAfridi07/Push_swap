/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_divide_conquer_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:09 by fkhan             #+#    #+#             */
/*   Updated: 2023/05/21 23:52:23 by fkhan            ###   ########.fr       */
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
