//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <math/Vec.h>
#include <uio/Unode.h>
#include <edit/Forward.h>
#include <edit/Controller/CameraController.h>

using namespace mud; namespace toy
{
	using Selection = vector<Ref>;

	TOY_EDIT_EXPORT Viewer& scene_viewport(Widget& parent, VisuScene& scene, HCamera camera, HMovable movable, Selection& selection);
}
