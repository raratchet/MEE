#pragma once
#include "MEE_Resources.h"
#include "MEE_Exports.h"

namespace MEE
{
	class MEE_EXPORT Texture2D : public Resource
	{
	public:
		virtual ~Texture2D() = default;
		virtual void Load(const std::string& path) = 0;
		virtual int GetWidth()const;
		virtual int GetHeight() const;

	protected:
		int width, height;
	};
}
