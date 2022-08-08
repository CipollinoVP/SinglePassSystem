cmake_minimum_required(VERSION 3.3)
project(SinglePassSystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")


set(SOURCE_FILES main.cpp LoginApp.h main_settings.h SinglePassApp.h OrderPassApp.h MessengerApp.h)
add_executable(SinglePassSystem ${SOURCE_FILES})

find_package(PostgreSQL REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

set(CMAKE_EXE_LINKER_FLAGS "-Wl,-export-dynamic")

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(SinglePassSystem PRIVATE ${PostgreSQL_LIBRARIES} ${GTK3_LIBRARIES})

target_include_directories(SinglePassSystem PRIVATE ${PostgreSQL_INCLUDE_DIRS})
