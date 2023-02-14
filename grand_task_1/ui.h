#pragma once
#ifndef UI_H
#define UI_H

#include<stddef.h>
#include<stdint.h>

#define NO_SELECT INTPTR_MAX
#define INVALID_IN "Invalid answer"

size_t select_name_dialog(char** items_names, size_t items_count, char* name);
int64_t select_number_dialog(int64_t begin, int64_t end, char* name);

#endif 
