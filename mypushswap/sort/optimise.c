#include "../push_swap.h"

void	ps_optimizoor(t_stack *b, int mid)
{
	if (b->data[0] > 0 && b->data[b->data[0]] < mid)
		rb(b);
}

void	ps_swapper(t_stack *a)
{
	if (a->data[0] > 0)
	{
		if (a->data[a->data[0]] > a->data[a->data[0] - 1])
			sa(a);
	}
}

int	ps_compare(t_stack *b)
{
	int	mid;
	int	first;
	int	second;

	first = ps_numlarge(b);
	second = ps_second(b);
	mid = b->data[0] / 2;
	if (b->flag == 0)
	{
		b->flag = 1;
		if (first > mid && second > mid && second > first)
			return (second);
		else if (first <= mid && second <= mid && second < first)
			return (second);
		else if (first <= mid && second > mid && b->data[0] - second < first)
			return (second);
		else if (first <= mid && second > mid && (b->data[0] - second) + 1 < first)
			return (second);
		else if (first > mid && second <= mid && (b->data[0] - first) + 1 > second)
			return (second);
	}
	b->flag = 0;
	return (first);
}
