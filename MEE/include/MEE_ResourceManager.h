/*****************************************************************//**
 * \file   MEE_ResourceManager.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/
#pragma once
#include <map>
#include <memory>
#include "MEE_Resources.h"

namespace MEE
{
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
            resource->OnLoad(path);
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

