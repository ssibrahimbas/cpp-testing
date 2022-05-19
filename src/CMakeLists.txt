set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

add_executable(src main.cpp internal/user/user.cpp internal/user/user.h internal/fs/fsHelper.cpp internal/fs/fsHelper.h internal/engine/GameEngine.cpp internal/engine/GameEngine.h internal/table/Table.cpp internal/table/Table.h internal/number/Number.cpp internal/number/Number.h internal/printer/IPrinter.h internal/printer/IPrinter.cpp)
add_library(${BINARY}_lib STATIC ${SOURCES})