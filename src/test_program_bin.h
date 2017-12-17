#ifndef TEST_PROGRAM_BIN_H
#define TEST_PROGRAM_BIN_H

#define Z 0x0000
#define START_ADDRESS 0x1000
#define CHAR_ADDRESS 0xFE80
#define LETTER 0x104A
#define OFFSET(relative_address) START_ADDRESS + relative_address
// 3 words
#define JMP(c) Z, Z, c
// 12 words
#define MOV(start_address, a, b)\
    b, b, start_address + 3,\
    a, Z, start_address + 6,\
    Z, b, start_address + 9,\
    Z, Z, start_address + 12
// 12 words
#define PUT_CHAR(start_address, char_word, index)\
    MOV(start_address, CHAR_ADDRESS + index, char_word)

uint16_t test_program_bin[] = {
    MOV(OFFSET(0), OFFSET(15), 0xFE80), // 0
    JMP(START_ADDRESS), // 12
    LETTER // 15
};

unsigned int test_program_bin_len = 16;

#endif
