/*****************************************************************//**
 * \file   MEE_Functional.h
 * \brief  Defines Special Functors and Parameter Objects
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
#pragma once
#include "MEE_Exports.h"
#include <functional>
#include <string>
#include <map>
#include <iostream>
#include <any>
#include <list> //Deberian de estar en el pch

/**
 * FunctionParameter is an object that hold any type with a given name.
 */
struct MEE_EXPORT FunctionParameter
{

	FunctionParameter() = default;

	FunctionParameter(std::string name, std::any param);

	std::string param_name;
	std::any parameter;

	template<class T>
	T As();

	void operator=(std::any param);
};

template<class T>
T FunctionParameter::As()
{
	try
	{
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

/**
 * FunctionParameters holds any number, of any type of arguments for a function.
 */
struct MEE_EXPORT FunctionParameters
{

	FunctionParameters() = default;

	FunctionParameters(std::list<std::pair<std::string, std::any>> params);

	FunctionParameters(std::list<FunctionParameter> params);

	~FunctionParameters();

	bool Has(const std::string& param_name)
	{
		auto exist = parameters.find(param_name);
		return (exist != parameters.end()) ? true : false;
	}

	void Add(FunctionParameter parameter);

	void Add(const std::string& param_name, std::any param);

	static FunctionParameters NoParameters()
	{
		static FunctionParameters NoParams;
		return NoParams;
	}

	std::map<std::string, std::shared_ptr<FunctionParameter>> parameters;

	FunctionParameter& operator[](const std::string& name);
};

