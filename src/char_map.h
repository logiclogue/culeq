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
Word char_map_get(CharMap self, Memory memory, int x, int y);
void char_map_test(void);

#endif
