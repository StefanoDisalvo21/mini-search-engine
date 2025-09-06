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

set(ICU_ROOT "/opt/homebrew/opt/icu4c")         
set(ICU_INCLUDE_DIR "${ICU_ROOT}/include")
set(ICU_LIBRARY_DIR "${ICU_ROOT}/lib")

include_directories(${ICU_INCLUDE_DIR})


set(ICU_LIBS
    ${ICU_LIBRARY_DIR}/libicuuc.dylib
    ${ICU_LIBRARY_DIR}/libicui18n.dylib
    ${ICU_LIBRARY_DIR}/libicudata.dylib
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(src)
add_subdirectory(tests)
