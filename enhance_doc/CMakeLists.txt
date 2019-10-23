cmake_minimum_required(VERSION 3.10)

project(enhance_doc)

# Conan
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.14/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
include(GenerateExportHeader)

conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP
                BUILD missing)

set(${PROJECT_NAME}_SOURCES ${PROJECT_SOURCE_DIR}/src/enhance_doc.cpp)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SOURCES})
generate_export_header(${PROJECT_NAME} 
                       EXPORT_FILE_NAME ${CMAKE_CURRENT_LIST_DIR}/include/enhance_doc/${PROJECT_NAME}_export.h)

message(STATUS ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC ${CONAN_LIBS})