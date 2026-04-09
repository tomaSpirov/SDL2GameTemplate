# Changelog

All notable changes to this project will be documented in this file.

This project follows **semantic versioning**:

- **MAJOR** – Breaking changes  
- **MINOR** – New features, backwards compatible  
- **PATCH** – Bug fixes, small improvements  

---

## [1.0.3] – Documentation & Contribution Policy Update

### Changed
- Updated `README.md`.
- Updated `CHANGELOG.md`



## [1.0.2] – Documentation & Contribution Policy Update

### Changed
- Updated `README.md`.
- Updated `CONTRIBUTING.md`

---

## [1.0.1] – Documentation & Contribution Policy Update

### Changed
- Updated `README.md` with clearer instructions, Windows 11 x64 note, and improved folder structure descriptions.
- Updated `CONTRIBUTING.md` to reflect the new project philosophy:
  - Only automation-related contributions are allowed.
  - Engine and game code must remain untouched.
  - Cross-platform automation (Linux/macOS) is now part of the roadmap.
- Added detailed explanations for each `CMakeLists.txt` in the folder structure diagram.
- Clarified optional renaming steps and improved build instructions.

### Added
- Future support notes for Linux and macOS.
- Clear rules for allowed vs. not allowed contributions.
- Improved documentation for CMake generator usage.

---

## [1.0.0] – Initial Release

### Added
- Complete SDL2 game template structure.
- Automatic SDL2 + SDL2_image + SDL2_mixer + SDL2_ttf download via FetchContent.
- Engine module with:
  - SDL initialization
  - SDL_image initialization
  - SDL_mixer initialization
  - SDL_ttf initialization
  - Window creation/destruction helpers
- Game module with example `main.cpp`.
- Automatic DLL copying for Debug/Release.
- Visual Studio 2022 CMake support.
- `.gitignore` tailored for C++/CMake/VS.
- README with usage instructions.

---

## [Future Versions]

### Planned (Automation Only)
- Cross-platform support for Linux and macOS.
- Automatic `.dll`, `.so`, and `.dylib` handling.
- Improved FetchContent reliability.
- Better error handling during SDL2 download/build.
- Optional CMake presets for multi‑OS builds.
- GitHub Actions CI workflow for Windows/Linux/macOS.

---

## [Unreleased]

Changes that are staged locally but not yet part of a tagged version.
