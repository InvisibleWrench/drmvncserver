PROJECT(drm-vncserver)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(EXTRA_FLAGS "-I/usr/include/drm")

FILE(GLOB SOURCES src/*.c)
ADD_EXECUTABLE(drm-vncserver ${SOURCES})


find_package(PkgConfig)
pkg_check_modules(DRM REQUIRED libdrm)

if(NOT DRM_FOUND)
	message(FATAL_ERROR "libdrm(-dev) not found")
	return()
endif()

# LIBVNC
find_library(LIBVNC NAMES libvncserver vncserver libdrm)

target_include_directories(drm-vncserver PRIVATE ${DRM_INCLUDE_DIRS})
target_link_libraries(drm-vncserver ${DRM_LDFLAGS} ${DRM_LIBRARIES} ${LIBVNC})
target_compile_options(drm-vncserver PRIVATE ${DRM_CFLAGS})

INSTALL(TARGETS drm-vncserver RUNTIME DESTINATION bin)