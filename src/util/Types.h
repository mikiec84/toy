#pragma once

#include <util/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#include <type/Vector.h>
#endif

#ifndef MUD_MODULES
#include <type/Types.h>
#include <math/Types.h>
#endif

#ifndef MUD_CPP_20
#include <stl/string.h>
#include <stl/vector.h>
#include <cstdint>
#endif


namespace mud
{
    // Exported types
    
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::Procedure>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::ProcedureType>();
    
    export_ template struct TOY_UTIL_EXPORT Typed<vector<toy::Procedure*>>;
    export_ template struct TOY_UTIL_EXPORT Typed<vector<toy::ProcedureType*>>;
}
