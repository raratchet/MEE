#pragma once
#include <string>
#include "MEE_Exports.h"

namespace MEE
{
	using ResourceID = unsigned int;

	class MEE_EXPORT Resource
	{
	public:
		virtual ~Resource() = default;
		virtual void Load(const std::string& path) = 0; // ¿Este método debería ser publico?
	};
}

