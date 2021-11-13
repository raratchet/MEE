/*****************************************************************//**
 * \file   MEE_Graphics.h
 * \brief The Interface between MEE and Graphics Module.\n
 * This header contains functions to bind and link a module function to the engine. \n
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/

#pragma once
#include <functional>
#include <vector>
#include "MEE_Exports.h"

/**
 * RenderAPIs supported by the engine.\n
 * Default is SDL_Render.
 */
enum class RenderAPI
{
	OpenGL,
	Vulkan,
	Metal,
	SDL_Render
};

/**
 * Window Libraries supported by the engine.\n
 * Default is SDL
 */
enum class WindowHandlerAPI
{
	SDL,
	GLFW
};

/**
 * MEE_Renderer is a generic for returning a renderer pointer.
 */
typedef void* MEE_Renderer;
/**
 * MEE_Texture2D is a generic pointer for a virtual Texture2D.
 */
typedef void* MEE_Texture2D;

//Estas funciones envuelen a las que existen en engine
//Son las funciones disponibles para los modulos y addons

/**
 * Sets the internal engine window library.\n
 * \param api: The api to set, uses WindowHandlerAPI enum
 * When set the engine will build the window using said API.\n
 */
void  MEE_EXPORT MEE_SetWindowHandlerAPI(const WindowHandlerAPI& api);
/**
 * Sets the internal engine render API.\n
 * \param api: The api to set, uses RenderAPI enum
 * \warning If the currently used window library doesn't support it engine will throw an exeption.\n
 */
void  MEE_EXPORT MEE_SetRenderAPI(const RenderAPI& api);
/**
 * Sets the internal window size.
 * \param w: Window width.
 * \param h: Window height.
 * If the window is already built, rebuild window is necessary for changes come into effect
 */
void  MEE_EXPORT MEE_SetWindowSize(unsigned int w, unsigned int h);
/**
 * Returns current window size.
 * \param w: Pointer to an int to write to.
 * \param h: Pointer to an int to write to.
 */
void  MEE_EXPORT MEE_GetWindowSize(unsigned int* w, unsigned int* h);
/**
 * Sets the internal window position.
 * \param x: Window x postion.
 * \param y: Window y postion.
 * If the window is already built, rebuild window is necessary for changes come into effect.
 */
void  MEE_EXPORT MEE_SetWindowPosition(int x, int y);
/**
 * Sets the internal window title.
 * \param name: String to set in window title
 * If the window is already built, rebuild window is necessary for changes come into effect.
 */
void  MEE_EXPORT MEE_SetWindowName(const char* name);
/**
 * Sets the internal Pixels per Unit variable.
 * \param ppu: Value to set 
 */
void  MEE_EXPORT MEE_SetPixelsPerUnit(float ppu);
/**
 * Get the internal Pixels per Unit variable
 * \return Pixes per Unit
 */
float MEE_EXPORT MEE_GetPixelsPerUnit();
float MEE_EXPORT MEE_GetUnitsPerPixel();
/**
 * Returns the internal SDL_Renderer.
 * \warning If Window Library isn't SDL will return a nullptr
 */
MEE_Renderer MEE_EXPORT MEE_GetSDLRenderer();

//Binding / Linking functions

