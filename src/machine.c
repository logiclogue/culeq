#include "machine.h"
#include "memory.h"
#include "word.h"
#include <assert.h>

Machine machine_new(Memory memory, Word start_address) {
    return (Machine) { memory, start_address };
}

Machine machine_execute(Machine machine) {
    Word a = memory_get(machine.memory, machine.program_counter);
    Word b = memory_get(machine.memory, machine.program_counter + 1);
    Word c = memory_get(machine.memory, machine.program_counter + 2);

    Word mem_a = memory_get(machine.memory, a);
    Word mem_b = memory_get(machine.memory, b);

    Word sub = mem_b - mem_a;

    machine.memory = memory_set(machine.memory, b, sub);

    if (sub > 0) {
        machine.program_counter += 3;
    } else {
        machine.program_counter = c;
    }

    return machine;
}

void machine_test(void) {
    Memory memory = memory_new();

    memory_set(memory, 0x0000, 0);
    memory_set(memory, 0x0001, 0);
    memory_set(memory, 0x0002, 42);

    Machine machine = machine_new(memory, 0x0000);

    assert(machine_execute(machine).program_counter == 42);
}
