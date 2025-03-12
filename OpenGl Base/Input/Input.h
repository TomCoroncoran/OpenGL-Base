#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>

#include "Keybinds.h"

namespace Input
{
    void Init();
    void PollEvents();
    void SetCursorMode(GLenum cursor_enabled);
    glm::dvec2 GetMousePosition();
    bool IsKeyDown(int key);
    double GetTimeSinceKeyPressed(int key);
    std::string GetKeyName(int key);
    bool WasKeyJustPressed(int key);
};

