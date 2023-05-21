

#include <../push_swap.h>

int *return_ind(t_stack *a, t_stack *chunk)
{
	int	div;
	int	*chunk_indecies;
	int	i;
	int	temp;

	i = CHUNK_SIZE - 1;
	div = a->data[0] / CHUNK_SIZE;
	temp = div;
	chunk_indecies = malloc(CHUNK_SIZE * sizeof(int));
	while (i >= 0)
	{
		chunk_indecies[i] = chunk->data[div];
		div += temp;
		i--;
	}
	return (chunk_indecies);
}

void    push_2_b(t_stack *a, t_stack *b, int *sorted)
{
int	i;
	int	d;
	int	mid;
	int	chunk_limit;

	i = 1;
	d = 0;
	mid = a->data[0] / 4;
	chunk_limit = (a->data[0] / CHUNK_SIZE) - 1;
	while (a->data[0] >= 0 && i < CHUNK_SIZE)
	{
		if (a->data[a->data[0]] < sorted[i])
		{
			pb(a, b);
			ps_optimizoor(b, mid);
			d++;
		}
		else
			ra(a);
		if (d >= chunk_limit)
		{
			d = 0;
			i++;
		}
	}
    
}

void	clean_push_back(t_stack *a, t_stack *b)
{
	while (a->data[0] >= 0)
		pb(a, b);
	while (b->data[0] >= 0)
		ps_push_back(a, b, ps_compare(b));
}




void chunk_sort(t_stack *a, t_stack *b, t_stack *chunk)
{
    int *sorted; // int array

    initchunk(a, chunk); // returning an array(malloced)called list 
    sorted = return_ind(a, chunk); // pic taken in phone
    push_2_b(a, b, sorted);
    clean_push_back(a, b);
    free(sorted);
    free_all(a, b, chunk, 0);

}