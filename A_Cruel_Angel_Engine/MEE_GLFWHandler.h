#pragma once
#include "MEE_WindowHandler.h"

namespace MEE
{

    class GLFWHandler : public WindowHandler
    {
	public:
		virtual bool init() override;
		virtual void stop() override;
		virtual void pollEvents() override;
		virtual void swapBuffer() override;
    };
}

