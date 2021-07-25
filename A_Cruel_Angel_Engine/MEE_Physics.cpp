#include "MEE_Physics.h"
#include "MEE_Global.h"

void MEE_bind_CreateCollider(int pl_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_CreateCollider = pl_manager->GetPluginFunction<MEE_Collider, SceneID>(pl_id, func_name);
	}
}
void MEE_bind_SetColliderPosition(int pl_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_SetColliderPosition = pl_manager->GetPluginFunction<void, MEE_Collider, float, float>(pl_id, func_name);
	}
}
void MEE_bind_PhysicsStep(int pl_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_PhysicsStep = pl_manager->GetPluginFunction<void, SceneID>(pl_id, func_name);
	}
}
void MEE_bind_CreatePhysicsWorld(int pl_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_CreatePhysicsWorld = pl_manager->GetPluginFunction<void, SceneID>(pl_id, func_name);
	}
}
void MEE_SetFixedUpdateSpeed(uint frameSpeed)
{

}
uint MEE_GetFixedUpdateSpeed()
{
	return 0;
}
