/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:47:07 by yusman            #+#    #+#             */
/*   Updated: 2023/05/14 18:43:46 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*data;
	int size;
	int flag;
}	t_stack;

# define CHUNK_SIZE 9

void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	swap(int *a, int *b);

int	smallnumber(t_stack *a);
int	bignumber(t_stack *stack);
int	secound(t_stack *stack);
int	isdigit(int c);
char	*argcheck(char **av);
void	letters(char *args);
void	free_split(char **str);
void	free_all(t_stack *a, t_stack *b, int flag);
void	free_data(t_stack *a, t_stack *b, int flag);
void	swap(int *a, int *b);
// void	init_chunk(t_stack *a, t_stack *chunk);
int		ps_atoi(char *str, t_stack *a, t_stack *b, char **new_av);
void	is_dup(t_stack *a, t_stack *b);
void	is_sorted(t_stack *a, t_stack *b);
void	sign_check2(char *str, t_stack *a, t_stack *b, char **new_av);
void	sign_check(char *str, t_stack *a, t_stack *b, char **new_av);
void	refactor_ac(t_stack *a, t_stack *b, char **av);
void	parsearg(t_stack *a, t_stack *b, char **av);
void	parsesort(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
int		second(t_stack *stack);
void	swapper(t_stack *a);
int		ps_compare(t_stack *b);
void	swapper(t_stack *a);
void	push_back(t_stack *a, t_stack *b, int index);
void	print_stack(t_stack *stk);
// int	*sort_chunk(t_stack *a);
void	bubble(int *list, int top);

#endif
