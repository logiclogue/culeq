#ifndef WORD_H
#define WORD_H

#include <inttypes.h>

typedef int16_t Word;

#define WORD_BYTES (sizeof(Word))
#define WORD_NYBLES (WORD_BYTES * 2)
#define WORD_BITS (WORD_BYTES * 8)

#endif
