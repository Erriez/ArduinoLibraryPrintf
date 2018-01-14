cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)

set(PROJECT_NAME ArduinoLibraryPrintf)
project(${PROJECT_NAME})

set(${CMAKE_PROJECT_NAME}_SKETCH examples/Example/Example.ino)

# Configure board, default Arduino UNO
set(${CMAKE_PROJECT_NAME}_BOARD uno)

# Configure serial port for Windows
set(${CMAKE_PROJECT_NAME}_PORT COM1)
# Or configure serial port for Linux
#set(${CMAKE_PROJECT_NAME}_PORT /dev/ttyUSB0)

include_directories(src)

generate_arduino_firmware(${CMAKE_PROJECT_NAME})
