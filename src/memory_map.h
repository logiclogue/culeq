#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include "word.h"
#include "memory.h"

typedef struct MemoryMapTag MemoryMap;

struct MemoryMapTag {
    Word start_address;
};

MemoryMap memory_map_new(Word start_address);
Word memory_map_get(MemoryMap self, Memory memory, int index);
void memory_map_test(void);

#endif
