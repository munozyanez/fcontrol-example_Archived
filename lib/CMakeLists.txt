
add_subdirectory(plot)

#fcontrol library
add_subdirectory(fcontrol)

set(SUBDIR_INCLUDE_DIRECTORIES ${SUBDIR_INCLUDE_DIRECTORIES}
    PARENT_SCOPE)
set(SUBDIR_LINK_NAMES ${SUBDIR_LINK_NAMES}
    PARENT_SCOPE)
