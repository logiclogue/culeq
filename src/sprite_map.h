#ifndef SPRITE_MAP_H
#define SPRITE_MAP_H

#include "word.h"
#include "memory.h"

typedef struct SpriteMapTag SpriteMap;

struct SpriteMapTag {
    Word start_address;
};

SpriteMap sprite_map_new(Word start_address);
Word sprite_map_top_block(SpriteMap self, Memory memory, int index);
Word sprite_map_bottom_block(SpriteMap self, Memory memory, int index);
void sprite_map_test(void);

#endif
