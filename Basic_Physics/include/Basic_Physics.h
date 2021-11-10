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

	PLUGIN_FUNCTION void OnInit(int);
	PLUGIN_FUNCTION void OnLoad();
	PLUGIN_FUNCTION void OnShutdown();
	PLUGIN_FUNCTION void OnUpdate();
	PLUGIN_FUNCTION void OnDraw();

	PLUGIN_FUNCTION void CreatePhysicsWorld(SceneID, FunctionParameters& params);
	PLUGIN_FUNCTION void UpdateTransform(MEE_Collider, float, float, float);
	PLUGIN_FUNCTION MEE_Collider CastCollider(MEE_Collider);
	PLUGIN_FUNCTION void ReadTransform(MEE_Collider, float*, float*, float*);
	PLUGIN_FUNCTION MEE_Collider CreateCollider(SceneID, FunctionParameters& params);
	PLUGIN_FUNCTION void PhysicsStep(SceneID);


}
