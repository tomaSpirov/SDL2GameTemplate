 
cmake_minimum_required(VERSION 3.20)

# Fix for SDL_ttf vendored FreeType
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

project(SDL2GameTemplate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Where to put external deps (optional, just for clarity)
set(FETCHCONTENT_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/sdl2")

# ======================================
# = SDL2 + extensions via FetchContent =
# ======================================
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.30.0
)

FetchContent_Declare(
    SDL2_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-2.8.2
)

FetchContent_Declare(
    SDL2_mixer
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
    GIT_TAG release-2.8.0
)

FetchContent_Declare(
    SDL2_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
    GIT_TAG release-2.22.0
)

FetchContent_MakeAvailable(SDL2 SDL2_image SDL2_mixer SDL2_ttf)


# ==============================================
# = Helper: copy all DLLs next to the game exe =
# ==============================================

function(copy_sdl_dlls TARGET_NAME)
    if (WIN32)
        # SDL2
        add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${FETCHCONTENT_BASE_DIR}/sdl2-build/$<CONFIG>"
                "$<TARGET_FILE_DIR:${TARGET_NAME}>"
        )

        # SDL2_image
        add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${FETCHCONTENT_BASE_DIR}/sdl2_image-build/$<CONFIG>"
                "$<TARGET_FILE_DIR:${TARGET_NAME}>"
        )

        # SDL2_mixer
        add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${FETCHCONTENT_BASE_DIR}/sdl2_mixer-build/$<CONFIG>"
                "$<TARGET_FILE_DIR:${TARGET_NAME}>"
        )

        # SDL2_ttf
        add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${FETCHCONTENT_BASE_DIR}/sdl2_ttf-build/$<CONFIG>"
                "$<TARGET_FILE_DIR:${TARGET_NAME}>"
        )
    endif()
endfunction()




# =================
# = Engine + Game =
# =================

add_subdirectory(engine)
add_subdirectory(game)
