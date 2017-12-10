#ifndef MEMORY_H
#define MEMORY_H

#include "Word.h"

typedef struct MemoryTag Memory;
struct MemoryTag;

Memory memory_new(void);
void memory_destroy(Memory self);
Memory memory_set(Memory self, Word address, Word value);
Word memory_get(Memory self, Word address);

void memory_test(void);

#endif
