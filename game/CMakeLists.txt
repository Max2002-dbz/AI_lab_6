add_library(game game.cpp game.ui)

#target_link_libraries(game)

target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})