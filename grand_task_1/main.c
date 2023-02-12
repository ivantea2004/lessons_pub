#include<stdio.h>
#include"config.h"
#include"rand.h"
#include"sort.h"
#include"generate.h"
#include"heap_sort.h"
#include"bubble_sort.h"

int main()
{

	init_rand();

	test_sort(bubble_sort, gen_rand, less_abs, 100);

	return 0;
}
