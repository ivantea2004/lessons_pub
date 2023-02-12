#pragma once
#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include<stddef.h>
#include"type.h"
#include"cmp.h"

void shell_sort(Type* arr, size_t size, comparator_t);

#endif SHELL_SORT_H
