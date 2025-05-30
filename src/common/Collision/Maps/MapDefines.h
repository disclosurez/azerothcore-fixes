/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MAPDEFINES_H
#define _MAPDEFINES_H

#include "Define.h"
#include "DetourNavMesh.h"

#define MAX_NUMBER_OF_GRIDS      64
#define MAX_NUMBER_OF_CELLS      8
#define SIZE_OF_GRIDS            533.3333f

#define MMAP_MAGIC 0x4d4d4150   // 'MMAP'
#define MMAP_VERSION 16

struct MmapTileHeader
{
    uint32 mmapMagic{MMAP_MAGIC};
    uint32 dtVersion;
    uint32 mmapVersion{MMAP_VERSION};
    uint32 size{0};
    char usesLiquids{true};
    char padding[3] {};

    MmapTileHeader() : dtVersion(DT_NAVMESH_VERSION) { }
};

// All padding fields must be handled and initialized to ensure mmaps_generator will produce binary-identical *.mmtile files
static_assert(sizeof(MmapTileHeader) == 20, "MmapTileHeader size is not correct, adjust the padding field size");
static_assert(sizeof(MmapTileHeader) == (sizeof(MmapTileHeader::mmapMagic) +
              sizeof(MmapTileHeader::dtVersion) +
              sizeof(MmapTileHeader::mmapVersion) +
              sizeof(MmapTileHeader::size) +
              sizeof(MmapTileHeader::usesLiquids) +
              sizeof(MmapTileHeader::padding)), "MmapTileHeader has uninitialized padding fields");

enum NavTerrain
{
    NAV_EMPTY   = 0x00,
    NAV_GROUND  = 0x01,
    NAV_MAGMA   = 0x02,
    NAV_SLIME   = 0x04,
    NAV_WATER   = 0x08,
    NAV_UNUSED1 = 0x10,
    NAV_UNUSED2 = 0x20,
    NAV_UNUSED3 = 0x40,
    NAV_UNUSED4 = 0x80
                  // we only have 8 bits
};

#endif /* _MAPDEFINES_H */
