#pragma once
#include <functional>
#include "MEE_Exports.h"

using SceneID = unsigned int;
using uint = unsigned int;

typedef void* MEE_Collider;

void MEE_EXPORT MEE_bind_CreateCollider(int pl_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_SetColliderTransform(int pl_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_GetColliderTransform(int pl_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_PhysicsStep(int pl_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_CreatePhysicsWorld(int pl_id, const std::string& func_name);
void MEE_EXPORT MEE_SetFixedUpdateSpeed(uint frameSpeed);
uint MEE_EXPORT MEE_GetFixedUpdateSpeed();

inline std::function<void(SceneID sceneID)> MEE_CreatePhysicsWorld;
inline std::function<void(SceneID sceneID)> MEE_DestroyPhysicsWorld;
inline std::function<MEE_Collider(SceneID sceneID)> MEE_CreateCollider;
inline std::function<void(MEE_Collider collider, float x, float y, float angle)> MEE_SetColliderTransform;
inline std::function<void(MEE_Collider collider, float* x, float* y, float* angle)> MEE_GetColliderTransform;
inline std::function<void(SceneID sceneID, MEE_Collider collider)> MEE_DestroyCollider;
inline std::function<void(SceneID sceneID)> MEE_PhysicsStep;



