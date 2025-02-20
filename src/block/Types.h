#pragma once

#include <block/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#include <type/Vector.h>
#endif

#ifndef MUD_MODULES
#include <type/Types.h>
#include <math/Types.h>
#include <wfc-gfx/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#endif

#ifndef MUD_CPP_20
#include <stl/string.h>
#include <stl/vector.h>
#include <cstdint>
#endif

#include <block/Structs.h>

namespace mud
{
    // Exported types
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::MatterState>();
    
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Block>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Chunk>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Element>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<mud::Grid<toy::Block*>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Heap>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Sector>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Tileblock>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<mud::ComponentHandle<toy::Block>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<mud::ComponentHandle<toy::Chunk>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<mud::ComponentHandle<toy::Heap>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<mud::ComponentHandle<toy::Sector>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<mud::ComponentHandle<toy::Tileblock>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Earth>();
    
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<toy::Block*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<toy::Chunk*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<toy::Element*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<mud::Grid<toy::Block*>*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<toy::Heap*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<toy::Sector*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<toy::Tileblock*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<mud::ComponentHandle<toy::Block>*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<mud::ComponentHandle<toy::Chunk>*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<mud::ComponentHandle<toy::Heap>*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<mud::ComponentHandle<toy::Sector>*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<mud::ComponentHandle<toy::Tileblock>*>>;
    export_ template struct TOY_BLOCK_EXPORT Typed<vector<toy::Earth*>>;
}
