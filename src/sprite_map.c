#include "sprite_map.h"
#include "memory.h"
#include "word.h"
#include "assert.h"

SpriteMap sprite_map_new(Word start_address) {
    SpriteMap self;

    self.start_address = start_address;

    return self;
}

Word sprite_map_top_block(SpriteMap self, Memory memory, int index) {
    return memory_get(memory, self.start_address + (2 * index));
}

Word sprite_map_bottom_block(SpriteMap self, Memory memory, int index) {
    return memory_get(memory, self.start_address + (2 * index) + 1);
}

void sprite_map_test(void) {
    Word sprite_memory_address = 0x4000;
    Memory memory = memory_new();
    SpriteMap sprite_map = sprite_map_new(sprite_memory_address);

    memory = memory_set(memory, 0x4002, 0xFF00);
    memory = memory_set(memory, 0x4003, 0x00FF);

    assert(sprite_map_top_block(sprite_map, memory, 1) == (Word)0xFF00);
    assert(sprite_map_bottom_block(sprite_map, memory, 1) == (Word)0x00FF);
}
