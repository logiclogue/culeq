#include <assert.h>
#include "char_map.h"

CharMap char_map_new(Word start_address, int width, int height) {
    return (CharMap){ start_address, width, height };
}

Word char_map_get_word(CharMap self, Memory memory, int x, int y) {
    return memory_get(memory, self.start_address + x + (y * self.width));
}

char char_map_get_char(CharMap self, Memory memory, int x, int y) {
    Word word = char_map_get_word(self, memory, x, y);

    return word & 0xFF;
}

int char_map_get_foreground(CharMap self, Memory memory, int x, int y) {
    Word word = char_map_get_word(self, memory, x, y);

    return (word & 0xF000) >> 12;
}

int char_map_get_background(CharMap self, Memory memory, int x, int y) {
    Word word = char_map_get_word(self, memory, x, y);

    return (word & 0x0F00) >> 8;
}

void char_map_test(void) {
    Memory memory = memory_new();
    CharMap char_map = char_map_new(0x3000, 16, 6);

    memory_set(memory, 0x3000, (Word)'J');
    memory_set(memory, 0x3001, (Word)'o');
    memory_set(memory, 0x3010, 0x1200 + (Word)'r');

    assert(char_map_get_word(char_map, memory, 0, 0) == 'J');
    assert(char_map_get_word(char_map, memory, 0, 1) == 0x1200 + 'r');
    assert(char_map_get_char(char_map, memory, 0, 1) == 'r');
    assert(char_map_get_foreground(char_map, memory, 0, 1) == 1);
    assert(char_map_get_background(char_map, memory, 0, 1) == 2);
}
