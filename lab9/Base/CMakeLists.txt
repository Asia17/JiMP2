
project(base)

set(HEDEAR_FILES Base.h)
set(SOURCE_FILES Base.cpp)

add_library(libbase STATIC ${SOURCE_FILES})
target_include_directories(libbase PUBLIC .)

add_executable(base ${SOURCE_FILES} main.cpp)

target_link_libraries(base libbase)
