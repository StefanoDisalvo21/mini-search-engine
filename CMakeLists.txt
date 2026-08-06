cmake_minimum_required(VERSION 3.14)
project(MiniSearchEngine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

list(APPEND CMAKE_PREFIX_PATH
    /opt/homebrew/opt/icu4c   # Apple Silicon Homebrew
    /usr/local/opt/icu4c      # Intel Mac Homebrew
)
find_package(ICU REQUIRED COMPONENTS uc i18n data)
set(ICU_LIBS ICU::uc ICU::i18n ICU::data)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(src)
add_subdirectory(tests)
