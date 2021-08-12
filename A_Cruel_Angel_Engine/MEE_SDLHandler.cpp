#include "MEE_SDLHandler.h"
#include "MEE_Graphics.h"

#ifndef GLEW_STATIC
//#define GLEW_STATIC
#endif // !GLEW_STATIC

#include <GL/glew.h>

namespace MEE
{
    bool SDLHandler::Init()
    {
        bool success = true;

        if (WindowHandler::GetRenderAPI() == RenderAPI::OpenGL)
        {
            if (SDL_Init(SDL_INIT_VIDEO) != -1)
            {

                window = SDL_CreateWindow
                (windowName.c_str(), pos_x, pos_y, width, height,
                    SDL_WINDOW_OPENGL);

                glContext = SDL_GL_CreateContext(window);


                SDL_GL_MakeCurrent(window, glContext);

                SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
                SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

                glewExperimental = GL_TRUE;

                if (glewInit() != GLEW_OK)
                    success = false;

                MEE_InitGL();
            }
            else
            {
                success = false;
            }
        }
        else if (WindowHandler::GetRenderAPI() == RenderAPI::SDL_Render)
        {
            SDL_CreateWindowAndRenderer(
                width, height,
                SDL_WINDOW_RESIZABLE,
                &window, &sdlRenderer);

            if (window != NULL)
            {
                SDL_SetWindowTitle(window, windowName.c_str());
                sdlSurface = SDL_GetWindowSurface(window);
            }
            else
            {
                success = false;
            }

            SDL_SetRenderDrawColor(sdlRenderer, 53, 40, 230, 255);

            if (MEE_RenderClear == nullptr)
                MEE_RenderClear = [=]() { this->SDL_Render_RenderClear(); }; //Probablemente esto no es adecuado
        }

        return success;
    }

    void SDLHandler::Stop()
    {
        if (WindowHandler::GetRenderAPI() == RenderAPI::OpenGL)
        {
            SDL_GL_DeleteContext(glContext);
        }
        else if (WindowHandler::GetRenderAPI() == RenderAPI::SDL_Render)
        {
            SDL_FreeSurface(sdlSurface);
            SDL_DestroyRenderer(sdlRenderer);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

    }


    void SDLHandler::SwapBuffer()
    {
        if (WindowHandler::GetRenderAPI() == RenderAPI::OpenGL)
            SDL_GL_SwapWindow(window);
        else if (WindowHandler::GetRenderAPI() == RenderAPI::SDL_Render)
            SDL_RenderPresent(sdlRenderer);
    }

    void SDLHandler::RefreshWindow()
    {

    }

    void SDLHandler::SDL_Render_RenderClear()
    {
        if(sdlRenderer)
            SDL_RenderClear(sdlRenderer);
    }

}

