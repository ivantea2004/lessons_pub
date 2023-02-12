#include<stdio.h>
#include"sort.h"
#include"generate.h"
#include"bubble_sort.h"

int main()
{

	init_rand();

	test_sort(bubble_sort, gen_descending, less_abs, 10);

	return 0;
}
