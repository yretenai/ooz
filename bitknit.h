#ifndef OOZ_BITKNIT_H
#define OOZ_BITKNIT_H

#include "ooz_types.h"

struct BitknitLiteral {
    uint16 lookup[512 + 4];
    uint16 a[300 + 1];
    uint16 freq[300];
    uint32 adapt_interval;
};

struct BitknitDistanceLsb {
    uint16 lookup[64 + 4];
    uint16 a[40 + 1];
    uint16 freq[40];
    uint32 adapt_interval;
};

struct BitknitDistanceBits {
    uint16 lookup[64 + 4];
    uint16 a[21 + 1];
    uint16 freq[21];
    uint32 adapt_interval;
};

struct BitknitState {
    uint32 recent_dist[8];
    uint32 last_match_dist;
    uint32 recent_dist_mask;
    uint32 bits, bits2;

    BitknitLiteral literals[4];
    BitknitDistanceLsb distance_lsb[4];
    BitknitDistanceBits distance_bits;
};

void BitknitState_Init(BitknitState *bk);
size_t Bitknit_Decode(const byte *src, const byte *src_end, byte *dst, byte *dst_end, byte *dst_start, BitknitState *bk);

#endif // OOZ_BITKNIT_H
