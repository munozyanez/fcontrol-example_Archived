project(fcontrol-example)

cmake_minimum_required(VERSION 2.8)
aux_source_directory(./src SRC_LIST)


#fcontrol library
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/fcontrol)
set(FCONTROL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/fcontrol ${FCONTROL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${FCONTROL_INCLUDE_DIR})




add_executable(${PROJECT_NAME} ${SRC_LIST})

#link with libs
target_link_libraries( ${PROJECT_NAME} fcontrol)