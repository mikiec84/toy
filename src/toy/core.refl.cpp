#pragma once

#include <mud/jobs.refl.h>
#include <mud/lang.refl.h>
#include <toy/core.refl.h>
#include <mud/geom.refl.h>
#include <toy/core.h>
#include <mud/type.refl.h>
#include <mud/refl.h>
#include <mud/math.refl.h>
#include <toy/util.refl.h>
#include <mud/infra.h>
#include <mud/type.h>
#include <mud/ecs.refl.h>

#ifdef MUD_MODULES
module toy.core;
#else
#endif


namespace mud
{
	void toy_core_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	{
		static Meta meta = { type<toy::CollisionGroup>(), &namspc({ "toy" }), "CollisionGroup", sizeof(toy::CollisionGroup), TypeClass::Enum };
		static Enum enu = { type<toy::CollisionGroup>(),
			false,
			{ "CM_NOMASK", "CM_OBJECT", "CM_SOLID", "CM_GROUND", "CM_AREA", "CM_BUFFER", "CM_LIGHT", "CM_LIGHTREFLECTOR", "CM_SOURCE", "CM_RECEPTOR", "CM_OBSTACLE" },
			{ 0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 },
			{ var(toy::CM_NOMASK), var(toy::CM_OBJECT), var(toy::CM_SOLID), var(toy::CM_GROUND), var(toy::CM_AREA), var(toy::CM_BUFFER), var(toy::CM_LIGHT), var(toy::CM_LIGHTREFLECTOR), var(toy::CM_SOURCE), var(toy::CM_RECEPTOR), var(toy::CM_OBSTACLE) }
		};
		meta_enum<toy::CollisionGroup>();
	}
	
	// Sequences
	{
		static Meta meta = { type<vector<toy::HSpatial>>(), &namspc({}), "vector<toy::HSpatial>", sizeof(vector<toy::HSpatial>), TypeClass::Sequence };
		static Class cls = { type<vector<toy::HSpatial>>() };
		cls.m_content = &type<toy::HSpatial>();
		meta_vector<vector<toy::HSpatial>, toy::HSpatial>();
	}
	
