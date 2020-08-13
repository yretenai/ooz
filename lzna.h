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

#ifndef OOZ_LZNA_H
#define OOZ_LZNA_H

#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include "export.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef uint16_t LznaBitModel;

// State for a 4-bit value RANS model
struct LznaNibbleModel {
    uint16_t prob[17];
};

// State for a 3-bit value RANS model
struct Lzna3bitModel {
    uint16_t prob[9];
};

// State for the literal model
struct LznaLiteralModel {
    LznaNibbleModel upper[16];
    LznaNibbleModel lower[16];
    LznaNibbleModel nomatch[16];
};

// State for a model representing a far distance
struct LznaFarDistModel {
    LznaNibbleModel first_lo;
    LznaNibbleModel first_hi;
    LznaBitModel second[31];
    LznaBitModel third[2][31];
};

// State for a model representing a near distance
struct LznaNearDistModel {
    LznaNibbleModel first;
    LznaBitModel second[16];
    LznaBitModel third[2][16];
};

// State for model representing the low bits of a distance
struct LznaLowBitsDistanceModel {
    LznaNibbleModel d[2];
    LznaBitModel v;
};

// State for model used for the short lengths for recent matches
struct LznaShortLengthRecentModel {
    Lzna3bitModel a[4];
};

// State for model for long lengths
struct LznaLongLengthModel {
    LznaNibbleModel first[4];
    LznaNibbleModel second;
    LznaNibbleModel third;
};

// Complete LZNA state
struct LznaState {
    uint32_t match_history[8];
    LznaLiteralModel literal[4];
    LznaBitModel is_literal[12 * 8];
    LznaNibbleModel type[12 * 8];
    LznaShortLengthRecentModel short_length_recent[4];
    LznaLongLengthModel long_length_recent;
    LznaLowBitsDistanceModel low_bits_of_distance[2];
    LznaBitModel short_length[12][4];
    LznaNearDistModel near_dist[2];
    Lzna3bitModel medium_length;
    LznaLongLengthModel long_length;
    LznaFarDistModel far_distance;
};

OOZ_EXPORT int LZNA_DecodeQuantum(uint8_t* dst, uint8_t* dst_end, uint8_t* dst_start, const uint8_t* src, const uint8_t* src_end,
                                  struct LznaState* lut);
OOZ_EXPORT void LZNA_InitLookup(LznaState* lut);

#ifdef __cplusplus
}
#endif
#endif // OOZ_LZNA_H
