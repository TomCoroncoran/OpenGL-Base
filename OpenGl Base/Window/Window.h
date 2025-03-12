#pragma once
#include <string>
#include <vector>
#include <GLM/glm.hpp>

struct GLFWwindow;
struct GLFWmonitor;

//-----------------------------------------<>-----------------------------------------//
// Struct to hold a GLFWWindowHint. Used by the WindowConfig struct to store all the 
// GLFWWindowHints needed when the window is created.
//-----------------------------------------<>-----------------------------------------//
struct WindowHint
{
    int name = 0;
    int value = 0;
};

//-----------------------------------------<>-----------------------------------------//
// Config struct for a window. Each member variable is used by the Window::Init() 
// function to configure your window at program startup. Can leave all member variables
// as there default values to create a default GLFWwindow.
// 
// Vars:
//  bool fullscreen - should the window be fullscreen upon initialisation
//  glm::ivec2 size - size of the window upon initialisation
//  glm::ivec2 pos - the position of the window upon initialization
//  std::string title - the title of the window upon initialization
//  std::vector<WindowHint> hints - a vector of GLFWWindowHints that will be used to set
//                                 hint values of the window
// Funcs:
//  WindowConfig::AddHint() - wrapper function for Vector::emplace_back()
//-----------------------------------------<>-----------------------------------------//
struct WindowConfig
{
    bool fullscreen = false;
    glm::ivec2 size = { 800, 600 };
    std::string title = { "Window"};
    std::vector<WindowHint> hints;

    void AddHint(const int& name, const int& value);
};

namespace Window
{
    inline bool fullscreen = false;

    void Init(WindowConfig* config);

    bool ShouldClose();
    void Tick();

    glm::ivec2 GetPos();
    glm::ivec2 GetSize();
    glm::ivec2 GetFrameBufferSize();
    GLFWwindow* GetGLFWWindow();
    GLFWmonitor* GetPrimaryMonitor();
    double GetDeltaTime();

    void SetPos(const glm::ivec2& pos);
    void SetSize(const glm::ivec2& size);

    void SetFullscreen();
    void SetWindowed();
}

