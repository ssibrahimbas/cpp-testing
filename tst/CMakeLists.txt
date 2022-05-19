set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES main.cpp classes/UserTests.cpp classes/NumberTests.cpp classes/GameEngineTests.cpp classes/TableTests.cpp classes/FsHelperTests.cpp classes/PrinterTests.cpp)

add_executable(${BINARY} ${TEST_SOURCES})
add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)