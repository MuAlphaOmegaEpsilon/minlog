###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.9.2)




###############################################################################
#                                  PROJECT                                    #
###############################################################################
PROJECT (minlog 
		VERSION 1.0.0 
		LANGUAGES CXX 
		DESCRIPTION "A Minimalist Logger for C++")




###############################################################################
#                                  LIBRARY                                    #
###############################################################################
ADD_LIBRARY (minlog INTERFACE)




###############################################################################
#                                  HEADERS                                    #
###############################################################################
TARGET_INCLUDE_DIRECTORIES (minlog INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})	




###############################################################################
#                                  SOURCES                                    #
###############################################################################
#TARGET_SOURCES (minlog INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src/minlog.cpp)	




###############################################################################
#                                DEPENDENCIES                                 #
###############################################################################
ADD_SUBDIRECTORY (libs/buildmode)	
TARGET_LINK_LIBRARIES (minlog INTERFACE buildmode)




###############################################################################
#                                    TESTS                                    #
###############################################################################
ADD_EXECUTABLE (main "${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp")
TARGET_LINK_LIBRARIES (main minlog)
TARGET_COMPILE_OPTIONS (main PRIVATE -std=c++17 -Wall -Wextra -pedantic -fverbose-asm -save-temps -O2)
IF (BUILD_TESTING)
	ENABLE_TESTING()
	ADD_EXECUTABLE (main "${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp")
	TARGET_LINK_LIBRARIES (main minlog)
	TARGET_COMPILE_OPTIONS (main PRIVATE -std=c++17 -Wall -Wextra -Werror -pedantic)
	ADD_TEST (TEST main)
# 	ADD_EXECUTABLE (isDebug "${CMAKE_CURRENT_SOURCE_DIR}/tests/debug_mode.cpp")

# 	TARGET_LINK_LIBRARIES (isDebug buildmode ${COVERAGE_FLAG})
	
# 	IF (MSVC)
# 		TARGET_COMPILE_OPTIONS (isRelease PRIVATE /std:c++17 /DNDEBUG)
# 	ELSE ()
# 		TARGET_COMPILE_OPTIONS (isRelease PRIVATE -std=c++17 -DNDEBUG -O3 -Wall -Wextra -Werror -pedantic ${COVERAGE_FLAG})
# 	ENDIF ()


# 	ADD_TEST (constexpr_bool_isRelease isRelease)
ENDIF ()