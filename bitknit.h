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

#ifndef OOZ_BITKNIT_H
#define OOZ_BITKNIT_H

#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include "export.h"

#ifdef __cplusplus
extern "C" {
#endif
struct BitknitLiteral {
    uint16_t lookup[512 + 4];
    uint16_t a[300 + 1];
    uint16_t freq[300];
    uint32_t adapt_interval;
};

struct BitknitDistanceLsb {
    uint16_t lookup[64 + 4];
    uint16_t a[40 + 1];
    uint16_t freq[40];
    uint32_t adapt_interval;
};

struct BitknitDistanceBits {
    uint16_t lookup[64 + 4];
    uint16_t a[21 + 1];
    uint16_t freq[21];
    uint32_t adapt_interval;
};

struct BitknitState {
    uint32_t recent_dist[8];
    uint32_t last_match_dist;
    uint32_t recent_dist_mask;
    uint32_t bits, bits2;

    BitknitLiteral literals[4];
    BitknitDistanceLsb distance_lsb[4];
    BitknitDistanceBits distance_bits;
};

OOZ_EXPORT void BitknitState_Init(BitknitState* bk);
OOZ_EXPORT size_t Bitknit_Decode(const uint8_t* src, const uint8_t* src_end, uint8_t* dst, uint8_t* dst_end, uint8_t* dst_start, BitknitState* bk);

#ifdef __cplusplus
}
#endif
#endif // OOZ_BITKNIT_H
