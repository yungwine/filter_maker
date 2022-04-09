cmake_minimum_required(VERSION 3.16)
project(project)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address"
		CACHE STRING "Compiler flags in asan build"
		FORCE)

set(CMAKE_CXX_FLAGS_UBSAN "-g -fsanitize=undefined"
		CACHE STRING "Compiler flags in ubsan build"
		FORCE)

add_executable(project
        main.cpp
        command_line_parser.cpp
        command_line_parser.h
        base_filter.cpp
        base_filter.h
        filter_pipeline_maker.cpp
        filter_pipeline_maker.h
        application.cpp
        application.h
        bitmap.cpp 
		bitmap.h
        test.h)