	// toy::BulletMedium
	{
		static Meta meta = { type<toy::BulletMedium>(), &namspc({ "toy" }), "BulletMedium", sizeof(toy::BulletMedium), TypeClass::Object };
		static Class cls = { type<toy::BulletMedium>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::BulletMedium>();
	}
	// toy::BulletShape
	{
		static Meta meta = { type<toy::BulletShape>(), &namspc({ "toy" }), "BulletShape", sizeof(toy::BulletShape), TypeClass::Object };
		static Class cls = { type<toy::BulletShape>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::BulletShape>();
	}
	// toy::Camera
	{
		static Meta meta = { type<toy::Camera>(), &namspc({ "toy" }), "Camera", sizeof(toy::Camera), TypeClass::Object };
		static Class cls = { type<toy::Camera>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Camera>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Camera>(ref)) toy::Camera(  ); }, {} },
				{ type<toy::Camera>(), [](Ref ref, array<Var> args) { new(&val<toy::Camera>(ref)) toy::Camera( val<toy::HSpatial>(args[0]), val<float>(args[1]), val<float>(args[2]), val<float>(args[3]) ); }, { { "spatial", var(toy::HSpatial()) }, { "lens_distance", var(float(1.f)), Param::Default }, { "near", var(float(0.001f)), Param::Default }, { "far", var(float(1000.f)), Param::Default } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::Camera>(), member_address(&toy::Camera::m_lens_distance), type<float>(), "lens_distance", var(float(1.f)), Member::Value, nullptr },
				{ type<toy::Camera>(), member_address(&toy::Camera::m_lens_angle), type<float>(), "lens_angle", var(float(0.f)), Member::Value, nullptr },
				{ type<toy::Camera>(), member_address(&toy::Camera::m_near), type<float>(), "near", var(float(0.001f)), Member::Value, nullptr },
				{ type<toy::Camera>(), member_address(&toy::Camera::m_far), type<float>(), "far", var(float(1000.f)), Member::Value, nullptr },
				{ type<toy::Camera>(), member_address(&toy::Camera::m_aspect), type<float>(), "aspect", var(float()), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::Camera>();
		meta_class<toy::Camera>();
	}
	// toy::Collider
	{
		static Meta meta = { type<toy::Collider>(), &namspc({ "toy" }), "Collider", sizeof(toy::Collider), TypeClass::Object };
		static Class cls = { type<toy::Collider>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Collider>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Collider>(ref)) toy::Collider(  ); }, {} },
				{ type<toy::Collider>(), [](Ref ref, array<Var> args) { new(&val<toy::Collider>(ref)) toy::Collider( val<toy::HSpatial>(args[0]), val<toy::HMovable>(args[1]), val<toy::CollisionShape>(args[2]), val<toy::Medium>(args[3]), val<toy::CollisionGroup>(args[4]) ); }, { { "spatial", var(toy::HSpatial()) }, { "movable", var(toy::HMovable()) }, { "collision_shape", Ref(type<toy::CollisionShape>()) }, { "medium", Ref(type<toy::Medium>()) }, { "group", var(toy::CollisionGroup()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::Collider>(), member_address(&toy::Collider::m_spatial), type<toy::HSpatial>(), "spatial", var(toy::HSpatial()), Member::Value, nullptr },
				{ type<toy::Collider>(), member_address(&toy::Collider::m_movable), type<toy::HMovable>(), "movable", var(toy::HMovable()), Member::Value, nullptr },
				{ type<toy::Collider>(), member_address(&toy::Collider::m_collision_shape), type<toy::CollisionShape>(), "collision_shape", Ref(type<toy::CollisionShape>()), Member::NonMutable, nullptr },
				{ type<toy::Collider>(), member_address(&toy::Collider::m_medium), type<toy::Medium>(), "medium", Ref(type<toy::Medium>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
				{ type<toy::Collider>(), member_address(&toy::Collider::m_group), type<toy::CollisionGroup>(), "group", var(toy::CollisionGroup()), Member::Value, nullptr },
				{ type<toy::Collider>(), member_address(&toy::Collider::m_object), type<toy::ColliderObject>(), "object", Ref(type<toy::ColliderObject>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
				{ type<toy::Collider>(), member_address<toy::ColliderImpl&(toy::Collider::*)()>(&toy::Collider::impl), type<toy::ColliderImpl>(), "impl", Ref(type<toy::ColliderImpl>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Collider>(object).impl()); } }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::Collider>();
		meta_class<toy::Collider>();
	}
	// toy::ColliderImpl
	{
		static Meta meta = { type<toy::ColliderImpl>(), &namspc({ "toy" }), "ColliderImpl", sizeof(toy::ColliderImpl), TypeClass::Object };
		static Class cls = { type<toy::ColliderImpl>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::ColliderImpl>();
	}
	// toy::ColliderObject
	{
		static Meta meta = { type<toy::ColliderObject>(), &namspc({ "toy" }), "ColliderObject", sizeof(toy::ColliderObject), TypeClass::Object };
		static Class cls = { type<toy::ColliderObject>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::ColliderObject>();
	}
	// toy::Collision
	{
		static Meta meta = { type<toy::Collision>(), &namspc({ "toy" }), "Collision", sizeof(toy::Collision), TypeClass::Struct };
		static Class cls = { type<toy::Collision>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Collision>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Collision>(ref)) toy::Collision(  ); }, {} }
			},
			// copy constructor
			{
				{ type<toy::Collision>(), [](Ref ref, Ref other) { new(&val<toy::Collision>(ref)) toy::Collision(val<toy::Collision>(other)); } }
			},
			// members
			{
				{ type<toy::Collision>(), member_address(&toy::Collision::m_first), type<toy::HCollider>(), "first", var(toy::HCollider{}), Member::Value, nullptr },
				{ type<toy::Collision>(), member_address(&toy::Collision::m_second), type<toy::HCollider>(), "second", var(toy::HCollider{}), Member::Value, nullptr },
				{ type<toy::Collision>(), member_address(&toy::Collision::m_hit_point), type<mud::vec3>(), "hit_point", var(mud::vec3(Zero3)), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::Collision>();
	}
	// toy::CollisionShape
	{
		static Meta meta = { type<toy::CollisionShape>(), &namspc({ "toy" }), "CollisionShape", sizeof(toy::CollisionShape), TypeClass::Object };
		static Class cls = { type<toy::CollisionShape>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::CollisionShape>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::CollisionShape>(ref)) toy::CollisionShape(  ); }, {} },
				{ type<toy::CollisionShape>(), [](Ref ref, array<Var> args) { new(&val<toy::CollisionShape>(ref)) toy::CollisionShape( val<mud::Shape>(args[0]), val<mud::vec3>(args[1]), val<float>(args[2]) ); }, { { "shape", Ref(type<mud::Shape>()) }, { "center", var(mud::vec3(Zero3)), Param::Default }, { "margin", var(float(0.f)), Param::Default } } }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::CollisionShape>();
		meta_class<toy::CollisionShape>();
	}
	// toy::ComponentPool
	{
		static Meta meta = { type<toy::ComponentPool>(), &namspc({ "toy" }), "ComponentPool", sizeof(toy::ComponentPool), TypeClass::Object };
		static Class cls = { type<toy::ComponentPool>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::ComponentPool>();
	}
	// toy::Core
	{
		static Meta meta = { type<toy::Core>(), &namspc({ "toy" }), "Core", sizeof(toy::Core), TypeClass::Object };
		static Class cls = { type<toy::Core>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::Core>();
	}
	// toy::DetourPath
	{
		static Meta meta = { type<toy::DetourPath>(), &namspc({ "toy" }), "DetourPath", sizeof(toy::DetourPath), TypeClass::Object };
		static Class cls = { type<toy::DetourPath>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::DetourPath>();
	}
	// toy::Emitter
	{
		static Meta meta = { type<toy::Emitter>(), &namspc({ "toy" }), "Emitter", sizeof(toy::Emitter), TypeClass::Object };
		static Class cls = { type<toy::Emitter>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Emitter>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Emitter>(ref)) toy::Emitter(  ); }, {} },
				{ type<toy::Emitter>(), [](Ref ref, array<Var> args) { new(&val<toy::Emitter>(ref)) toy::Emitter( val<toy::HSpatial>(args[0]) ); }, { { "spatial", var(toy::HSpatial()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::Emitter>();
		meta_class<toy::Emitter>();
	}
	// toy::EntityScript
	{
		static Meta meta = { type<toy::EntityScript>(), &namspc({ "toy" }), "EntityScript", sizeof(toy::EntityScript), TypeClass::Object };
		static Class cls = { type<toy::EntityScript>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::EntityScript>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::EntityScript>(ref)) toy::EntityScript(  ); }, {} },
				{ type<toy::EntityScript>(), [](Ref ref, array<Var> args) { new(&val<toy::EntityScript>(ref)) toy::EntityScript( val<toy::HSpatial>(args[0]) ); }, { { "spatial", var(toy::HSpatial()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::EntityScript>(), member_address(&toy::EntityScript::m_logic_script), type<mud::Script>(), "logic_script", Ref(type<mud::Script>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
				{ type<toy::EntityScript>(), member_address(&toy::EntityScript::m_render_script), type<mud::Script>(), "render_script", Ref(type<mud::Script>()), Member::Flags(Member::Pointer|Member::Link), nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::EntityScript>();
		meta_class<toy::EntityScript>();
	}
	// toy::Medium
	{
		static Meta meta = { type<toy::Medium>(), &namspc({ "toy" }), "Medium", sizeof(toy::Medium), TypeClass::Object };
		static Class cls = { type<toy::Medium>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::Medium>(), member_address(&toy::Medium::m_name), type<string>(), "name", var(string()), Member::Value, nullptr },
				{ type<toy::Medium>(), member_address(&toy::Medium::m_occlusions), type<bool>(), "occlusions", var(bool()), Member::Value, nullptr },
				{ type<toy::Medium>(), member_address(&toy::Medium::m_solid), type<bool>(), "solid", var(bool()), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::Medium>();
	}
	// toy::Movable
	{
		static Meta meta = { type<toy::Movable>(), &namspc({ "toy" }), "Movable", sizeof(toy::Movable), TypeClass::Object };
		static Class cls = { type<toy::Movable>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Movable>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Movable>(ref)) toy::Movable(  ); }, {} },
				{ type<toy::Movable>(), [](Ref ref, array<Var> args) { new(&val<toy::Movable>(ref)) toy::Movable( val<toy::HSpatial>(args[0]) ); }, { { "spatial", var(toy::HSpatial()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::Movable>(), member_address(&toy::Movable::m_linear_velocity), type<mud::vec3>(), "linear_velocity", var(mud::vec3(Zero3)), Member::Value, nullptr },
				{ type<toy::Movable>(), member_address(&toy::Movable::m_angular_velocity), type<mud::vec3>(), "angular_velocity", var(mud::vec3(Zero3)), Member::Value, nullptr },
				{ type<toy::Movable>(), member_address(&toy::Movable::m_moving), type<bool>(), "moving", var(bool(false)), Member::Value, nullptr },
				{ type<toy::Movable>(), member_address(&toy::Movable::m_previous_position), type<mud::vec3>(), "previous_position", var(mud::vec3()), Member::Value, nullptr }
			},
			// methods
			{
				{ type<toy::Movable>(), "set_linear_velocity", member_address<void(toy::Movable::*)(const mud::vec3&)>(&toy::Movable::set_linear_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Movable>(object).set_linear_velocity(val<mud::vec3>(args[0])); }, { { "velocity", var(mud::vec3()) } }, Var() },
				{ type<toy::Movable>(), "modify_linear_velocity", member_address<void(toy::Movable::*)(const mud::vec3&)>(&toy::Movable::modify_linear_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Movable>(object).modify_linear_velocity(val<mud::vec3>(args[0])); }, { { "velocity", var(mud::vec3()) } }, Var() },
				{ type<toy::Movable>(), "set_angular_velocity", member_address<void(toy::Movable::*)(const mud::vec3&)>(&toy::Movable::set_angular_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Movable>(object).set_angular_velocity(val<mud::vec3>(args[0])); }, { { "velocity", var(mud::vec3()) } }, Var() },
				{ type<toy::Movable>(), "modify_angular_velocity", member_address<void(toy::Movable::*)(const mud::vec3&)>(&toy::Movable::modify_angular_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Movable>(object).modify_angular_velocity(val<mud::vec3>(args[0])); }, { { "velocity", var(mud::vec3()) } }, Var() }
			},
			// static members
			{
			}
		};
		init_pool<toy::Movable>();
		meta_class<toy::Movable>();
	}
	// toy::Navblock
	{
		static Meta meta = { type<toy::Navblock>(), &namspc({ "toy" }), "Navblock", sizeof(toy::Navblock), TypeClass::Object };
		static Class cls = { type<toy::Navblock>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Navblock>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Navblock>(ref)) toy::Navblock(  ); }, {} },
				{ type<toy::Navblock>(), [](Ref ref, array<Var> args) { new(&val<toy::Navblock>(ref)) toy::Navblock( val<toy::HSpatial>(args[0]), val<toy::HWorldPage>(args[1]), val<toy::Navmesh>(args[2]) ); }, { { "spatial", var(toy::HSpatial()) }, { "world_page", var(toy::HWorldPage()) }, { "navmesh", Ref(type<toy::Navmesh>()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::Navblock>(), member_address(&toy::Navblock::m_navmesh), type<toy::Navmesh>(), "navmesh", Ref(type<toy::Navmesh>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
				{ type<toy::Navblock>(), member_address(&toy::Navblock::m_auto_update), type<bool>(), "auto_update", var(bool(false)), Member::Value, nullptr },
				{ type<toy::Navblock>(), member_address(&toy::Navblock::m_updated), type<size_t>(), "updated", var(size_t(0)), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::Navblock>();
		meta_class<toy::Navblock>();
	}
	// toy::Navmesh
	{
		static Meta meta = { type<toy::Navmesh>(), &namspc({ "toy" }), "Navmesh", sizeof(toy::Navmesh), TypeClass::Object };
		static Class cls = { type<toy::Navmesh>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Navmesh>(), [](Ref ref, array<Var> args) { new(&val<toy::Navmesh>(ref)) toy::Navmesh( val<toy::World>(args[0]) ); }, { { "world", Ref(type<toy::World>()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::Navmesh>(), Address(), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Navmesh>(object).m_world); } },
				{ type<toy::Navmesh>(), member_address(&toy::Navmesh::m_updated), type<size_t>(), "updated", var(size_t(0)), Member::Value, nullptr },
				{ type<toy::Navmesh>(), member_address(&toy::Navmesh::m_dirty), type<bool>(), "dirty", var(bool(false)), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::Navmesh>();
		meta_class<toy::Navmesh>();
	}
	// toy::Origin
	{
		static Meta meta = { type<toy::Origin>(), &namspc({ "toy" }), "Origin", sizeof(toy::Origin), TypeClass::Object };
		static Class cls = { type<toy::Origin>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Origin>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Origin>(ref)) toy::Origin(  ); }, {} },
				{ type<toy::Origin>(), [](Ref ref, array<Var> args) { new(&val<toy::Origin>(ref)) toy::Origin( val<toy::HSpatial>(args[0]) ); }, { { "spatial", var(toy::HSpatial()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::Origin>();
		meta_class<toy::Origin>();
	}
	// mud::OwnedHandle<toy::Collider>
	{
		static Meta meta = { type<mud::OwnedHandle<toy::Collider>>(), &namspc({ "mud" }), "OwnedHandle<toy::Collider>", sizeof(mud::OwnedHandle<toy::Collider>), TypeClass::Struct };
		static Class cls = { type<mud::OwnedHandle<toy::Collider>>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<mud::OwnedHandle<toy::Collider>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::OwnedHandle<toy::Collider>>(ref)) mud::OwnedHandle<toy::Collider>(  ); }, {} }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::OwnedHandle<toy::Collider>>();
	}
	// mud::OwnedHandle<toy::Solid>
	{
		static Meta meta = { type<mud::OwnedHandle<toy::Solid>>(), &namspc({ "mud" }), "OwnedHandle<toy::Solid>", sizeof(mud::OwnedHandle<toy::Solid>), TypeClass::Struct };
		static Class cls = { type<mud::OwnedHandle<toy::Solid>>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<mud::OwnedHandle<toy::Solid>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::OwnedHandle<toy::Solid>>(ref)) mud::OwnedHandle<toy::Solid>(  ); }, {} }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::OwnedHandle<toy::Solid>>();
	}
	// toy::Pathfinder
	{
		static Meta meta = { type<toy::Pathfinder>(), &namspc({ "toy" }), "Pathfinder", sizeof(toy::Pathfinder), TypeClass::Object };
		static Class cls = { type<toy::Pathfinder>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Pathfinder>(), [](Ref ref, array<Var> args) { new(&val<toy::Pathfinder>(ref)) toy::Pathfinder( val<toy::Navmesh>(args[0]) ); }, { { "navmesh", Ref(type<toy::Navmesh>()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::Pathfinder>();
		meta_class<toy::Pathfinder>();
	}
	// toy::PhysicWorld
	{
		static Meta meta = { type<toy::PhysicWorld>(), &namspc({ "toy" }), "PhysicWorld", sizeof(toy::PhysicWorld), TypeClass::Object };
		static Class cls = { type<toy::PhysicWorld>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::PhysicWorld>(), Address(), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::PhysicWorld>(object).m_world); } }
			},
			// methods
			{
				{ type<toy::PhysicWorld>(), "ground_point", member_address<mud::vec3(toy::PhysicWorld::*)(const mud::Ray&)>(&toy::PhysicWorld::ground_point), [](Ref object, array<Var> args, Var& result) { val<mud::vec3>(result) = val<toy::PhysicWorld>(object).ground_point(val<mud::Ray>(args[0])); }, { { "ray", var(mud::Ray()) } }, var(mud::vec3()) },
				{ type<toy::PhysicWorld>(), "raycast", member_address<toy::Collision(toy::PhysicWorld::*)(const mud::Ray&, short)>(&toy::PhysicWorld::raycast), [](Ref object, array<Var> args, Var& result) { val<toy::Collision>(result) = val<toy::PhysicWorld>(object).raycast(val<mud::Ray>(args[0]), val<short>(args[1])); }, { { "ray", var(mud::Ray()) }, { "mask", var(short()) } }, var(toy::Collision()) }
			},
			// static members
			{
			}
		};
		meta_class<toy::PhysicWorld>();
	}
	// toy::Receptor
	{
		static Meta meta = { type<toy::Receptor>(), &namspc({ "toy" }), "Receptor", sizeof(toy::Receptor), TypeClass::Object };
		static Class cls = { type<toy::Receptor>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Receptor>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Receptor>(ref)) toy::Receptor(  ); }, {} },
				{ type<toy::Receptor>(), [](Ref ref, array<Var> args) { new(&val<toy::Receptor>(ref)) toy::Receptor( val<toy::HSpatial>(args[0]) ); }, { { "spatial", var(toy::HSpatial()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
				{ type<toy::Receptor>(), "scope", member_address<toy::ReceptorScope*(toy::Receptor::*)(toy::Medium&)>(&toy::Receptor::scope), [](Ref object, array<Var> args, Var& result) { result = Ref(val<toy::Receptor>(object).scope(val<toy::Medium>(args[0]))); }, { { "medium", Ref(type<toy::Medium>()) } }, Ref(type<toy::ReceptorScope>()) }
			},
			// static members
			{
			}
		};
		init_pool<toy::Receptor>();
		meta_class<toy::Receptor>();
	}
	// toy::Solid
	{
		static Meta meta = { type<toy::Solid>(), &namspc({ "toy" }), "Solid", sizeof(toy::Solid), TypeClass::Object };
		static Class cls = { type<toy::Solid>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::Solid>(), member_address(&toy::Solid::m_spatial), type<toy::HSpatial>(), "spatial", var(toy::HSpatial()), Member::Value, nullptr },
				{ type<toy::Solid>(), member_address(&toy::Solid::m_static), type<bool>(), "static", var(bool(false)), Member::Value, nullptr },
				{ type<toy::Solid>(), member_address(&toy::Solid::m_mass), type<float>(), "mass", var(float(0.f)), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::Solid>();
	}
	// toy::SolidImpl
	{
		static Meta meta = { type<toy::SolidImpl>(), &namspc({ "toy" }), "SolidImpl", sizeof(toy::SolidImpl), TypeClass::Object };
		static Class cls = { type<toy::SolidImpl>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
				{ type<toy::SolidImpl>(), "linear_velocity", member_address<mud::vec3(toy::SolidImpl::*)()>(&toy::SolidImpl::linear_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(args); val<mud::vec3>(result) = val<toy::SolidImpl>(object).linear_velocity(); }, {}, var(mud::vec3()) },
				{ type<toy::SolidImpl>(), "angular_velocity", member_address<mud::vec3(toy::SolidImpl::*)()>(&toy::SolidImpl::angular_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(args); val<mud::vec3>(result) = val<toy::SolidImpl>(object).angular_velocity(); }, {}, var(mud::vec3()) },
				{ type<toy::SolidImpl>(), "set_linear_velocity", member_address<void(toy::SolidImpl::*)(const mud::vec3&)>(&toy::SolidImpl::set_linear_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::SolidImpl>(object).set_linear_velocity(val<mud::vec3>(args[0])); }, { { "force", var(mud::vec3()) } }, Var() },
				{ type<toy::SolidImpl>(), "set_angular_velocity", member_address<void(toy::SolidImpl::*)(const mud::vec3&)>(&toy::SolidImpl::set_angular_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::SolidImpl>(object).set_angular_velocity(val<mud::vec3>(args[0])); }, { { "torque", var(mud::vec3()) } }, Var() },
				{ type<toy::SolidImpl>(), "set_angular_factor", member_address<void(toy::SolidImpl::*)(const mud::vec3&)>(&toy::SolidImpl::set_angular_factor), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::SolidImpl>(object).set_angular_factor(val<mud::vec3>(args[0])); }, { { "factor", var(mud::vec3()) } }, Var() },
				{ type<toy::SolidImpl>(), "impulse", member_address<void(toy::SolidImpl::*)(const mud::vec3&, const mud::vec3&)>(&toy::SolidImpl::impulse), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::SolidImpl>(object).impulse(val<mud::vec3>(args[0]), val<mud::vec3>(args[1])); }, { { "force", var(mud::vec3()) }, { "point", var(mud::vec3()) } }, Var() }
			},
			// static members
			{
			}
		};
		meta_class<toy::SolidImpl>();
	}
	// mud::SparseHandle<toy::Collider>
	{
		static Meta meta = { type<mud::SparseHandle<toy::Collider>>(), &namspc({ "mud" }), "SparseHandle<toy::Collider>", sizeof(mud::SparseHandle<toy::Collider>), TypeClass::Struct };
		static Class cls = { type<mud::SparseHandle<toy::Collider>>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<mud::SparseHandle<toy::Collider>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::SparseHandle<toy::Collider>>(ref)) mud::SparseHandle<toy::Collider>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::SparseHandle<toy::Collider>>(), [](Ref ref, Ref other) { new(&val<mud::SparseHandle<toy::Collider>>(ref)) mud::SparseHandle<toy::Collider>(val<mud::SparseHandle<toy::Collider>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::SparseHandle<toy::Collider>>();
	}
	// mud::SparseHandle<toy::Solid>
	{
		static Meta meta = { type<mud::SparseHandle<toy::Solid>>(), &namspc({ "mud" }), "SparseHandle<toy::Solid>", sizeof(mud::SparseHandle<toy::Solid>), TypeClass::Struct };
		static Class cls = { type<mud::SparseHandle<toy::Solid>>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<mud::SparseHandle<toy::Solid>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::SparseHandle<toy::Solid>>(ref)) mud::SparseHandle<toy::Solid>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::SparseHandle<toy::Solid>>(), [](Ref ref, Ref other) { new(&val<mud::SparseHandle<toy::Solid>>(ref)) mud::SparseHandle<toy::Solid>(val<mud::SparseHandle<toy::Solid>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::SparseHandle<toy::Solid>>();
	}
	// toy::User
	{
		static Meta meta = { type<toy::User>(), &namspc({ "toy" }), "User", sizeof(toy::User), TypeClass::Object };
		static Class cls = { type<toy::User>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::User>();
	}
	// toy::Waypoint
	{
		static Meta meta = { type<toy::Waypoint>(), &namspc({ "toy" }), "Waypoint", sizeof(toy::Waypoint), TypeClass::Object };
		static Class cls = { type<toy::Waypoint>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::Waypoint>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Waypoint>(ref)) toy::Waypoint(  ); }, {} },
				{ type<toy::Waypoint>(), [](Ref ref, array<Var> args) { new(&val<toy::Waypoint>(ref)) toy::Waypoint( val<toy::HSpatial>(args[0]) ); }, { { "parent", var(toy::HSpatial()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::Waypoint>();
		meta_class<toy::Waypoint>();
	}
	// toy::World
	{
		static Meta meta = { type<toy::World>(), &namspc({ "toy" }), "World", sizeof(toy::World), TypeClass::Object };
		static Class cls = { type<toy::World>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::World>(), [](Ref ref, array<Var> args) { new(&val<toy::World>(ref)) toy::World( val<uint32_t>(args[0]), val<mud::Complex>(args[1]), val<string>(args[2]), val<mud::JobSystem>(args[3]) ); }, { { "id", var(uint32_t()) }, { "complex", Ref(type<mud::Complex>()) }, { "name", var(string()) }, { "job_system", Ref(type<mud::JobSystem>()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::World>(), member_address(&toy::World::m_id), type<uint32_t>(), "id", var(uint32_t()), Member::Value, nullptr },
				{ type<toy::World>(), Address(), type<mud::Complex>(), "complex", Ref(type<mud::Complex>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::World>(object).m_complex); } },
				{ type<toy::World>(), member_address(&toy::World::m_name), type<string>(), "name", var(string()), Member::Value, nullptr },
				{ type<toy::World>(), member_address<toy::HSpatial(toy::World::*)()>(&toy::World::origin), type<toy::HSpatial>(), "origin", var(toy::HSpatial()), Member::Flags(Member::Value|Member::NonMutable|Member::Structure), nullptr },
				{ type<toy::World>(), member_address<toy::HSpatial(toy::World::*)()>(&toy::World::unworld), type<toy::HSpatial>(), "unworld", var(toy::HSpatial()), Member::Flags(Member::Value|Member::NonMutable|Member::Structure), nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::World>();
		meta_class<toy::World>();
	}
	// toy::WorldClock
	{
		static Meta meta = { type<toy::WorldClock>(), &namspc({ "toy" }), "WorldClock", sizeof(toy::WorldClock), TypeClass::Object };
		static Class cls = { type<toy::WorldClock>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::WorldClock>();
	}
	// toy::WorldPage
	{
		static Meta meta = { type<toy::WorldPage>(), &namspc({ "toy" }), "WorldPage", sizeof(toy::WorldPage), TypeClass::Object };
		static Class cls = { type<toy::WorldPage>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<toy::WorldPage>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::WorldPage>(ref)) toy::WorldPage(  ); }, {} },
				{ type<toy::WorldPage>(), [](Ref ref, array<Var> args) { new(&val<toy::WorldPage>(ref)) toy::WorldPage( val<toy::HSpatial>(args[0]), val<bool>(args[1]), val<mud::vec3>(args[2]) ); }, { { "spatial", var(toy::HSpatial()) }, { "open", var(bool()) }, { "extents", var(mud::vec3()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::WorldPage>(), member_address(&toy::WorldPage::m_open), type<bool>(), "open", var(bool(true)), Member::Value, nullptr },
				{ type<toy::WorldPage>(), member_address(&toy::WorldPage::m_extents), type<mud::vec3>(), "extents", var(mud::vec3(Zero3)), Member::Value, nullptr },
				{ type<toy::WorldPage>(), member_address(&toy::WorldPage::m_world), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
				{ type<toy::WorldPage>(), member_address(&toy::WorldPage::m_last_rebuilt), type<size_t>(), "last_rebuilt", var(size_t(0)), Member::Value, nullptr }
			},
			// methods
			{
				{ type<toy::WorldPage>(), "update_geometry", member_address<void(toy::WorldPage::*)(size_t)>(&toy::WorldPage::update_geometry), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::WorldPage>(object).update_geometry(val<size_t>(args[0])); }, { { "tick", var(size_t()) } }, Var() },
				{ type<toy::WorldPage>(), "ground_point", member_address<void(toy::WorldPage::*)(const mud::vec3&, bool, mud::vec3&)>(&toy::WorldPage::ground_point), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::WorldPage>(object).ground_point(val<mud::vec3>(args[0]), val<bool>(args[1]), val<mud::vec3>(args[2])); }, { { "position", var(mud::vec3()) }, { "relative", var(bool()) }, { "outputPoint", var(mud::vec3()), Param::Output } }, Var() },
				{ type<toy::WorldPage>(), "raycast_ground", member_address<void(toy::WorldPage::*)(const mud::vec3&, const mud::vec3&, mud::vec3&)>(&toy::WorldPage::raycast_ground), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::WorldPage>(object).raycast_ground(val<mud::vec3>(args[0]), val<mud::vec3>(args[1]), val<mud::vec3>(args[2])); }, { { "from", var(mud::vec3()) }, { "to", var(mud::vec3()) }, { "ground_point", var(mud::vec3()) } }, Var() }
			},
			// static members
			{
			}
		};
		init_pool<toy::WorldPage>();
		meta_class<toy::WorldPage>();
	}
	// toy::BulletCollider
	{
		static Meta meta = { type<toy::BulletCollider>(), &namspc({ "toy" }), "BulletCollider", sizeof(toy::BulletCollider), TypeClass::Object };
		static Class cls = { type<toy::BulletCollider>(),
			// bases
			{ &type<toy::ColliderImpl>() },
			{ base_offset<toy::BulletCollider, toy::ColliderImpl>() },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::BulletCollider>();
	}
	// toy::BulletSolid
	{
		static Meta meta = { type<toy::BulletSolid>(), &namspc({ "toy" }), "BulletSolid", sizeof(toy::BulletSolid), TypeClass::Object };
		static Class cls = { type<toy::BulletSolid>(),
			// bases
			{ &type<toy::SolidImpl>() },
			{ base_offset<toy::BulletSolid, toy::SolidImpl>() },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::BulletSolid>();
	}
	// toy::BulletWorld
	{
		static Meta meta = { type<toy::BulletWorld>(), &namspc({ "toy" }), "BulletWorld", sizeof(toy::BulletWorld), TypeClass::Object };
		static Class cls = { type<toy::BulletWorld>(),
			// bases
			{ &type<toy::PhysicWorld>() },
			{ base_offset<toy::BulletWorld, toy::PhysicWorld>() },
			// constructors
			{
				{ type<toy::BulletWorld>(), [](Ref ref, array<Var> args) { new(&val<toy::BulletWorld>(ref)) toy::BulletWorld( val<toy::World>(args[0]) ); }, { { "world", Ref(type<toy::World>()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::BulletWorld>();
		meta_class<toy::BulletWorld>();
	}
	// mud::ComponentHandle<toy::Camera>
	{
		static Meta meta = { type<mud::ComponentHandle<toy::Camera>>(), &namspc({ "mud" }), "ComponentHandle<toy::Camera>", sizeof(mud::ComponentHandle<toy::Camera>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<toy::Camera>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<toy::Camera>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<toy::Camera>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Camera>>(ref)) mud::ComponentHandle<toy::Camera>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<toy::Camera>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Camera>>(ref)) mud::ComponentHandle<toy::Camera>(val<mud::ComponentHandle<toy::Camera>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::ComponentHandle<toy::Camera>>();
	}
	// mud::ComponentHandle<toy::Emitter>
	{
		static Meta meta = { type<mud::ComponentHandle<toy::Emitter>>(), &namspc({ "mud" }), "ComponentHandle<toy::Emitter>", sizeof(mud::ComponentHandle<toy::Emitter>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<toy::Emitter>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<toy::Emitter>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<toy::Emitter>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Emitter>>(ref)) mud::ComponentHandle<toy::Emitter>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<toy::Emitter>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Emitter>>(ref)) mud::ComponentHandle<toy::Emitter>(val<mud::ComponentHandle<toy::Emitter>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::ComponentHandle<toy::Emitter>>();
	}
	// mud::ComponentHandle<toy::EntityScript>
	{
		static Meta meta = { type<mud::ComponentHandle<toy::EntityScript>>(), &namspc({ "mud" }), "ComponentHandle<toy::EntityScript>", sizeof(mud::ComponentHandle<toy::EntityScript>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<toy::EntityScript>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<toy::EntityScript>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<toy::EntityScript>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::EntityScript>>(ref)) mud::ComponentHandle<toy::EntityScript>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<toy::EntityScript>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::EntityScript>>(ref)) mud::ComponentHandle<toy::EntityScript>(val<mud::ComponentHandle<toy::EntityScript>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::ComponentHandle<toy::EntityScript>>();
	}
	// mud::ComponentHandle<toy::Movable>
	{
		static Meta meta = { type<mud::ComponentHandle<toy::Movable>>(), &namspc({ "mud" }), "ComponentHandle<toy::Movable>", sizeof(mud::ComponentHandle<toy::Movable>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<toy::Movable>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<toy::Movable>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<toy::Movable>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Movable>>(ref)) mud::ComponentHandle<toy::Movable>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<toy::Movable>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Movable>>(ref)) mud::ComponentHandle<toy::Movable>(val<mud::ComponentHandle<toy::Movable>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::ComponentHandle<toy::Movable>>();
	}
	// mud::ComponentHandle<toy::Navblock>
	{
		static Meta meta = { type<mud::ComponentHandle<toy::Navblock>>(), &namspc({ "mud" }), "ComponentHandle<toy::Navblock>", sizeof(mud::ComponentHandle<toy::Navblock>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<toy::Navblock>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<toy::Navblock>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<toy::Navblock>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Navblock>>(ref)) mud::ComponentHandle<toy::Navblock>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<toy::Navblock>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Navblock>>(ref)) mud::ComponentHandle<toy::Navblock>(val<mud::ComponentHandle<toy::Navblock>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::ComponentHandle<toy::Navblock>>();
	}
	// mud::ComponentHandle<toy::Origin>
	{
		static Meta meta = { type<mud::ComponentHandle<toy::Origin>>(), &namspc({ "mud" }), "ComponentHandle<toy::Origin>", sizeof(mud::ComponentHandle<toy::Origin>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<toy::Origin>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<toy::Origin>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<toy::Origin>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Origin>>(ref)) mud::ComponentHandle<toy::Origin>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<toy::Origin>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Origin>>(ref)) mud::ComponentHandle<toy::Origin>(val<mud::ComponentHandle<toy::Origin>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::ComponentHandle<toy::Origin>>();
	}
	// mud::ComponentHandle<toy::Receptor>
	{
		static Meta meta = { type<mud::ComponentHandle<toy::Receptor>>(), &namspc({ "mud" }), "ComponentHandle<toy::Receptor>", sizeof(mud::ComponentHandle<toy::Receptor>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<toy::Receptor>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<toy::Receptor>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<toy::Receptor>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Receptor>>(ref)) mud::ComponentHandle<toy::Receptor>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<toy::Receptor>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Receptor>>(ref)) mud::ComponentHandle<toy::Receptor>(val<mud::ComponentHandle<toy::Receptor>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::ComponentHandle<toy::Receptor>>();
	}
	// mud::ComponentHandle<toy::Spatial>
	{
		static Meta meta = { type<mud::ComponentHandle<toy::Spatial>>(), &namspc({ "mud" }), "ComponentHandle<toy::Spatial>", sizeof(mud::ComponentHandle<toy::Spatial>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<toy::Spatial>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<toy::Spatial>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<toy::Spatial>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Spatial>>(ref)) mud::ComponentHandle<toy::Spatial>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<toy::Spatial>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Spatial>>(ref)) mud::ComponentHandle<toy::Spatial>(val<mud::ComponentHandle<toy::Spatial>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::ComponentHandle<toy::Spatial>>();
	}
	// mud::ComponentHandle<toy::Waypoint>
	{
		static Meta meta = { type<mud::ComponentHandle<toy::Waypoint>>(), &namspc({ "mud" }), "ComponentHandle<toy::Waypoint>", sizeof(mud::ComponentHandle<toy::Waypoint>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<toy::Waypoint>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<toy::Waypoint>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<toy::Waypoint>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Waypoint>>(ref)) mud::ComponentHandle<toy::Waypoint>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<toy::Waypoint>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Waypoint>>(ref)) mud::ComponentHandle<toy::Waypoint>(val<mud::ComponentHandle<toy::Waypoint>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::ComponentHandle<toy::Waypoint>>();
	}
	// mud::ComponentHandle<toy::WorldPage>
	{
		static Meta meta = { type<mud::ComponentHandle<toy::WorldPage>>(), &namspc({ "mud" }), "ComponentHandle<toy::WorldPage>", sizeof(mud::ComponentHandle<toy::WorldPage>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<toy::WorldPage>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<toy::WorldPage>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<toy::WorldPage>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::WorldPage>>(ref)) mud::ComponentHandle<toy::WorldPage>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<toy::WorldPage>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::WorldPage>>(ref)) mud::ComponentHandle<toy::WorldPage>(val<mud::ComponentHandle<toy::WorldPage>>(other)); } }
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<mud::ComponentHandle<toy::WorldPage>>();
	}
	// toy::DefaultWorld
	{
		static Meta meta = { type<toy::DefaultWorld>(), &namspc({ "toy" }), "DefaultWorld", sizeof(toy::DefaultWorld), TypeClass::Object };
		static Class cls = { type<toy::DefaultWorld>(),
			// bases
			{ &type<mud::Complex>() },
			{ base_offset<toy::DefaultWorld, mud::Complex>() },
			// constructors
			{
				{ type<toy::DefaultWorld>(), [](Ref ref, array<Var> args) { new(&val<toy::DefaultWorld>(ref)) toy::DefaultWorld( val<string>(args[0]), val<mud::JobSystem>(args[1]) ); }, { { "name", var(string()) }, { "job_system", Ref(type<mud::JobSystem>()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::DefaultWorld>(), member_address(&toy::DefaultWorld::m_world), type<toy::World>(), "world", Ref(type<toy::World>()), Member::NonMutable, nullptr },
				{ type<toy::DefaultWorld>(), member_address(&toy::DefaultWorld::m_bullet_world), type<toy::BulletWorld>(), "bullet_world", Ref(type<toy::BulletWorld>()), Member::Flags(Member::NonMutable|Member::Component), nullptr },
				{ type<toy::DefaultWorld>(), member_address(&toy::DefaultWorld::m_navmesh), type<toy::Navmesh>(), "navmesh", Ref(type<toy::Navmesh>()), Member::Flags(Member::NonMutable|Member::Component), nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::DefaultWorld>();
		meta_class<toy::DefaultWorld>();
	}
	// toy::EmitterScope
	{
		static Meta meta = { type<toy::EmitterScope>(), &namspc({ "toy" }), "EmitterScope", sizeof(toy::EmitterScope), TypeClass::Object };
		static Class cls = { type<toy::EmitterScope>(),
			// bases
			{ &type<toy::PhysicScope>() },
			{ base_offset<toy::EmitterScope, toy::PhysicScope>() },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::EmitterScope>();
	}
	// toy::NavmeshShape
	{
		static Meta meta = { type<toy::NavmeshShape>(), &namspc({ "toy" }), "NavmeshShape", sizeof(toy::NavmeshShape), TypeClass::Object };
		static Class cls = { type<toy::NavmeshShape>(),
			// bases
			{ &type<mud::Shape>() },
			{ base_offset<toy::NavmeshShape, mud::Shape>() },
			// constructors
			{
				{ type<toy::NavmeshShape>(), [](Ref ref, array<Var> args) { new(&val<toy::NavmeshShape>(ref)) toy::NavmeshShape( val<toy::Navmesh>(args[0]) ); }, { { "navmesh", Ref(type<toy::Navmesh>()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::NavmeshShape>();
		meta_class<toy::NavmeshShape>();
	}
	// toy::Obstacle
	{
		static Meta meta = { type<toy::Obstacle>(), &namspc({ "toy" }), "Obstacle", sizeof(toy::Obstacle), TypeClass::Object };
		static Class cls = { type<toy::Obstacle>(),
			// bases
			{ &type<toy::Collider>() },
			{ base_offset<toy::Obstacle, toy::Collider>() },
			// constructors
			{
				{ type<toy::Obstacle>(), [](Ref ref, array<Var> args) { new(&val<toy::Obstacle>(ref)) toy::Obstacle( val<toy::HSpatial>(args[0]), val<toy::HMovable>(args[1]), val<toy::Medium>(args[2]), val<toy::CollisionShape>(args[3]), val<float>(args[4]) ); }, { { "spatial", var(toy::HSpatial()) }, { "movable", var(toy::HMovable()) }, { "medium", Ref(type<toy::Medium>()) }, { "shape", Ref(type<toy::CollisionShape>()) }, { "throughput", var(float()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::Obstacle>(), member_address(&toy::Obstacle::m_shape), type<toy::CollisionShape>(), "shape", Ref(type<toy::CollisionShape>()), Member::NonMutable, nullptr },
				{ type<toy::Obstacle>(), member_address(&toy::Obstacle::m_throughput), type<float>(), "throughput", var(float()), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<toy::Obstacle>();
		meta_class<toy::Obstacle>();
	}
	// toy::PhysicScope
	{
		static Meta meta = { type<toy::PhysicScope>(), &namspc({ "toy" }), "PhysicScope", sizeof(toy::PhysicScope), TypeClass::Object };
		static Class cls = { type<toy::PhysicScope>(),
			// bases
			{ &type<toy::ColliderObject>() },
			{ base_offset<toy::PhysicScope, toy::ColliderObject>() },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::PhysicScope>();
	}
	// toy::ReceptorScope
	{
		static Meta meta = { type<toy::ReceptorScope>(), &namspc({ "toy" }), "ReceptorScope", sizeof(toy::ReceptorScope), TypeClass::Object };
		static Class cls = { type<toy::ReceptorScope>(),
			// bases
			{ &type<toy::PhysicScope>() },
			{ base_offset<toy::ReceptorScope, toy::PhysicScope>() },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::ReceptorScope>();
	}
	// toy::SolidMedium
	{
		static Meta meta = { type<toy::SolidMedium>(), &namspc({ "toy" }), "SolidMedium", sizeof(toy::SolidMedium), TypeClass::Object };
		static Class cls = { type<toy::SolidMedium>(),
			// bases
			{ &type<toy::Medium>() },
			{ base_offset<toy::SolidMedium, toy::Medium>() },
			// constructors
			{
				{ type<toy::SolidMedium>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::SolidMedium>(ref)) toy::SolidMedium(  ); }, {} }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
				{ type<toy::SolidMedium>(), "me", Ref(&toy::SolidMedium::me) }
			}
		};
		init_pool<toy::SolidMedium>();
		meta_class<toy::SolidMedium>();
	}
	// toy::SoundMedium
	{
		static Meta meta = { type<toy::SoundMedium>(), &namspc({ "toy" }), "SoundMedium", sizeof(toy::SoundMedium), TypeClass::Object };
		static Class cls = { type<toy::SoundMedium>(),
			// bases
			{ &type<toy::Medium>() },
			{ base_offset<toy::SoundMedium, toy::Medium>() },
			// constructors
			{
				{ type<toy::SoundMedium>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::SoundMedium>(ref)) toy::SoundMedium(  ); }, {} }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
				{ type<toy::SoundMedium>(), "me", Ref(&toy::SoundMedium::me) }
			}
		};
		init_pool<toy::SoundMedium>();
		meta_class<toy::SoundMedium>();
	}
	// toy::Spatial
	{
		static Meta meta = { type<toy::Spatial>(), &namspc({ "toy" }), "Spatial", sizeof(toy::Spatial), TypeClass::Object };
		static Class cls = { type<toy::Spatial>(),
			// bases
			{ &type<mud::Transform>() },
			{ base_offset<toy::Spatial, mud::Transform>() },
			// constructors
			{
				{ type<toy::Spatial>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Spatial>(ref)) toy::Spatial(  ); }, {} },
				{ type<toy::Spatial>(), [](Ref ref, array<Var> args) { new(&val<toy::Spatial>(ref)) toy::Spatial( val<toy::HSpatial>(args[0]), val<mud::vec3>(args[1]), val<mud::quat>(args[2]) ); }, { { "parent", var(toy::HSpatial()) }, { "position", var(mud::vec3()) }, { "rotation", var(mud::quat()) } } },
				{ type<toy::Spatial>(), [](Ref ref, array<Var> args) { new(&val<toy::Spatial>(ref)) toy::Spatial( val<toy::World>(args[0]), val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), val<mud::quat>(args[3]) ); }, { { "world", Ref(type<toy::World>()) }, { "parent", var(toy::HSpatial()) }, { "position", var(mud::vec3()) }, { "rotation", var(mud::quat()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::Spatial>(), member_address(&toy::Spatial::m_world), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
				{ type<toy::Spatial>(), member_address(&toy::Spatial::m_parent), type<toy::HSpatial>(), "parent", var(toy::HSpatial()), Member::Flags(Member::Value|Member::Link), nullptr },
				{ type<toy::Spatial>(), member_address(&toy::Spatial::m_contents), type<vector<toy::HSpatial>>(), "contents", var(vector<toy::HSpatial>()), Member::Flags(Member::Value|Member::Structure), nullptr }
			},
			// methods
			{
				{ type<toy::Spatial>(), "set_position", member_address<void(toy::Spatial::*)(const mud::vec3&)>(&toy::Spatial::set_position), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Spatial>(object).set_position(val<mud::vec3>(args[0])); }, { { "position", var(mud::vec3()) } }, Var() },
				{ type<toy::Spatial>(), "set_rotation", member_address<void(toy::Spatial::*)(const mud::quat&)>(&toy::Spatial::set_rotation), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Spatial>(object).set_rotation(val<mud::quat>(args[0])); }, { { "rotation", var(mud::quat()) } }, Var() }
			},
			// static members
			{
			}
		};
		init_pool<toy::Spatial>();
		meta_class<toy::Spatial>();
	}
	// toy::VisualMedium
	{
		static Meta meta = { type<toy::VisualMedium>(), &namspc({ "toy" }), "VisualMedium", sizeof(toy::VisualMedium), TypeClass::Object };
		static Class cls = { type<toy::VisualMedium>(),
			// bases
			{ &type<toy::Medium>() },
			{ base_offset<toy::VisualMedium, toy::Medium>() },
			// constructors
			{
				{ type<toy::VisualMedium>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::VisualMedium>(ref)) toy::VisualMedium(  ); }, {} }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
				{ type<toy::VisualMedium>(), "me", Ref(&toy::VisualMedium::me) }
			}
		};
		init_pool<toy::VisualMedium>();
		meta_class<toy::VisualMedium>();
	}
	// toy::WorldMedium
	{
		static Meta meta = { type<toy::WorldMedium>(), &namspc({ "toy" }), "WorldMedium", sizeof(toy::WorldMedium), TypeClass::Object };
		static Class cls = { type<toy::WorldMedium>(),
			// bases
			{ &type<toy::Medium>() },
			{ base_offset<toy::WorldMedium, toy::Medium>() },
			// constructors
			{
				{ type<toy::WorldMedium>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::WorldMedium>(ref)) toy::WorldMedium(  ); }, {} }
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
				{ type<toy::WorldMedium>(), "me", Ref(&toy::WorldMedium::me) }
			}
		};
		init_pool<toy::WorldMedium>();
		meta_class<toy::WorldMedium>();
	}
		m.m_types.push_back(&type<toy::BulletMedium>());
		m.m_types.push_back(&type<toy::BulletShape>());
		m.m_types.push_back(&type<toy::Camera>());
		m.m_types.push_back(&type<toy::Collider>());
		m.m_types.push_back(&type<toy::ColliderImpl>());
		m.m_types.push_back(&type<toy::ColliderObject>());
		m.m_types.push_back(&type<toy::Collision>());
		m.m_types.push_back(&type<toy::CollisionGroup>());
		m.m_types.push_back(&type<toy::CollisionShape>());
		m.m_types.push_back(&type<toy::ComponentPool>());
		m.m_types.push_back(&type<toy::Core>());
		m.m_types.push_back(&type<toy::DetourPath>());
		m.m_types.push_back(&type<toy::Emitter>());
		m.m_types.push_back(&type<toy::EntityScript>());
		m.m_types.push_back(&type<toy::Medium>());
		m.m_types.push_back(&type<toy::Movable>());
		m.m_types.push_back(&type<toy::Navblock>());
		m.m_types.push_back(&type<toy::Navmesh>());
		m.m_types.push_back(&type<toy::Origin>());
		m.m_types.push_back(&type<mud::OwnedHandle<toy::Collider>>());
		m.m_types.push_back(&type<mud::OwnedHandle<toy::Solid>>());
		m.m_types.push_back(&type<toy::Pathfinder>());
		m.m_types.push_back(&type<toy::PhysicWorld>());
		m.m_types.push_back(&type<toy::Receptor>());
		m.m_types.push_back(&type<toy::Solid>());
		m.m_types.push_back(&type<toy::SolidImpl>());
		m.m_types.push_back(&type<mud::SparseHandle<toy::Collider>>());
		m.m_types.push_back(&type<mud::SparseHandle<toy::Solid>>());
		m.m_types.push_back(&type<toy::User>());
		m.m_types.push_back(&type<toy::Waypoint>());
		m.m_types.push_back(&type<toy::World>());
		m.m_types.push_back(&type<toy::WorldClock>());
		m.m_types.push_back(&type<toy::WorldPage>());
		m.m_types.push_back(&type<vector<toy::HSpatial>>());
		m.m_types.push_back(&type<toy::BulletCollider>());
		m.m_types.push_back(&type<toy::BulletSolid>());
		m.m_types.push_back(&type<toy::BulletWorld>());
		m.m_types.push_back(&type<mud::ComponentHandle<toy::Camera>>());
		m.m_types.push_back(&type<mud::ComponentHandle<toy::Emitter>>());
		m.m_types.push_back(&type<mud::ComponentHandle<toy::EntityScript>>());
		m.m_types.push_back(&type<mud::ComponentHandle<toy::Movable>>());
		m.m_types.push_back(&type<mud::ComponentHandle<toy::Navblock>>());
		m.m_types.push_back(&type<mud::ComponentHandle<toy::Origin>>());
		m.m_types.push_back(&type<mud::ComponentHandle<toy::Receptor>>());
		m.m_types.push_back(&type<mud::ComponentHandle<toy::Spatial>>());
		m.m_types.push_back(&type<mud::ComponentHandle<toy::Waypoint>>());
		m.m_types.push_back(&type<mud::ComponentHandle<toy::WorldPage>>());
		m.m_types.push_back(&type<toy::DefaultWorld>());
		m.m_types.push_back(&type<toy::Obstacle>());
		m.m_types.push_back(&type<toy::PhysicScope>());
		m.m_types.push_back(&type<toy::EmitterScope>());
		m.m_types.push_back(&type<toy::NavmeshShape>());
		m.m_types.push_back(&type<toy::ReceptorScope>());
		m.m_types.push_back(&type<toy::SolidMedium>());
		m.m_types.push_back(&type<toy::SoundMedium>());
		m.m_types.push_back(&type<toy::Spatial>());
		m.m_types.push_back(&type<toy::VisualMedium>());
		m.m_types.push_back(&type<toy::WorldMedium>());
		{
			auto func = [](array<Var> args, Var& result) {  val<bool>(result) = toy::move_2d(val<toy::Spatial>(args[0]), val<toy::Movable>(args[1]), val<mud::vec3>(args[2]), val<float>(args[3]), val<float>(args[4]), val<float>(args[5])); };
			vector<Param> params = { { "spatial", Ref(type<toy::Spatial>()) }, { "movable", Ref(type<toy::Movable>()) }, { "target", var(mud::vec3()) }, { "velocity", var(float()) }, { "time_step", var(float()) }, { "margin", var(float(0.1f)), Param::Default } };
			static Function f = { &namspc({ "toy" }), "move_2d", funcptr<bool(*)(toy::Spatial&, toy::Movable&, const mud::vec3&, float, float, float)>(&toy::move_2d), func, params, var(bool()) };
			m.m_functions.push_back(&f);
		}
		{
			auto func = [](array<Var> args, Var& result) {  val<bool>(result) = toy::steer_2d(val<toy::Spatial>(args[0]), val<toy::Movable>(args[1]), val<mud::vec3>(args[2]), val<float>(args[3]), val<float>(args[4]), val<float>(args[5])); };
			vector<Param> params = { { "spatial", Ref(type<toy::Spatial>()) }, { "movable", Ref(type<toy::Movable>()) }, { "target", var(mud::vec3()) }, { "velocity", var(float()) }, { "time_step", var(float()) }, { "margin", var(float(0.1f)), Param::Default } };
			static Function f = { &namspc({ "toy" }), "steer_2d", funcptr<bool(*)(toy::Spatial&, toy::Movable&, const mud::vec3&, float, float, float)>(&toy::steer_2d), func, params, var(bool()) };
			m.m_functions.push_back(&f);
		}
	}
}

namespace toy
{
	toy_core::toy_core()
		: Module("toy::core", { &mud_type::m(), &mud_jobs::m(), &mud_ecs::m(), &mud_math::m(), &mud_geom::m(), &mud_lang::m(), &toy_util::m() })
	{
		// setup reflection meta data
		toy_core_meta(*this);
	}
}

#ifdef TOY_CORE_MODULE
extern "C"
Module& getModule()
{
		return toy_core::m();
}
#endif
