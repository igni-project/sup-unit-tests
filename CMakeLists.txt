cmake_minimum_required(VERSION 3.15...4.0)

project(
	sup-unit-tests
	VERSION 0.1
	LANGUAGES C
)

add_executable(
	sup-unit-tests
	src/main.c
)

find_library(LIBSUP sup)

target_link_libraries(sup-unit-tests ${LIBSUP})

install(TARGETS sup-unit-tests)
include(CPack)

