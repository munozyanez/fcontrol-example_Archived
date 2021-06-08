cmake_minimum_required(VERSION 3.0)

# Find cmake modules - they all must be in the cmake subdirectory
# let cmake use them
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)

#old simple way
add_subdirectory(i-plot)
add_subdirectory(clconv)

find_package(fcontrol)
if(FCONTROL_LIBRARY)
    message(STATUS "Using system fcontrol library found.")
    set(SUBDIR_INCLUDE_DIRECTORIES ${SUBDIR_INCLUDE_DIRECTORIES} ${FCONTROL_INCLUDE_DIRS})
    set(SUBDIR_LINK_NAMES ${SUBDIR_LINK_NAMES} ${FCONTROL_LIBRARIES})
else()
    message(STATUS "System installed fcontrol not found. Compiling from source")
    add_subdirectory(fcontrol)
endif()



#new automated way
#[[MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()
#get list
SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
#add every subdir
FOREACH(subdir ${SUBDIRS})
    find_package(${subdir} QUIET)
     message(STATUS ${${subdir}_LIBRARY})
    if(${subdir}_LIBRARY STREQUAL "${subdir}_LIBRARY_FOUND")
        message(STATUS "System installed ${subdir} not found. Compiling from source")
        ADD_SUBDIRECTORY(${subdir})
    else()
        message(STATUS "Using system ${subdir} library found.")
    endif()
ENDFOREACH()]]



set(SUBDIR_INCLUDE_DIRECTORIES ${SUBDIR_INCLUDE_DIRECTORIES}
    PARENT_SCOPE)
set(SUBDIR_LINK_NAMES ${SUBDIR_LINK_NAMES}
    PARENT_SCOPE)
