#ifndef MEMORY_H
#define MEMORY_H

#include "word.h"
#include <stdio.h>

typedef struct MemoryTag Memory;

struct MemoryTag {
    Word *array;
    long size;
};

Memory memory_new(void);
void memory_destroy(Memory self);
Memory memory_set(Memory self, Word address, Word value);
Word memory_get(Memory self, Word address);
Memory memory_load(Memory self, Word address, Word words[], int length);
Memory memory_load_from_file(Memory self, FILE *file);

void memory_test(void);

#endif
