====================================
= Contributing to SDL2GameTemplate =
====================================

Thank you for your interest in contributing to this template.

This project is designed to be a clean, reusable starting point for new SDL2‑based C++ games.  
The goal is to provide a **fully automated setup** that downloads, builds, and configures SDL2  
without requiring the user to install anything manually.

Because this template must remain simple and ready‑to‑use, **engine code and game code must not be modified**.  
All contributions must focus only on **automation improvements**, including future support for Linux and macOS.

---

================
= Requirements =
================

To build and work with this template, you need:

- Visual Studio 2022 (with C++ Desktop Development)
- CMake 3.20+
- Git (optional)
- Windows 10/11 (template currently tested on Windows 11 x64)

SDL2 and all extensions are downloaded automatically using CMake FetchContent.

Linux and macOS support is planned through cross‑platform CMake automation.

---

=====================
= Project Structure =
=====================

SDL2GameTemplate/
├─ assets/          # Game assets (images, audio, fonts…)
├─ engine/          # Engine layer (must remain unchanged)
├─ game/            # Game entry point (must remain unchanged)
├─ external/sdl2/   # Auto-downloaded SDL2 sources + builds
└─ CMakeLists.txt   # Root build script (automation logic lives here)


---



Only the **build automation**, **FetchContent logic**, and **DLL copy logic** should be improved.  
The engine and game folders must remain untouched.

---

==================================
= Building the Project (Windows) =
==================================

### 1. Create a build folder

mkdir build
cd build


### 2. Generate Visual Studio solution
cmake -G "Visual Studio 17 2022" ..


### 3. Build
cmake --build . --config Debug



The game executable will be located in:
build/game/Debug/game.exe



All required DLLs are copied automatically.

---

====================
= Running the Game =
====================

Make sure your working directory is the project root so assets load correctly.  
Visual Studio is already configured to do this.

---

====================================
= Cross‑Platform Support (Planned) =
====================================

Future updates will include:

- Automatic `.dll`, `.so`, and `.dylib` handling  
- Linux Makefile/Ninja build support  
- macOS Xcode/Makefile build support  
- Platform‑aware CMake logic  
- Optional CMakePresets.json for multi‑OS builds  

Contributions in these areas are welcome.

---

==================================
= What Contributions Are Allowed =
==================================

Only improvements related to **automation** are accepted:

### Allowed (Automation Only)
- Improving SDL2 FetchContent reliability  
- Improving DLL/SO/DYLIB copy logic  
- Improving cross‑platform CMake automation  
- Improving build scripts for Linux/macOS  
- Improving error handling in the build process  
- Improving documentation related to automation  

### Not Allowed
- will be added after the first release if any.
 
The engine and game code must remain untouched so the template stays simple and ready to use.

---

==========================
= Updating SDL2 Versions =
==========================

To update SDL2 or its extensions:

1. Open the root `CMakeLists.txt`
2. Update the `GIT_TAG` values under `FetchContent_Declare`
3. Delete the `external/sdl2/` folder
4. Reconfigure CMake

---
====================
= Reporting Issues =
====================

If you encounter a problem:

- Describe what you expected to happen  
- Include the error message  
- Include your CMake version and Visual Studio version  
- Mention whether you built Debug or Release  
- Mention your Windows version (or Linux/macOS version when supported)  

---

=================
= Pull Requests =
=================

If you fork this template and improve the automation:

- Keep changes small and focused  
- Do not modify engine or game code  
- Do not change the folder structure  
- Test Debug and Release builds  
- Update the CHANGELOG.md if needed  

---

Thank you for helping improve the automation and cross‑platform support of this template!


