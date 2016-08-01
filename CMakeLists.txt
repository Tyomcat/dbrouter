if(PACKAGE)
	cmake_minimum_required(VERSION 2.8.12)
else()
	cmake_minimum_required(VERSION 2.8)
endif()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
# Read BuildPCRE2 for details about how to add pcre2 as a dependency to a target 
find_package(PCRE2) 
if(NOT PCRE2_FOUND)
	message(STATUS "Using bundled PCRE2 library") 
	include(ExternalProject)

	ExternalProject_Add(pcre2 SOURCE_DIR ${CMAKE_SOURCE_DIR}/pcre2/
	CMAKE_ARGS -DCMAKE_C_FLAGS=-fPIC -DBUILD_SHARED_LIBS=N -DPCRE2_BUILD_PCRE2GREP=N  -DPCRE2_BUILD_TESTS=N
	BINARY_DIR ${CMAKE_BINARY_DIR}/pcre2/
	BUILD_COMMAND make
	INSTALL_COMMAND "")

	set(PCRE2_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/pcre2/ CACHE PATH "PCRE2 headers" FORCE)
	set(PCRE2_LIBRARIES ${CMAKE_BINARY_DIR}/pcre2/libpcre2-8.a CACHE PATH "PCRE2 libraries" FORCE)
	set(PCRE2_FOUND TRUE CACHE BOOL "Found PCRE2 libraries" FORCE)
endif()
include_directories(${PCRE2_INCLUDE_DIRS}) 

find_package(FLEX) 
find_package(BISON)
if(BISON_FOUND AND FLEX_FOUND)
	BISON_TARGET(
		ruleparser 
		src/ruleparser.y 
		${CMAKE_CURRENT_BINARY_DIR}/ruleparser.c
		COMPILE_FLAGS "--defines=${CMAKE_CURRENT_BINARY_DIR}/ruleparser.yy.h"
	)
	FLEX_TARGET(
		token 
		src/token.l 
		${CMAKE_CURRENT_BINARY_DIR}/token.c 
		COMPILE_FLAGS "--header-file=${CMAKE_CURRENT_BINARY_DIR}/lex.yy.h"
	)
	
	ADD_FLEX_BISON_DEPENDENCY(
		token
		ruleparser
	)

	INCLUDE_DIRECTORIES(
		include
		src
                ${CMAKE_CURRENT_BINARY_DIR}
	)

#        FIND_LIBRARY(PCRE2_LIB libpcre2-8.a ${CMAKE_BINARY_DIR}/pcre2/)
	LINK_LIBRARIES(
		dbwallfilter
		${CMAKE_BINARY_DIR}/pcre2/libpcre2-8.a
	)
	ADD_DEFINITIONS(
		-W -Wall
		-D_LINUX
		-D_REENTRANT
		-DSQLITE_ASCII
		-D__STDC_FORMAT_MACROS
	)

	ADD_LIBRARY(
		dbwallfilter 
		STATIC 
		src/dbwallfilter.c 
		${BISON_ruleparser_OUTPUTS}
		${FLEX_token_OUTPUTS}
		src/spinlock.c
		src/atomic.c
		src/hashtable.c
	)

	if(BUILD_TOOLS) 
		ADD_EXECUTABLE(
		dbwallruleparser 
		src/dbfwfilter.c 
		${BISON_ruleparser_OUTPUTS}
		${FLEX_token_OUTPUTS}
		src/spinlock.c
		src/atomic.c
		src/hashtable.c
		FIND_LIBRARY(PCRE2_LIB libpcre2-8.a ../pcre2)
		LINK_LIBRARIES(
			dbwallfilter
			${CMAKE_BINARY_DIR}/pcre2/libpcre2-8.a
		)
	)
	endif() 
else()
	message(FATAL_ERROR "Could not find Bison or Flex: ${BISON_EXECUTABLE} ${FLEX_EXECUTABLE}") 
endif()

