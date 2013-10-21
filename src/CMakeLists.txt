
configure_file (
	"NontetrisConfig.h.in"
	"${PROJECT_BINARY_DIR}/NontetrisConfig.h"
	)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/srclib/Box2D/")
if(NOT DEFINED DUETTO)
include_directories("${PROJECT_SOURCE_DIR}/srclib/lodepng/")
endif(NOT DEFINED DUETTO)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(MY_SOURCES nontetris.cpp physichandler.cpp inputhandler.cpp graphichandler.cpp inputhandler.cpp)

if(DEFINED DUETTO)
	set (MY_SOURCES ${MY_SOURCES} duettogl.cpp)
	add_library (nontetris ${MY_SOURCES})
else(DEFINED DUETTO)
	add_executable (nontetris ${MY_SOURCES})
endif(DEFINED DUETTO)

target_link_libraries(nontetris Box2D)

if(NOT DEFINED DUETTO)
	target_link_libraries(nontetris ${OPENGL_LIBRARIES} lodepng)

	if(NOT DEFINED EMSCRIPTEN)
		target_link_libraries(nontetris ${GLEW_LIBRARIES})
	endif(NOT DEFINED EMSCRIPTEN)

	if(USE_GLFW_3)
		target_link_libraries(nontetris ${GLFW_STATIC_LIBRARIES})
	else(USE_GLFW_3)
		target_link_libraries(nontetris ${GLFW_LIBRARIES})
	endif(USE_GLFW_3)
endif(NOT DEFINED DUETTO)