/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:02:59 by yusman            #+#    #+#             */
/*   Updated: 2023/05/21 21:39:36 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int ac, char **av)
{
	int	bulb;
	int	i;

	bulb = 0;
	i = 1;
	while (i <= ac - 1)
	{
		if (av[i][0])
			bulb++;
		i++;
	}
	if (bulb == 0)
		exit (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		exit (EXIT_SUCCESS);
	check_args(ac, av);
	parsearg(&a, &b, av);
	parsesort(&a, &b);
}
