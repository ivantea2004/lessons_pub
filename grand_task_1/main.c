#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"rand.h"
#include"generate.h"
#include"bubble_sort.h"
#include"shell_sort.h"
#include"heap_sort.h"
#include"test.h"
#include"ui.h"

#define INVALID_ARGS "Invalid arguments. Use -h for help."
#define HELP_MSG "-h Show this text\n"\
"-t Test a sorting algorithm\n" \
"-i Inspect a sorting algorithm\n" \
"-c Compare two sorting algorithms" 

#define SORTS_COUNT 3
#define GENS_COUNT 3
#define CMPS_COUNT 4

sort_t sorts[SORTS_COUNT] = { bubble_sort, heap_sort, shell_sort };
char* sort_names[SORTS_COUNT] = { "bubble sort", "heap sort", "shell sort" };

generator_t gens[GENS_COUNT] = { gen_ascending, gen_descending, gen_rand };
char* gen_names[GENS_COUNT] = { "ascending", "descending", "random" };

comparator_t cmps[CMPS_COUNT] = { less, greater,less_abs, greater_abs };
char* cmp_names[CMPS_COUNT] = { "ascending", "descending", "ascening by absolute valud", "descending by absolute value" };

sort_t* select_sort_dialog(char*name)
{
	size_t index = select_name_dialog(sort_names, SORTS_COUNT, name);
	if(index == NO_SELECT)
		return NULL;
	return sorts + index;
}

generator_t* select_generator_dialog(char*name)
{
	size_t index = select_name_dialog(gen_names, GENS_COUNT, name);
	if(index == NO_SELECT)
		return NULL;
	return gens + index;
}

comparator_t* select_comparator_dialog(char*name)
{
	size_t index = select_name_dialog(cmp_names, CMPS_COUNT, name);
	if(index == NO_SELECT)
		return NULL;
	return cmps + index;
}

int compare_sorts()
{

	sort_t* sort1 = select_sort_dialog("first sort");
	if(!sort1)
		return 1;
	
	sort_t* sort2 = select_sort_dialog("second sort");
	if(!sort2)
		return 1;

	generator_t* gen = select_generator_dialog("how array is generated");
	if(!gen)
		return 1;

	comparator_t* cmp = select_comparator_dialog("how array must be sorted");
	if(!cmp)
		return 1;

	size_t tests_count = select_number_dialog(1, MAX_TESTS + 1, "number of tests");
	if(tests_count == NO_SELECT)
		return 1;

	sort_t run_sorts[2] = { *sort1, *sort2 };
	char* run_sort_names[2] = { sort_names[sort1 - sorts], sort_names[sort2 - sorts] };
	size_t sizes[MAX_TESTS] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

	run_tests(*gen, *cmp, run_sorts, run_sort_names, 2, sizes, tests_count);
	
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

int check_sort()
{
	sort_t* sort = select_sort_dialog("sort to test");
	if(!sort)
		return 1;
	
	generator_t* gen = select_generator_dialog("how array is generated");
	if(!gen)
		return 1;

	comparator_t* cmp = select_comparator_dialog("how array must be sorted");
	if(!cmp)
		return 1;

	size_t size = select_number_dialog(1, 1000000 + 1, "size of array");
	if(size == NO_SELECT)
		return size;

	test_sort(*sort, *gen, *cmp, size);

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
	else if(strcmp(argv[1], "-t") == 0)
		return check_sort();
	else
	{
		printf(INVALID_ARGS"\n");
		return 1;
	}
	
	return 0;
}
