cmake_minimum_required(VERSION 3.14)

# Nome do projeto e framework
project(CodeFramework VERSION 1.0 LANGUAGES CXX)

# Configurações globais
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Habilitar FetchContent para baixar dependências automaticamente
include(FetchContent)

# Declarar SDL2 como dependência
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG release-2.30.9
)

# Baixar e tornar disponível o SDL2
FetchContent_MakeAvailable(SDL2)

# Configurar os arquivos de cabeçalho e código-fonte
file(GLOB_RECURSE FRAMEWORK_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/CodeFramework/*.hpp")
file(GLOB_RECURSE FRAMEWORK_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Criar a biblioteca estática
add_library(CodeFramework STATIC ${FRAMEWORK_SOURCES})

# Configurar os diretórios de inclusão
target_include_directories(CodeFramework
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # Durante a construção
        $<INSTALL_INTERFACE:include>                          # Após instalação
)

# Vincular a dependência SDL2
target_link_libraries(CodeFramework PUBLIC SDL2::SDL2-static)

# Criar um alias para facilitar importação
add_library(CodeFramework::CodeFramework ALIAS CodeFramework)

# Configurar instalação da biblioteca
install(
    TARGETS CodeFramework
    EXPORT CodeFrameworkTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Instalar os arquivos de cabeçalho
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/CodeFramework
    DESTINATION include/CodeFramework
)

# Instalar SDL2
install(
    TARGETS SDL2-static
    EXPORT SDL2Targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(
    EXPORT SDL2Targets
    FILE SDL2Targets.cmake
    NAMESPACE SDL2::
    DESTINATION lib/cmake/SDL2
)

# Exportar os targets para uso em outros projetos
install(
    EXPORT CodeFrameworkTargets
    FILE CodeFrameworkTargets.cmake
    NAMESPACE CodeFramework::
    DESTINATION lib/cmake/CodeFramework
)
