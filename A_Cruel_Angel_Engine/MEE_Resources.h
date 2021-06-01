#pragma once

#include <map>
#include <string>
#include <memory>
#include "MEE_Exports.h"

namespace MEE
{

	class MEE_EXPORT Resource
	{
	public:
		virtual ~Resource() = default;
		virtual void load(const std::string& path) = 0; // ¿Este método debería ser publico?
	};

	class MEE_EXPORT ResourceManager
	{
	public:
		template<class T = Resource>
		bool load(const std::string& name, const std::string& path);
		bool isLoaded(const std::string& name);
		bool unload(const std::string& name);
		void clear();
		bool init();
		template<class T = Resource>
		std::weak_ptr<T> get(const std::string& name);
		//Esto no es final
		bool loadTexture2D(const std::string& name, const std::string& path);
	private:
		std::map<std::string, std::shared_ptr<Resource>> resources;
	};

	template<class T>
	bool ResourceManager::load(const std::string& name, const std::string& path)
	{

		if (resources.find(name) == resources.end())
		{
			T* resource = new T;
			resource->load(path);
			resources.insert(std::make_pair(name, resource));
			return true;
		}
		return false;
	}
	template<class T>
	std::weak_ptr<T> ResourceManager::get(const std::string& name)
	{
		auto& res = resources.at(name);
		std::weak_ptr<T> ptr = std::reinterpret_pointer_cast<T>(res);
		return ptr;
	}
}

