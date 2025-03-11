#include "Menu.h"

#include <GLM/glm.hpp>
#include <imgui/imgui.h>

#include "../../Window/Window.h"

namespace Debug
{
    namespace Visuals
    {
        namespace Menu
        {
            bool visible = true;

            void DrawVideoTab();


            void Init()
            {

            }

            void Draw()
            {
                int flags = 0;
                flags |= ImGuiWindowFlags_NoResize;
                flags |= ImGuiWindowFlags_AlwaysAutoResize;
                ImGui::Begin("Debug Window", &visible, flags );

                if (ImGui::BeginTabBar("Tabs"))
                {
                    if (ImGui::BeginTabItem("Video"))
                    {
                        DrawVideoTab();
                        ImGui::EndTabItem();
                    }

                    ImGui::EndTabBar();
                }

                ImGui::End();
            }

            void DrawVideoTab()
            {
                glm::ivec2 window_pos = Window::GetPos();
                glm::ivec2 window_size = Window::GetSize();
                glm::ivec2 frame_buffer_size = Window::GetFrameBufferSize();
                
                bool update_window_pos = ImGui::InputInt2("Window Position", &window_pos.x);
                bool update_window_size = ImGui::InputInt2("Window Size", &window_size.x);
                ImGui::InputInt2("Frame Buffer Size", &frame_buffer_size.x);

                bool fullscreen_pending_update = ImGui::Checkbox("Fullscreen", &Window::fullscreen);


                if (update_window_pos) Window::SetPos(window_pos);
                if (update_window_size) Window::SetSize(window_size);

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
        }
    }
}