project(HELLO)
if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-std=c++11)
    message(STATUS "optional:-std=c++11")   
endif(CMAKE_COMPILER_IS_GNUCXX)
#SET(CMAKE_SYSTEM_NAME Linux)
#SET(CMAKE_C_COMPILER "arm-linux-gnueabihf-gcc")
SET(CMAKE_C_COMPILER "gcc")
#SET(CMAKE_CXX_COMPILER "arm-linux-gnueabihf-g++")
SET(CMAKE_CXX_COMPILER "g++")

#指定交叉编译环境安装目录...
#SET(CMAKE_FIND_ROOT_PATH "/home/seanwon/tool/gcc-linaro-arm-linux-gnueabihf-4.9-2014.07_linux")

#从来不在指定目录下查找工具程序
#SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

#只在指定目录下查找库文件
#SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)

#只在指定目录下查找头文件
#SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

add_subdirectory(ExcelMain)
add_subdirectory(ExcelLib)
