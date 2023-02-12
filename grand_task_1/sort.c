#include"sort.h"
#include"array_io.h"
#include"swap.h"
#include<stdlib.h>

void execute_sort(sort_t sort, Type* arr, size_t size, comparator_t cmp, size_t* cmps, size_t* swaps)
{
	clear_comparations();
	clear_swaps();
	sort(arr, size, cmp);
	if (cmps)
		*cmps = get_comparations();
	if (swaps)
		*swaps = get_swaps();
}

void test_sort(sort_t sort, generator_t gen, comparator_t cmp, size_t size)
{

	Type* arr = malloc(sizeof(Type) * size);

	gen(arr, size);
	printf("Generated array:\n");
	write_arr(arr, size);
	execute_sort(sort, arr, size, cmp, NULL, NULL);
	printf("Sorted arrays:\n");
	write_arr(arr, size);
	free(arr);
}
