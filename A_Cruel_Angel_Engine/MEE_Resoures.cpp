#include "MEE_Resources.h"
#include "MEE_Graphics.h"

namespace MEE
{
	bool ResourceManager::init()
	{
		return true;
	}

	bool ResourceManager::loadTexture2D(const std::string& name, const std::string& path)
	{
		if (resources.find(name) == resources.end())
		{
			Texture2D* tex2D = (Texture2D*) MEE_createTexture2D(path);
			resources.insert(std::make_pair(name, tex2D));
			return true;
		}
		return false;
	}

	bool ResourceManager::isLoaded(const std::string& name)
	{
		return false;
	}

	bool ResourceManager::unload(const std::string& name)
	{
		return false;
	}

	void ResourceManager::clear()
	{
		resources.clear();
	}


}


