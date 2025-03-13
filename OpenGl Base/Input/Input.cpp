#include "Input.h"
#include <array>

#include "../Debug/Log/Log.h"
#include "../Window/Window.h"

namespace Input
{
    struct Key
    {
        bool pressed;
        bool released;
        double time_pressed;
    };

    std::array<Key, GLFW_KEY_LAST> keys;
    std::array<Key, GLFW_MOUSE_BUTTON_LAST> mouse_buttons;

    glm::dvec2 mouse_pos = {  };
    glm::dvec2 mouse_delta = {  };
    double scroll_delta = {  };
    double scroll_offset = {  };

    void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
    void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);


    void Init()
    {
        for (Key& key : keys)
        {
            key.pressed = false;
            key.released = true;
            key.time_pressed = 0.0;
        }

        for (Key& key : mouse_buttons)
        {
            key.pressed = false;
            key.released = true;
            key.time_pressed = 0.0;
        }

        GLFWwindow* window = Window::GetGLFWWindow();
        Debug::Assert(window, "Window::GetGLFWWindow() Returned Nullptr", __LINE__, __FILE__);
        
        if (glfwRawMouseMotionSupported())
            glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
        

        glfwSetKeyCallback(window, KeyCallBack);
        glfwSetCursorPosCallback(window, CursorPositionCallback);
        glfwSetMouseButtonCallback(window, MouseButtonCallback);
        glfwSetScrollCallback(window, ScrollCallback);
    }

    void Tick()
    {
        static glm::dvec2 last_mouse_pos = mouse_pos;
        mouse_delta = mouse_pos - last_mouse_pos;
        last_mouse_pos = mouse_pos;

        scroll_delta = scroll_offset;
        scroll_offset = 0.0;

        glfwPollEvents();
    }

    void SetCursorMode(int mode)
    {
        GLFWwindow* window = Window::GetGLFWWindow();
        if (Debug::LogError(window, "Window::GetGLFWWindow() Returned Nullptr", __LINE__, __FILE__))
            return;

        glfwSetInputMode(window, GLFW_CURSOR, mode);
    }

    glm::dvec2 GetMousePosition()
    {
        return mouse_pos;
    }

    glm::dvec2 GetMouseDelta()
    {
        return mouse_delta;
    }

    double GetScrollDelta()
    {
        return scroll_delta;
    }

    bool IsMouseButtonDown(int button)
    {
        return mouse_buttons[button].pressed;
    }

    double GetTimeSinceMouseButtonPressed(int button)
    {
        return glfwGetTime() - mouse_buttons[button].time_pressed;
    }

    std::string GetMouseButtonName(int button)
    {
        switch (button)
        {
        case(GLFW_MOUSE_BUTTON_4): return "Mouse Button 4";
        case(GLFW_MOUSE_BUTTON_5): return "Mouse Button 5";
        case(GLFW_MOUSE_BUTTON_6): return "Mouse Button 6";
        case(GLFW_MOUSE_BUTTON_7): return "Mouse Button 7";
        case(GLFW_MOUSE_BUTTON_8): return "Mouse Button 8";
        case(GLFW_MOUSE_BUTTON_LEFT): return "Mouse Button Left";
        case(GLFW_MOUSE_BUTTON_RIGHT): return "Mouse Button Right";
        case(GLFW_MOUSE_BUTTON_MIDDLE): return "Mouse Button Middle";
        default: return "Mouse Button Unknown";
        }
    }

    bool WasMouseButtonJustPressed(int button)
    {
        if (mouse_buttons[button].pressed && mouse_buttons[button].released)
        {
            mouse_buttons[button].released = false;
            return true;
        }

        return false;
    }

    bool IsKeyDown(int key)
    {
        return keys[key].pressed;
    }

    double GetTimeSinceKeyPressed(int key)
    {
        return glfwGetTime() - keys[key].time_pressed;
    }

    std::string GetKeyName(int key)
    {
        switch (key)
        {
        case GLFW_KEY_SPACE: return "SPACE";
        case GLFW_KEY_APOSTROPHE: return "APOSTROPHE (' )";
        case GLFW_KEY_COMMA: return "COMMA (, )";
        case GLFW_KEY_MINUS: return "MINUS (- )";
        case GLFW_KEY_PERIOD: return "PERIOD (. )";
        case GLFW_KEY_SLASH: return "SLASH (/ )";
        case GLFW_KEY_0: return "0";
        case GLFW_KEY_1: return "1";
        case GLFW_KEY_2: return "2";
        case GLFW_KEY_3: return "3";
        case GLFW_KEY_4: return "4";
        case GLFW_KEY_5: return "5";
        case GLFW_KEY_6: return "6";
        case GLFW_KEY_7: return "7";
        case GLFW_KEY_8: return "8";
        case GLFW_KEY_9: return "9";
        case GLFW_KEY_SEMICOLON: return "SEMICOLON (; )";
        case GLFW_KEY_EQUAL: return "EQUAL (= )";
        case GLFW_KEY_A: return "A";
        case GLFW_KEY_B: return "B";
        case GLFW_KEY_C: return "C";
        case GLFW_KEY_D: return "D";
        case GLFW_KEY_E: return "E";
        case GLFW_KEY_F: return "F";
        case GLFW_KEY_G: return "G";
        case GLFW_KEY_H: return "H";
        case GLFW_KEY_I: return "I";
        case GLFW_KEY_J: return "J";
        case GLFW_KEY_K: return "K";
        case GLFW_KEY_L: return "L";
        case GLFW_KEY_M: return "M";
        case GLFW_KEY_N: return "N";
        case GLFW_KEY_O: return "O";
        case GLFW_KEY_P: return "P";
        case GLFW_KEY_Q: return "Q";
        case GLFW_KEY_R: return "R";
        case GLFW_KEY_S: return "S";
        case GLFW_KEY_T: return "T";
        case GLFW_KEY_U: return "U";
        case GLFW_KEY_V: return "V";
        case GLFW_KEY_W: return "W";
        case GLFW_KEY_X: return "X";
        case GLFW_KEY_Y: return "Y";
        case GLFW_KEY_Z: return "Z";
        case GLFW_KEY_LEFT_BRACKET: return "LEFT BRACKET ([ )";
        case GLFW_KEY_BACKSLASH: return "BACKSLASH (\\ )";
        case GLFW_KEY_RIGHT_BRACKET: return "RIGHT BRACKET (] )";
        case GLFW_KEY_GRAVE_ACCENT: return "GRAVE ACCENT (` )";
        case GLFW_KEY_ESCAPE: return "ESCAPE";
        case GLFW_KEY_ENTER: return "ENTER";
        case GLFW_KEY_TAB: return "TAB";
        case GLFW_KEY_BACKSPACE: return "BACKSPACE";
        case GLFW_KEY_INSERT: return "INSERT";
        case GLFW_KEY_DELETE: return "DELETE";
        case GLFW_KEY_RIGHT: return "RIGHT ARROW";
        case GLFW_KEY_LEFT: return "LEFT ARROW";
        case GLFW_KEY_DOWN: return "DOWN ARROW";
        case GLFW_KEY_UP: return "UP ARROW";
        case GLFW_KEY_F1: return "F1";
        case GLFW_KEY_F2: return "F2";
        case GLFW_KEY_F3: return "F3";
        case GLFW_KEY_F4: return "F4";
        case GLFW_KEY_F5: return "F5";
        case GLFW_KEY_F6: return "F6";
        case GLFW_KEY_F7: return "F7";
        case GLFW_KEY_F8: return "F8";
        case GLFW_KEY_F9: return "F9";
        case GLFW_KEY_F10: return "F10";
        case GLFW_KEY_F11: return "F11";
        case GLFW_KEY_F12: return "F12";
        case GLFW_KEY_KP_0: return "NUMPAD 0";
        case GLFW_KEY_KP_1: return "NUMPAD 1";
        case GLFW_KEY_KP_2: return "NUMPAD 2";
        case GLFW_KEY_KP_3: return "NUMPAD 3";
        case GLFW_KEY_KP_4: return "NUMPAD 4";
        case GLFW_KEY_KP_5: return "NUMPAD 5";
        case GLFW_KEY_KP_6: return "NUMPAD 6";
        case GLFW_KEY_KP_7: return "NUMPAD 7";
        case GLFW_KEY_KP_8: return "NUMPAD 8";
        case GLFW_KEY_KP_9: return "NUMPAD 9";
        case GLFW_KEY_LEFT_SHIFT: return "LEFT SHIFT";
        case GLFW_KEY_LEFT_CONTROL: return "LEFT CONTROL";
        case GLFW_KEY_LEFT_ALT: return "LEFT ALT";
        case GLFW_KEY_RIGHT_SHIFT: return "RIGHT SHIFT";
        case GLFW_KEY_RIGHT_CONTROL: return "RIGHT CONTROL";
        case GLFW_KEY_RIGHT_ALT: return "RIGHT ALT";
        case GLFW_KEY_MENU: return "MENU";
        default: return "UNKNOWN";
        }
    }

    bool WasKeyJustPressed(int key)
    {
        if (keys[key].pressed && keys[key].released)
        {
            keys[key].released = false;
            return true;
        }

        return false;
    }

    void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            keys[key].pressed = true;
            keys[key].time_pressed = glfwGetTime();
        }
        else if (action == GLFW_RELEASE)
        {
            keys[key].released = true;
            keys[key].pressed = false;
            keys[key].time_pressed = 0;
        }
    }

    static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
    {
        mouse_pos.x = xpos;
        mouse_pos.y = ypos;
    }

    void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            mouse_buttons[button].pressed = true;
            mouse_buttons[button].time_pressed = glfwGetTime();
        }
        else if (action == GLFW_RELEASE)
        {
            mouse_buttons[button].released = true;
            mouse_buttons[button].pressed = false;
            mouse_buttons[button].time_pressed = 0;
        }
    }

    void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
    {
        scroll_offset += yoffset;
    }
}