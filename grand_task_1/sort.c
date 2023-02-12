#include<stdlib.h>
#include"sort.h"
#include"array_io.h"
#include"swap.h"

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
	size_t cmps, swaps;

	Type* arr = malloc(sizeof(Type) * size);

	gen(arr, size);
	printf("Generated array:\n");
	write_arr(arr, size);
	execute_sort(sort, arr, size, cmp, &cmps, &swaps);
	printf("\nSorted array:\n");
	write_arr(arr, size);

	int ok = 1;
	for (size_t i = 1; i < size; i++)
		if (cmp(arr[i - 1], arr[i]) > 0)
			ok = 0;
	free(arr);

	if (ok)
		puts("\nSorted");
	else 
		puts("\nNot sorted");
	
	printf("Swaps: %"PRIuPTR", Cmps: %"PRIuPTR"\n", swaps, cmps);

}