/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_RenderClear.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_RenderClear(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_RenderClear.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_RenderTexture2D(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_RenderTexture2D.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_SetRenderColor(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_SetRenderColor.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_SetRenderViewport(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_SetRenderViewport.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_RenderLine(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_RenderLine
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_RenderPoint(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_Point
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_RenderPolygon(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_RenderPolygon.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_RenderSolidPolygon(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_RenderSolidPolygon.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_RenderCircle(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_RenderCircle.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_RenderSolidCircle(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_RenderSolidCircle.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_CreateTexture2D(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_CreateTexture2D.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_InitGL(int plugin_id, const char* func_name);
/**
 * Searches for the function with func_name in the plugin id \n
 * and links it to the function MEE_InitGL.
 * \warning You must be sure that the function you are binding is compatible with the function you are binding to.\n
 * Failing to match paramters can result in undefined behaviour.
 */
void  MEE_EXPORT MEE_bind_RenderDebugGrid(int plugin_id, const char* func_name);

//Engine Functions
#ifdef MEE_ENGINE

/**
 * Should clean the renderer in prearation for next frame. 
 */
extern std::function<void()> MEE_RenderClear;
/**
 * Should change the rendering color of the renderer.
 * \param r: RED
 * \param g: GREEN
 * \param b: BLUE
 * \param a: ALHPA
 */
extern std::function<void(int r,int g,int b,int a)> MEE_SetRenderColor;
/**
 * Should move and resize the current viewport.
 * \param x: Position x
 * \param y: Position y
 * \param w: Width
 * \param h: Height
 */
extern std::function<void(int x, int y, int w, int h)> MEE_SetRenderViewport;
/**
 * Function to prepare Graphic Library when all modules are loaded.
 * \warning Only called by the engine when using the OpenGL render API.
 */
extern std::function<void()> MEE_InitGL;
/**
 * Should Render a line in screen.
 * \param x1: First x position of line
 * \param y1: First y position of line
 * \param x2: Second x position of line
 * \param y2: Second y position of line
 */
extern std::function<void(float x1, float y1, float x2, float y2)> MEE_RenderLine;
/**
 * Should render a point in screen.
 * \param x: X position of point
 * \param y: Y position of point
 */
extern std::function<void(float x, float y)> MEE_RenderPoint;
/**
 * Should render a polygon in screen.
 * \param vertices: An array containing all position for the polygon vertices.
 */
extern std::function<void(std::vector<float> vertices)> MEE_RenderPolygon;
/**
 * Should render a filled polygon in screen.
 * \param vertices: An array containing all position for the polygon vertices.
 */
extern std::function<void(std::vector<float> vertices)> MEE_RenderSolidPolygon;
/**
 * Should render a circle in screen.
 * \param x: X position for circle center
 * \param y: Y position for circle center
 * \param radius: Circle radius
 */
extern std::function<void(float x, float y, float radius)> MEE_RenderCircle;
/**
 * Should render a filled circle in screen.
 * \param x: X position for circle center
 * \param y: Y position for circle center
 * \param radius: Circle radius
 */
extern std::function<void(float x, float y, float radius)> MEE_RenderSolidCircle;
/**
 * Should render a grid in screen based in the current Pixels Per Unit.
 */
extern std::function<void()> MEE_RenderDebugGrid;
/**
 * Should render the given Texture2D as a rectangle in screen.
 * \param texture: The given texture to draw
 * \param x: X position to draw the image.
 * \param y: Y position to draw the image.
 * \param clipX: Clip X position for the image.
 * \param clipY: Clip Y position for the image.
 * \param clipW: Clip W position for the image.
 * \param clipH: Clip H position for the image.
 * \param angle: The angles to rotate the image.
 * \param h_flip: A boolean that indicates if image should be flip horizontally.
 * \param v:flip: A boolean that indicates if image should be flip vertically.
 * Note that Texture2D is given in the MEE_Texture2D generic form and should be casted before using it.
 */
extern std::function<void(const MEE_Texture2D texture,float x, float y, float scale_x, float scale_y, float angle,
	int clipX, int clipY, int clipW, int clipH , bool h_flip,bool v_flip)> MEE_RenderTexture2D;
/**
 * Should create and load a Texture2D as a pointer and return it in the generic form MEE_Texture2D.
 * \param path: The path where texture is located given by the loading entity.
 * \return A MEE_Texture2D pointer for the Texture2D
 */
extern std::function<MEE_Texture2D(const char* path)> MEE_CreateTexture2D;

#endif // MEE_ENGINE

