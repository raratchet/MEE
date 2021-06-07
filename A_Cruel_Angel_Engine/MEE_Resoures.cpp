#include "MEE_Resources.h"
#include "MEE_Graphics.h"
#include "MEE_Texture.h"

namespace MEE
{
	bool ResourceManager::Init()
	{
		return true;
	}

	bool ResourceManager::LoadTexture2D(const std::string& name, const std::string& path)
	{
		if (resources.find(name) == resources.end())
		{
			Texture2D* tex2D = (Texture2D*) MEE_CreateTexture2D(path);
			resources.insert(std::make_pair(name, tex2D));
			return true;
		}
		return false;
	}

	bool ResourceManager::IsLoaded(const std::string& name)
	{
		return false;
	}

	bool ResourceManager::Unload(const std::string& name)
	{
		return false;
	}

	void ResourceManager::Clear()
	{
		resources.clear();
	}


}


