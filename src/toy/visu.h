#pragma once

#include <mud/gfx.h>
#include <mud/snd.h>
#include <toy/core.h>
#include <mud/tree.h>
#include <mud/ecs.h>
#include <toy/util.h>
#include <mud/math.h>
#include <mud/gfx.ui.h>
#include <mud/infra.h>
#include <mud/type.h>



#ifndef TOY_VISU_EXPORT
#define TOY_VISU_EXPORT MUD_IMPORT
#endif

namespace toy
{
    struct VisuPainter;
    class PhysicDebugDraw;
    class VisuScene;
    class OgreViewport;
    class SoundSource;
}


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

#ifndef MUD_MODULES
#endif

#ifndef MUD_CPP_20
#include <stl/string.h>
#include <cstdint>
#include <stl/vector.h>
#endif


namespace mud
{
    // Exported types
    
    export_ template <> TOY_VISU_EXPORT Type& type<toy::PhysicDebugDraw>();
    export_ template <> TOY_VISU_EXPORT Type& type<toy::VisuScene>();
    
    export_ template struct TOY_VISU_EXPORT Typed<vector<toy::PhysicDebugDraw*>>;
    export_ template struct TOY_VISU_EXPORT Typed<vector<toy::VisuScene*>>;
}




#include <stl/string.h>
#include <stl/function.h>




#define TOY_PHYSIC_DEBUG_DRAW

using namespace mud; namespace toy
{
	struct TOY_VISU_EXPORT VisuPainter
	{
		VisuPainter(cstring name, size_t index, function<void(size_t, VisuScene&, Gnode&)> paint)
			: m_name(name)
			, m_index(index)
			, m_paint(paint)
		{}

		string m_name;
		size_t m_index;
		bool m_enabled = true;

		function<void(size_t, VisuScene&, Gnode&)> m_paint;
	};

	class refl_ TOY_VISU_EXPORT PhysicDebugDraw
	{
	public:
		PhysicDebugDraw(ImmediateDraw& immediate);
		~PhysicDebugDraw();

		void draw_physics(Gnode& parent, World& world, Medium& medium);

		class Impl;
		unique<Impl> m_impl;
	};

	class refl_ TOY_VISU_EXPORT VisuScene : public NonCopy
    {
    public:
        VisuScene(GfxSystem& gfx_system, SoundManager* sound_system = nullptr);
        ~VisuScene();

		attr_ GfxSystem& m_gfx_system;
		attr_ Scene m_scene;

		Ref m_player;

#ifdef TOY_SOUND
		SoundManager& m_snd_manager;
#endif

		vector<Gnode*> m_entities;

		vector<unique<VisuPainter>> m_painters;

		meth_ void next_frame();

		Gnode& entity_node(Gnode& parent, uint32_t entity, Spatial& spatial, size_t painter);

		inline void painter(cstring name, function<void(size_t, VisuScene&, Gnode&)> paint)
		{
			m_painters.emplace_back(construct<VisuPainter>(name, m_painters.size(), paint));
		}

		template <class T>
		inline void entity_painter(cstring name, World& world, void (*paint_func)(Gnode&, T&))
		{
			auto paint = [this, &world, paint_func](size_t index, VisuScene&, Gnode& parent)
			{
				world.m_ecs.loop_ent<Spatial, T>([this, paint_func, index, &parent](uint32_t entity, Spatial& spatial, T& component)
				{
					paint_func(this->entity_node(parent, entity, spatial, index), component);
				});
			};
			m_painters.emplace_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
		}

		template <class T, class T_PaintFunc>
		inline void range_entity_painter(HSpatial reference, float range, cstring name, World& world, T_PaintFunc paint_func)
		{
			float range2 = range * range;
			auto paint = [reference, range2, this, &world, paint_func](size_t index, VisuScene&, Gnode& parent)
			{
				vec3 position = reference->m_position;
				world.m_ecs.loop_ent<Spatial, T>([&position, range2, this, paint_func, index, &parent](uint32_t entity, Spatial& spatial, T& component)
				{
					float dist2 = distance2(spatial.m_position, position);
					if(dist2 < range2)
						paint_func(this->entity_node(parent, entity, spatial, index), component);
				});
			};
			m_painters.emplace_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
		}

		template <class T, class T_Container>
		inline void object_painter(cstring name, T_Container& objects, void (*paint_func)(Gnode&, T&))
		{
			auto paint = [this, &objects, paint_func](size_t index, VisuScene&, Gnode& parent)
			{
				for(auto object : objects)
					paint_func(this->entity_node(parent, object->m_spatial.m_handle, object->m_spatial, index), *object);
			};
			m_painters.emplace_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
		}

	private:
		Clock m_clock;
    };

	export_ TOY_VISU_EXPORT void update_camera(Camera& camera, mud::Camera& gfx_camera);

	export_ TOY_VISU_EXPORT void paint_selection(Gnode& parent, Selection& selection, Ref hovered);

	export_ TOY_VISU_EXPORT void paint_camera(Gnode& parent, Camera& camera);
	//export_ TOY_VISU_EXPORT void paint_light(Gnode& parent, LightSource& light);
	//export_ TOY_VISU_EXPORT void paint_symbolic(Gnode& parent, Symbolic& symbolic);
	export_ TOY_VISU_EXPORT void paint_obstacle(Gnode& parent, Obstacle& obstacle);
	//export_ TOY_VISU_EXPORT void paint_disq(Gnode& parent, Disq& disq);
	//export_ TOY_VISU_EXPORT void paint_event_sphere(Gnode& parent, EventReceptor& receptor);
	export_ TOY_VISU_EXPORT void paint_entity(Gnode& parent, Spatial& spatial);
	//export_ TOY_VISU_EXPORT void paint_active(Gnode& parent, Active& active);

	export_ TOY_VISU_EXPORT void scene_painters(VisuScene& scene, World& world);

	export_ TOY_VISU_EXPORT bool sound(Gnode& parent, const string& sound, bool loop = false, float volume = 1.f);
}

