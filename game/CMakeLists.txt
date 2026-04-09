add_executable(game
    src/main.cpp
)

target_link_libraries(game
    PRIVATE
        engine
)

# Optional: set working directory to project root or assets
set_target_properties(game PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
 

copy_sdl_dlls(game)
