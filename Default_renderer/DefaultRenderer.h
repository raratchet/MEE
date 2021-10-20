#pragma once

#include <MEE_PluginHeader.h>
#ifndef GLEW_STATIC
//#define GLEW_STATIC
#endif // !GLEW_STATIC
#include <GL/glew.h>
#include <functional>
#include "OpenGL_Texture2D.h"
#include <MEE_Graphics.h>

namespace DefaultRenderer {
	// Events that will be triggered from the main process.

	extern "C" 
	{
		PLUGIN_FUNCTION void OnInit(int);
		PLUGIN_FUNCTION void OnLoad();
		PLUGIN_FUNCTION void OnShutdown();


		PLUGIN_FUNCTION void renderTexture(MEE_Texture2D tex, float x, float y,
			int clipX, int clipY, int clipW,
			int clipH, float a);
		PLUGIN_FUNCTION MEE_Texture2D createTexture2D(const std::string path);

		PLUGIN_FUNCTION void renderClear();
		PLUGIN_FUNCTION void renderQuad();
		PLUGIN_FUNCTION void initGL();
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

	OpenGL_Texture2D texture;
	OpenGL_Texture2D texture2;

	GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);


	// Handle to the main process.
	PLUGIN_HANDLE_TYPE PLUGIN;
}

