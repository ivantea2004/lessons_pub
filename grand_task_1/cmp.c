#include"cmp.h"

static size_t cmps = 0;

void inc_comparations()
{
	cmps++;
}

void clear_comparations()
{
	cmps = 0;
}

size_t get_comparations()
{
	return cmps;
}

int less(Type a, Type b)
{
	inc_comparations();
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
		return 0;
}

int greater(Type a, Type b)
{
	inc_comparations();
	if (a < b)
		return 1;
	else if (a > b)
		return -1;
	else
		return 0;
}
