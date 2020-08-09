/*
=== Kraken Decompressor for Windows ===
Copyright (C) 2016, Powzix

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OOZ_KRAKEN_H
#define OOZ_KRAKEN_H

#include <cstdint>

struct HuffRange {
    uint16_t symbol;
    uint16_t num;
};

typedef struct BitReader {
    // |p| holds the current byte and |p_end| the end of the buffer.
    const uint8_t *p, *p_end;
    // Bits accumulated so far
    uint32_t bits;
    // Next byte will end up in the |bitpos| position in |bits|.
    int bitpos;
} BitReader;

int Kraken_DecodeBytes(uint8_t**output, const uint8_t*src, const uint8_t*src_end, int *decoded_size, size_t output_size, bool force_memmove,
                       uint8_t*scratch, uint8_t*scratch_end);
int Kraken_GetBlockSize(const uint8_t*src, const uint8_t*src_end, int *dest_size, int dest_capacity);
int Huff_ConvertToRanges(HuffRange *range, int num_symbols, int P, const uint8_t*symlen, BitReader *bits);

#endif // OOZ_KRAKEN_H
