#
# Try to find NVIDIA's Cg compiler, runtime libraries, and include path.
# Once done this will define
#
# CG_FOUND =system has NVIDIA Cg and it can be used. 
# CG_INCLUDE_PATH = directory where cg.h resides
# CG_LIBRARY = full path to libCg.so (Cg.DLL on win32)
# CG_GL_LIBRARY = full path to libCgGL.so (CgGL.dll on win32)
# CG_COMPILER = full path to cgc (cgc.exe on win32)
# 

# On OSX default to using the framework version of Cg.

IF (APPLE)
  INCLUDE(${CMAKE_ROOT}/Modules/CMakeFindFrameworks.cmake)
  SET(CG_FRAMEWORK_INCLUDES)
  CMAKE_FIND_FRAMEWORKS(Cg)
  IF (Cg_FRAMEWORKS)
    FOREACH(dir ${Cg_FRAMEWORKS})
      SET(CG_FRAMEWORK_INCLUDES ${CG_FRAMEWORK_INCLUDES}
        ${dir}/Headers ${dir}/PrivateHeaders)
    ENDFOREACH(dir)

    # Find the include  dir
    FIND_PATH(CG_INCLUDE_PATH cg.h
      ${CG_FRAMEWORK_INCLUDES}
      )

    # Since we are using Cg framework, we must link to it.
	# Note, we use weak linking, so that it works even when Cg is not available.
    SET(CG_LIBRARY "-weak_framework Cg" CACHE STRING "Cg library")
    SET(CG_GL_LIBRARY "-weak_framework Cg" CACHE STRING "Cg GL library")
  ENDIF (Cg_FRAMEWORKS)
  FIND_PROGRAM(CG_COMPILER cgc
    /usr/bin
    /usr/local/bin
    DOC "The Cg compiler"
    )
ELSE (APPLE)
  IF (WIN32)
		IF (CMAKE_SIZEOF_VOID_P EQUAL 8)
						FIND_PROGRAM( CG_COMPILER cgc
							$ENV{CG_BIN64_PATH}
							$ENV{PROGRAMFILES}/Cg
							${PROJECT_SOURCE_DIR}/../Cg
							DOC "The Cg Compiler"
							)
		ELSE()
						FIND_PROGRAM( CG_COMPILER cgc
							$ENV{CG_BIN_PATH}
							$ENV{PROGRAMFILES}/Cg
							${PROJECT_SOURCE_DIR}/../Cg
							DOC "The Cg Compiler"
							)
		ENDIF()
    IF (CG_COMPILER)
      GET_FILENAME_COMPONENT(CG_COMPILER_DIR ${CG_COMPILER} PATH)
      GET_FILENAME_COMPONENT(CG_COMPILER_SUPER_DIR ${CG_COMPILER_DIR} PATH)
    ELSE (CG_COMPILER)
      SET (CG_COMPILER_DIR .)
      SET (CG_COMPILER_SUPER_DIR ..)
    ENDIF (CG_COMPILER)
    FIND_PATH( CG_INCLUDE_PATH Cg/cg.h
      $ENV{CG_INC_PATH}
      $ENV{PROGRAMFILES}/NVIDIA\ Corporation/Cg/include
      $ENV{PROGRAMFILES}/Cg
      ${PROJECT_SOURCE_DIR}/../Cg
      ${CG_COMPILER_SUPER_DIR}/include
      ${CG_COMPILER_DIR}
      DOC "The directory where Cg/cg.h resides"
      )
		IF (CMAKE_SIZEOF_VOID_P EQUAL 8)
						FIND_LIBRARY( CG_LIBRARY
							NAMES Cg
							PATHS
							$ENV{CG_LIB64_PATH}
							$ENV{PROGRAMFILES}/Cg
							${PROJECT_SOURCE_DIR}/../Cg
							${CG_COMPILER_SUPER_DIR}/lib
							${CG_COMPILER_DIR}
							DOC "The Cg runtime library"
							)
						FIND_LIBRARY( CG_GL_LIBRARY
							NAMES CgGL
							PATHS
							$ENV{CG_LIB64_PATH}
							$ENV{PROGRAMFILES}/Cg
							${PROJECT_SOURCE_DIR}/../Cg
							${CG_COMPILER_SUPER_DIR}/lib
							${CG_COMPILER_DIR}
							DOC "The Cg runtime library"
							)
		ELSE()
						FIND_LIBRARY( CG_LIBRARY
							NAMES Cg
							${CG_LIB_SEARCH_PATH}
							PATHS
							$ENV{CG_LIB_PATH}
							$ENV{PROGRAMFILES}/Cg
							${PROJECT_SOURCE_DIR}/../Cg
							${CG_COMPILER_SUPER_DIR}/lib
							${CG_COMPILER_DIR}
							DOC "The Cg runtime library"
							)
						FIND_LIBRARY( CG_GL_LIBRARY
							NAMES CgGL
							${CG_LIB_SEARCH_PATH}
							PATHS
							$ENV{PROGRAMFILES}/Cg
							${PROJECT_SOURCE_DIR}/../Cg
							${CG_COMPILER_SUPER_DIR}/lib
							${CG_COMPILER_DIR}
							DOC "The Cg runtime library"
							)
		ENDIF()
  ELSE (WIN32)
    FIND_PROGRAM( CG_COMPILER cgc
      /usr/bin
      /usr/local/bin
      DOC "The Cg Compiler"
      )
    GET_FILENAME_COMPONENT(CG_COMPILER_DIR "${CG_COMPILER}" PATH)
    GET_FILENAME_COMPONENT(CG_COMPILER_SUPER_DIR "${CG_COMPILER_DIR}" PATH)
    FIND_PATH( CG_INCLUDE_PATH Cg/cg.h
      /usr/include
      /usr/local/include
      ${CG_COMPILER_SUPER_DIR}/include
      DOC "The directory where Cg/cg.h resides"
      )
    FIND_LIBRARY( CG_LIBRARY Cg
      PATHS
      /usr/lib64
      /usr/lib
      /usr/local/lib64
      /usr/local/lib
      ${CG_COMPILER_SUPER_DIR}/lib64
      ${CG_COMPILER_SUPER_DIR}/lib
      DOC "The Cg runtime library"
      )
	SET(CG_LIBRARY ${CG_LIBRARY} -lpthread)
    FIND_LIBRARY( CG_GL_LIBRARY CgGL
      PATHS
      /usr/lib64
      /usr/lib
      /usr/local/lib64
      /usr/local/lib
      ${CG_COMPILER_SUPER_DIR}/lib64
      ${CG_COMPILER_SUPER_DIR}/lib
      DOC "The Cg runtime library"
      )
  ENDIF (WIN32)
