#include"swap.h"

static size_t swaps = 0;

void inc_swaps()
{
	swaps++;
}

void clear_swaps()
{
	swaps = 0;
}

size_t get_swaps()
{
	return swaps;
}

void swap(Type*a, Type*b)
{
	inc_swaps();
	Type tmp = *a;
	*a = *b;
	*b = tmp;
}
