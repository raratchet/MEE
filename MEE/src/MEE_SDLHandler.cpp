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
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != -1)
            {

                m_window = SDL_CreateWindow
                (m_windowName.c_str(), m_x, m_y, m_width, m_height,
                 SDL_WINDOW_OPENGL);

                m_glContext = SDL_GL_CreateContext(m_window);


                SDL_GL_MakeCurrent(m_window, m_glContext);

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
            auto controller = SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);

            SDL_CreateWindowAndRenderer(
                    m_width, m_height,
                    SDL_WINDOW_RESIZABLE,
                    &m_window, &m_sdlRenderer);

            if (m_window != NULL)
            {
                SDL_SetWindowTitle(m_window, m_windowName.c_str());
                m_sdlSurface = SDL_GetWindowSurface(m_window);
            }
            else
            {
                success = false;
            }

            SDL_SetRenderDrawColor(m_sdlRenderer, 53, 40, 230, 255);

            if (MEE_RenderClear == nullptr)
                MEE_RenderClear = [=]() { this->SDL_Render_RenderClear(); }; //Probablemente esto no es adecuado
        }

        return success;
    }

    void SDLHandler::Stop()
    {
        if (WindowHandler::GetRenderAPI() == RenderAPI::OpenGL)
        {
            SDL_GL_DeleteContext(m_glContext);
        }
        else if (WindowHandler::GetRenderAPI() == RenderAPI::SDL_Render)
        {
            SDL_FreeSurface(m_sdlSurface);
            SDL_DestroyRenderer(m_sdlRenderer);
        }

        SDL_DestroyWindow(m_window);
        SDL_Quit();

    }


    void SDLHandler::SwapBuffer()
    {
        if (WindowHandler::GetRenderAPI() == RenderAPI::OpenGL)
            SDL_GL_SwapWindow(m_window);
        else if (WindowHandler::GetRenderAPI() == RenderAPI::SDL_Render)
            SDL_RenderPresent(m_sdlRenderer);
    }

    void SDLHandler::RefreshWindow()
    {

    }

    void SDLHandler::SDL_Render_RenderClear()
    {
        if(m_sdlRenderer)
            SDL_RenderClear(m_sdlRenderer);
    }

    SDL_Renderer *SDLHandler::GetRenderer() {
        return m_sdlRenderer;
    }

}

