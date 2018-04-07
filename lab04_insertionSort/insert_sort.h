#ifndef __INSERT_SORT_H
#define __INSERT_SORT_H
#include "bank.h"

void insertInOrder(record *init, int current_index);
void recursive_isort(record *init, int start, int end);
#endif
