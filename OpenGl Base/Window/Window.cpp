#include "Window.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include "../Debug/Log/Log.h"

void WindowConfig::AddHint(const int& name, const int& value)
{
    hints.emplace_back(WindowHint{name, value});
}

namespace Window
{
    GLFWwindow* window = {  };
    
    glm::ivec2 size = {  };
    glm::ivec2 pos = {  };
    glm::ivec2 framebuffer_size = {  };

    void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
    void SizeCallback(GLFWwindow* window, int width, int height);
    void PosCallback(GLFWwindow* window, int x, int y);

    void Init(WindowConfig* config)
    {
        Debug::Assert(config, "WindowConfig* Invalid", __LINE__, __FILE__);
        Debug::Assert(glfwInit(), "GLFW Failed To Initialize", __LINE__, __FILE__);

        for (const WindowHint& hint : config->hints)
        {
            glfwWindowHint(hint.name, hint.value);
        }

        GLFWmonitor* monitor = nullptr;
        if (config->fullscreen)
        {
            monitor = glfwGetPrimaryMonitor();
            Debug::LogError(monitor, "GLFW Failed To Get Primary Monitor", __LINE__, __FILE__);
        }

        window = glfwCreateWindow(config->size.x, config->size.y, config->title.c_str(), monitor, NULL);
        Debug::Assert(window, "GLFW Failed To Create A Window", __LINE__, __FILE__);

        glfwMakeContextCurrent(window);

        int version = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        Debug::Assert(version, "Glad Failed To Initialize", __LINE__, __FILE__);

        glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);
        glfwSetWindowSizeCallback(window, SizeCallback);
        glfwSetWindowPosCallback(window, PosCallback);

        glfwGetWindowPos(window, &pos.x, &pos.y);
        glfwGetFramebufferSize(window, &framebuffer_size.x, &framebuffer_size.y);
        glfwGetWindowSize(window, &size.x, &size.y);

        glViewport(0, 0, config->size.x, config->size.y);
    }

    bool ShouldClose()
    {
        if (Debug::LogError(window, "Window Not Valid. Did You Forget To Call Window::Init()", __LINE__, __FILE__))
            return true;

        return glfwWindowShouldClose(window);
    }

    void Tick()
    {
        Debug::LogError(window, "Window Not Valid. Did You Forget To Call Window::Init()", __LINE__, __FILE__);
    
        glfwSwapBuffers(window);
    }

    glm::ivec2 GetPos()
    {
        return pos;
    }

    glm::ivec2 GetSize()
    {
        return size;
    }

    glm::ivec2 GetFrameBufferSize()
    {
        return framebuffer_size;
    }

    GLFWwindow* GetGLFWWindow()
    {
        return window;
    }

    GLFWmonitor* GetPrimaryMonitor()
    {
        return glfwGetPrimaryMonitor();
    }

    void SetPos(const glm::ivec2& pos)
    {
        Debug::LogError(window, "Window Invalid. Did You Forget To Call Window::Init()", __LINE__, __FILE__);

        glfwSetWindowPos(window, pos.x, pos.y);
    }

    void SetSize(const glm::ivec2& size)
    {
        Debug::LogError(window, "Window Invalid. Did You Forget To Call Window::Init()", __LINE__, __FILE__);
        
        glfwSetWindowSize(window, size.x, size.y);
    }

    void SetFullscreen()
    {
        if (Debug::LogError(glfwGetWindowMonitor(window), "Window Is Already Fullscreen", __LINE__, __FILE__))
            return;

        glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), pos.x, pos.y, size.x, size.y, GLFW_DONT_CARE);
    }

    void SetWindowed()
    {
        if (Debug::LogError(glfwGetWindowMonitor(window) == nullptr, "Window Is Already Windowed", __LINE__, __FILE__))
            return;
    
        glfwSetWindowMonitor(window, nullptr, pos.x, pos.y, size.x, size.y, GLFW_DONT_CARE);

    }

    void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
    {   
        framebuffer_size.x = width;
        framebuffer_size.y = height;
        
        std::string status = "Window Framebuffer Size Updated: \n    Width: " + std::to_string(framebuffer_size.x) + "\n    Height: " + std::to_string(framebuffer_size.x);
        Debug::LogStatus(status);

        glViewport(0, 0, framebuffer_size.x, framebuffer_size.y);
    }

    void SizeCallback(GLFWwindow* window, int width, int height)
    {
        size.x = width;
        size.y = height;
        std::string status = "Window Size Updated: \n    Width: " + std::to_string(size.x) + "\n    Height: " + std::to_string(size.y);
        Debug::LogStatus(status);
    }

    void PosCallback(GLFWwindow* window, int x, int y)
    {
        pos.x = x;
        pos.y = y;
        
        std::string status = "Window Position Updated: \n    X: " + std::to_string(pos.x) + "\n    Y: " + std::to_string(pos.y);
        Debug::LogStatus(status);
    }
}