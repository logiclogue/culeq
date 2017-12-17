# Culeq

A one instruction set computer (OISC) emulator.

Culeq is a 16-bit machine based off the single 'subleq' instruction.

Culeq has 64K words of directly addressable RAM, or 128Kb.

The display is memory mapped.

## Memory Map

| Utility           | From   | To     |
|-------------------|--------|--------|
| Empty             | 0x0000 | 0xFC6F |
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

- There can be found hard-coded in `src/colours_bin.h`

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

### Sprites
