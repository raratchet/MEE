/*****************************************************************//**
 * \file   MEE_GLFWHandler.h
 * \brief  Currently GLFW is not supported. Please don't use it.
 * 
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "MEE_WindowHandler.h"

namespace MEE
{

    class GLFWHandler : public WindowHandler
    {
	public:
		virtual bool Init() override;
		virtual void Stop() override;
		virtual void SwapBuffer() override;
		virtual void RefreshWindow() override;
    };
}

