#include "Hud.h"
#include <string>
#include <imgui/imgui.h>

#include "../../Window/Window.h"
#include "../../Input/Input.h"

namespace Debug
{
    namespace Visuals
    {
        namespace Hud
        {
            void DrawFpsCounter();
            void DrawFrameBufferSize();
            void DrawInputOverlay();

            void DrawHud()
            {
                ImGuiViewport* viewport = ImGui::GetMainViewport();

                ImGui::SetNextWindowPos(viewport->Pos);     
                ImGui::SetNextWindowSize(viewport->Size);
                
                ImGui::Begin("HUD", nullptr,
                    ImGuiWindowFlags_NoDecoration |
                    ImGuiWindowFlags_NoBackground |
                    ImGuiWindowFlags_NoInputs |
                    ImGuiWindowFlags_NoMove |
                    ImGuiWindowFlags_NoScrollbar |
                    ImGuiWindowFlags_NoScrollWithMouse);
                
                if (fps_counter)
                    DrawFpsCounter();

                if (frame_buffer_size)
                    DrawFrameBufferSize();

                if (input_overlay)
                    DrawInputOverlay();


                ImGui::End();
            }

            void DrawFpsCounter()
            {
                int fps = static_cast<int>(1.0 / Window::GetDeltaTime());

                std::string text = "Window FPS: " + std::to_string(fps);

                ImGui::TextColored(ImVec4{ 255, 255, 255, 255 }, text.c_str());
            }

            void DrawFrameBufferSize()
            {
                glm::ivec2 frame_buffer_size = Window::GetFrameBufferSize();

                std::string text = "Framebuffer Size:\n"
                                   "   X: " + std::to_string(frame_buffer_size.x) + "\n" +
                                   "   Y: " + std::to_string(frame_buffer_size.y);

                ImGui::TextColored(ImVec4{ 255, 255, 255, 255 }, text.c_str());
            }

            void DrawInputOverlay()
            {
                ImGui::TextColored(ImVec4{ 255, 255, 255, 255 }, "Input Overlay");

                for (int i = 0; i < GLFW_KEY_LAST; ++i)
                {
                    if (Input::IsKeyDown(i))
                    {
                        std::string text = Input::GetKeyName(i);
                        text += ": ";
                        text += std::to_string(Input::GetTimeSinceKeyPressed(i));

                        ImGui::TextColored(ImVec4{ 255, 255, 255, 255 }, text.c_str());
                    }
                }
            }
        }
    }
}