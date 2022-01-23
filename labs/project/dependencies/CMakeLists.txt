include(FetchContent)

#SFML
set(SFML_VERSION "2.5.1")

FetchContent_Declare(
        sfml
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG        "${SFML_VERSION}"
)

message(STATUS "Declaring sfml to fetch...")

set(SOURCE_FILES
        stb/stb_image.h)
add_library(stb INTERFACE ${SOURCE_FILES})
target_include_directories(stb INTERFACE stb)


add_subdirectory(sfml)