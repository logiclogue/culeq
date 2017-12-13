#ifndef CHAR_MAP_H
#define CHAR_MAP_H

#include "word.h"
#include "memory.h"

typedef struct CharMapTag CharMap;

struct CharMapTag {
    Word start_address;
    int width;
    int height;
};

CharMap char_map_new(Word start_address, int width, int height);
char char_map_get_char(CharMap self, Memory memory, int i);
char char_map_get_char_by_coords(CharMap self, Memory memory, int x, int y);
void char_map_test(void);

#endif
