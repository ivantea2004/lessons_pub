#include<stdio.h>
#include"sort.h"
#include"generate.h"
#include"bubble_sort.h"

int main()
{

	init_rand();

	test_sort(bubble_sort, gen_rand, less_abs, 100);

	return 0;
}
