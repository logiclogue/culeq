#include <assert.h>
#include "word.h"
#include "word_colour.h"

int word_colour_red(Word word) {
    return (word & 0xF000) >> 8;
}

int word_colour_green(Word word) {
    return (word & 0x0F00) >> 4;
}

int word_colour_blue(Word word) {
    return word & 0x00F0;
}

int word_colour_alpha(Word word) {
    return (word & 0x000F) << 4;
}

void word_colour_test(void) {
    Word word = 0x1234;

    assert(word_colour_red(word) == 0x10);
    assert(word_colour_green(word) == 0x20);
    assert(word_colour_blue(word) == 0x30);
    assert(word_colour_alpha(word) == 0x40);
}
