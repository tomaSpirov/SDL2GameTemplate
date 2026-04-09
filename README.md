\# SDL2 Game Template (C++/CMake/Visual Studio 2022/Windows 11 x64)



\## Info

A modern, reusable SDL2 game template for C++ projects with automatic download and setup of:

SDL2 (release‑2.30.0)
SDL2\_image (release‑2.8.2)
SDL2\_mixer (release‑2.8.0)
SDL2\_ttf (release‑2.22.0)

This is an all‑in‑one setup with no hassle.

It is suitable even for people with no SDL2 or CMake knowledge, and is ready to use immediately.

All libraries are downloaded automatically using CMake FetchContent, so you never need to
manually install or configure SDL again.

This template is designed to be cloned and reused every time you start a new game.

Prepared and tested on Windows 11 x64 using Visual Studio 2022.



\## Project Structure



The engine folder contains the SDL2 initialization layer.
The game folder uses the engine and contains your game logic.

This structure is powerful and clean, allowing you to build your own custom engine while keeping
game logic separate.



\## Features

* Clean project structure  
Only rename the main folder (SDL2GameTemplate) when starting a new project.
* Engine and game separation  
The engine initializes all SDL subsystems.
Your game links to the engine and stays clean.
* Automatic SDL2 download  
SDL2 and all extensions are fetched from GitHub automatically.
No installers, no manual linking, no DLL hunting.
* Automatic DLL copying  
After each build, all required DLLs (including dependencies) are copied next to the game executable.
* Debug and Release support  
Debug uses SDL2d.dll, Release uses SDL2.dll.
Everything is handled automatically.
* Zero Visual Studio configuration  
CMake generates the entire solution.
No manual project editing required.



\## How to use



1. Download this template from GitHub.
2. (Optional) Rename the template folder.  
Rename SDL2GameTemplate to your new project name.
3. (Skip this step if you did NOT rename the folder in step 2.)  
Edit the root CMakeLists.txt:  
Change:
project(SDL2GameTemplate)
To:
project(MyNewGame)
4. Open a command prompt.
5. Move to the project folder:
cd SDL2GameTemplate
or:
cd MyNewGame
6. Create a build folder:
mkdir build
7. Move to the build folder:
cd build
8. Generate the Visual Studio solution:
cmake -G "Visual Studio 17 2022" ..



Note: The ".." (two dots) is important — it tells CMake to use the parent folder
where the main CMakeLists.txt is located.





9\. Build (Debug):

cmake --build . --config Debug



10\. Run the game:
build/game/Debug/game.exe



9\. Build (Release):

cmake --build . --config Release



10\. Run the game:
build/game/Release/game.exe



\## Clean Rebuild



If you need a fresh build:

Delete the entire build/ folder.

Repeat steps 6–10.



\## License

This template is free to use for any personal or commercial project.

