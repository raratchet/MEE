#include "MEE_ResourceManager.h"
#include "MEE_Global.h"
#include "MEE_Texture.h"

namespace MEE
{
	bool ResourceManager::Init()
	{
		return true;
	}

	ResourceID ResourceManager::LoadTexture2D(const std::string& name, const std::string& path)
	{
		if (resources.find(name) == resources.end())
		{
			auto rendering = MEE_GLOBAL::application->GetRenderManager();
			Texture2D* tex2D = rendering->CreateTexture2D(path);
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