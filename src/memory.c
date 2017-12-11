#include "memory.h"
#include "word.h"
#include <assert.h>
#include <stdlib.h>

Memory memory_new(void) {
    long size = 1 << (sizeof(Word) * 8);
    Word *array = malloc(size * sizeof(Word));

    return (Memory){ array, size };
}

void memory_destroy(Memory self) {
    free(self.array);
}

Memory memory_set(Memory self, Word address, Word value) {
    self.array[address] = value;

    return self;
}

Word memory_get(Memory self, Word address) {
    return self.array[address];
}

void memory_test(void) {
    Memory memory = memory_new();

    assert(memory.size == 65536);

    memory = memory_set(memory, 400, 42);

    assert(memory_get(memory, 400) == 42);
}
