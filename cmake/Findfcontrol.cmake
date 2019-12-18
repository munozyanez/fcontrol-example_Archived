# - Try to find library installed at system
# Once done this will define
#  FCONTROL_FOUND - System has the library
#  FCONTROL_INCLUDE_DIRS - The include directories
#  FCONTROL_LIBRARIES - The link directions

#Default location is /usr/local
set(LOCATION /usr/local)
set(NAME fcontrol)

message(STATUS "Looking for ${NAME} in: [${LOCATION}].")

find_path(FCONTROL_INCLUDE_DIR fcontrol.h
    PATHS "${LOCATION}/include/${NAME}/"
    HINTS ${LOCATION}
    PATH_SUFFIXES ${NAME} )

find_library(FCONTROL_LIBRARY NAMES ${NAME} lib${NAME}
    PATHS "${LOCATION}/lib/${NAME}/")

if(${FCONTROL_LIBRARY} STREQUAL "FCONTROL_LIBRARY-NOTFOUND")
    message(STATUS "${NAME} not installed.")
else()
    message(STATUS "${NAME} library found...")
    #deps
    #1-fftw
    #find_package(FFTW REQUIRED)
    #2-eigen
    find_package(Eigen3 REQUIRED NO_MODULE)
    #message(STATUS "EIGEN: " ${EIGEN3_VERSION} " (system installed version)")
    #include_directories(${EIGEN3_INCLUDE_DIR})
    set (FCONTROL_FOUND TRUE)
    message(STATUS "Local ${NAME} files detected: [${FCONTROL_LIBRARY}].")
    message(STATUS "Local include directories: [${FCONTROL_INCLUDE_DIR}].")
    set(FCONTROL_LIBRARIES ${FCONTROL_LIBRARY} )
    set(FCONTROL_INCLUDE_DIRS ${FCONTROL_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR})

    set(SUBDIR_INCLUDE_DIRECTORIES ${SUBDIR_INCLUDE_DIRECTORIES} ${FCONTROL_INCLUDE_DIRS})
    set(SUBDIR_LINK_NAMES ${SUBDIR_LINK_NAMES} ${FCONTROL_LIBRARIES})


endif()




#mark_as_advanced(FCONTROL_INCLUDE_DIR FCONTROL_LIBRARY )
