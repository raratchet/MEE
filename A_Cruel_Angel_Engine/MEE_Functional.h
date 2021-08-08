#pragma once
#include <functional>
#include <string>
#include <map>
#include <any>
#include <iostream>
#include "MEE_Exports.h"


//Mover funciones al ccp y esconder los includes

struct MEE_EXPORT FunctionParameter
{

	FunctionParameter() = default;

	FunctionParameter(std::string name, std::any param) : parameter(param), param_name(name)
	{

	}

	std::string param_name;
	std::any parameter;

	template<class T>
	T As();

	void operator=(std::any param)
	{
		parameter = param;
	}
};

template<class T>
T FunctionParameter::As()
{
	try
	{
		//std::cout << parameter.type().name() << std::endl;
		T t = std::any_cast<T>(parameter);
		return t;
	}
	catch (const std::bad_any_cast& e)
	{
		std::cout << e.what() << '\n';
	}
	T type = T();
	return type;
}

struct MEE_EXPORT FunctionParameters
{

	FunctionParameters()
	{

	}

	FunctionParameters(std::pair<std::string, std::any> params ...)
	{
		for (int i = 0; i < (sizeof(params) / sizeof(std::pair<std::string, std::any>)); i++)
		{
			auto param = &params + i;
			std::string name = param->first;
			std::any* any = &param->second;
			FunctionParameter* fparam = new FunctionParameter(name, *any);
			parameters.insert({ name,fparam });
		}
	}

	FunctionParameters(FunctionParameter params ...)
	{
		for (int i = 0; i < (sizeof(params) / sizeof(FunctionParameter)); i++)
		{
			auto param = &params + i;
			FunctionParameter* fparam = new FunctionParameter(param->param_name, param->parameter);
			parameters.insert({ param->param_name,fparam });
		}
	}

	~FunctionParameters()
	{
		for (auto& param : parameters)
		{
			param.second->parameter.reset();
			delete param.second;
		}

		parameters.clear();
	}

	std::map<std::string, FunctionParameter*> parameters;

	FunctionParameter& operator[](const std::string& name)
	{
		return *parameters[name];
	}
};
