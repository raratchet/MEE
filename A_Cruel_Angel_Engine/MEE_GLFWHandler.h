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

