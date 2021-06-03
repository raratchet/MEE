#include "MEE_OpenGL_Texture2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

void MEE::Default_OpenGL_Texture2D::Load(const std::string& path)
{
	int w, h, channels;
	stbi_set_flip_vertically_on_load(1);
	stbi_uc* data = nullptr;


	data = stbi_load(path.c_str(), &w, &h, &channels, 0);

	if (!data) 
		return;

	width = w;
	height = h;

	GLenum internalFormat = 0, dataFormat = 0;
	if (channels == 4)
	{
		internalFormat = GL_RGBA8;
		dataFormat = GL_RGBA;
	}
	else if (channels == 3)
	{
		internalFormat = GL_RGB8;
		dataFormat = GL_RGB;
	}

	m_InternalFormat = internalFormat;
	m_DataFormat = dataFormat;


	glGenTextures(1, &m_RendererID);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);
}


void MEE::Default_OpenGL_Texture2D::bind(GLenum slot)
{
	glActiveTexture(slot);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

GLuint MEE::Default_OpenGL_Texture2D::getRendererID()
{
	return m_RendererID;
}
