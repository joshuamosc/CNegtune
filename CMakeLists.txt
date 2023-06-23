cmake_minimum_required(VERSION 3.25)
project(CNegtune)

set(CMAKE_CXX_STANDARD 17)

add_executable(CNegtune main.cpp headers/CNegtuneDirectives.h features/files.cpp headers/files.h features/crossPlatformsFunctionalities.cpp headers/crossPlatformsFunctionalities.h features/menu.cpp headers/menu.h)
