/*****************************************************************//**
 * \file   MEE_Global.h
 * \brief  Defines the global space for MEE. 
 * Used to simplify sintax in Interfaces
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "MEE_Application.h"
#include "MEE_Exports.h"

namespace MEE_GLOBAL
{
	 extern MEE_EXPORT MEE::Application* application;
}