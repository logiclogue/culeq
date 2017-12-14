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

Memory memory_load(Memory self, Word address, Word words[], int length) {
    for (int i = 0; i < length; i += 1) {
        self = memory_set(self, address + i, words[i]);
    }

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

    Word words[] = {
        0x0011, 0x0123
    };

    int words_len = 2;

    memory = memory_load(memory, 0x42, words, words_len);

    assert(memory_get(memory, 0x42) == words[0]);
    assert(memory_get(memory, 0x43) == words[1]);
}
