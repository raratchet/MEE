#pragma once
#include <MEE_PluginHeader.h>
#include <MEE_Physics.h>
#include "BoxCollider.h"
#include <set>
#include <map>
#include <box2d/box2d.h> 
#include "BoxContactListener.h"
namespace Basic_Physics
{

	std::map<SceneID, b2World*> physicWorlds;
	std::map<b2World*, std::vector<BoxCollider*>> bodies;

	extern "C"
	{
		PLUGIN_EXPORT void OnInit(int);
		PLUGIN_EXPORT void OnLoad();
		PLUGIN_EXPORT void OnShutdown();
		PLUGIN_EXPORT void OnUpdate();
		PLUGIN_EXPORT void OnDraw();

		PLUGIN_EXPORT void CreatePhysicsWorld(SceneID, FunctionParameters& params);
		PLUGIN_EXPORT void UpdateTransform(MEE_Collider,float,float,float);
		PLUGIN_EXPORT MEE_Collider CastCollider(MEE_Collider);
		PLUGIN_EXPORT void ReadTransform(MEE_Collider, float*, float*, float*);
		PLUGIN_EXPORT MEE_Collider CreateCollider(SceneID, FunctionParameters& params);
		PLUGIN_EXPORT void PhysicsStep(SceneID);

	}


}
