#include "Menu.h"

#include <GLM/glm.hpp>
#include <imgui/imgui.h>

#include "../../Window/Window.h"
#include "../../Input/Input.h"
#include "../Hud/Hud.h"

namespace Debug
{
    namespace Visuals
    {
        namespace Menu
        {
            bool visible = true;

            void HandleInput();
            void DrawWindowTab();
            void DrawOverlaysTab();


            void Init()
            {

            }

            void Draw()
            {
                HandleInput();

                if (!visible)
                    return;

                // Setting window to always snap to top left of content area.
                ImGuiViewport* viewport = ImGui::GetMainViewport();
                ImGui::SetNextWindowPos(viewport->Pos);

                int flags = 0;
                flags |= ImGuiWindowFlags_NoResize;
                flags |= ImGuiWindowFlags_AlwaysAutoResize;
                flags |= ImGuiWindowFlags_NoCollapse;

                ImGui::Begin("Debug Window", &visible, flags );

                if (ImGui::BeginTabBar("Tabs"))
                {
                    if (ImGui::BeginTabItem("Video"))
                    {
                        DrawWindowTab();
                        ImGui::EndTabItem();
                    }
                    if (ImGui::BeginTabItem("Overlays"))
                    {
                        DrawOverlaysTab();
                        ImGui::EndTabItem();
                    }

                    ImGui::EndTabBar();
                }

                ImGui::End();
            }

            void HandleInput()
            {
                if (Input::WasKeyJustPressed(TOGGLE_DEBUG_MENU))
                {
                    visible = !visible;
                }

                if (!visible)
                {
                    Input::SetCursorMode(GLFW_CURSOR_DISABLED);
                }
                else
                {
                    Input::SetCursorMode(GLFW_CURSOR_NORMAL);
                }
            }

            void DrawWindowTab()
            {
                glm::ivec2 window_pos = Window::GetPos();
                glm::ivec2 window_size = Window::GetSize();
                
                if (ImGui::InputInt2("Window Position", &window_pos.x)) Window::SetPos(window_pos);
                if (ImGui::InputInt2("Window Size", &window_size.x)) Window::SetSize(window_pos);

                bool fullscreen_pending_update = ImGui::Checkbox("Fullscreen", &Window::fullscreen);
                
                ImGui::Checkbox("FPS Counter", &Hud::fps_counter);
                ImGui::Checkbox("Frame Buffer Size", &Hud::frame_buffer_size);
                


                if (fullscreen_pending_update)
                {
                    if (Window::fullscreen)
                    {
                        Window::SetFullscreen();
                    }
                    else
                    {
                        Window::SetWindowed();
                    }
                }
            }

            void DrawOverlaysTab()
            {
                ImGui::Checkbox("FPS Counter", &Hud::input_overlay);
            }
        }
    }
}