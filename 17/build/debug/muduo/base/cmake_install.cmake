# Install script for directory: /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/build/debug-install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/build/debug/lib/libmuduo_base.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/muduo/base" TYPE FILE FILES
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/Atomic.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/BlockingQueue.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/BoundedBlockingQueue.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/Condition.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/CountDownLatch.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/CurrentThread.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/Exception.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/Mutex.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/Singleton.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/Thread.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/ThreadPool.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/Timestamp.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/Types.h"
    "/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/jmuduo/muduo/base/copyable.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/17/build/debug/muduo/base/tests/cmake_install.cmake")

endif()

