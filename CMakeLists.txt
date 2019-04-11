cmake_minimum_required(VERSION 2.8.12)
project(abb_libegm)

find_package(catkin REQUIRED)

find_package(Boost REQUIRED COMPONENTS system thread)

#############################
## Google Protocol Buffers ##
#############################
find_package(Protobuf REQUIRED)

# work around Protobuf exporting 'lpthread' as a library: we
# export the dependency on pthread using the CFG_EXTRAS files
list (REMOVE_ITEM PROTOBUF_LIBRARIES "-lpthread")

# Make sure protoc is present, as apparently the above find_package() doesn't check that.
find_program(Protobuf_PROTOC_LOC NAMES protoc)
if (NOT Protobuf_PROTOC_LOC)
  message(FATAL_ERROR "Cannot find required 'protoc', cannot process Protobuf files without it. Aborting.")
endif()

# Generate C++ for protocol classes (headers and sources get written to the CMAKE_CURRENT_BINARY_DIR location).
set(EgmProtoFiles proto/egm.proto proto/egm_wrapper.proto proto/egm_wrapper_trajectory.proto)
if (NOT QUIET)
  message(STATUS "Generating protobuf C++ for: ${EgmProtoFiles}")
endif()
protobuf_generate_cpp(EgmProtoSources EgmProtoHeaders ${EgmProtoFiles})

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS
    include
  LIBRARIES
    ${PROJECT_NAME}
  CFG_EXTRAS
    # this exports pthread dependency for us
    abb_libegm-extras.cmake
  DEPENDS
    Boost
    PROTOBUF
)

###########
## Build ##
###########
set(SRC_FILES
    src/egm_base_interface.cpp
    src/egm_common.cpp
    src/egm_common_auxiliary.cpp
    src/egm_controller_interface.cpp
    src/egm_interpolator.cpp
    src/egm_logger.cpp
    src/egm_udp_server.cpp
    src/egm_trajectory_interface.cpp
    ${EgmProtoSources})

include_directories(include
                    ${CMAKE_CURRENT_BINARY_DIR} # Contains protobuf generated sources
                    ${Boost_INCLUDE_DIRS}
                    ${PROTOBUF_INCLUDE_DIRS}
                    ${catkin_INCLUDE_DIRS})

add_library(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${PROTOBUF_LIBRARIES} ${catkin_LIBRARIES})

#############
## Install ##
#############
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})

install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        FILES_MATCHING PATTERN "*.h")

install(FILES ${EgmProtoHeaders}
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})

install(FILES ${EgmProtoFiles}
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
