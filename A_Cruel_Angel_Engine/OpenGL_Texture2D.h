#pragma once
#include "MEE_Texture.h"
#include <GL/glew.h>

namespace MEE
{
	class MEE_EXPORT Default_OpenGL_Texture2D : public Texture2D
	{
	public:
		Default_OpenGL_Texture2D() = default;
		virtual ~Default_OpenGL_Texture2D() = default;
		virtual void Load(const std::string & path) override;
		void bind(GLenum slot = GL_TEXTURE0);
		GLuint getRendererID();
	private:
		GLuint m_RendererID = 0;
		GLenum m_InternalFormat = 0, m_DataFormat = 0;
	};
}

