/*****************************************************************//**
 * \file   MEE_Resources.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
#pragma once
#include <string>
#include "MEE_Exports.h"

namespace MEE
{
	using ResourceID = unsigned int;

	/**
	 * Base class for all game Resources.
	 */
	class MEE_EXPORT Resource
	{
	public:
		virtual ~Resource() = default;
		virtual void Load(const std::string& path) = 0; // ¿Este método debería ser publico?
	};
}

