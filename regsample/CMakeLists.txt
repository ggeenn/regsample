project(regsample DESCRIPTION "regsample.")

add_executable(${PROJECT_NAME} regsample.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE common)

#add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE:${PROJECT_NAME}>)
