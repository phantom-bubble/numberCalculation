# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMakeProject1")

set(CMAKE_CXX_FLAGS "-O3")

#把文件parentsisMatch.cpp编译为动态链接库

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
# 获取src文件夹下所有的.cpp文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCES)
add_library (number SHARED ${SOURCES})
target_include_directories(number PRIVATE
  ${PROJECT_SOURCE_DIR}/include
)

# 将源代码添加到此项目的可执行文件。
add_executable (CMakeProject1 "main.cpp" "src/number.cpp" "src/rational.cpp")
#target_link_libraries(CMakeProject1 number)
target_include_directories(CMakeProject1 PRIVATE
  ${PROJECT_SOURCE_DIR}/include
)

if(TEST)

add_subdirectory(tests)

# 启用测试
enable_testing()
add_test(NAME MainTest COMMAND CMakeProject1)

endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
