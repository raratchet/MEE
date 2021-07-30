#pragma once
#include <functional>
#include "MEE_Exports.h"

enum class RenderAPI
{
	OpenGL,
	Vulkan,
	Metal,
	SDL_Render
};

enum class WindowHandlerAPI
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
void MEE_EXPORT MEE_bind_SetRenderColor(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_SetRenderViewport(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_RenderLine(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_RenderPoint(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_RenderPolygon(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_RenderSolidPolygon(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_RenderCircle(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_RenderSolidCircle(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_CreateTexture2D(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_InitGL(int plugin_id, const std::string& func_name);
MEE_SDL_Renderer MEE_EXPORT MEE_GetSDLRenderer();

/**
 * Calls the render clear function in the render module.
 */
inline std::function<void()> MEE_RenderClear;

/**
 * Changes the rendering color in the render module.
 * \param r: RED
 * \param g: GREEN
 * \param b: BLUE
 * \param a: ALHPA
 */
inline std::function<void(int r,int g,int b,int a)> MEE_SetRenderColor;

/**
 * .
 */
inline std::function<void(int x, int y, int w, int h)> MEE_SetRenderViewport;

/**
 * Calls the InitGL function in the render module.
 * Only called when using the OpenGL render API.
 */
inline std::function<void()> MEE_InitGL;

/**
 * Renders a line in screen.
 * \param x1: First x position of line
 * \param y1: First y position of line
 * \param x2: Second x position of line
 * \param y2: Second y position of line
 */
inline std::function<void(float x1, float y1, float x2, float y2)> MEE_RenderLine;

/**
 * Renders a point in screen.
 * \param x: X position of point
 * \param y: Y position of point
 */
inline std::function<void(float x, float y)> MEE_RenderPoint;

/**
 * .
 */
inline std::function<void(int* vectices, int vertexCount)> MEE_RenderPolygon;

/**
 * .
 */
inline std::function<void(int* vectices, int vertexCount)> MEE_RenderSolidPolygon;

/**
 * .
 */
inline std::function<void(float x, float y, float radius)> MEE_RenderCircle;

/**
 * .
 */
inline std::function<void(float x, float y, float radius)> MEE_RenderSolidCircle;

/**
 * Renders the Texture2D in screen.
 * \param x: X position to draw the image.
 * \param y: Y position to draw the image.
 * \param clipX: Clip X position for the image.
 * \param clipY: Clip Y position for the image.
 * \param clipW: Clip W position for the image.
 * \param clipH: Clip H position for the image.
 * \param angle: The angles to rotate the image.
 */
inline std::function<void(const MEE_Texture2D,float x, float y, float scale_x, float scale_y, float angle,
	int clipX, int clipY, int clipW, int clipH )> MEE_RenderTexture2D;

/**
 * Creates and loads a Texture2d.
 * \param path: The path where texture is located.
 * \return A MEE_Texture2D pointer for the Texture2D
 */
inline std::function<MEE_Texture2D(const std::string& path)> MEE_CreateTexture2D;



