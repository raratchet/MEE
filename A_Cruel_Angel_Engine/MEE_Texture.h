#pragma once
#include "MEE_Resources.h"
#include "MEE_Exports.h"

namespace MEE
{
	class MEE_EXPORT Texture : public Resource 
	{
	public:
		virtual ~Texture() = default;
		virtual void Load(const std::string & path) = 0;
		virtual int getWidth()const;
		virtual int getHeight() const;

	protected:
		int width, height;
	};

	class MEE_EXPORT Texture2D : public Texture
	{
	public:
		virtual ~Texture2D() = default;
		virtual void Load(const std::string& path) = 0;
	};
}
