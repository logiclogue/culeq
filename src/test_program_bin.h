#ifndef TEST_PROGRAM_BIN_H
#define TEST_PROGRAM_BIN_H

#define Z 0x0000
#define START_ADDRESS 0x1000
#define START_ADDRESS 0x1000
#define LETTER 0x104A
#define JMP(c) Z, Z, c
#define OFFSET(relative_address) START_ADDRESS + relative_address
#define MOV(start_address, a, b)\
    b, b, start_address + 3,\
    a, Z, start_address + 6,\
    Z, b, start_address + 9,\
    Z, Z, start_address + 12

uint16_t test_program_bin[] = {
    MOV(OFFSET(0), OFFSET(15), 0xFE80),
    JMP(START_ADDRESS),
    LETTER
};

unsigned int test_program_bin_len = 16;

#endif
