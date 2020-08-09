//
// Created by yretenai on 2020-08-09.
//

#ifndef OOZ_LZNA_H
#define OOZ_LZNA_H

#include "ooz_types.h"

int LZNA_DecodeQuantum(byte *dst, byte *dst_end, byte *dst_start,
                       const byte *src, const byte *src_end,
                       struct LznaState *lut);
void LZNA_InitLookup(LznaState *lut);

#endif // OOZ_LZNA_H
