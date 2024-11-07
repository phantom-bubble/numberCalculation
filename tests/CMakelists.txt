# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("my_test")

set(CMAKE_CXX_FLAGS "-O3")

# 将源代码添加到此项目的可执行文件。
#add_executable (CMakeProject1 "main.cpp" "src/number.cpp")
#target_link_libraries(CMakeProject1 number)
#target_include_directories(CMakeProject1 PRIVATE
#  ${PROJECT_SOURCE_DIR}/include
#)



#add_subdirectory(tests)

# 启用测试
#enable_testing()
#add_test(NAME MainTest COMMAND CMakeProject1)



#if (CMAKE_VERSION VERSION_GREATER 3.12)
  #set_property(TARGET CMakeProject1 PROPERTY CXX_STANDARD 20)
#endif()
