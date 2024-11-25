cmake_minimum_required(VERSION 3.14)

# Nome da framework
project(CodeFramework VERSION 1.0 LANGUAGES CXX)

# Habilitar FetchContent para baixar o SDL automaticamente
include(FetchContent)

# Declarar o SDL2 como dependência
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL
  GIT_TAG release-2.30.9
)

# Baixar e tornar disponível o SDL2
FetchContent_MakeAvailable(SDL2)

# Configurar os arquivos fonte e cabeçalhos da framework
file(GLOB_RECURSE FRAMEWORK_HEADERS "include/MyFramework/*.hpp")
file(GLOB_RECURSE FRAMEWORK_SOURCES "src/*.cpp")

# Criar a biblioteca estática
add_library(CodeFramework STATIC ${FRAMEWORK_HEADERS} ${FRAMEWORK_SOURCES})

# Configurar os diretórios de inclusão
target_include_directories(CodeFramework
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${SDL2_SOURCE_DIR}/include  # Incluir cabeçalhos do SDL
)

# Vincular o SDL à framework
target_link_libraries(CodeFramework PUBLIC SDL2::SDL2-static)

# Configurar as opções de compilação
target_compile_features(CodeFramework PUBLIC cxx_std_17)

# Instalar a framework (opcional)
install(TARGETS CodeFramework
    EXPORT CodeFrameworkTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)
