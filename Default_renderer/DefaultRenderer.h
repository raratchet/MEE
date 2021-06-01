#pragma once

#include <MEE_PluginHeader.h>
#ifndef GLEW_STATIC
//#define GLEW_STATIC
#endif // !GLEW_STATIC
#include <GL/glew.h>
#include <functional>
#include <MEE_OpenGL_Texture2D.h>

namespace DefaultRenderer {
	// Events that will be triggered from the main process.

	extern "C" 
	{
		PLUGIN_EXPORT void onInit(int);
		PLUGIN_EXPORT void onLoad();
		PLUGIN_EXPORT void onShutdown();


		PLUGIN_EXPORT void renderClear();
		PLUGIN_EXPORT void renderQuad();
		PLUGIN_EXPORT void initGL();
	}

	//static const GLfloat base_quad_buffer_data[] = {
	//					-1.0f, -1.0f, 0.0f,
	//					-1.0f,  1.0f, 0.0f,
	//					 1.0f,  1.0f, 0.0f,
	//					 1.0f, -1.0f, 0.0f,
	//											};

	static const GLfloat base_quad_buffer_data[] = {
					-1.0f, -1.0f, 0.0f, 0.0f,
					-1.0f,  1.0f, 0.0f, 1.0f,
					 1.0f,  1.0f, 1.0f, 1.0f,
					 1.0f, -1.0f, 1.0f, 0.0f
	};

	static const GLuint indices[]
	{
		0,1,2,
		2,3,0
	};

	GLuint vertexbuffer;
	GLuint vao;
	GLuint ibo;
	GLuint shader;
	GLint textureSlot;
	GLuint m_RendererID = 384;

	MEE::Default_OpenGL_Texture2D texture;
	MEE::Default_OpenGL_Texture2D texture2;

	GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);


	// Handle to the main process.
	PLUGIN_HANDLE_TYPE PLUGIN;
}

