#include<stdio.h>
#include<inttypes.h>
#include"ui.h"


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

int64_t select_number_dialog(int64_t begin, int64_t end, char *name)
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
