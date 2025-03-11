#include <iostream>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <Imgui/imgui.h>

#include "Window/Window.h"
#include "Debug/Visuals/Visuals.h"

int main()
{    
    WindowConfig window_config;
    window_config.title = "OpenGL Base";
    window_config.size = glm::ivec2{ 800, 600 };
    window_config.fullscreen = false;
    window_config.AddHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    window_config.AddHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window_config.AddHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window_config.AddHint(GLFW_RESIZABLE, GLFW_FALSE);

    Window::Init(&window_config);
    
    Debug::Visuals::Init();

    while (!Window::ShouldClose())
    {   
        Window::Tick();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Debug::Visuals::Draw();

        glfwPollEvents();
    }
    
    return 0;
}