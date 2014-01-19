# Copyright (C) 2011-2014 EMPulseGaming.LLC <http://www.empulsegaming.com/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if( USE_COREPCH )
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

file(GLOB_RECURSE sources_game game/*.cpp game/*.h)

source_group(CMake FILES CMakeLists.txt)
source_group(game FILES ${sources_game})

# Create game-library

if( USE_GAMEPCH AND MSVC )
  set(game_STAT_SRCS
    PrecompiledHeaders/gamePCH.cpp
    PrecompiledHeaders/gamePCH.h
  )
endif()
SET(game_STAT_SRCS
	Dope.cpp                                                                                                                                           
	Dope.h
	main.cpp
    )

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(game STATIC ${game_STAT_SRCS})

add_dependencies(game revision.h)

# Generate pre-compiled header
if( USE_COREPCH )
  if(CMAKE_COMPILER_IS_GNUCXX)
    add_precompiled_header(game ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/gamePCH.h)
  elseif(MSVC)
    add_native_precompiled_header(game ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders/gamePCH)
  endif()
endif()
