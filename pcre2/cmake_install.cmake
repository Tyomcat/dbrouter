# Install script for directory: /root/MaxScale-develop/pcre2

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/root/MaxScale-develop/pcre2/libpcre2-8.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/root/MaxScale-develop/pcre2/libpcre2posix.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2grep" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2grep")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2grep"
         RPATH "")
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/MaxScale-develop/pcre2/pcre2grep")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2grep" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2grep")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2grep")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2test" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2test")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2test"
         RPATH "")
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/root/MaxScale-develop/pcre2/pcre2test")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2test" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2test")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcre2test")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/root/MaxScale-develop/pcre2/pcre2.h"
    "/root/MaxScale-develop/pcre2/src/pcre2posix.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/man/man1" TYPE FILE FILES
    "/root/MaxScale-develop/pcre2/doc/pcre2-config.1"
    "/root/MaxScale-develop/pcre2/doc/pcre2grep.1"
    "/root/MaxScale-develop/pcre2/doc/pcre2test.1"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/man/man3" TYPE FILE FILES
    "/root/MaxScale-develop/pcre2/doc/pcre2.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_callout_enumerate.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_code_free.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_compile.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_compile_context_copy.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_compile_context_create.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_compile_context_free.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_config.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_dfa_match.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_general_context_copy.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_general_context_create.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_general_context_free.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_get_error_message.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_get_mark.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_get_ovector_count.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_get_ovector_pointer.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_get_startchar.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_jit_compile.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_jit_free_unused_memory.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_jit_match.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_jit_stack_assign.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_jit_stack_create.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_jit_stack_free.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_maketables.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_match.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_match_context_copy.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_match_context_create.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_match_context_free.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_match_data_create.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_match_data_create_from_pattern.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_match_data_free.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_pattern_info.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_serialize_decode.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_serialize_encode.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_serialize_free.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_serialize_get_number_of_codes.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_set_bsr.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_set_callout.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_set_character_tables.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_set_compile_recursion_guard.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_set_match_limit.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_set_newline.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_set_parens_nest_limit.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_set_recursion_limit.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_set_recursion_memory_management.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substitute.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_copy_byname.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_copy_bynumber.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_free.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_get_byname.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_get_bynumber.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_length_byname.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_length_bynumber.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_list_free.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_list_get.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_nametable_scan.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2_substring_number_from_name.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2api.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2build.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2callout.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2compat.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2demo.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2jit.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2limits.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2matching.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2partial.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2pattern.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2perform.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2posix.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2sample.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2serialize.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2stack.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2syntax.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2unicode.3"
    "/root/MaxScale-develop/pcre2/doc/pcre2unicode.3"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/pcre2/html" TYPE FILE FILES
    "/root/MaxScale-develop/pcre2/doc/html/index.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2-config.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_callout_enumerate.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_code_free.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_compile.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_compile_context_copy.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_compile_context_create.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_compile_context_free.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_config.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_dfa_match.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_general_context_copy.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_general_context_create.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_general_context_free.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_get_error_message.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_get_mark.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_get_ovector_count.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_get_ovector_pointer.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_get_startchar.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_jit_compile.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_jit_free_unused_memory.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_jit_match.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_jit_stack_assign.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_jit_stack_create.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_jit_stack_free.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_maketables.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_match.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_match_context_copy.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_match_context_create.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_match_context_free.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_match_data_create.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_match_data_create_from_pattern.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_match_data_free.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_pattern_info.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_serialize_decode.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_serialize_encode.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_serialize_free.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_serialize_get_number_of_codes.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_set_bsr.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_set_callout.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_set_character_tables.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_set_compile_recursion_guard.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_set_match_limit.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_set_newline.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_set_parens_nest_limit.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_set_recursion_limit.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_set_recursion_memory_management.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substitute.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_copy_byname.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_copy_bynumber.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_free.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_get_byname.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_get_bynumber.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_length_byname.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_length_bynumber.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_list_free.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_list_get.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_nametable_scan.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2_substring_number_from_name.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2api.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2build.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2callout.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2compat.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2demo.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2grep.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2jit.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2limits.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2matching.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2partial.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2pattern.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2perform.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2posix.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2sample.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2serialize.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2stack.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2syntax.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2test.html"
    "/root/MaxScale-develop/pcre2/doc/html/pcre2unicode.html"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/root/MaxScale-develop/pcre2/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/root/MaxScale-develop/pcre2/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
