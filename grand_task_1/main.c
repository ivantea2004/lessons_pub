#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"rand.h"
#include"generate.h"
#include"bubble_sort.h"
#include"shell_sort.h"
#include"heap_sort.h"
#include"test.h"

#define INVALID_ARGS "Invalid arguments. Use -h for help."
#define INVALID_IN "Invalid answer"
#define HELP_MSG "-h Show this text\n"\
"-i Inspect a sorting algorithm\n" \
"-c Compare two sorting algorithms" 

#define NO_SELECT INT64_MAX

#define SORTS_COUNT 3
#define GENS_COUNT 3
#define CMPS_COUNT 4

sort_t sorts[SORTS_COUNT] = { bubble_sort, heap_sort, shell_sort };
char* sort_names[SORTS_COUNT] = { "bubble sort", "heap sort", "shell sort" };

generator_t gens[GENS_COUNT] = { gen_ascending, gen_descending, gen_rand };
char* gen_names[GENS_COUNT] = { "ascending", "descending", "random" };

comparator_t cmps[CMPS_COUNT] = { less, greater,less_abs, greater_abs };
char* cmp_names[CMPS_COUNT] = { "less", "greater", "less by abs", "greater by abs" };


size_t select_name_dialog(char** items_names, size_t items_count, char*name)
{
	printf("Select %s\n", name);
	for (size_t i = 0; i < items_count; i++)
		printf("%"PRIuPTR":%s\n", i + 1, items_names[i]);
	size_t i;
	
	if (scanf("%"SCNuPTR, &i) != 1 || i < 1 || i > items_count)
	{
		printf(INVALID_IN"\n");
		return NO_SELECT;
	}
	return i - 1;
}

int64_t select_range_dialog(int64_t begin, int64_t end, char *name)
{
	printf("Select %s (from %"PRIi64" to %"PRIi64")\n", name, begin, end - 1);
	int64_t answer;
	if(scanf("%"SCNi64, &answer) != 1 || !(answer >= begin && answer < end))
	{
		printf(INVALID_IN"\n");
		return NO_SELECT;
	}
	return answer;
}

int compare_sorts()
{
	size_t sort1 = select_name_dialog(sort_names, SORTS_COUNT, "first sort");
	if (sort1 == NO_SELECT)
		return 1;

	size_t sort2 = select_name_dialog(sort_names, SORTS_COUNT, "second sort");
	if (sort2 == NO_SELECT)
		return 1;
	size_t gen = select_name_dialog(gen_names, GENS_COUNT, "generator");
	if (gen == NO_SELECT)
		return 1;
	size_t cmp = select_name_dialog(cmp_names, CMPS_COUNT, "comparator");
	if (cmp == NO_SELECT)
		return 1;

	size_t tests_count = select_range_dialog(1, MAX_TESTS + 1, "number of tests");
	if(tests_count == NO_SELECT)
		return 1;

	sort_t run_sorts[2] = { sorts[sort1], sorts[sort2] };
	char* run_sort_names[2] = { sort_names[sort1], sort_names[sort2] };
	size_t sizes[MAX_TESTS] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

	run_tests(gens[gen], cmps[cmp], run_sorts, run_sort_names, 2, sizes, tests_count);
	return 0;
}

int print_help()
{
	printf(HELP_MSG"\n");
	return 0;
}

int inspect_sort()
{
	return 0;
}

int main(int argc, char**argv)
{

	init_rand();
	
	if(argc <= 1)
		return compare_sorts();
	
	if(argc > 2)
	{
		printf(INVALID_ARGS"\n");
		return 1;
	}

	if(strcmp(argv[1], "-h") == 0)
		return print_help();
	else if(strcmp(argv[1], "-c") == 0)
		return compare_sorts();
	else if(strcmp(argv[1], "-i") == 0)
		return inspect_sort();
	else
	{
		printf(INVALID_ARGS"\n");
		return 1;
	}
	
	return 0;
}
