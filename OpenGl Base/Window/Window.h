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

    void AddHint(int name, int value);
};

namespace Window
{
    // Has to be exposed in the header for ImGui to access it. 
    inline bool fullscreen = false;

    inline bool log_pos_callbacks = false;
    inline bool log_size_callbacks = true;
    inline bool log_framebuffer_size_callbacks = true;

    //-----------------------------------------<>-----------------------------------------//
    // Function to init the application window.
    // WindowConfig* config - A Pointer to a WindowConfig struct. This must be valid or the
    //  program will exit.
    //-----------------------------------------<>-----------------------------------------//
    void Init(WindowConfig* config);

    //-----------------------------------------<>-----------------------------------------//
    // Function To Check if the application window should close.
    // Return - Will return true the application window should close.
    //-----------------------------------------<>-----------------------------------------//
    bool ShouldClose();

    //-----------------------------------------<>-----------------------------------------//
    // Function to update the window. Should be called every single time you wish to update
    // the window. Generally once per application tick.
    //-----------------------------------------<>-----------------------------------------//
    void Tick();

    //-----------------------------------------<>-----------------------------------------//
    // Basic getter functions.
    //-----------------------------------------<>-----------------------------------------//
    glm::ivec2 GetPos();
    glm::ivec2 GetSize();
    glm::ivec2 GetFrameBufferSize();
    GLFWwindow* GetGLFWWindow();
    GLFWmonitor* GetPrimaryMonitor();
    double GetDeltaTime();

    //-----------------------------------------<>-----------------------------------------//
    // Function to change the position of the window. Can take any values both negative and
    // positive. Will only change the position of the window if the new position is a valid
    // screen coordinate.
    // glm::ivec2 pos - The new position of the window.
    //-----------------------------------------<>-----------------------------------------//
    void SetPos(const glm::ivec2& pos);

    //-----------------------------------------<>-----------------------------------------//
    // Function to change the size of the window. Will only take positive values. Will fail
    // to update the window if the values are not valid
    // glm::ivec2 size - The new size of the window.
    //-----------------------------------------<>-----------------------------------------//
    void SetSize(const glm::ivec2& size);

    //-----------------------------------------<>-----------------------------------------//
    // Functions to set the window to fullscreen or windowed respectfully
    //-----------------------------------------<>-----------------------------------------//
    void SetFullscreen();
    void SetWindowed();
}

