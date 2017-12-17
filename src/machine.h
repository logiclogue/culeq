#ifndef MACHINE_H
#define MACHINE_H

#include "memory.h"
#include "word.h"

typedef struct MachineTag Machine;

struct MachineTag {
    Memory memory;
    Word program_counter;
};

Machine machine_new(Memory memory, Word start_address);
Machine machine_execute(Machine machine);
void machine_test(void);

#endif
