#pragma once

#include <toy/visu.h>
#include <mud/ui.h>
#include <toy/core.h>
#include <mud/uio.h>
#include <mud/tool.h>
#include <toy/util.h>
#include <mud/math.h>
#include <mud/gfx.ui.h>
#include <mud/infra.h>
#include <mud/type.h>




#ifndef TOY_EDIT_EXPORT
#define TOY_EDIT_EXPORT MUD_IMPORT
#endif

namespace toy
{
    class CameraController;
    class FPSCameraController;
    class RTSCameraController;
    class Edit;
    class Clone;
    class Cut;
    class Paste;
    class Toolbox;
    class DynamicToolbox;
    class Toolbelt;
	class RunTool;
    class PlayTool;
    struct ActionGroup;
    struct GraphicsDebug;
    class Editor;
}

using namespace mud; namespace toy
{
#if 0
	class EditorApp : public NonCopy
	{
	public:
		EditorApp(const string& execPath, const string& resourcePath);
		~EditorApp();

		void init(bool prompt);
		int pump();
		void cleanup();

		void startEditor();

		void loadGame(const string& path);
		void reloadGame();

	protected:
		User m_user;

		object<Shell> m_shell;
		object<Editor> m_editor;
	};
#endif
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
    
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::ActionGroup>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Clone>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Cut>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Edit>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::GraphicsDebug>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Paste>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Toolbelt>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Toolbox>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::DynamicToolbox>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Editor>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::PlayTool>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::RunTool>();
    
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::ActionGroup*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Clone*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Cut*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Edit*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::GraphicsDebug*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Paste*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Toolbelt*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Toolbox*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::DynamicToolbox*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Editor*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::PlayTool*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::RunTool*>>;
}



using namespace mud; namespace toy
{
	class TOY_EDIT_EXPORT CameraController : public ViewerController, public EventDispatch
	{
	public:
		CameraController(Viewer& viewer, HCamera camera, HMovable movable);

		void default_velocities();
		void set_velocities(const map<Key, vec3>& velocities);

		void rotate_left();
		void rotate_right();

		void stop_rotate_left();
		void stop_rotate_right();

		void stop();

		void zoom_in();
		void zoom_out();

		void pitch_lens_up();
		void pitch_lens_down();

	protected:
		Viewer& m_viewer;
		HCamera m_camera;
		HMovable m_movable;
		float m_velocity;
		float m_angular_velocity;
	};
}



using namespace mud; namespace toy
{
	class TOY_EDIT_EXPORT FPSCameraController : public CameraController
	{
	public:
		FPSCameraController(Viewer& viewer, HCamera camera, HMovable movable);

		virtual void process(Widget& widget) { UNUSED(widget); }
		virtual void process(Viewer& viewer);

		void process(Viewer& viewer, Spatial& spatial, Camera& camera);
	};
}



using namespace mud; namespace toy
{
	class TOY_EDIT_EXPORT RTSCameraController : public CameraController
	{
	public:
		RTSCameraController(Viewer& viewer, HCamera camera, HMovable movable);

		virtual void process(Widget& widget) { UNUSED(widget); }
		virtual void process(Viewer& viewer);

		void process(Viewer& viewer, Spatial& spatial, Camera& camera);
	};
}



using namespace mud; namespace toy
{
	class refl_ TOY_EDIT_EXPORT Edit : public TypedProcedure<Edit>
	{
	public:
		Edit(User* user, Ref object, vector<Ref> args) : TypedProcedure(user, object) { UNUSED(args); }

		static bool checkObject(Ref object) { UNUSED(object); return true; }

		void begin();
	};

	class refl_ TOY_EDIT_EXPORT Clone : public TypedProcedure<Clone>
	{
	public:
		Clone(User* user, Ref object, vector<Ref> args) : TypedProcedure(user, object) { UNUSED(args); }

		static bool checkObject(Ref object) { UNUSED(object); return true; }

		void begin();
	};

	class refl_ TOY_EDIT_EXPORT Cut : public TypedProcedure<Cut>
	{
	public:
		Cut(User* user, Ref object, vector<Ref> args) : TypedProcedure(user, object) { UNUSED(args); }

		void begin() {}
	};

	class refl_ TOY_EDIT_EXPORT Paste : public TypedProcedure<Paste>
	{
	public:
		Paste(User* user, Ref object, vector<Ref> args) : TypedProcedure(user, object) { UNUSED(args); }

		void begin() {}
	};
}



#ifndef MUD_CPP_20
#include <stl/vector.h>
#endif

