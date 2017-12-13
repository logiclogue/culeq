#include "memory_map.h"
#include "memory.h"
#include "word.h"
#include "assert.h"

MemoryMap memory_map_new(Word start_address) {
    return (MemoryMap){ start_address };
}

Word memory_map_get(MemoryMap self, Memory memory, int index) {
    return memory_get(memory, self.start_address + index);
}

void memory_map_test(void) {
    Memory memory = memory_new();
    MemoryMap memory_map = memory_map_new(0x4000);

    memory = memory_set(memory, 0x4002, (Word)0xFF00);
    memory = memory_set(memory, 0x4003, (Word)0x00FF);

    assert(memory_map_get(memory_map, memory, 2) == (Word)0xFF00);
    assert(memory_map_get(memory_map, memory, 3) == (Word)0x00FF);
}
