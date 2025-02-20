//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/ECS.h>
#include <block/Forward.h>
#include <block/Block.h>
#include <block/Chunk.h>
#include <block/Sector.h>

namespace mud
{
	export_ template struct refl_ TOY_BLOCK_EXPORT ComponentHandle<toy::Block>;
	export_ template struct refl_ TOY_BLOCK_EXPORT ComponentHandle<toy::Chunk>;
	export_ template struct refl_ TOY_BLOCK_EXPORT ComponentHandle<toy::Heap>;
	export_ template struct refl_ TOY_BLOCK_EXPORT ComponentHandle<toy::Sector>;
	export_ template struct refl_ TOY_BLOCK_EXPORT ComponentHandle<toy::Tileblock>;
}
