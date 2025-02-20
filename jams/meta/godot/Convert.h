#pragma once

#include <godot/Types.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Meta.h>
#include <refl/Enum.h>
#include <infra/StringConvert.h>
#endif

namespace mud
{
	export_ template <> inline void to_value(const string& str, Faction& val) { val = Faction(enu<Faction>().value(str.c_str())); };
	export_ template <> inline void to_string(const Faction& val, string& str) { str = enu<Faction>().name(uint32_t(val)); };
	
	
}
