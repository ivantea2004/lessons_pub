#pragma once
#ifndef INSPECT_H
#define INSPECT_H

#include<stddef.h>
#include"type.h"

void inspect_init(Type* arr, size_t size);
void inspect_log();
void inspect_set_enabled();
int inspect_is_enabled();

#endif
