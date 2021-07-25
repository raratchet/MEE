#pragma once
#include <functional>
#include <string>
#include <map>
#include <any>

struct FunctionParameter
{

	FunctionParameter() = default;

	FunctionParameter(std::any param) : parameter(param)
	{

	}

	std::any parameter;

	template<class T>
	T As()
	{
		return std::any_cast<T>(parameter)
	}

	void operator=(std::any param)
	{
		parameter = param;
	}
};

struct FunctionParameters
{
	FunctionParameters(std::pair<std::string, std::any> params ...)
	{
		for (int i = 0; i < (sizeof(params) / sizeof(std::pair<std::string, std::any>)); i++)
		{
			auto param = &params + i;
			parameters.insert({param->first,param->second});
		}
	}

	std::map<std::string, FunctionParameter> parameters;

	FunctionParameter& operator[](const std::string& name)
	{
		return parameters[name];
	}
};
