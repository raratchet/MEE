#pragma once

#include <map>
#include <string>
#include <memory>
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

	class MEE_EXPORT ResourceManager
	{
	public:
		template<class T = Resource>
		ResourceID Load(const std::string& name, const std::string& path);
		ResourceID LoadTexture2D(const std::string& name, const std::string& path);
		bool IsLoaded(const std::string& name);
		bool Unload(const std::string& name);
		void Clear();
		bool Init();
		template<class T = Resource>
		std::weak_ptr<T> Get(const std::string& name);
	private:
		std::map<std::string, std::shared_ptr<Resource>> resources;
	};

	template<class T>
	ResourceID ResourceManager::Load(const std::string& name, const std::string& path)
	{

		if (resources.find(name) == resources.end())
		{
			T* resource = new T;
			resource->Load(path);
			resources.insert(std::make_pair(name, resource));
			return true;
		}
		return false;
	}

	template<class T>
	std::weak_ptr<T> ResourceManager::Get(const std::string& name)
	{
		auto& res = resources.at(name);
		std::weak_ptr<T> ptr = std::reinterpret_pointer_cast<T>(res);
		return ptr;
	}
}

