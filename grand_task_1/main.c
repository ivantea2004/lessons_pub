#include<stdio.h>
#include"sort.h"
#include"generate.h"
#include"bubble_sort.h"
#include"shell_sort.h"

int main()
{

	init_rand();

	test_sort(shell_sort, gen_rand, less_abs, 10);

	return 0;
}
