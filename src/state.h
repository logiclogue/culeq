#ifndef STATE_H
#define STATE_H

#include "memory.h"
#include "word.h"

typedef struct StateTag State;

struct StateTag {
    Memory memory;
    Word program_counter;
};

#endif
