

#include "../push_swap.h"

void	chunk_sort(t_stack *a, t_stack *b)
{
	t_setinfo	*setinfo;
	t_psinfo	info;

	info.a = *a;
	info.b = *b;
	setinfo = create_sets(&info, 15);
	divide_conquer(&info, setinfo, 20);
	free_sets(setinfo);
}