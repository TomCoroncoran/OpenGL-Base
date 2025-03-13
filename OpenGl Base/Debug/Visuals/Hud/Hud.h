#pragma once
namespace Debug
{
    namespace Visuals
    {
        namespace Hud
        {
            //have to be exposed in header for ImGui to access them
            inline bool fps_counter = true;
            inline bool frame_buffer_size = true;
            inline bool input_overlay = true;

            //-----------------------------------------<>-----------------------------------------//
            // Function to draw all debug related visuals. Should be called once per application 
            // tick.
            //-----------------------------------------<>-----------------------------------------//
            void Draw();
        }
    }
}

