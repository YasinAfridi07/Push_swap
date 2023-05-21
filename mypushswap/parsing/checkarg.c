/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 07:14:32 by yusman            #+#    #+#             */
/*   Updated: 2023/05/14 20:58:47 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*argcheck(char **av)
{
	int		i;
	int		j;
	int		k;
	char	*args;

	i = 1;
	j = 0;
	while (av[i])
		j = j + ft_strlen(av[i++]);
	args = malloc(j + i - 1);
	i = 1;
	j = 0;
	while (av[i])
	{
		k = 0;
		while (av[i][k])
			args[j++] = av[i][k++];
		if (av[i + 1])
			args[j++] = ' ';
		i++;
	}
	args[j] = '\0';
	return (args);
}
// 100 3 2 4 5

int	is_digit(int c)
{
	// printf("%c --- %d\n", c, c);
	if (!((c >= '0' && c <= '9') || (c == ' ') || c == '-' || c == '+'))
		return (1);
	return (0);
}

void letters(char *args)
{
	int i;

	i = 0;
	while (args[i])
	{
		if (is_digit(args[i]))
		{
			free(args);
			ft_putstr_fd("1. Error\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
void	refactor_ac(t_stack *a, t_stack *b, char **av)
{
	char *args; // Combine arguments into a single string
	char **new_av; // Split the string into an array of strings
	int len;
	int i;

	args = argcheck(av);
	letters(args); // Check if string contains only digits, spaces, and signs (+/-)
	new_av = ft_split(args, ' ');
	free(args); // Free the combined string
	len = 0;
	while (new_av[len]) // Get the length of the array
		len++;
	a->size = len;
	b->size = 0;
	a->data = malloc(sizeof(int) * len); // Allocate memory for stack A
	b->data = malloc(sizeof(int) * len); // Allocate memory for stack B
	i = 0;
	while (i < len) // Convert the array of strings to integers and push onto stack A
	{
		a->data[i] = ps_atoi(new_av[i], a, b, new_av);
		i++;
	}
	free_split(new_av); // Free the array of strings
}
// 100 1 2
void	parsearg(t_stack *a, t_stack *b, char **av)
{
	refactor_ac(a, b, av);
	is_sorted(a, b);
	is_dup(a, b);
}
