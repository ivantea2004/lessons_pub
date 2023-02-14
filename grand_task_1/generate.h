#pragma once
#ifndef GENERATE_H
#define GENERATE_H

#include<stddef.h>
#include"type.h"

typedef void(*generator_t)(Type* arr, size_t size);

void gen_ascending(Type* arr, size_t size);
void gen_descending(Type* arr, size_t size);
void gen_rand(Type* arr, size_t size);

#endif
