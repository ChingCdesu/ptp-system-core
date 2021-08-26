cmake_minimum_required(VERSION 3.5)

project(ptp-system-core)

file(GLOB_RECURSE SRC_FILES src/*.cc)

# c++17
set(CMAKE_CXX_STANDARD 17)

# 库编译设置
set(BUILD_EXAMPLES OFF)
set(BUILD_TESTING OFF)
set(build_static_lib ON)
set(CREATE_DOCS OFF)
set(BUILD_SAMPLES OFF)
set(BUILD_TESTS OFF)
set(BUILD_BENCHMARKS OFF)

# easylogging++ 日志库
add_subdirectory(thirdparty/easyloggingpp)

# fmt 格式化字符串库
add_subdirectory(thirdparty/fmt)

# libuv 事件驱动库
add_subdirectory(thirdparty/libuv)

# drogon 网络库
add_subdirectory(thirdparty/drogon)

# DOCX 读写库
add_subdirectory(thirdparty/DuckX)

# XLSX 读写库
add_subdirectory(thirdparty/OpenXLSX)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_include_directories(${PROJECT_NAME} PRIVATE
  thirdparty/OpenXLSX/library/headers
  thirdparty/DuckX/include
  thirdparty/easyloggingpp/src
  thirdparty/fmt/include
  thirdparty/libuv/include
  thirdparty/drogon/lib/inc
  thirdparty/drogon/nosql_lib/redis/inc
  thirdparty/drogon/orm_lib/inc
  ${MYSQL_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
  uv
  fmt
  duckx
  drogon
  easyloggingpp
  OpenXLSX-static
  ${MYSQL_LIBRARIES}
)
