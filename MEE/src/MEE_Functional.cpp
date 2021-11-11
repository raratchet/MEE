#include "MEE_Functional.h"

FunctionParameter::FunctionParameter(std::string name, std::any param) : parameter(param), param_name(name)
{

}

void FunctionParameter::operator=(std::any param)
{
	parameter = param;
}

FunctionParameters::FunctionParameters(std::list<std::pair<std::string, std::any>> params)
{
	for (auto param : params)
	{
		std::string name = param.first;
		std::any any = param.second;
		FunctionParameter* fparam = new FunctionParameter(name, any);
		parameters.insert({ name,std::shared_ptr<FunctionParameter>(fparam) });
	}
}

FunctionParameters::FunctionParameters(std::list<FunctionParameter> params)
{
	for (auto param : params)
	{
		FunctionParameter* fparam = new FunctionParameter(param.param_name, param.parameter);
		parameters.insert({ param.param_name,std::shared_ptr<FunctionParameter>(fparam) });
	}
}

FunctionParameters::~FunctionParameters()
{
	parameters.clear();
}

void FunctionParameters::Add(FunctionParameter parameter)
{
	parameters.insert({ parameter.param_name, std::make_shared<FunctionParameter>(parameter) });
}

void FunctionParameters::Add(const std::string& param_name, std::any param)
{
	FunctionParameter parameter = { param_name,param };
	parameters.insert({ param_name,std::make_shared<FunctionParameter>(parameter) });
}

FunctionParameter& FunctionParameters::operator[](const std::string& name)
{
	return *parameters[name];
}

