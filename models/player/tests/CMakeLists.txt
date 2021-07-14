add_executable(PlayerModelTest player_test.cpp test_runner.cpp)

find_package(GTest REQUIRED)

target_link_libraries(PlayerModelTest PRIVATE GTest::GTest jd::PlayerModel)
add_test(NAME PlayerModelTest
        COMMAND PlayerModelTest
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

add_custom_command(
        TARGET PlayerModelTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_LIST_DIR}/resource
                ${CMAKE_CURRENT_BINARY_DIR}/resource)
        
add_custom_target(PlayerModelTest_Run ALL DEPENDS PlayerModelTest WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR} COMMAND PlayerModelTest)


