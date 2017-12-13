#include <assert.h>
#include "word_char.h"

char word_char(Word word) {
    return word & 0x00FF;
}

int word_char_foreground(Word word) {
    return (word & 0xF000) >> 12;
}

int word_char_background(Word word) {
    return (word & 0x0F00) >> 8;
}

void word_char_test(void) {
    Word word = 0x1200 + 'J';

    assert(word_char(word) == 'J');
    assert(word_char_foreground(word) == 1);
    assert(word_char_background(word) == 2);
}
