#include <assert.h>
#include "char_map.h"

CharMap char_map_new(Word start_address, int width, int height) {
    return (CharMap){ start_address, width, height };
}

char char_map_get_char(CharMap self, Memory memory, int i) {
    return memory_get(memory, self.start_address + i);
}

char char_map_get_char_by_coords(CharMap self, Memory memory, int x, int y) {
    return memory_get(memory, self.start_address + x + (y * self.width));
}

void char_map_test(void) {
    Memory memory = memory_new();
    CharMap char_map = char_map_new(0x3000, 16, 6);

    memory_set(memory, 0x3000, (Word)'J');
    memory_set(memory, 0x3001, (Word)'o');
    memory_set(memory, 0x3010, (Word)'r');

    assert(char_map_get_char(char_map, memory, 0) == (Word)'J');
    assert(char_map_get_char(char_map, memory, 1) == (Word)'o');
    assert(char_map_get_char_by_coords(char_map, memory, 0, 0) == (Word)'J');
    assert(char_map_get_char_by_coords(char_map, memory, 0, 1) == (Word)'r');
}
