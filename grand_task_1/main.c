#include<stdio.h>
#include"rand.h"
#include"sort.h"
#include"generate.h"
#include"bubble_sort.h"
#include"shell_sort.h"

int main()
{

	init_rand();

	test_sort(shell_sort, gen_rand, less, 10);

	return 0;
}
