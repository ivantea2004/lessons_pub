#pragma once
#ifndef ARRAY_IO_H
#define ARRAY_IO_H

#include<stdio.h>
#include<stddef.h>
#include"type.h"

void read_arr(Type* arr, size_t size);
void write_arr(Type* arr, size_t size);

#endif
