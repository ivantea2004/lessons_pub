#include"config.h"

typedef int(*comparator_t)(Type, Type);

size_t get_comparations();
void clear_comparations();

int greater(Type, Type);
int less(Type, Type);
