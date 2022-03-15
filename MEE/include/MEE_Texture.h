/*****************************************************************//**
 * \file   MEE_Texture.h
 * \brief  Conatains Graphic related Resoruces
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
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
		int m_width, m_height;
	};
}
