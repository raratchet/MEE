#pragma once
#include "MEE_Texture.h"
#include <GL/glew.h>

class MEE_EXPORT OpenGL_Texture2D : public MEE::Texture2D
{
public:
	OpenGL_Texture2D() = default;
	virtual ~OpenGL_Texture2D() = default;
	virtual void Load(const std::string& path) override;
	void Bind(GLenum slot = GL_TEXTURE0);
	GLuint GetRendererID();
private:
	GLuint m_RendererID = 0;
	GLenum m_InternalFormat = 0, m_DataFormat = 0;
};

