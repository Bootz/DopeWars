# Copyright (C) 2011-2014 EMPulseGaming.LLC <http://www.empulsegaming.com/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# output generic information about the core and build-type chosen
message("")
message("* DopeWars revision   : ${rev_hash} ${rev_date} (${rev_branch} branch)")
if( UNIX )
  message("* DopeWars buildtype  : ${CMAKE_BUILD_TYPE}")
endif()
message("")

# output information about installation-directories and locations

message("* Install world to             : ${CMAKE_INSTALL_PREFIX}")
if( UNIX )
  message("* Install any libraries to   : ${LIBSDIR}")
  message("* Install any configs to     : ${CONF_DIR}")
endif()
message("")

# Show information about the options selected during configuration

if( SERVERS )
  message("* Build world       : Yes (default)")
else()
  message("* Build world       : No")
endif()

if( WITH_WARNINGS )
  message("* Show all warnings      : Yes")
else()
  message("* Show compile-warnings  : No  (default)")
endif()

if( WITH_COREDEBUG )
  message("* Use coreside debug     : Yes")
  add_definitions(-DSKYFIRE_DEBUG)
else()
  message("* Use coreside debug     : No  (default)")
endif()

if ( WITHOUT_GIT )
  message("* Use GIT revision hash  : No")
  message("")
  message(" *** WITHOUT_GIT - WARNING!")
  message(" *** By choosing the WITHOUT_GIT option you have waived all rights for support,")
  message(" *** and accept that or all requests for support or assistance sent to the core")
  message(" *** developers will be rejected. This due to that we will be unable to detect")
  message(" *** what revision of the codebase you are using in a proper way.")
  message(" *** We remind you that you need to use the repository codebase and a supported")
  message(" *** version of git for the revision-hash to work, and be allowede to ask for")
  message(" *** support if needed.")
else()
  message("* Use GIT revision hash  : Yes")
endif()

if ( NOJEM )
  message("")
  message(" *** NOJEM - WARNING!")
  message(" *** jemalloc linking has been disabled!")
  message(" *** Please note that this is for DEBUGGING WITH VALGRIND only!")
  message(" *** DO NOT DISABLE IT UNLESS YOU KNOW WHAT YOU'RE DOING!")
endif()

message("")

