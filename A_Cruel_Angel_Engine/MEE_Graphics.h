#pragma once
#include <functional>
#include "MEE_Exports.h"
#include "MEE_Texture.h"

enum RenderAPI
{
	OpenGL,
	Vulkan,
	Metal,
	SDL_Render
};

enum WindowHandlerAPI
{
	SDL,
	GLFW
};

typedef void* MEE_SDL_Renderer;
typedef void* MEE_Texture2D;

//Estas funciones envuelen a las que existen en engine
//Son las funciones disponibles para los modulos y addons

void MEE_EXPORT MEE_SetWindowHandlerAPI(const WindowHandlerAPI& api);
void MEE_EXPORT MEE_SetRenderAPI(const RenderAPI& api);
void MEE_EXPORT MEE_SetWindowSize(unsigned int w, unsigned int h);
void MEE_EXPORT MEE_SetWindowPosition(int x, int y);
void MEE_EXPORT MEE_SetWindowName(const std::string& name);
void MEE_EXPORT MEE_bind_RenderClear(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_RenderTexture2D(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_CreateTexture2D(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_InitGL(int plugin_id, const std::string& func_name);
MEE_SDL_Renderer MEE_EXPORT MEE_GetSDLRenderer();

inline std::function<void()> MEE_RenderClear;
//Formato RGBA
inline std::function<void(int r,int g,int b,int a)> MEE_SetRenderColor;
inline std::function<void()> MEE_InitGL;
inline std::function<void(float x1, float y1, float x2, float y2)> MEE_RenderLine;
inline std::function<void(float x, float y)> MEE_RenderPoint;
inline std::function<void(const MEE::Texture2D&,float x, float y, 
	int clipX, int clipY, int clipW, int clipH, float angle )> MEE_RenderTexture2D;
inline std::function<MEE_Texture2D(const std::string& path)> MEE_CreateTexture2D;



