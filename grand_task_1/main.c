#include<stdio.h>
#include<stdlib.h>
#include"rand.h"
#include"generate.h"
#include"bubble_sort.h"
#include"shell_sort.h"
#include"heap_sort.h"
#include"test.h"

#define SORTS_COUNT 3

sort_t sorts[SORTS_COUNT] = { bubble_sort, heap_sort, shell_sort };
char* sort_names[SORTS_COUNT] = { "bubble sort", "heap sort", "shell sort" };

#define GENS_COUNT 3

generator_t gens[GENS_COUNT] = { gen_ascending, gen_descending, gen_rand };
char* gen_names[GENS_COUNT] = { "ascending", "descending", "random" };

#define CMPS_COUNT 4

comparator_t cmps[CMPS_COUNT] = { less, greater,less_abs, greater_abs };
char* cmp_names[CMPS_COUNT] = { "less", "greater", "less by abs", "greater by abs" };

#define NO_SELECT UINT64_MAX

size_t select_dialog(char** items_names, size_t items_count, char*name)
{
	printf("Select %s\n", name);
	for (size_t i = 0; i < items_count; i++)
		printf("%"PRIuPTR":%s\n", i + 1, items_names[i]);
	size_t i;
	
	if (scanf("%"SCNuPTR, &i) != 1 || i < 1 || i > items_count)
	{
		printf("Invalid answer\n");
		return NO_SELECT;
	}
	return i - 1;
}

int main()
{

	init_rand();
	
	size_t sort1 = select_dialog(sort_names, SORTS_COUNT, "first sort");
	if (sort1 == NO_SELECT)
		return 1;

	size_t sort2 = select_dialog(sort_names, SORTS_COUNT, "second sort");
	if (sort2 == NO_SELECT)
		return 1;
	size_t gen = select_dialog(gen_names, GENS_COUNT, "generator");
	if (gen == NO_SELECT)
		return 1;
	size_t cmp = select_dialog(cmp_names, CMPS_COUNT, "comparator");
	if (cmp == NO_SELECT)
		return 1;

	sort_t run_sorts[2] = { sorts[sort1], sorts[sort2] };
	char* run_sort_names[2] = { sort_names[sort1], sort_names[sort2] };
	size_t sizes[] = { 10, 100, 1000, 10000 };

	run_tests(gens[gen], cmps[cmp], run_sorts, run_sort_names, 2, sizes, 4);
	
	return 0;
}
