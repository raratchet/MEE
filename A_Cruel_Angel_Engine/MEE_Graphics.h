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

void MEE_EXPORT MEE_setWindowHandlerAPI(const WindowHandlerAPI& api);
void MEE_EXPORT MEE_setRenderAPI(const RenderAPI& api);
void MEE_EXPORT MEE_setWindowSize(unsigned int w, unsigned int h);
void MEE_EXPORT MEE_setWindowPosition(int x, int y);
void MEE_EXPORT MEE_setWindowName(const std::string& name);
void MEE_EXPORT MEE_bindRenderClear(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bindRenderTexture2D(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bindCreateTexture2D(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bindinitGL(int plugin_id, const std::string& func_name);
MEE_SDL_Renderer MEE_EXPORT MEE_getSDLRenderer();

inline std::function<void()> MEE_renderClear;
//Formato RGBA
inline std::function<void(int r,int g,int b,int a)> MEE_setRenderColor;
inline std::function<void()> MEE_initGL;
inline std::function<void(float x1, float y1, float x2, float y2)> MEE_renderLine;
inline std::function<void(float x, float y)> MEE_renderPoint;
inline std::function<void(const MEE::Texture2D&,float x, float y, 
	int clipX, int clipY, int clipW, int clipH, float angle )> MEE_renderTexture2D;
inline std::function<MEE_Texture2D(const std::string& path)> MEE_createTexture2D;



