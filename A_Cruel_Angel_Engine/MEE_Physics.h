#pragma once
#include "MEE_Functional.h"	
#include "MEE_Exports.h"

using SceneID = unsigned int;
using uint = unsigned int;

typedef void* MEE_Collider;

void  MEE_EXPORT MEE_bind_CreateCollider(int pl_id, const std::string& func_name);
void  MEE_EXPORT MEE_bind_SetColliderTransform(int pl_id, const std::string& func_name);
void  MEE_EXPORT MEE_bind_GetColliderTransform(int pl_id, const std::string& func_name);
void  MEE_EXPORT MEE_bind_PhysicsStep(int pl_id, const std::string& func_name);
void  MEE_EXPORT MEE_bind_CreatePhysicsWorld(int pl_id, const std::string& func_name);
void  MEE_EXPORT MEE_SetFixedUpdateSpeed(uint frameSpeed);
uint  MEE_EXPORT MEE_GetFixedUpdateSpeed();

extern void  MEE_EXPORT MEE_SetPixelsPerUnit(float ppu);
extern float MEE_EXPORT MEE_GetPixelsPerUnit();
extern float MEE_EXPORT MEE_GetUnitsPerPixel();

extern MEE_ENGINE_FUNCTION std::function<void(SceneID sceneID)> MEE_CreatePhysicsWorld;
extern MEE_ENGINE_FUNCTION std::function<void(SceneID sceneID)> MEE_DestroyPhysicsWorld;
extern MEE_ENGINE_FUNCTION std::function<MEE_Collider(SceneID sceneID,FunctionParameters& params)> MEE_CreateCollider;
extern MEE_ENGINE_FUNCTION std::function<void(MEE_Collider collider, float x, float y, float angle)> MEE_SetColliderTransform;
extern MEE_ENGINE_FUNCTION std::function<void(MEE_Collider collider, float* x, float* y, float* angle)> MEE_GetColliderTransform;
extern MEE_ENGINE_FUNCTION std::function<void(SceneID sceneID, MEE_Collider collider)> MEE_DestroyCollider;
extern MEE_ENGINE_FUNCTION std::function<void(SceneID sceneID)> MEE_PhysicsStep;