using namespace mud; namespace toy
{
	using Selection = vector<Ref>;

	//TOY_EDIT_EXPORT void context_menu(Widget& parent, Selector& selector, Ref object);

	TOY_EDIT_EXPORT void edit_toolbox(Widget& parent, Toolbox& toolbox);
	TOY_EDIT_EXPORT void edit_toolbelt(Widget& parent, Toolbelt& toolbelt);

	TOY_EDIT_EXPORT void edit_selection(Widget& parent, Selection& selection);
	//TOY_EDIT_EXPORT void edit_selector(Widget& parent, Selector& selector);

	TOY_EDIT_EXPORT void scene_edit(Widget& parent, World& world);

	TOY_EDIT_EXPORT void registry(Widget& parent, Indexer& indexer, Selection& selection);
	TOY_EDIT_EXPORT void registry_section(Widget& parent, Indexer& indexer, Selection& selection);
	TOY_EDIT_EXPORT void library(Widget& parent, const vector<Type*>& types, Selection& selection);
	TOY_EDIT_EXPORT void library_section(Widget& parent, const vector<Type*>& types, Selection& selection);

	TOY_EDIT_EXPORT void editor_menu(Widget& parent, ActionGroup& action_group);
	TOY_EDIT_EXPORT void editor_menu_bar(Widget& parent, Editor& editor);
	TOY_EDIT_EXPORT void editor_graph(Widget& parent, Editor& editor, Selection& selection);

	TOY_EDIT_EXPORT void editor_components(Widget& parent, Editor& editor);

	TOY_EDIT_EXPORT void editor(Widget& parent, Editor& editor, Widget*& screen);
	TOY_EDIT_EXPORT void mini_editor(Widget& parent, Editor& editor, Widget*& screen);

	TOY_EDIT_EXPORT Widget& editor_viewer_overlay(Viewer& viewer, Editor& editor);
}



using namespace mud; namespace toy
{
	//TOY_EDIT_EXPORT void edit_reactive(Widget& parent, Reactive& reactive);
}



using namespace mud; namespace toy
{
	using Selection = vector<Ref>;

	TOY_EDIT_EXPORT Viewer& scene_viewport(Widget& parent, VisuScene& scene, HCamera camera, HMovable movable, Selection& selection);
}


#include <stl/map.h>
#include <stl/function.h>


#include <stl/string.h>
#include <stl/map.h>

using namespace mud; namespace toy
{
	using Selection = vector<Ref>;

	class refl_ Toolbox : public NonCopy
	{
	public:
		Toolbox(cstring name);
		virtual ~Toolbox();

		string m_name;
		vector<Tool*> m_tools;
	};

	class refl_ DynamicToolbox : public Toolbox
	{
	public:
		DynamicToolbox(cstring name, const Selection& targets);

		void update_tools(const Selection& targets);

	protected:
		vector<Tool*> m_current_tools;

		const Selection& m_targets;
	};

	class refl_ Toolbelt : public NonCopy
	{
	public:
		Toolbelt();

		map<string, object<Toolbox>> m_toolboxes;

		Tool* m_activeTool;
		Brush* m_activeBrush;

		Toolbox& toolbox(cstring name);

		void setActiveTool(Tool& tool);
	};
}


using namespace mud; namespace toy
{
	using Selection = vector<Ref>;

	export_ class refl_ TOY_EDIT_EXPORT PlayTool : public Tool
	{
	public:
		PlayTool(ToolContext& context, Editor& editor);

		virtual void activate() final;

		Editor& m_editor;
	};

	export_ class refl_ TOY_EDIT_EXPORT RunTool : public Tool
	{
	public:
		RunTool(ToolContext& context, Editor& editor);

		virtual void activate() final;

		Editor& m_editor;
	};

	struct refl_ TOY_EDIT_EXPORT ActionGroup
	{
		string m_name;
		map<string, function<void()>> m_actions;
	};

	struct refl_ TOY_EDIT_EXPORT GraphicsDebug
	{
		bool m_debug_draw_csm = false;
	};

	class refl_ TOY_EDIT_EXPORT Editor : public EditContext
    {
    public:
		Editor(GfxSystem& gfx_system);
        
		Toolbelt m_toolbelt;

		attr_ RunTool m_run_tool;
		attr_ PlayTool m_play_tool;
		
		attr_ FrameViewTool m_frame_view_tool;

		map<string, ActionGroup> m_action_groups;

		attr_ World* m_edited_world = nullptr;
		attr_ bool m_run_game = false;
		attr_ bool m_play_game = false;

		vector<Scene*> m_scenes;

		GraphicsDebug m_graphics_debug;

		void update();

		void create_scripted_brush();

		ActionGroup& action_group(const string& name);
    };
}

