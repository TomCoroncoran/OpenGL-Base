#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>

#include "Keybinds.h"


//-----------------------------------------<>-----------------------------------------//
//Namespace for handing all input related tasks. Uses the GLFW Library.
//-----------------------------------------<>-----------------------------------------//
namespace Input
{
    //-----------------------------------------<>-----------------------------------------//
    // Function to Initialize the namespace, other functions will not work if this has not 
    // been called first.
    //-----------------------------------------<>-----------------------------------------//
    void Init();

    //-----------------------------------------<>-----------------------------------------//
    // Function to update internal workings of the namespace. Must be called each time your
    // application udpates. Generally this is once whenever your window updates.
    //-----------------------------------------<>-----------------------------------------//
    void Tick();

    //-----------------------------------------<>-----------------------------------------//
    // Function to set the mode of the cursor for the current window.
    // int mode - The mode to set the cursor to. Choose between 4 options:
    // GLFW_CURSOR_NORMAL - Cursor is visible, free to move, and not locked to the window.
    // GLFW_CURSOR_HIDDEN - Same as GLFW_CURSOR_NORMAL however when the cursor is inside the
    // content area of the window it will be hidden.
    // GLFW_CURSOR_DISABLED - Cursor is hidden and locked to the center of the content area.
    // Will still provide a virtual cursor position. Useful for Camera Control.
    // GLFW_CURSOR_CAPTURED - Same as GLFW_CURSOR_NORMAL however the cursor cannot leave the
    // content area of the window.
    //-----------------------------------------<>-----------------------------------------//
    void SetCursorMode(int mode);

    //-----------------------------------------<>-----------------------------------------//
    // Function to get the current position of the mouse.
    //-----------------------------------------<>-----------------------------------------//
    glm::dvec2 GetMousePosition();

    //-----------------------------------------<>-----------------------------------------//
    // Function to get how far the mouse has moved since Input::Tick() was last called.
    //-----------------------------------------<>-----------------------------------------//
    glm::dvec2 GetMouseDelta();

    //-----------------------------------------<>-----------------------------------------//
    // Function to get how far the mouse has scrolled since Input::Tick() was last called
    //-----------------------------------------<>-----------------------------------------//
    double GetScrollDelta();

    //-----------------------------------------<>-----------------------------------------//
    // Function to see if a mouse button is being held down.
    // int button - The mouse button that is being held. Can be any value from 
    // GLFW_MOUSE_BUTTON
    //-----------------------------------------<>-----------------------------------------//
    bool IsMouseButtonDown(int button);

    //-----------------------------------------<>-----------------------------------------//
    // Function to get the elapsed time in seconds since a mouse button was pressed.
    // int button - The mouse button that is being held. Can be any value from 
    // GLFW_MOUSE_BUTTON
    //-----------------------------------------<>-----------------------------------------//
    double GetTimeSinceMouseButtonPressed(int button);

    //-----------------------------------------<>-----------------------------------------//
    // Function to get the name of a mouse button.    
    // int button - The mouse button that is being held. Can be any value from 
    // GLFW_MOUSE_BUTTON
    //-----------------------------------------<>-----------------------------------------//
    std::string GetMouseButtonName(int button);

    //-----------------------------------------<>-----------------------------------------//
    // Function to see if a mouse button has just been pressed down. This function will
    // return true for one Input::Tick() and will then return false even if the mouse button
    // is still being held down. Useful for actions that require a single input.    
    // int button - The mouse button that is being clicked. Can be any value from 
    // GLFW_MOUSE_BUTTON
    //-----------------------------------------<>-----------------------------------------//
    bool WasMouseButtonJustPressed(int button);

    bool IsKeyDown(int key);
    double GetTimeSinceKeyPressed(int key);
    std::string GetKeyName(int key);
    bool WasKeyJustPressed(int key);
};