ENDIF (APPLE)

if (WIN32)
	IF (CMAKE_SIZEOF_VOID_P EQUAL 8)
		GET_FILENAME_COMPONENT(CG_LIBPATH "${CG_LIBRARY}" PATH)
		GET_FILENAME_COMPONENT(CG_LIBNAME "${CG_LIBRARY}" NAME_WE)
		SET(CG_DLLPATH "CG_DLLPATH-NOTFOUND" CACHE STRING "" FORCE)	
		FIND_FILE(CG_DLLPATH
			NAMES "${CG_LIBNAME}.dll"
			HINTS "${CG_LIBPATH}"
			PATH_SUFFIXES ../bin.x64 ../dll.x64
		)
		GET_FILENAME_COMPONENT(CG_GL_LIBPATH "${CG_GL_LIBRARY}" PATH)
		GET_FILENAME_COMPONENT(CG_GL_LIBNAME "${CG_GL_LIBRARY}" NAME_WE)
		SET(CG_GL DLLPATH "CG_GL_DLLPATH-NOTFOUND" CACHE STRING "" FORCE)	
		FIND_FILE(CG_GL_DLLPATH
			NAMES "${CG_GL_LIBNAME}.dll"
			HINTS "${CG_GL_LIBPATH}"
			PATH_SUFFIXES ../bin.x64 ../dll.x64
		)
	ELSE()
		GET_FILENAME_COMPONENT(CG_LIBPATH "${CG_LIBRARY}" PATH)
		GET_FILENAME_COMPONENT(CG_LIBNAME "${CG_LIBRARY}" NAME_WE)
		SET(CG_DLLPATH "CG_DLLPATH-NOTFOUND" CACHE STRING "" FORCE)	
		FIND_FILE(CG_DLLPATH
			NAMES "${CG_LIBNAME}.dll"
			HINTS "${CG_LIBPATH}"
			PATH_SUFFIXES ../bin ../dll
		)
		GET_FILENAME_COMPONENT(CG_GL_LIBPATH "${CG_GL_LIBRARY}" PATH)
		GET_FILENAME_COMPONENT(CG_GL_LIBNAME "${CG_GL_LIBRARY}" NAME_WE)
		SET(CG_GL_DLLPATH "CG_GL_DLLPATH-NOTFOUND" CACHE STRING "" FORCE)	
		FIND_FILE(CG_GL_DLLPATH
			NAMES "${CG_GL_LIBNAME}.dll"
			HINTS "${CG_GL_LIBPATH}"
			PATH_SUFFIXES ../bin ../dll
		)
	ENDIF()
	MESSAGE(STATUS "${CG_DLLPATH}")
	MESSAGE(STATUS "${CG_GL_DLLPATH}")
	SET(CG_DLLS ${CG_DLLPATH} ${CG_GL_DLLPATH})
ENDIF(WIN32)

IF (CG_INCLUDE_PATH)
  SET( CG_FOUND 1 CACHE STRING "Set to 1 if CG is found, 0 otherwise")
ELSE (CG_INCLUDE_PATH)
  SET( CG_FOUND 0 CACHE STRING "Set to 1 if CG is found, 0 otherwise")
ENDIF (CG_INCLUDE_PATH)

MARK_AS_ADVANCED( CG_FOUND )