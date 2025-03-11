#include "Visuals.h"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/spectrum.h>

#include "../../Window/Window.h"
#include "menu/Menu.h"


namespace Debug
{
    namespace Visuals
    {
        ImGuiIO* io = nullptr;
        
        void Init()
        {
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            io = &ImGui::GetIO();
            ImGui::Spectrum::StyleColorsSpectrum();

            ImGui_ImplGlfw_InitForOpenGL(Window::GetGLFWWindow(), true);
            ImGui_ImplOpenGL3_Init("#version 330 core");

            Menu::Init();
        }

        void Draw()
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            Menu::Draw();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }
    }
}