using namespace mud; namespace toy
{
	export_ TOY_VISU_EXPORT void build_geometry(Geometry& geometry, array<Item*> items);
	export_ TOY_VISU_EXPORT void build_world_page_geometry(WorldPage& page, array<Item*> items);
	export_ TOY_VISU_EXPORT void build_world_page_geometry(Scene& scene, WorldPage& page);

	export_ TOY_VISU_EXPORT void paint_world_page(Gnode& parent, WorldPage& page);
	export_ TOY_VISU_EXPORT void paint_navmesh(Gnode& parent, Navmesh& navmesh);
}



using namespace mud; namespace toy
{
	class TOY_VISU_EXPORT OgreViewport : public Viewer
	{
	public:
		OgreViewport(Widget* parent, void* identity, Scene& scene/*, VisuCamera& camera*/);
	};
}

#if 0


#ifdef TOY_SOUND
#endif

#ifndef MUD_CPP_20
#include <stl/map.h>
#endif

using namespace mud; namespace toy
{
	class refl_ TOY_VISU_EXPORT SoundSource : public StoreObserver<State>
	{
	public:
#ifdef TOY_SOUND
		SoundSource(HSpatial spatial, SoundManager& soundManager);
#else
		SoundSource(HSpatial spatial);
#endif

		attr_ HSpatial m_spatial;

#ifdef TOY_SOUND
		void soundDestroyed(Sound& sound);
#endif

		void handle_add(State& effect);
		void handle_remove(State& effect);

	private:
		Active& m_active;

#ifdef TOY_SOUND
		SoundManager& m_soundManager;
		map<State*, Sound*> m_sounds;
#endif

		size_t m_updated;
	};
}
#endif

