# avoid updating flags multiple times
if(DEFINED __ABB_LIBEGM_EXTRAS_INCLUDED)
  return()
endif()
set(__ABB_LIBEGM_EXTRAS_INCLUDED TRUE)

# we export the dependency on pthread here. Protobuf exports it as a library
# via its PROTOBUF_LIBRARIES, but that trips Catkin up when it tries to
# evaluate that variable as part of the call to catkin_package( .. DEPENDS ..)
list(APPEND CMAKE_CXX_FLAGS -pthread)
