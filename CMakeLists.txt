cmake_minimum_required(VERSION 3.22)

project(qtTest VERSION 1.0 LANGUAGES CXX)

# ## Require out-of-source builds
if("${CMAKE_BINARY_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  message(FATAL_ERROR "In-source builds illegal. Please make build directory out-of-source. ${CMAKE_BINARY_DIR}  ${CMAKE_SOURCE_DIR}")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

set(Qt6_DIR "/home/ryan/Qt/6.6.0/gcc_64/lib/cmake/Qt6")

find_package(Qt6 6.6
  REQUIRED
  COMPONENTS
  Core
  Qml
  Quick
  QuickControls2
  QuickLayouts
  QuickTemplates2
  Multimedia
)

qt_policy(SET QTP0001 NEW)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(src)