# Culeq

A one instruction set computer (OISC) emulator.

Culeq is a 16-bit machine based off the single 'subleq' instruction.

Culeq has 64K words of directly addressable RAM, or 128Kb.

The display is memory mapped.

## Compiling

```
make
```

## Usage

```
./build/culeq [binary file]
```

## Example

```
./build/culeq examples/paint_screen.bin
```

- This program paints the screen pink
- It shows how slow having 1 instruction is
- Even on 8-bit computers of the 80s, we'd expect it to clear the screen almost
  instantly

- Unfortunately, I wasn't able to build any reasonable program for Culeq due to
  the complexity of writing programs with 1 instruction
- I hope this still demonstrates somewhat what it can do

- You can find other example programs in the `examples` directory

## Tests

- Run tests

```
./build/culeq
```

## Memory Map

| Utility           | From   | To     |
|-------------------|--------|--------|
| Null              | 0x0000 | 0x0000 |
| User program/heap | 0x0001 | 0xFC6F |
| Sprites           | 0xFC70 | 0xFE6F |
| Colours           | 0xFE70 | 0xFE7F |
| Character display | 0xFE80 | 0xFFFF |

## Display

- 32x12 characters

- Character at (0, 0) will be address 0xFE80
- Character at (2, 0) will be address 0xFE82
- etc.

### Character word

- The character words exist in memory between 0xFE80 and 0xFFFF
- The bits in the character are split as follows (from most (0th) to least
  (31st) significant):

| Utility           | AND mask |
|-------------------|----------|
| Foreground colour | 0xF000   |
| Background colour | 0x0F00   |
| ASCII char code   | 0x00FF   |

### Colours

- The colours are stored in memory from 0xFE70 to 0xFE7F
- That's 16 colours in total at one time
- Here is how each colour word is split up:

| Utility | AND mask |
|---------|----------|
| Red     | 0xF000   |
| Green   | 0x0F00   |
| Blue    | 0x00F0   |

### Default colour palette

- These can be found hard-coded in `src/colours_bin.h`

| Address | Word   | Description |
|---------|--------|-------------|
| 0xFE70  | 0x0000 | Black       |
| 0xFE71  | 0xFFF0 | White       |
| 0xFE72  | 0xF000 | Red         |
| 0xFE73  | 0x0F00 | Green       |
| 0xFE74  | 0x00F0 | Blue        |
| 0xFE75  | 0xFF00 | Yellow      |
| 0xFE76  | 0xF0F0 | Pink        |
| 0xFE77  | 0x0FF0 | Cyan        |
| 0xFE78  | 0x4440 | Dark grey   |
| 0xFE79  | 0x8880 | Grey        |
| 0xFE7A  | 0x8000 | Dark red    |
| 0xFE7B  | 0x0800 | Dark green  |
| 0xFE7C  | 0x0080 | Dark blue   |
| 0xFE7D  | 0x8800 | Gold        |
| 0xFE7E  | 0x8080 | Purple      |
| 0xFE7F  | 0x0880 | Teal        |

- You can override these colours with your own 12-bit colours

### Sprites

- There are 256 sprites
- There is 1 sprite for every ASCII character
- Each sprite is 4x8 pixels
- Each sprite requires 2 words in memory
    - Because 1 word is 16-bits which can represent a 4x4 square
- Sprites are indexed in memory by their respective ASCII character
- Sprites exist between 0xFC70 and 0xFE6F in memory
- Default sprites can be found in `src/sprites_bin.h`

- Most of the sprites haven't been defined since it was taking me so long!

#### Letter A example

- Letter A

```
 *  - 4
* * - A
* * - A
*** - E
* * - A
* * - A
* * - A
```

- 1st word: `0x4AAE`
- 2nd word: `0xAAA0`
- Exists at 0xFCF2 (1st word) and 0xFCF3 (2st word)
    - ASCII code 65 = 0x41
    - 0xFC70 + (0x41 * 2)
    - 0xFC70 + 0x82
    - 0xFCF2
