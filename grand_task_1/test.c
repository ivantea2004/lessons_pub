#include<stdlib.h>
#include<string.h>
#include"test.h"
#include"sort.h"



void run_tests(generator_t gen, comparator_t cmp, sort_t* sorts, char** sort_names, size_t sorts_count, size_t* sizes, size_t sizes_count)
{
	Type* arrs[MAX_TESTS] = { 0 };
	for (size_t i = 0; i < sizes_count; i++)
	{
		arrs[i] = malloc(sizeof(Type) * sizes[i]);
		gen(arrs[i], sizes[i]);
	}

	for (size_t i = 0; i < sorts_count; i++)
	{
		printf("%s:\n", sort_names[i]);
		for (size_t j = 0; j < sizes_count; j++)
		{
			Type* arr = malloc(sizeof(Type) * sizes[j]);
			memcpy(arr, arrs[j], sizeof(Type) * sizes[j]);

			size_t cmps, swaps;

			execute_sort(sorts[i], arr, sizes[j], cmp, &cmps, &swaps);

			printf("%"PRIuPTR": cmps=%"PRIuPTR", swaps=%"PRIuPTR"\n", sizes[j], cmps, swaps);

			free(arr);
		}
	}

	for (size_t i = 0; i < sizes_count; i++)
		free(arrs[i]);

}

