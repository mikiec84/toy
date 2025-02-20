#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <wren/Forward.h>
#include <wren/Types.h>

#ifndef _WREN_REFL_EXPORT
#define _WREN_REFL_EXPORT MUD_IMPORT
#endif

export_ class _WREN_REFL_EXPORT _wren : public Module
{
private:
	_wren();
	
public:
	static _wren& m() { static _wren instance; return instance; }
};

#ifdef _WREN_MODULE
extern "C"
_WREN_REFL_EXPORT Module& getModule();
#endif
