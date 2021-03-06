/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/sbefw/core/sbeXipUtils.H $                                */
/*                                                                        */
/* OpenPOWER sbe Project                                                  */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef SBE_XIP_UTILS_H
#define SBE_XIP_UTILS_H

#include "p9_xip_image.h"
#include "ppe42_scom.h"  // for PPE_STVD
#include "sbe_link.H"  // for SBE_BASE_ORIGIN, SBE_SEEPROM_BASE_ORIGIN

// Unconditional jump to a memory location
#define JUMP_TO_ADDR(VAL ) \
{ \
asm volatile ( \
    "mtlr  %0 \n\t" \
    :   \
    : "r" (VAL)); \
asm volatile ( \
    "blr  \n\t" \
    :   \
    );\
}

// PIBMEM start address
const uint32_t g_pibMemAddr = SBE_BASE_ORIGIN;
// SEEPROM start address
const uint32_t g_headerAddr = SBE_SEEPROM_BASE_ORIGIN;
// IVPR register address
const uint32_t g_ivprLoc = 0xC0000160;

// Get XIP image header
inline P9XipHeader * getXipHdr()
{
    P9XipHeader *hdr = (P9XipHeader *)( g_headerAddr );
    return hdr;
}

// Get Section start addess
inline uint8_t * getSectionAddr( P9XipSection * i_section )
{
    return ( (uint8_t *)( g_headerAddr + i_section->iv_offset));
}
#endif // SBE_XIP_UTILS_H
