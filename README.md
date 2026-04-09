SDL2 Game Template (C++/CMake/Visual Studio 2022/Windows 11 x64)


========
= Info =
========

A modern, reusable SDL2 game template for C++ projects with automatic download and setup of:

SDL2 (release‑2.30.0)
SDL2_image (release‑2.8.2)
SDL2_mixer (release‑2.8.0)
SDL2_ttf (release‑2.22.0)

This is an all‑in‑one setup with no hassle.

It is suitable even for people with no SDL2 or CMake knowledge, and is ready to use immediately.

All libraries are downloaded automatically using CMake FetchContent, so you never need to
manually install or configure SDL again.

This template is designed to be cloned and reused every time you start a new game.

Prepared and tested on Windows 11 x64 using Visual Studio 2022.


=====================
= Project Structure =
=====================

SDL2GameTemplate/
 |
 |-- CMakeLists.txt
 |      # Main build script for the entire project.
 |      # - Defines project name
 |      # - Downloads SDL2 + extensions via FetchContent
 |      # - Adds engine/ and game/ subdirectories
 |      # - Contains DLL copy logic
 |
 |-- assets/
 |      # Game assets (images, audio, fonts, etc.)
 |
 |-- external/
 |      |-- sdl2/
 |             # Auto-downloaded SDL2 sources + builds
 |             # (Created automatically by CMake)
 |
 |-- engine/
 |      |-- CMakeLists.txt
 |      |      # Builds the engine as a static library.
 |      |      # - Compiles Engine.cpp
 |      |      # - Links SDL2, SDL2_image, SDL2_mixer, SDL2_ttf
 |      |      # - Exposes engine functions to the game
 |      |
 |      |-- src/
 |             |-- Engine.h
 |             |-- Engine.cpp
 |                    # Initializes all SDL2 subsystems
 |                    # (video, audio, image, mixer, ttf)
 |
 |-- game/
        |-- CMakeLists.txt
        |      # Builds the game executable.
        |      # - Compiles main.cpp
        |      # - Links against the engine library
        |      # - Copies all SDL2 DLLs after build
        |
        |-- src/
               |-- main.cpp
                      # Game entry point



The engine folder contains the SDL2 initialization layer.
The game folder uses the engine and contains your game logic.

This structure is powerful and clean, allowing you to build your own custom engine while keeping
game logic separate.


============
= Features =
============

 - Clean project structure  
   Only rename the main folder (SDL2GameTemplate) when starting a new project.

 - Engine and game separation  
   The engine initializes all SDL subsystems.
   Your game links to the engine and stays clean.

 - Automatic SDL2 download  
   SDL2 and all extensions are fetched from GitHub automatically.
   No installers, no manual linking, no DLL hunting.

 - Automatic DLL copying  
   After each build, all required DLLs (including dependencies) are copied next to the game executable.

 - Debug and Release support  
   Debug uses SDL2d.dll, Release uses SDL2.dll.
   Everything is handled automatically.

 - Zero Visual Studio configuration  
   CMake generates the entire solution.
   No manual project editing required.


==============
= How to Use =
==============

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


For Debug:
9. Build (Debug):
       cmake --build . --config Debug

10. Run the game:
       build/game/Debug/game.exe


For Release:
9. Build (Release):
       cmake --build . --config Release

10. Run the game:
       build/game/Release/game.exe


=================
= Clean Rebuild =
=================

If you need a fresh build:

Delete the entire build/ folder.

Repeat steps 6–10.


===========
= License =
===========

This template is free to use for any personal or commercial project.
