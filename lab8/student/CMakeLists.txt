
project(studentexception)

set(HEDEAR_FILES StudentException.h)
set(SOURCE_FILES StudentException.cpp)

add_library(libstudentexception STATIC ${SOURCE_FILES})
target_include_directories(libstudentexception PUBLIC .)

add_executable(studentexception ${SOURCE_FILES} main.cpp)

target_link_libraries(studentexception libstudentexception)
