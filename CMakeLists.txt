cmake_minimum_required(VERSION 3.15)
project(CodeFramework)

# Define a versão C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Diretórios do projeto
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

# Incluir o FetchContent para gerenciar dependências
include(FetchContent)

# Configuração para baixar e incluir SDL2
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.28.4 # Escolha a versão apropriada
)
FetchContent_MakeAvailable(SDL2)

# Adicionar a biblioteca estática
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Diretórios de include
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

# Linkar a biblioteca SDL2
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2-static)

# Instalação (opcional)
install(TARGETS ${PROJECT_NAME}
        EXPORT CodeFrameworkTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY ${INCLUDE_DIR}/
        DESTINATION include)
