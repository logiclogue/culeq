# Culeq

A one instruction set computer (OISC) emulator.

Culeq is a 16-bit machine based off the single 'subleq' instruction.

Culeq has 64K words of directly addressable RAM, or 128Kb.

The display is memory mapped.

## Memory Map

| Utility           | From   | To     |
|-------------------|--------|--------|
| Sprites           | 0xFC70 | 0xFE6F |
| Colours           | 0xFE70 | 0xFE7F |
| Character display | 0xFE80 | 0xFFFF |

## Display

- 32x12 characters

### Default colour palette

### Sprites
