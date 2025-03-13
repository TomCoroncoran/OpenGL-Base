# <ins>OpenGL Base Project</ins>
## Overview
This project is an OpenGL-based application that provides a framework for handling window creation, input management, and rendering using GLFW and GLAD libraries. It includes functionalities for managing window properties, handling user input (keyboard and mouse), and rendering graphics.
## Features
•	Window Management: Create and manage application windows with customizable properties.
•	Input Handling: Comprehensive input handling for keyboard and mouse using the GLFW library.
•	Rendering: Utilize OpenGL for rendering graphics.
•	Debugging Tools: Includes debugging tools and visual overlays for development purposes.
## Installation
1.	Clone the Repository:
2.	Install Dependencies:
•	Ensure you have the following libraries installed:
•	GLFW
•	GLAD
•	GLM
•	ImGui
3.	Build the Project:
•	Open the project in Visual Studio 2022.
•	Build the solution using the provided project files.
## Usage
1.	Initialize the Window:
•	Configure the window properties using the WindowConfig struct.
•	Call Window::Init() to initialize the window.
2.	Handle Input:
•	Use the Input namespace to handle keyboard and mouse input.
•	Functions include Input::IsKeyDown(), Input::GetMousePosition(), and more.
3.	Rendering:
•	Use OpenGL functions to render graphics within the window.
•	Utilize the provided Debug::Visuals namespace for debugging overlays.
4.	Debugging:
•	Enable and configure debugging tools using the Debug::Visuals::Menu namespace.
•	Toggle visibility and configure settings through the provided ImGui interface.
## Example
Basic Example of functionality included in main.cpp
## Contributing
Contributions are welcome! Please fork the repository and submit pull requests for any improvements or bug fixes.
## License
This project is licensed under the MIT License. See the LICENSE file for details.
