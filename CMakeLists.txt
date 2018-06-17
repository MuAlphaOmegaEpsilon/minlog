###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.9.5)




###############################################################################
#                                  PROJECT                                    #
###############################################################################
PROJECT (MinLog LANGUAGES CXX VERSION 1.0.0 DESCRIPTION "A Minimalist Logger for C++")




###############################################################################
#                                  LIBRARY                                    #
###############################################################################
ADD_LIBRARY (MinLog INTERFACE)




###############################################################################
#                               HEADERS INCLUSION                             #
###############################################################################
TARGET_INCLUDE_DIRECTORIES (MinLog INTERFACE "${PROJECT_SOURCE_DIR}/include")




###############################################################################
#                                    TESTS                                    #
###############################################################################
IF (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)							# This is true when someone is building the MinLog standalone
	SET (COMPILER "${COMPILER} -Wall -Wextra -Werror -pedantic")				# Enable all warnings

	IF (${BUILD_TESTING})
		ADD_EXECUTABLE (MinLogTest "${PROJECT_SOURCE_DIR}/tests/main.cpp")
		TARGET_LINK_LIBRARIES (MinLogTest PRIVATE MinLog)
	ELSE ()
		MESSAGE (STATUS "Remember that you can build the examples in the tests/ folder by adding the -DBUILD_TESTING=ON to CMake.")
	ENDIF ()
	
ENDIF ()
