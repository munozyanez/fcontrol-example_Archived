project(fcontrol-example)

cmake_minimum_required(VERSION 2.8)
aux_source_directory(./src SRC_LIST)


#fcontrol library
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/fcontrol)
set(FCONTROL_LIBRARIES ${FCONTROL_LIBRARY} )
set(FCONTROL_INCLUDE_DIRS ${FCONTROL_INCLUDE_DIR} )
INCLUDE_DIRECTORIES(${FCONTROL_INCLUDE_DIRS})



add_executable(${PROJECT_NAME} ${SRC_LIST})

#link with libs
target_link_libraries( ${PROJECT_NAME} fcontrol)


##functions
function(echo_all_cmake_variable_values)
  message(STATUS "")
  get_cmake_property(vs VARIABLES)
  foreach(v ${vs})
    message(STATUS "${v}='${${v}}'")
  endforeach(v)
  message(STATUS "")
endfunction()


#echo_all_cmake_variable_values()
