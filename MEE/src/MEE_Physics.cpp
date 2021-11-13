#include "MEE_Physics.h"
#include "MEE_Global.h"

inline std::function<void(SceneID sceneID, FunctionParameters& params)> MEE_CreatePhysicsWorld;
inline std::function<void(SceneID sceneID)> MEE_DestroyPhysicsWorld;
inline std::function<MEE_Collider(SceneID sceneID,FunctionParameters& params)> MEE_CreateCollider;
inline std::function<void(MEE_Collider collider, float x, float y, float angle)> MEE_SetColliderTransform;
inline std::function<void(MEE_Collider collider, float* x, float* y, float* angle)> MEE_GetColliderTransform;
inline std::function<void(SceneID sceneID, MEE_Collider collider)> MEE_DestroyCollider;
inline std::function<void(SceneID sceneID)> MEE_PhysicsStep;

void MEE_bind_CreateCollider(int pl_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_CreateCollider = pl_manager->GetPluginFunction<MEE_Collider, SceneID, FunctionParameters&>(pl_id, func_name);
	}
}
void MEE_bind_SetColliderTransform(int pl_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_SetColliderTransform = pl_manager->GetPluginFunction<void, MEE_Collider, float, float,float>(pl_id, func_name);
	}
}
void MEE_bind_GetColliderTransform(int pl_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_GetColliderTransform = pl_manager->GetPluginFunction<void, MEE_Collider, float*, float*, float*>(pl_id, func_name);
	}
}
void MEE_bind_PhysicsStep(int pl_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_PhysicsStep = pl_manager->GetPluginFunction<void, SceneID>(pl_id, func_name);
	}
}
void MEE_bind_CreatePhysicsWorld(int pl_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_CreatePhysicsWorld = pl_manager->GetPluginFunction<void, SceneID, FunctionParameters&>(pl_id, func_name);
	}
}
void MEE_SetFixedUpdateSpeed(uint frameSpeed)
{

}
double MEE_GetDeltaTime()
{
	auto timeManager = MEE_GLOBAL::application->GetTimeManager().lock();

	return timeManager->GetDeltaTime();
}
