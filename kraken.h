#ifndef OOZ_KRAKEN_H
#define OOZ_KRAKEN_H

#include "ooz_types.h"

struct HuffRange {
    uint16 symbol;
    uint16 num;
};

typedef struct BitReader {
    // |p| holds the current byte and |p_end| the end of the buffer.
    const byte *p, *p_end;
    // Bits accumulated so far
    uint32 bits;
    // Next byte will end up in the |bitpos| position in |bits|.
    int bitpos;
} BitReader;

int Kraken_DecodeBytes(byte **output, const byte *src, const byte *src_end, int *decoded_size, size_t output_size, bool force_memmove, uint8 *scratch, uint8 *scratch_end);
int Kraken_GetBlockSize(const uint8 *src, const uint8 *src_end, int *dest_size, int dest_capacity);
int Huff_ConvertToRanges(HuffRange *range, int num_symbols, int P, const uint8 *symlen, BitReader *bits);

#endif // OOZ_KRAKEN_H
